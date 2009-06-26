/*
 *  rz.c  - RZ directory and file classes under HBook2 module
 *    This program is a part of Ruby/CERNLIB package
 *  (c) 1999 - 2003  TAKAHASHI Hitoshi <hitoshi.takahashi@kek.jp>
 */

#include <ruby.h>
#include <math.h>
#include <unistd.h>
#include "hbook2.h"


/*** functions for RZDir class ***/

static void
free_rz_dir(RZDir *dir)
{
  if (dir->name)
    free(dir->name);
  free(dir);
}

static void
init_rz_dir(RZDir *dir, char *name)
{
  dir->name = ALLOC_N(char, strlen(name) + 1);
  strcpy(dir->name, name);
  dir->hid = 0;
  dir->closed = 0;
}

static VALUE
make_rz_dir(char *name)
{
  RZDir *dir;
  VALUE obj = Data_Make_Struct(cRZDir, RZDir, 0, free_rz_dir, dir);
  init_rz_dir(dir, name);
  return obj;
}

RZDir*
hbook2_get_rz_dir(VALUE obj)
{
  RZDir *dir;

  Data_Get_Struct(obj, RZDir, dir);
  if (dir->closed)
    rb_raise(rb_eRuntimeError, "RZ dir %s was already closed!\n", dir->name);
  return dir;
}

char*
hbook2_current_dir_name()
{
  int i;
  char *option = "R";
  char *dir = ALLOC_N(char, 1024);

  hcdir_(dir, option, 1023, 1);
  for (i = 1022; dir[i] == ' ' && i >= 0; i--);
  dir[i + 1] = '\0';
  return dir;
}

static char *
full_path_name(char *path)
{
  int i;
  char *cd_option = " ";
  char *pwd_option = "R";
  char *cur_dir = hbook2_current_dir_name();
  char *dir = ALLOC_N(char, 1024);

  hcdir_(path, cd_option, strlen(path), 1);
  hcdir_(dir, pwd_option, 1023, 1);
  for (i = 1022; dir[i] == ' ' && i >=0; i--);
  dir[i + 1] = '\0'; 
  hcdir_(cur_dir, cd_option, strlen(cur_dir), 1);
  free(cur_dir);
  return dir;
}

static VALUE
rzdir_s_expand_path(VALUE obj, VALUE path)
{
  char *dir = full_path_name(STR2CSTR(path));
  VALUE str = rb_str_new2(dir);

  free(dir);
  return str;
}

static VALUE
rzdir_s_current_dir(VALUE obj)
{
  char *dir = hbook2_current_dir_name();
  VALUE dirname = rb_str_new2(dir);

  free(dir);
  return dirname;
}

static VALUE
rzdir_s_make_dir(VALUE obj, VALUE dir)
{
  char *option = " ";
  char *dirname;
  VALUE new_dir;

  hmdir_(STR2CSTR(dir), option, RSTRING(dir)->len, 1);
  dirname = full_path_name(STR2CSTR(dir));
  new_dir = make_rz_dir(dirname);
  free(dirname);
  return new_dir;
}

static VALUE
rzdir_s_remove_dir(VALUE obj, VALUE dir)
{
  hddir_(STR2CSTR(dir), RSTRING(dir)->len);
  return Qnil;
}

static VALUE
rzdir_s_change_dir(VALUE obj, VALUE dir)
{
  char *option = " ";

  hcdir_(STR2CSTR(dir), option, RSTRING(dir)->len, 1);
  return Qnil;
}

static VALUE
rzdir_s_list_dir(int argc, VALUE *argv, VALUE obj)
{
  VALUE dir;
  char *option = " ";
  char *dirname;

  if (rb_scan_args(argc, argv, "01", &dir) == 1)
    dirname = STR2CSTR(dir);
  else
    dirname = " ";
  hldir_(dirname, option, strlen(dirname), 1);
  return Qnil;
}

static VALUE
rzdir_s_allocate(VALUE klass)
{
  RZDir *dir;
  return Data_Make_Struct(klass, RZDir, 0, free_rz_dir, dir);
}

#ifdef HAVE_OBJECT_ALLOCATE
#define rzdir_s_new rb_class_new_instance
#else
static VALUE
rzdir_s_new(int argc, VALUE *argv, VALUE klass)
{
  VALUE obj = rzdir_s_allocate(klass);
  rb_obj_call_init(obj, argc, argv);
  return obj;
}
#endif

