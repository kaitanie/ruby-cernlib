/*
 *  hbook2.c  - more Obeject-Oriented Histogram and N-tuple classes
 *    This program is a part of Ruby/CERNLIB package
 *  (c) 1999 - 2003  TAKAHASHI Hitoshi <hitoshi.takahashi@kek.jp>
 */

#include <ruby.h>
#include <unistd.h>
#include "hbook2.h"

/* How can I allocate memory of /PAWC/ dynamically? */
/* Default memory size of PAW is 2000000. */
#define NWPAWC 2000000
struct {
  float hmemor[NWPAWC];
} pawc_;

VALUE mHBook2;
VALUE cBasicHist;
VALUE cHist1;
VALUE cHist2;
VALUE cProfile;
VALUE cNtuple;
VALUE cRWNtuple;
VALUE cCWNtuple;
VALUE cCWNBlock;
VALUE cTable;
VALUE cRZFile;
VALUE cRZDir;


/*** functions for HBOOK module ***/

static VALUE
hbook2_write_all(VALUE module, VALUE file)
{
  char *option = "N";

  Check_SafeStr(file);
  hrput_(&zero, STR2CSTR(file), option, RSTRING(file)->len, 1);
  return Qnil;
}

int
hbook2_read_file(int id, char *filename)
{
  int stat;
  int lun = 1, lrec = 1024, cycle = 0, offset = 0;
  char *option = " ";
  char *topname = "HBOOK";

  if (eaccess(filename, R_OK) < 0) {
    rb_sys_fail(filename);
    return -1;
  }
  hropen_(&lun, topname, filename, option, &lrec, &stat,
	  strlen(topname), strlen(filename), 1);
  hrin_(&id, &cycle, &offset);
  hrend_(topname, strlen(topname));

  return 0;
}

VALUE
hbook2_make_object_from_data_auto_type(int id)
{
  int kind[32];
  char *option = " ";

  hkind_(&id, kind, option, 1);
  switch (kind[0]) {
  case 1:
    return hbook2_make_histogram_from_data(cHist1, id);
  case 2:
    return hbook2_make_histogram_from_data(cHist1, id);
  case 3:
    return hbook2_make_histogram_from_data(cTable, id);
  case 4:
    return hbook2_make_ntuple_from_data(id);
  case 8:
    return hbook2_make_histogram_from_data(cProfile, id);
  default:
    rb_raise(rb_eRuntimeError, "Unknown histogram or N-tuple type: %d", kind[0]);
  }
}

static VALUE
hbook2_read_all(int argc, VALUE *argv, VALUE module)
{
  int i;
  VALUE file, max;
  int num_hist = 100;
  int *hid;
  VALUE ary_hist1 = rb_ary_new();
  VALUE ary_hist2 = rb_ary_new();
  VALUE ary_prof = rb_ary_new();
  VALUE ary_ntuple = rb_ary_new();
  VALUE ary_table = rb_ary_new();
  int kind[32];
  char *option = " ";

  if (rb_scan_args(argc, argv, "11", &file, &max) == 2)
    num_hist = NUM2INT(max);

  Check_SafeStr(file);
  if (hbook2_read_file(0, STR2CSTR(file)) < 0)
    return Qnil;

  hid = ALLOCA_N(int, num_hist);
  hidall_(hid, &num_hist);
  for (i = 0; i < num_hist; i++) {
    hkind_(&hid[i], kind, option, 1);
    switch (kind[0]) {
    case 1:
      rb_ary_push(ary_hist1, hbook2_make_histogram_from_data(cHist1, hid[i]));
      break;
    case 2:
      rb_ary_push(ary_hist2, hbook2_make_histogram_from_data(cHist2, hid[i]));
      break;
    case 3:
      rb_ary_push(ary_table, hbook2_make_histogram_from_data(cTable, hid[i]));
      break;
    case 4:
      rb_ary_push(ary_ntuple, hbook2_make_ntuple_from_data(hid[i]));
      break;
    case 8:
      rb_ary_push(ary_prof, hbook2_make_histogram_from_data(cProfile, hid[i]));
      break;
    }
  }

  return rb_ary_new3(3, ary_hist1, ary_hist2, ary_prof, ary_ntuple, ary_table);
}

static VALUE
hbook2_exist_p(VALUE module, VALUE id)
{
  int hid = NUM2INT(id);

  return hexist_(&hid) ? Qtrue : Qfalse;
}

static VALUE
hbook2_merge(VALUE module, VALUE src, VALUE dest)
{
  int i, j;
  int num_file, len;
  char *srcfiles, *src_ptr, *ptr;
  int len_max = 0;

  Check_Type(src, T_ARRAY);
  Check_SafeStr(dest);
  num_file = RARRAY(src)->len;
  for (i = 0; i < num_file; i++) {
    Check_SafeStr(RARRAY(src)->ptr[i]);
    len = RSTRING(RARRAY(src)->ptr[i])->len;
    if (len_max < len)
      len_max = len;
  }
  srcfiles = ALLOCA_N(char, num_file * len_max + 1);
  src_ptr = srcfiles;
  for (i = 0; i < num_file; i++) {
    ptr = STR2CSTR(RARRAY(src)->ptr[i]);
    for (j = 0; j < len_max && *ptr; j++)
      *src_ptr++ = *ptr++;
    for (; j < len_max; j++)
      *src_ptr++ = ' ';
  }
  srcfiles[num_file * len_max] = '\0';

  hmerge_(&num_file, srcfiles, STR2CSTR(dest),
	  len_max, RSTRING(dest)->len);
  return Qnil;
}


void
Init_hbook2()
{
  VALUE mCERN;
  const int nwpawc = NWPAWC;

  hlimit_(&nwpawc);

  /*** definitions of HBOOK module ***/
  mCERN = rb_define_module("CERN");
  mHBook2 = rb_define_module_under(mCERN, "HBook2");

  rb_define_const(mHBook2, "NWPAWC", INT2NUM(NWPAWC));
  rb_define_module_function(mHBook2, "write_all", hbook2_write_all, 1);
  rb_define_module_function(mHBook2, "read_all", hbook2_read_all, -1);
  rb_define_module_function(mHBook2, "exist?", hbook2_exist_p, 1);
  rb_define_module_function(mHBook2, "merge", hbook2_merge, 2);
#if 0  /* not yet */
  rb_define_module_function(mHBook2, "read1", hbook2_read1, -1);
  rb_define_module_function(mHBook2, "read2", hbook2_read2, -1);
#endif

  /*** definitions of Histogram classes ***/
  Init_hbook2_hist();

  /*** definitions of Ntuple classes ***/
  Init_hbook2_ntuple();

  /*** definitions of RZFile/RZDir classes ***/
  Init_hbook2_rz();
}