static void
rzdir_init_intern(int argc, VALUE *argv, RZDir *dir)
{
  VALUE dirname;
  char *name;

  if (rb_scan_args(argc, argv, "01", &dirname) == 1)
    name = full_path_name(STR2CSTR(dirname));
  else
    name = hbook2_current_dir_name();
  init_rz_dir(dir, name);
  free(name);
}

static VALUE
rzdir_initialize(int argc, VALUE *argv, VALUE obj)
{
  rzdir_init_intern(argc, argv, hbook2_get_rz_dir(obj));
  return obj;
}

static VALUE
rzdir_s_open(int argc, VALUE *argv, VALUE klass)
{
  VALUE result;
  RZDir *dir;
  VALUE obj = Data_Make_Struct(klass, RZDir, 0, free_rz_dir, dir);
  rzdir_init_intern(argc, argv, dir);
  if (rb_block_given_p()) {
    result = rb_yield(obj);
    dir->closed = 1;
    return result;
  } else {
    return obj;
  }
}

static VALUE
rzdir_closed_p(VALUE obj)
{
  RZDir *dir;

  Data_Get_Struct(obj, RZDir, dir);
  return dir->closed ? Qtrue : Qfalse;
}

static VALUE
rzdir_close(VALUE obj)
{
  hbook2_get_rz_dir(obj)->closed = 1;
  return Qnil;
}

static VALUE
rzdir_to_s(VALUE obj)
{
  return rb_str_new2(hbook2_get_rz_dir(obj)->name);
}

static VALUE
rzdir_inspect(VALUE obj)
{
  RZDir *dir = hbook2_get_rz_dir(obj);
  char *klass = rb_class2name(CLASS_OF(obj));
  char *str = ALLOCA_N(char, strlen(klass) + strlen(dir->name) + 10);

  sprintf(str, "#<%s:\"%s\">", klass, dir->name);
  return rb_str_new2(str);
}

static VALUE
rzdir_rewind(VALUE obj)
{
  hbook2_get_rz_dir(obj)->hid = 0;
  return Qnil;
}

static VALUE
rzdir_write(VALUE obj, VALUE hist)
{
  char *option = " ";
  RZDir *dir = hbook2_get_rz_dir(obj);
  HistData *data = hbook2_get_hist_data(hist);
  char *cur_dir = hbook2_current_dir_name();
  int cycle;

  hcdir_(dir->name, option, strlen(dir->name), 1);
  hrout_(&data->id, &cycle, option, 1);
  hcdir_(cur_dir, option, strlen(cur_dir), 1);
  free(cur_dir);
  return obj;
}

static VALUE
rzdir_write_all(VALUE obj)
{
  char *option = " ";
  RZDir *dir = hbook2_get_rz_dir(obj);
  char *cur_dir = hbook2_current_dir_name();
  int id = 0;
  int cycle;

  hcdir_(dir->name, option, strlen(dir->name), 1);
  hrout_(&id, &cycle, option, 1);
  hcdir_(cur_dir, option, strlen(cur_dir), 1);
  free(cur_dir);
  return Qnil;
}

static VALUE
rzdir_read_by_id(VALUE obj, VALUE id)
{
  char *option = " ";
  RZDir *dir = hbook2_get_rz_dir(obj);
  int offset = 0;
  int cycle = 999;
  int hid = NUM2INT(id);
  char *cur_dir = hbook2_current_dir_name();

  hcdir_(dir->name, option, strlen(dir->name), 1);
  hrin_(&hid, &cycle, &offset);
  hcdir_(cur_dir, option, strlen(cur_dir), 1);
  free(cur_dir);
  hid += offset;
  if (hexist_(&hid))
    return hbook2_make_object_from_data_auto_type(hid);
  else
    rb_raise(rb_eArgError, "No such a histogram: ID#%d", hid - offset);
}

static VALUE
rzdir_next_object(int *id, char *dir)
{
  int i;
  char *dirname;
  char *option = " ";
  char type[2], title[MAX_TITLE_LENGTH + 1];
  int cycle = 0, offset = 0;

  hlnext_(id, type, title, option, 1, MAX_TITLE_LENGTH, strlen(option));
  if (*id == 0)
    return Qnil;
  switch (type[0]) {
  case '1':  /* 1D-histogram or profile */
    hrin_(id, &cycle, &offset);
    return hbook2_make_object_from_data_auto_type(*id);
  case '2':  /* 2D-histogram */
    hrin_(id, &cycle, &offset);
    return hbook2_make_histogram_from_data(cHist2, *id);
  case 'N':  /* N-tuple */
    return hbook2_make_ntuple_from_data(*id);
  case 'D':  /* subdirectory */
    for (i = MAX_TITLE_LENGTH - 1; title[i] == ' ' && i >= 0; i--);
    title[i + 1] = '\0';
    dirname = ALLOCA_N(char, strlen(dir) + i + 3);
    sprintf(dirname, "%s/%s", dir, title);
    return make_rz_dir(dirname);
  case '?':  /* unknown type */
  default:
    rb_raise(rb_eRuntimeError, "contents type unknown: ID#%d", *id);
  }
}

static VALUE
rzdir_read_intern(VALUE obj)
{
  RZDir *dir = hbook2_get_rz_dir(obj);
  return rzdir_next_object(&dir->hid, dir->name);
}

static VALUE
rzdir_popd(VALUE dir)
{
  char *option = " ";
  char *dirname = STR2CSTR(dir);

  hcdir_(dirname, option, strlen(dirname), 1);
  return Qnil;
}

static VALUE
rzdir_read(VALUE obj)
{
  char *option = " ";
  RZDir *dir = hbook2_get_rz_dir(obj);
  char *cur_dir = hbook2_current_dir_name();
  VALUE cur_dir_name = rb_str_new2(cur_dir);

  free(cur_dir);
  hcdir_(dir->name, option, strlen(dir->name), 1);
  return rb_ensure(rzdir_read_intern, obj, rzdir_popd, cur_dir_name);
}

static VALUE
rzdir_each_intern(VALUE obj)
{
  int id = 0;
  RZDir *dir = hbook2_get_rz_dir(obj);
  VALUE new_obj;

  while (1) {
    new_obj = rzdir_next_object(&id, dir->name);
    if (id == 0)
      break;
    rb_yield(new_obj);
  }
  return Qnil;
}

static VALUE
rzdir_each(VALUE obj)
{
  char *option = " ";
  RZDir *dir = hbook2_get_rz_dir(obj);
  char *cur_dir = hbook2_current_dir_name();
  VALUE cur_dir_name = rb_str_new2(cur_dir);

  free(cur_dir);
  hcdir_(dir->name, option, strlen(dir->name), 1);
  return rb_ensure(rzdir_each_intern, obj, rzdir_popd, cur_dir_name);
}

static VALUE
rzdir_make_dir(VALUE obj, VALUE subdir)
{
  RZDir *dir = hbook2_get_rz_dir(obj);
  char *option = " ";
  char *cur_dir = hbook2_current_dir_name();
  char *dirname;
  VALUE new_dir;

  hcdir_(dir->name, option, strlen(dir->name), 1);
  hmdir_(STR2CSTR(subdir), option, RSTRING(subdir)->len, 1);
  dirname = full_path_name(STR2CSTR(subdir));
  new_dir = make_rz_dir(dirname);
  hcdir_(cur_dir, option, strlen(cur_dir), 1);
  free(cur_dir);
  free(dirname);
  return new_dir;
}

static VALUE
rzdir_change_dir(VALUE obj)
{
  RZDir *dir = hbook2_get_rz_dir(obj);
  char *option = " ";

  hcdir_(dir->name, option, strlen(dir->name), 1);
  return Qnil;
}

static VALUE
rzdir_s_foreach(int argc, VALUE *argv, VALUE obj)
{
  VALUE dirname, dir;

  if (rb_scan_args(argc, argv, "01", &dirname) != 1)
    dirname = rb_str_new2(" ");
  dir = rb_funcall(cRZDir, rb_intern("open"), 1, dirname);
  return rb_ensure(rzdir_each, dir, rzdir_close, dir);
}

static VALUE
rzdir_s_entries(int argc, VALUE *argv, VALUE obj)
{
  VALUE dirname, dir;

  if (rb_scan_args(argc, argv, "01", &dirname) != 1)
    dirname = rb_str_new2(" ");
  dir = rb_funcall(cRZDir, rb_intern("open"), 1, dirname);
  return rb_ensure(rb_Array, dir, rzdir_close, dir);
}


/*** functions for RZFile class ***/

static void
free_rz_file(RZFile *file)
{
  if (file->dir.name)
    free(file->dir.name);
  if (file->filename)
    free(file->filename);
  if (file->option)
    free(file->option);
  free(file);
}

RZFile *
hbook2_get_rz_file(VALUE obj)
{
  RZFile *rz_file;

  Data_Get_Struct(obj, RZFile, rz_file);
  if (rz_file->dir.closed)
    rb_raise(rb_eRuntimeError, "RZ file %s was already closed!\n", rz_file->filename);
  return rz_file;
}

static VALUE
rzfile_s_allocate(VALUE klass)
{
  RZFile *file;
  return Data_Make_Struct(klass, RZFile, 0, free_rz_file, file);
}

#ifdef HAVE_OBJECT_ALLOCATE
#define rzfile_s_new rb_class_new_instance
#else
static VALUE
rzfile_s_new(int argc, VALUE *argv, VALUE klass)
{
  VALUE obj = rzfile_s_allocate(klass);
  rb_obj_call_init(obj, argc, argv);
  return obj;
}
#endif

static void
rzfile_init_intern(int argc, VALUE *argv, RZFile *file)
{
  static int lun = 1;
  VALUE filename, topname, opt;
  int stat;
  int lrec = 1024;
  char *option = " ";
  char *cd_option = " ";
  char *cur_dir = hbook2_current_dir_name();
  int n = rb_scan_args(argc, argv, "12", &filename, &topname, &opt);

  Check_SafeStr(filename);

  file->lun = lun;
  file->filename = ALLOC_N(char, RSTRING(filename)->len + 1);
  strcpy(file->filename, STR2CSTR(filename));
  if (n > 1) {
    Check_Type(topname, T_STRING);
    file->topname = ALLOC_N(char, RSTRING(topname)->len + 1);
    strcpy(file->topname, STR2CSTR(topname));
  } else {
    file->topname = ALLOC_N(char, (int) log10(lun) + 6);
    sprintf(file->topname, "lun%d", lun);
  }
  if (n == 3)
    option = STR2CSTR(opt);
  file->option = ALLOC_N(char, strlen(option) + 1);
  strcpy(file->option, option);
  file->dir.name = ALLOC_N(char, strlen(file->topname) + 2);
  sprintf(file->dir.name, "//%s", file->topname);
  file->dir.hid = 0;
  file->dir.closed = 0;

#if 0
  if (eaccess(file->filename, R_OK) < 0)
    rb_sys_fail(file->filename);
#endif
  hropen_(&file->lun, file->topname, file->filename, file->option,
	  &lrec, &stat, strlen(file->topname),
	  strlen(file->filename), strlen(file->option));
  lun++;
  hcdir_(cur_dir, cd_option, strlen(cur_dir), 1);
  free(cur_dir);
}

static VALUE
rzfile_initialize(int argc, VALUE *argv, VALUE obj)
{
  rzfile_init_intern(argc, argv, hbook2_get_rz_file(obj));
  return obj;
}

static VALUE
rzfile_s_open(int argc, VALUE *argv, VALUE klass)
{
  VALUE result;
  RZFile *file;
  VALUE obj = Data_Make_Struct(cRZFile, RZFile, 0, free_rz_file, file);
  rzfile_init_intern(argc, argv, file);
  if (rb_block_given_p()) {
    result = rb_yield(obj);
    hrend_(file->topname, strlen(file->topname));
    file->dir.closed = 1;
    return result;
  } else {
    return obj;
  }
}

static VALUE
rzfile_close(VALUE obj)
{
  RZFile *file = hbook2_get_rz_file(obj);

  hrend_(file->topname, strlen(file->topname));
  file->dir.closed = 1;
  return Qnil;
}

static VALUE
rzfile_inspect(VALUE obj)
{
  RZFile *file = hbook2_get_rz_file(obj);
  char *klass = rb_class2name(CLASS_OF(obj));
  char *str = ALLOCA_N(char, strlen(klass) + strlen(file->filename)
		              + ((int) log10(file->lun)) + 10);

  sprintf(str, "#<%s:%d,\"%s\">",
	  klass, file->lun, file->filename);
  return rb_str_new2(str);
}

static VALUE
rzfile_lun(VALUE obj)
{
  return INT2NUM(hbook2_get_rz_file(obj)->lun);
}

static VALUE
rzfile_filename(VALUE obj)
{
  return rb_str_new2(hbook2_get_rz_file(obj)->filename);
}

static VALUE
rzfile_topname(VALUE obj)
{
  return rb_str_new2(hbook2_get_rz_file(obj)->topname);
}

static VALUE
rzfile_option(VALUE obj)
{
  return rb_str_new2(hbook2_get_rz_file(obj)->option);
}


void
Init_hbook2_rz()
{
  cRZDir = rb_define_class_under(mHBook2, "RZDir", rb_cData);

  rb_include_module(cRZDir, rb_mEnumerable);

#ifdef HAVE_OBJECT_ALLOCATE
  rb_define_alloc_func(cRZDir, rzdir_s_allocate);
#else
  rb_define_singleton_method(cRZDir, "new", rzdir_s_new, -1);
#endif

  rb_define_singleton_method(cRZDir, "expand_path", rzdir_s_expand_path, 1);
  rb_define_singleton_method(cRZDir, "getwd", rzdir_s_current_dir, 0);
  rb_define_singleton_method(cRZDir, "pwd", rzdir_s_current_dir, 0);
  rb_define_singleton_method(cRZDir, "mkdir", rzdir_s_make_dir, 1);
  rb_define_singleton_method(cRZDir, "rmdir", rzdir_s_remove_dir, 1);
  rb_define_singleton_method(cRZDir, "delete", rzdir_s_remove_dir, 1);
  rb_define_singleton_method(cRZDir, "chdir", rzdir_s_change_dir, 1);
  rb_define_singleton_method(cRZDir, "list", rzdir_s_list_dir, -1);
  rb_define_singleton_method(cRZDir, "foreach", rzdir_s_foreach, -1);
  rb_define_singleton_method(cRZDir, "entries", rzdir_s_entries, -1);
  rb_define_singleton_method(cRZDir, "open", rzdir_s_open, -1);
  rb_define_method(cRZDir, "initialize", rzdir_initialize, -1);
  rb_define_method(cRZDir, "close", rzdir_close, 0);
  rb_define_method(cRZDir, "closed?", rzdir_closed_p, 0);
  rb_define_method(cRZDir, "to_s", rzdir_to_s, 0);
  rb_define_method(cRZDir, "inspect", rzdir_inspect, 0);
  rb_define_method(cRZDir, "rewind", rzdir_rewind, 0);
  rb_define_method(cRZDir, "write", rzdir_write, 1);
  rb_define_method(cRZDir, "<<", rzdir_write, 1);
  rb_define_method(cRZDir, "write_all", rzdir_write_all, 0);
  rb_define_method(cRZDir, "[]", rzdir_read_by_id, 1);
  rb_define_method(cRZDir, "read", rzdir_read, 0);
  rb_define_method(cRZDir, "each", rzdir_each, 0);
  rb_define_method(cRZDir, "mkdir", rzdir_make_dir, 1);
  rb_define_method(cRZDir, "chdir", rzdir_change_dir, 0);


  cRZFile = rb_define_class_under(mHBook2, "RZFile", cRZDir);

#ifdef HAVE_OBJECT_ALLOCATE
  rb_define_alloc_func(cRZFile, rzfile_s_allocate);
#else
  rb_define_singleton_method(cRZFile, "new", rzfile_s_new, -1);
#endif

  rb_define_singleton_method(cRZFile, "open", rzfile_s_open, -1);
  rb_define_method(cRZFile, "initialize", rzfile_initialize, -1);
  rb_define_method(cRZFile, "close", rzfile_close, 0);
  rb_define_method(cRZFile, "inspect", rzfile_inspect, 0);
  rb_define_method(cRZFile, "lun", rzfile_lun, 0);
  rb_define_method(cRZFile, "filename", rzfile_filename, 0);
  rb_define_method(cRZFile, "topname", rzfile_topname, 0);
  rb_define_method(cRZFile, "option", rzfile_option, 0);
}
