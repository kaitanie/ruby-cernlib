/*
 *  ntuple.c  - N-tuple classes under HBook2 module
 *    This program is a part of Ruby/CERNLIB package
 *  (c) 1999 - 2003  TAKAHASHI Hitoshi <hitoshi.takahashi@kek.jp>
 */

#include <ruby.h>
#include <math.h>
#include "hbook2.h"

static VALUE cwnblock_ref(VALUE obj);
static VALUE cwnblock_set(VALUE obj, VALUE val);
static VALUE cwnblock_s_ref(VALUE klass);
static VALUE cwnblock_s_set(VALUE klass, VALUE val);
static VALUE cwnblock_s_new(int argc, VALUE *argv, VALUE klass);
static VALUE cwnblock_s_members(VALUE klass);


/* translate Fortran-style string to C-style and return its length */
int
cern_util_str_f2c(char *str, int max_len)
{
  int len = max_len - 1;
  while (*(str + len) == ' ' && len >= 0)
    len--;
  *(str + (++len)) = '\0';
  return len;
}


static int
get_member_index(RWNData *data, char *member)
{
  int i;

  for (i = 0; i < data->nvar; i++) {
    if (strcmp(data->variable[i], member) == 0)
      return i;
  }
  rb_raise(rb_eNameError, "%s is not struct member", member);
}

static int
get_num_entry(NtupleData *data)
{
  int entry;
  hnoent_(&data->id, &entry);
  return entry;
}

static void
free_rwn(RWNData *data)
{
  int i;

  if (hexist_(&data->id))
    hdelet_(&data->id);
  if (data->title)
    free(data->title);
  for (i = 0; i < data->nvar; i++) {
    if (data->variable[i])
      free(data->variable[i]);
  }
  free(data);
}

NtupleData *
hbook2_get_ntuple_data(VALUE obj)
{
  NtupleData *data;

  Data_Get_Struct(obj, NtupleData, data);
  if (data->deleted)
    rb_raise(rb_eRuntimeError, "Ntuple ID#%d was deleted!\n", data->id);
  return data;
}

static void
free_cwn(CWNData *data)
{
  int i;

  if (hexist_(&data->id))
    hdelet_(&data->id);
  if (data->title)
    free(data->title);
  if (data->blocks) {
    for (i = 0; i < data->num_block; i++) {
      if (data->blocks[i].name)
	free(data->blocks[i].name);
      if (data->blocks[i].buf)
	free(data->blocks[i].buf);
    }
    free(data->blocks);
  }
  free(data);
}

static void
mark_cwn(CWNData *data)
{
  int i;
  for (i = 0; i < data->num_block; i++)
    rb_gc_mark(data->blocks[i].klass);
}

static void
free_cwnblock(CWNBlock *block)
{
  if (block) {
    if (block->buf)
      free(block->buf);
    free(block);
  }
}

CWNBlock *
hbook2_get_cwnblock(VALUE obj)
{
  CWNBlock *block;

  Data_Get_Struct(obj, CWNBlock, block);
  return block;
}

static VALUE
make_cwnblock_class(char *blockname, int nvar, CWNVar *var)
{
  int i;
  long *ptr;
  CWNBlock *block;
  VALUE klass = rb_define_class_under(cCWNBlock, blockname, cCWNBlock);
  VALUE template = Data_Make_Struct(cCWNBlock, CWNBlock, 0,
				    free_cwnblock, block);
  VALUE singleton_klass = rb_singleton_class(klass);

  block->name = rb_intern(blockname);
  block->nvar = nvar;
  block->var = ALLOC_N(CWNVar, nvar);
  memcpy(block->var, var, sizeof(CWNVar) * nvar);
  block->size = 0;
  for (i = 0; i < nvar; i++) {
    block->size += var[i].size;
    rb_define_method_id(klass, var[i].name, cwnblock_ref, 0);
    rb_define_method_id(klass, rb_id_attrset(var[i].name), cwnblock_set, 1);
    rb_define_method_id(singleton_klass, var[i].name, cwnblock_s_ref, 0);
    rb_define_method_id(singleton_klass, rb_id_attrset(var[i].name), cwnblock_s_set, 1);
  }
  ptr = block->buf = ALLOC_N(float, block->size);
  for (i = 0; i < nvar; i++) {
    block->var[i].ptr = ptr;
    *ptr = 0;
    ptr += block->var[i].size;
  }

  rb_iv_set(klass, "__template__", template);
  rb_define_singleton_method(klass, "new", cwnblock_s_new, -1);
  rb_define_singleton_method(klass, "members", cwnblock_s_members, 0);

  return klass;
}

static VALUE
make_cwnblock_instance(VALUE klass, CWNBlock **block)
{
  int i;
  long *ptr;
  VALUE template = rb_iv_get(klass, "__template__");
  CWNBlock *template_block = hbook2_get_cwnblock(template);
  VALUE obj = Data_Make_Struct(klass, CWNBlock, 0,
			       free_cwnblock, *block);

  (*block)->name = template_block->name;
  (*block)->size = template_block->size;
  (*block)->nvar = template_block->nvar;
  (*block)->var = ALLOC_N(CWNVar, (*block)->nvar);
  memcpy((*block)->var, template_block->var, sizeof(CWNVar) * (*block)->nvar);
  ptr = (*block)->buf = ALLOC_N(float, (*block)->size);
  for (i = 0; i < (*block)->nvar; i++) {
    (*block)->var[i].ptr = ptr;
    ptr += (*block)->var[i].size;
  }
  return obj;
}

static VALUE
make_rwn_from_data_intern(int id, char *title, int nvar, char *varname)
{
  int i;
  RWNData *data;
  int len_varname;
  VALUE obj = Data_Make_Struct(cRWNtuple, RWNData, 0, free_rwn, data);

  data->id = id;
  data->nvar = nvar;
  data->title = ALLOC_N(char, strlen(title) + 1);
  strcpy(data->title, title);
  data->variable = ALLOC_N(char*, nvar);
  for (i = 0; i < nvar; i++) {
    for (len_varname = MAX_VARNAME_LENGTH - 1;
	 *(varname + len_varname) == ' ' && len_varname >= 0; len_varname--);
    *(varname + (++len_varname)) = '\0';
    data->variable[i] = ALLOC_N(char, len_varname + 1);
    strcpy(data->variable[i], varname);
    varname += MAX_VARNAME_LENGTH;
  }
  data->deleted = 0;
  return obj;
}

static VALUE
make_cwn_from_data_intern(int id, char *title, int nvar)
{
  int i;
  CWNData *data;
  char block_name[MAX_BLOCKNAME_LENGTH + 1], var_name[MAX_VARNAME_LENGTH + 1];
  int len_blockname;
  ID block_id, pre_block_id;
  CWNStoredBlock *cur_block;
  CWNVar *cwnvar, *cwnvar_p;
  int *block_nvar, *block_size;
  int nsub, size, type, elem;
  VALUE obj = Data_Make_Struct(cCWNtuple, CWNData, mark_cwn, free_cwn, data);

  data->id = id;
  data->nvar = nvar;
  data->num_block = 0;
  data->blocks = NULL;
  data->title = ALLOC_N(char, strlen(title) + 1);
  strcpy(data->title, title);

  cwnvar = ALLOCA_N(CWNVar, nvar);
  block_nvar = ALLOCA_N(int, nvar);
  block_size = ALLOCA_N(int, nvar);
  pre_block_id = 0;
  for (i = 1; i <= nvar; i++) {
    hntvar_(&data->id, &i, var_name, block_name, &nsub, &type, &size, &elem,
	    MAX_VARNAME_LENGTH, MAX_BLOCKNAME_LENGTH);
    len_blockname = cern_util_str_f2c(block_name, MAX_BLOCKNAME_LENGTH);
    block_id = rb_intern(block_name);
    if (block_id != pre_block_id) {
      data->blocks =
	REALLOC_N(data->blocks, CWNStoredBlock, data->num_block + 1);
      cur_block = &data->blocks[data->num_block];
      cur_block->id = block_id;
      cur_block->name = ALLOC_N(char, len_blockname + 1);
      strcpy(cur_block->name, block_name);
      cur_block->name_len = len_blockname;
      block_nvar[data->num_block] = 0;
      block_size[data->num_block] = 0;
      data->num_block++;
    }
    block_nvar[data->num_block - 1]++;
    block_size[data->num_block - 1] += elem;
    cern_util_str_f2c(var_name, MAX_VARNAME_LENGTH);
    cwnvar[i - 1].name = rb_intern(var_name);
    cwnvar[i - 1].size = elem;
    switch (type) {
    case 1:
      cwnvar[i - 1].type = 'r';
      break;
    case 2:
      cwnvar[i - 1].type = 'i';
      break;
    default:
      rb_raise(rb_eRuntimeError,
	       "CWNBlock member type %d is not supported yet", type);
    }
    cwnvar[i - 1].ptr = NULL;
    pre_block_id = block_id;
  }

  cwnvar_p = cwnvar;
  for (i = 0; i < data->num_block; i++) {
    data->blocks[i].klass =
      make_cwnblock_class(data->blocks[i].name, block_nvar[i], cwnvar_p);
    data->blocks[i].buf = ALLOC_N(char, sizeof(long) * block_size[i]);
    cwnvar_p += block_nvar[i];
  }

  data->deleted = 0;

  return obj;
}

VALUE
hbook2_make_ntuple_from_data(int id)
{
  float minimum[MAX_NUM_VARIABLES], maximum[MAX_NUM_VARIABLES];
  char title[MAX_TITLE_LENGTH + 1];
  char variables[MAX_NUM_VARIABLES * MAX_VARNAME_LENGTH];
  char block_name[MAX_BLOCKNAME_LENGTH + 1], var_name[MAX_VARNAME_LENGTH + 1];
  int stat, nsub, type, size, elem;
  int cycle = 9999;
  int var = 1;
  int nvar = MAX_NUM_VARIABLES;

  hrin_(&id, &cycle, &stat);
  hgiven_(&id, title, &nvar, variables, minimum, maximum,
	  MAX_TITLE_LENGTH, MAX_VARNAME_LENGTH);
  cern_util_str_f2c(title, MAX_TITLE_LENGTH);

  hntvar_(&id, &var, var_name, block_name, &nsub, &type, &size, &elem,
	  MAX_VARNAME_LENGTH, MAX_BLOCKNAME_LENGTH);
  if (cern_util_str_f2c(block_name, MAX_BLOCKNAME_LENGTH) > 0) {
    return make_cwn_from_data_intern(id, title, nvar);
  } else {
    return make_rwn_from_data_intern(id, title, nvar, variables);
  }
}

VALUE
hbook2_make_rwn_from_data(int id)
{
  float minimum[MAX_NUM_VARIABLES], maximum[MAX_NUM_VARIABLES];
  char title[MAX_TITLE_LENGTH + 1];
  char variables[MAX_NUM_VARIABLES * MAX_VARNAME_LENGTH];
  char *routine = "make_rwn";
  int nvar = MAX_NUM_VARIABLES;

  hgnpar_(&id, routine, strlen(routine));
  hgiven_(&id, title, &nvar, variables, minimum, maximum,
	  MAX_TITLE_LENGTH, MAX_VARNAME_LENGTH);
  cern_util_str_f2c(title, MAX_TITLE_LENGTH);
  return make_rwn_from_data_intern(id, title, nvar, variables);
}

VALUE
hbook2_make_cwn_from_data(int id)
{
  float minimum[MAX_NUM_VARIABLES], maximum[MAX_NUM_VARIABLES];
  char title[MAX_TITLE_LENGTH + 1];
  char variables[MAX_NUM_VARIABLES * MAX_VARNAME_LENGTH];
  int stat;
  int cycle = 9999;
  int nvar = MAX_NUM_VARIABLES;

  hrin_(&id, &cycle, &stat);
  hgiven_(&id, title, &nvar, variables, minimum, maximum,
	  MAX_TITLE_LENGTH, MAX_VARNAME_LENGTH);
  cern_util_str_f2c(title, MAX_TITLE_LENGTH);
  return make_cwn_from_data_intern(id, title, nvar);
}


/*** functions for N-tuple class ***/

static VALUE
ntuple_deleted_p(VALUE obj)
{
  NtupleData *data;

  Data_Get_Struct(obj, NtupleData, data);
  return data->deleted ? Qtrue : Qfalse;
}

static VALUE
ntuple_delete(VALUE obj)
{
  NtupleData *data = hbook2_get_ntuple_data(obj);

  hdelet_(&data->id);
  data->deleted = 1;
  return Qnil;
}

static VALUE
ntuple_inspect(VALUE obj)
{
  NtupleData *data = hbook2_get_ntuple_data(obj);
  char *klass = rb_class2name(CLASS_OF(obj));
  char *str = ALLOCA_N(char, strlen(klass) + strlen(data->title)
		              + ((int) log10(data->id)) + 10);

  sprintf(str, "#<%s:%d,\"%s\">",
	  klass, data->id, data->title);
  return rb_str_new2(str);
}

static VALUE
ntuple_reset(int argc, VALUE *argv, VALUE obj)
{
  VALUE title;
  NtupleData *data = hbook2_get_ntuple_data(obj);
  char *ptitle = " ";

  if (rb_scan_args(argc, argv, "01", &title) == 1)
    ptitle = STR2CSTR(title);
  hreset_(&data->id, ptitle, strlen(ptitle));
  return Qnil;
}

static VALUE
ntuple_get_id(VALUE obj)
{
  return INT2FIX(hbook2_get_ntuple_data(obj)->id);
}

static VALUE
ntuple_set_id(VALUE obj, VALUE id)
{
  NtupleData *data = hbook2_get_ntuple_data(obj);
  int new_id = NUM2INT(id);

#if 0  /* bug of HRENID ?? */
  hrenid_(&data->id, &new_id);
  data->id = new_id;
#endif
  return INT2FIX(data->id);
}

static VALUE
ntuple_title(VALUE obj)
{
  return rb_str_new2(hbook2_get_ntuple_data(obj)->title);
}

static VALUE
ntuple_entry(VALUE obj)
{
  return INT2NUM(get_num_entry(hbook2_get_ntuple_data(obj)));
}


/*** functions for Row-Wise Ntuple ***/

static VALUE
rwn_s_allocate(VALUE klass)
{
  RWNData *data;
  return Data_Make_Struct(klass, RWNData, 0, free_rwn, data);
}

#ifdef HAVE_OBJECT_ALLOCATE
#define rwn_s_new rb_class_new_instance
#else
static VALUE
rwn_s_new(int argc, VALUE *argv, VALUE klass)
{
  VALUE obj = rwn_s_allocate(klass);
  rb_obj_call_init(obj, argc, argv);
  return obj;
}
#endif

static VALUE
rwn_initialize(int argc, VALUE *argv, VALUE obj)
{
  RWNData *data = hbook2_get_rwn(obj);
  int i, j;
  int memory;
  char *dirname, *variables, *var_ptr;
  VALUE id, title, dir, max, members, klass_dir;

  rb_scan_args(argc, argv, "4*", &id, &title, &dir, &max, &members);
  
  memory = NUM2INT(max);

  data->id = NUM2INT(id);
  Check_Type(title, T_STRING);
  data->title = ALLOC_N(char, RSTRING(title)->len + 1);
  strcpy(data->title, STR2CSTR(title));
  Check_Type(members, T_ARRAY);
  data->nvar = RARRAY(members)->len;
  data->variable = ALLOC_N(char*, RARRAY(members)->len);
  data->deleted = 0;

  variables = ALLOC_N(char, data->nvar * MAX_VARNAME_LENGTH + 1);
  var_ptr = variables;
  for (i = 0; i < data->nvar; i++) {
    char *ptr = STR2CSTR(RARRAY(members)->ptr[i]);
    data->variable[i] = ALLOC_N(char, RSTRING(RARRAY(members)->ptr[i])->len + 1);
    strcpy(data->variable[i], ptr);
    for (j = 0; j < MAX_VARNAME_LENGTH && *ptr; j++)
      *var_ptr++ = *ptr++;
    for (; j < MAX_VARNAME_LENGTH; j++)
      *var_ptr++ = ' ';
  }
  variables[data->nvar * MAX_VARNAME_LENGTH] = '\0';

  klass_dir = CLASS_OF(dir);
  if (klass_dir == cRZDir || klass_dir == cRZFile) {
    dirname = hbook2_get_rz_dir(dir)->name;
  } else {
    dirname = STR2CSTR(dir);
  }

  hbookn_(&data->id, data->title, &data->nvar, dirname, &memory, variables,
	  RSTRING(title)->len, strlen(dirname), MAX_VARNAME_LENGTH);

  return obj;
}

static VALUE
rwn_members(VALUE obj)
{
  int i;
  RWNData *data = hbook2_get_rwn(obj);
  VALUE ary = rb_ary_new2(data->nvar);

  for (i = 0; i < data->nvar; i++)
    rb_ary_store(ary, i, rb_str_new2(data->variable[i]));
  return ary;
}

static VALUE
rwn_min(VALUE obj, VALUE var)
{
  char title[MAX_TITLE_LENGTH];
  RWNData *data = hbook2_get_rwn(obj);
  int index = get_member_index(data, STR2CSTR(var));
  float *minimum = ALLOCA_N(float, data->nvar);
  float *maximum = ALLOCA_N(float, data->nvar);
  char *variables = ALLOCA_N(char, data->nvar * MAX_VARNAME_LENGTH);

  hgiven_(&data->id, title, &data->nvar, variables, minimum, maximum,
	  MAX_TITLE_LENGTH, MAX_VARNAME_LENGTH);
  return rb_float_new(minimum[index]);
}

static VALUE
rwn_max(VALUE obj, VALUE var)
{
  char title[MAX_TITLE_LENGTH];
  RWNData *data = hbook2_get_rwn(obj);
  int index = get_member_index(data, STR2CSTR(var));
  float *minimum = ALLOCA_N(float, data->nvar);
  float *maximum = ALLOCA_N(float, data->nvar);
  char *variables = ALLOCA_N(char, data->nvar * MAX_VARNAME_LENGTH);

  hgiven_(&data->id, title, &data->nvar, variables, minimum, maximum,
	  MAX_TITLE_LENGTH, MAX_VARNAME_LENGTH);
  return rb_float_new(maximum[index]);
}

static VALUE
rwn_copy(int argc, VALUE *argv, VALUE obj)
{
  int i;
  RWNData *src = hbook2_get_rwn(obj), *dest;
  int len_title;
  int buffer = -1;
  char *option = " ";
  char *ptitle;
  VALUE id, title;
  VALUE new_obj = Data_Make_Struct(RBASIC(obj)->klass, RWNData, 0,
				   free_rwn, dest);

  if (rb_scan_args(argc, argv, "11", &id, &title) == 1)
    ptitle = dest->title;
  else
    ptitle = STR2CSTR(title);

  dest->id = NUM2INT(id);
  dest->nvar = src->nvar;
  len_title = strlen(ptitle);
  dest->title = ALLOC_N(char, len_title + 1);
  strcpy(dest->title, ptitle);
  for (i = 0; i < dest->nvar; i++) {
    dest->variable[i] = ALLOC_N(char, strlen(src->variable[i]) + 1);
    strcpy(dest->variable[i], src->variable[i]);
  }
  dest->deleted = 0;

  hntdup_(&src->id, &dest->id, buffer, dest->title, option, len_title, 1);

  return new_obj;
}

static VALUE
rwn_fill(VALUE obj, VALUE hash)
{
  int i;
  RWNData *data = hbook2_get_rwn(obj);
  float *variables = ALLOCA_N(float, data->nvar);
  VALUE var;

  for (i = 0; i < data->nvar; i++) {
    var = rb_hash_aref(hash, rb_str_new2(data->variable[i]));
    if (NIL_P(var))
      rb_raise(rb_eRuntimeError, "value of %s is not set", data->variable[i]);
    variables[i] = (float) NUM2DBL(var);
  }
  hfn_(&data->id, variables);
  return obj;
}

static VALUE
rwn_get_event(VALUE obj, VALUE event)
{
  int i;
  int error;
  RWNData *data = hbook2_get_rwn(obj);
  char *routine = "get_event";
  int num_event = NUM2INT(event);
  float *values = ALLOCA_N(float, data->nvar);
  VALUE hash = rb_hash_new();

  hgnpar_(&data->id, routine, strlen(routine));
  hgnf_(&data->id, &num_event, values, &error);
  for (i = 0; i < data->nvar; i++)
    rb_hash_aset(hash, rb_str_new2(data->variable[i]), rb_float_new(values[i]));
  return hash;
}

static VALUE
rwn_each(VALUE obj)
{
  int i;
  int error;
  int event, num_event;
  RWNData *data = hbook2_get_rwn(obj);
  char *routine = "each";
  float *values = ALLOCA_N(float, data->nvar);
  VALUE hash = rb_hash_new();
  VALUE *variables = ALLOCA_N(VALUE, data->nvar);

  for (i = 0; i < data->nvar; i++)
    variables[i] = rb_str_new2(data->variable[i]);
  hnoent_(&data->id, &num_event);
  hgnpar_(&data->id, routine, strlen(routine));
  for (event = 1; event <= num_event; event++) {
    hgnf_(&data->id, &event, values, &error);
    for (i = 0; i < data->nvar; i++)
      rb_hash_aset(hash, variables[i], rb_float_new(values[i]));
    rb_yield(hash);
  }
  return obj;
}

static VALUE
rwn_projection(VALUE obj, VALUE hist)
{
  int i;
  RWNData *data = hbook2_get_rwn(obj);
  HistData *hist_data = hbook2_get_hist_data(hist);
  char *routine = "projection";
  int event, num_event;
  float *values = ALLOCA_N(float, data->nvar);
  VALUE *variables = ALLOCA_N(VALUE, data->nvar);
  VALUE hash = rb_hash_new();
  VALUE result;
  float x, y;
  int error;
  float weight = 1;

  for (i = 0; i < data->nvar; i++)
    variables[i] = rb_str_new2(data->variable[i]);
  hnoent_(&data->id, &num_event);
  hgnpar_(&data->id, routine, strlen(routine));
  for (event = 1; event <= num_event; event++) {
    hgnf_(&data->id, &event, values, &error);
    for (i = 0; i < data->nvar; i++)
      rb_hash_aset(hash, variables[i], rb_float_new(values[i]));
    result = rb_yield(hash);
    if (! NIL_P(result)) {
      if (CLASS_OF(result) == rb_cArray) {
	x = (float) NUM2DBL(RARRAY(result)->ptr[0]);
	y = (float) NUM2DBL(RARRAY(result)->ptr[1]);
      } else {
	x = (float) NUM2DBL(result);
	y = 0;
      }
      hfill_(&hist_data->id, &x, &y, &weight);
    }
  }
  return obj;
}

static int current_nt_nvar = 0;
static VALUE *current_nt_variables = NULL;

static float
nt_fill_hist_weight_function(float *x, int *isel)
{
  int i;
  VALUE result;
#if 1
  VALUE hash = rb_hash_new();
  for (i = 0; i < current_nt_nvar; i++)
    rb_hash_aset(hash, current_nt_variables[i], rb_float_new(x[i]));
  result = rb_yield(hash);
#else
  VALUE ary = rb_ary_new2(current_nt_nvar);
  for (i = 0; i < current_nt_nvar; i++)
    rb_ary_store(ary, i, rb_float_new(x[i]));
  result = rb_yield(ary);
#endif
  switch (result) {
  case Qnil:
    *isel = 0;
    return 1;
  case Qfalse:
    return 0;
  case Qtrue:
    return 1;
  default:
    return NUM2DBL(result);
  }
}

static VALUE
rwn_fill_hist1(int argc, VALUE *argv, VALUE obj)
{
  int i, n;
  VALUE var, hist, from, to;
  RWNData *data = hbook2_get_rwn(obj);
  HistData *hist_data;
  int index, flag, event_from, event_to;
  float (*function)(float*, int*) = NULL;

  n = rb_scan_args(argc, argv, "22", &var, &hist, &from, &to);
  if (n > 2)
    event_from = NUM2INT(from);
  else
    event_from = 1;
  if (n > 3)
    event_to = NUM2INT(to);
  else
    event_to = get_num_entry((NtupleData*) data);

  hist_data = hbook2_get_hist_data(hist);
  index = get_member_index(data, STR2CSTR(var)) + 1;
                       /* in HBOOK, index is from 1 */
  if (rb_block_given_p()) {
    function = nt_fill_hist_weight_function;
    flag = 1;
    current_nt_nvar = data->nvar;
    current_nt_variables = ALLOCA_N(VALUE, data->nvar);
    for (i = 0; i < data->nvar; i++)
      current_nt_variables[i] = rb_str_new2(data->variable[i]);
  } else {
    function = NULL;
    flag = 0;
  }
  hproj1_(&hist_data->id, &data->id, &flag, function,
	  &event_from, &event_to, &index);
  current_nt_nvar = 0;
  current_nt_variables = NULL;
  
  return Qnil;
}

#if 0  /* old to_hist1 */
static VALUE
ntuple_to_hist1(int argc, VALUE *argv, VALUE obj)
{
  int n;
  VALUE var, id, from, to, new_hist;
  RWNData *data = hbook2_get_rwn(obj);
  int hid, index, flag, event_from, event_to;
  float *minimum, *maximum, min, max;
  char *variables;
  char title[31];
  float (*function)(float*, int*) = NULL;

  n = rb_scan_args(argc, argv, "22", &var, &id, &from, &to);
  if (n > 2)
    event_from = NUM2INT(from);
  else
    event_from = 1;
  if (n > 3)
    event_to = NUM2INT(to);
  else
    event_to = get_num_entry((NtupleData*) data);

  hid = NUM2INT(id);
  index = get_member_index(data, STR2CSTR(var));
  minimum = ALLOCA_N(float, data->nvar);
  maximum = ALLOCA_N(float, data->nvar);
  variables = ALLOCA_N(char, data->nvar * MAX_VARNAME_LENGTH);
  hgiven_(&data->id, title, &data->nvar, variables, minimum, maximum,
	  30, MAX_VARNAME_LENGTH);
  if (maximum[index] == minimum[index]) {
    min = minimum[index] - 10;
    max = minimum[index] + 10;
  } else {
    double tmp = log10(maximum[index] - minimum[index]);
    int power = tmp > 0 ? (int) tmp : (int) (tmp - 1);
    double order = pow(10, power);
    min = floor (minimum[index] / order) * order;
    max = floor (maximum[index] / order + 1) * order;
  }
  new_hist = hbook2_make_histogram(cHist1, hid, STR2CSTR(var),
				   100, min, max, 0, 0, 0, NULL);

  if (rb_block_given_p()) {
    function = nt_fill_hist_weight_function;
    flag = 1;
    current_nt_nvar = data->nvar;
  } else {
    function = NULL;
    flag = 0;
  }
  index++;  /* in HBOOK, index is from 1 */
  hproj1_(&hid, &data->id, &flag, function,
	  &event_from, &event_to, &index);
  current_nt_nvar = 0;

  return new_hist;
}
#endif

static VALUE
rwn_fill_hist2(int argc, VALUE *argv, VALUE obj)
{
  int i, n;
  VALUE xvar, yvar, hist, from, to;
  RWNData *data = hbook2_get_rwn(obj);
  HistData *hist_data;
  int index_x, index_y, flag, event_from, event_to;
  float (*function)(float*, int*) = NULL;

  n = rb_scan_args(argc, argv, "32", &xvar, &yvar, &hist, &from, &to);
  if (n > 3)
    event_from = NUM2INT(from);
  else
    event_from = 1;
  if (n > 4)
    event_to = NUM2INT(to);
  else
    event_to = get_num_entry((NtupleData*) data);

  hist_data = hbook2_get_hist_data(hist);
  index_x = get_member_index(data, STR2CSTR(xvar));
  index_y = get_member_index(data, STR2CSTR(yvar));
  index_x++;  /* in HBOOK, index is from 1 */
  index_y++;

  if (rb_block_given_p()) {
    function = nt_fill_hist_weight_function;
    flag = 1;
    current_nt_nvar = data->nvar;
    current_nt_variables = ALLOCA_N(VALUE, data->nvar);
    for (i = 0; i < data->nvar; i++)
      current_nt_variables[i] = rb_str_new2(data->variable[i]);
  } else {
    function = NULL;
    flag = 0;
  }
  hproj2_(&hist_data->id, &data->id, &flag, function,
	  &event_from, &event_to, &index_x, &index_y);
  current_nt_nvar = 0;
  current_nt_variables = NULL;
  
  return Qnil;
}


/*** functions for Column-Wise Ntuple ***/

static VALUE
cwn_s_allocate(VALUE klass)
{
  CWNData *data;
  return Data_Make_Struct(klass, CWNData, mark_cwn, free_cwn, data);
}

#ifdef HAVE_OBJECT_ALLOCATE
#define cwn_s_new rb_class_new_instance
#else
static VALUE
cwn_s_new(int argc, VALUE *argv, VALUE klass)
{
  VALUE obj = cwn_s_allocate(klass);
  rb_obj_call_init(obj, argc, argv);
  return obj;
}
#endif

static VALUE
cwn_initialize(VALUE obj, VALUE id, VALUE title, VALUE dir)
{
  CWNData *data = hbook2_get_cwn(obj);
  VALUE klass;
  char *opt = " ";
  char *cur_dir;

  data->id = NUM2INT(id);
  Check_Type(title, T_STRING);
  data->title = ALLOC_N(char, RSTRING(title)->len + 1);
  strcpy(data->title, STR2CSTR(title));
  data->num_block = 0;
  data->blocks = NULL;
  data->deleted = 0;

  cur_dir = hbook2_current_dir_name();
  klass = CLASS_OF(dir);
  if (klass == rb_cString) {
    hcdir_(STR2CSTR(dir), opt, RSTRING(dir)->len, 1);
  } else if (klass == cRZDir || klass == cRZFile) {
    RZDir *rzdir = hbook2_get_rz_dir(dir);
    hcdir_(rzdir->name, opt, strlen(rzdir->name), 1);
  }
  hbnt_(&data->id, data->title, opt, RSTRING(title)->len, 1);
  hcdir_(cur_dir, opt, strlen(cur_dir), 1);
  free(cur_dir);

  return obj;
}

static int
parse_definition(char *def, ID *name, int *size, int *type)
{
  char *cname, *csize, *ctype;

  if (index(def, '(')) {
    cname = strtok(def, "(");
    csize = strtok(NULL, "):");
    ctype = strtok(NULL, ":");
    if (csize && ctype) {
      *name = rb_intern(cname);
      *size = atoi(csize);
      *type = ctype[0];
      return 0;
    } else {
      return 1;
    }
  } else {
    cname = strtok(def, ":");
    ctype = strtok(NULL, ":");
    if (ctype) {
      *name = rb_intern(cname);
      *type = ctype[0];
      *size = 1;
      return 0;
    } else {
      return 1;
    }
  }
}

static VALUE
cwn_set_block(VALUE obj, VALUE cwnblock)
{
  VALUE template = rb_iv_get(cwnblock, "__template__");
  CWNBlock *block = hbook2_get_cwnblock(template);
  CWNData *data = hbook2_get_cwn(obj);
  int length = 0;
  char *name, *variables, *var_ptr;
  CWNStoredBlock *cur_block;
  int i, n;

  data->blocks = REALLOC_N(data->blocks, CWNStoredBlock, data->num_block + 1);
  cur_block = &data->blocks[data->num_block];
  name = rb_id2name(block->name);
  cur_block->klass = cwnblock;
  cur_block->name_len = strlen(name);
  cur_block->name = ALLOC_N(char, cur_block->name_len + 1);
  strcpy(cur_block->name, name);
  cur_block->id = rb_intern(cur_block->name);
  cur_block->buf = ALLOC_N(char, sizeof(long) * block->size);

  for (i = 0; i < block->nvar; i++) {
    if (block->var[i].size > 1)
      length +=
	strlen(rb_id2name(block->var[i].name)) + log10(block->var[i].size) + 6;
    else
      length +=	strlen(rb_id2name(block->var[i].name)) + 3;
  }
  var_ptr = variables = ALLOCA_N(char, length);
  for (i = 0; i < block->nvar; i++) {
    if (block->var[i].size > 1)
      n = sprintf(var_ptr, "%s(%d):%c,",
		  rb_id2name(block->var[i].name), block->var[i].size,
		  block->var[i].type);
    else
      n = sprintf(var_ptr, "%s:%c,",
		  rb_id2name(block->var[i].name), block->var[i].type);
    var_ptr += n;
  }
  *(var_ptr - 1) = '\0';  /* last ',' is overwritten */

  hbname_(&data->id, name, cur_block->buf, variables,
	  cur_block->name_len, strlen(variables));

  data->num_block++;
  data->nvar += block->nvar;

  return obj;
}

static VALUE
cwn_blocks(VALUE obj)
{
  int i;
  CWNData *data = hbook2_get_cwn(obj);
  VALUE ary = rb_ary_new2(data->num_block);
  for (i = 0; i < data->num_block; i++)
    rb_ary_store(ary, i, data->blocks[i].klass);
  return ary;
}

static VALUE
cwn_fill(VALUE obj, VALUE val)
{
  int i;
  CWNData *data = hbook2_get_cwn(obj);
  CWNBlock *block = hbook2_get_cwnblock(val);

  for (i = 0; i < data->num_block; i++) {
    if (data->blocks[i].id == block->name) {
      memcpy(data->blocks[i].buf, block->buf, sizeof(long) * block->size);
      hfntb_(&data->id, data->blocks[i].name, data->blocks[i].name_len);
      return obj;
    }
  }
  rb_raise(rb_eArgError, "Block %s is not set", rb_id2name(block->name));
}

static VALUE
cwn_fill_all(VALUE obj, VALUE val)
{
  int i;
  VALUE template;
  CWNData *data = hbook2_get_cwn(obj);
  CWNBlock *block;

  for (i = 0; i < data->num_block; i++) {
    template = rb_iv_get(data->blocks[i].klass, "__template__");
    block = hbook2_get_cwnblock(template);
    memcpy(data->blocks[i].buf, block->buf, sizeof(long) * block->size);
  }
  hfnt_(&data->id);
  return obj;
}

static VALUE
cwn_get_event_block(VALUE obj, VALUE event, VALUE klass)
{
  int i;
  int error;
  CWNData *data = hbook2_get_cwn(obj);
  int num_event = NUM2INT(event);
  VALUE template = rb_iv_get(klass, "__template__");
  CWNBlock *template_block = hbook2_get_cwnblock(template);
  CWNBlock *block;
  VALUE blockobj;

  hbname_(&data->id, " ", NULL, "$CLEAR", 1, 6);
  for (i = 0; i < data->num_block; i++) {
    if (data->blocks[i].id == template_block->name) {
      hbname_(&data->id, data->blocks[i].name, data->blocks[i].buf,
	      "$SET", data->blocks[i].name_len, 4);
      hgnt_(&data->id, &num_event, &error);
      blockobj = make_cwnblock_instance(klass, &block);
      memcpy(block->buf, data->blocks[i].buf, sizeof(long) * block->size);
      return blockobj;
    }
  }
  rb_raise(rb_eArgError, "Block %s is not set", rb_id2name(block->name));
}

static VALUE
cwn_get_event_all(VALUE obj, VALUE event)
{
  int i;
  int error;
  CWNData *data = hbook2_get_cwn(obj);
  int num_event = NUM2INT(event);
  CWNBlock **block = ALLOCA_N(CWNBlock*, data->num_block);
  VALUE blockobj;
  VALUE ary = rb_ary_new2(data->num_block);

  hbname_(&data->id, " ", NULL, "$CLEAR", 1, 6);
  for (i = 0; i < data->num_block; i++) {
    hbname_(&data->id, data->blocks[i].name, data->blocks[i].buf,
	    "$SET", data->blocks[i].name_len, 4);
    blockobj = make_cwnblock_instance(data->blocks[i].klass, &block[i]);
    rb_ary_store(ary, i, blockobj);
  }
  hgnt_(&data->id, &num_event, &error);
  for (i = 0; i < data->num_block; i++)
    memcpy(block[i]->buf, data->blocks[i].buf, sizeof(long) * block[i]->size);
  return ary;
}

static VALUE
cwn_get_event(int argc, VALUE *argv, VALUE obj)
{
  VALUE klass, event;

  if (rb_scan_args(argc, argv, "11", &event, &klass) == 1)
    return cwn_get_event_all(obj, event);
  else
    return cwn_get_event_block(obj, event, klass);
}

static VALUE
cwn_each(VALUE obj)
{
  int i;
  int error;
  int event, num_event;
  CWNData *data = hbook2_get_cwn(obj);
  CWNBlock **block = ALLOCA_N(CWNBlock*, data->num_block);
  VALUE blockobj;
  VALUE ary = rb_ary_new2(data->num_block);

  hnoent_(&data->id, &num_event);
  hbname_(&data->id, " ", NULL, "$CLEAR", 1, 6);
  for (i = 0; i < data->num_block; i++) {
    hbname_(&data->id, data->blocks[i].name, data->blocks[i].buf,
	    "$SET", data->blocks[i].name_len, 4);
    blockobj = make_cwnblock_instance(data->blocks[i].klass, &block[i]);
    rb_ary_store(ary, i, blockobj);
  }
  for (event = 1; event <= num_event; event++) {
    hgnt_(&data->id, &event, &error);
    for (i = 0; i < data->num_block; i++) {
      memcpy(block[i]->buf, data->blocks[i].buf, sizeof(long) * block[i]->size);
    }
    rb_yield(ary);
  }
  return obj;
}


static VALUE
cwnvar2value(CWNVar *var)
{
  switch (var->type) {
  case CWNVAR_INTEGER:
    return INT2NUM(*((int*) var->ptr));
  case CWNVAR_REAL:
    return rb_float_new(*((float*) var->ptr));
  default:
    return Qnil;
  }
}

static VALUE
cwnvar_set(CWNVar *var, VALUE val)
{
  switch (var->type) {
  case CWNVAR_INTEGER:
    *((int*)var->ptr) = NUM2INT(val);
    break;
  case CWNVAR_REAL:
    *((float*)var->ptr) = NUM2DBL(val);
    break;
  default:
  }
  return val;
}

static VALUE
cwnblock_s_new(int argc, VALUE *argv, VALUE klass)
{
  int i;
  CWNBlock *block;
  VALUE obj = make_cwnblock_instance(klass, &block);

  for (i = 0; i < argc; i++)
    cwnvar_set(&block->var[i], argv[i]);
  return obj;
}

static VALUE
cwnblock_s_members(VALUE klass)
{
  int i;
  VALUE template = rb_iv_get(klass, "__template__");
  CWNBlock *block = hbook2_get_cwnblock(template);
  VALUE ary = rb_ary_new2(block->nvar);

  for (i = 0; i < block->nvar; i++)
    rb_ary_store(ary, i, rb_str_new2(rb_id2name(block->var[i].name)));

  return ary;
}

static VALUE
cwnblock_ref(VALUE obj)
{
  int i;
  ID id = rb_frame_last_func();
  CWNBlock *block = hbook2_get_cwnblock(obj);

  for (i = 0; i < block->nvar; i++) {
    if (block->var[i].name == id)
      return cwnvar2value(&block->var[i]);
  }
  rb_raise(rb_eNameError, "%s is not block member", rb_id2name(id));
  return Qnil;  /* not reached */
}

static VALUE
cwnblock_set(VALUE obj, VALUE val)
{
  int i;
  ID id = rb_frame_last_func();
  CWNBlock *block = hbook2_get_cwnblock(obj);

  for (i = 0; i < block->nvar; i++) {
    if (rb_id_attrset(block->var[i].name) == id)
      return cwnvar_set(&block->var[i], val);
  }
  rb_raise(rb_eNameError, "not block member");
  return Qnil;  /* not reached */
}

static VALUE
cwnblock_s_ref(VALUE klass)
{
  return cwnblock_ref(rb_iv_get(klass, "__template__"));
}

static VALUE
cwnblock_s_set(VALUE klass, VALUE val)
{
  return cwnblock_set(rb_iv_get(klass, "__template__"), val);
}

static VALUE
cwnblock_s_def_class(int argc, VALUE *argv, VALUE klass)
{
  VALUE blockname, members;
  CWNVar *var;
  char *ptr;
  int i;

  rb_scan_args(argc, argv, "1*", &blockname, &members);

  var = ALLOCA_N(CWNVar, RARRAY(members)->len);

  for (i = 0; i < RARRAY(members)->len; i++) {
    ptr = ALLOCA_N(char, RSTRING(RARRAY(members)->ptr[i])->len + 1);
    strcpy(ptr, STR2CSTR(RARRAY(members)->ptr[i]));
    if (parse_definition(ptr, &var[i].name, &var[i].size, &var[i].type) == 1)
      rb_raise(rb_eRuntimeError, "Invalid variable definition: '%s'", ptr);
    if (var[i].type != CWNVAR_INTEGER && var[i].type != CWNVAR_REAL)
      rb_raise(rb_eRuntimeError, "No such a variable type: '%c'", var[i].type);
    var[i].ptr = NULL;
  }

  return make_cwnblock_class(STR2CSTR(blockname), RARRAY(members)->len, var);
}

static VALUE
cwnblock_inspect(VALUE obj)
{
  int i;
  CWNBlock *block = hbook2_get_cwnblock(obj);
  VALUE str = rb_str_new2("#<");

  rb_str_cat2(str, rb_class2name(CLASS_OF(obj)));
  rb_str_cat2(str, ": ");
  for (i = 0; i < block->nvar; i++) {
    if (i > 0) {
      rb_str_cat2(str, ", ");
    }
    rb_str_cat2(str, rb_id2name(block->var[i].name));
    rb_str_cat2(str, "=");
    rb_str_append(str, rb_inspect(cwnvar2value(&block->var[i])));
  }
  rb_str_cat2(str, ">");
  return str;
}

static VALUE
cwnblock_each(VALUE obj)
{
  int i;
  CWNBlock *block = hbook2_get_cwnblock(obj);

  for (i = 0; i < block->nvar; i++)
    rb_yield(cwnvar2value(&block->var[i]));
  return obj;
}

static VALUE
cwnblock_to_a(VALUE obj)
{
  int i;
  CWNBlock *block = hbook2_get_cwnblock(obj);
  VALUE ary = rb_ary_new2(block->nvar);

  for (i = 0; i < block->nvar; i++)
    rb_ary_store(ary, i, cwnvar2value(&block->var[i]));
  return ary;
}

static VALUE
cwnblock_size(VALUE obj)
{
  return INT2FIX(hbook2_get_cwnblock(obj)->nvar);
}

static VALUE
cwnblock_equal(VALUE obj, VALUE obj2)
{
  int i;
  CWNBlock *block = hbook2_get_cwnblock(obj);
  CWNBlock *block2 = hbook2_get_cwnblock(obj2);

  if (obj == obj2)
    return Qtrue;
  if (CLASS_OF(obj) != CLASS_OF(obj2))
    return Qfalse;
  if (block->nvar != block2->nvar) {
    rb_bug("inconsistent CWNBlock"); /* should never happen */
  }

  for (i = 0; i < block->nvar; i++) {
    if (! rb_equal(cwnvar2value(&block->var[i]), cwnvar2value(&block2->var[i])))
      return Qfalse;
  }
  return Qtrue;
}

static VALUE
cwnblock_members(VALUE obj)
{
  return cwnblock_s_members(CLASS_OF(obj));
}


void
Init_hbook2_ntuple()
{
  cNtuple = rb_define_class_under(mHBook2, "Ntuple", rb_cData);

  rb_include_module(cNtuple, rb_mEnumerable);

  rb_define_method(cNtuple, "delete", ntuple_delete, 0);
  rb_define_method(cNtuple, "deleted?", ntuple_deleted_p, 0);
  rb_define_method(cNtuple, "inspect", ntuple_inspect, 0);
  rb_define_method(cNtuple, "reset", ntuple_reset, -1);
  rb_define_method(cNtuple, "ntuple_id", ntuple_get_id, 0);
#if 0
  rb_define_method(cNtuple, "ntuple_id=", ntuple_set_id, 1);
#endif
  rb_define_method(cNtuple, "title", ntuple_title, 0);
  rb_define_method(cNtuple, "entry", ntuple_entry, 0);
  rb_define_method(cNtuple, "size", ntuple_entry, 0);
  rb_define_method(cNtuple, "length", ntuple_entry, 0);
#if 0
  rb_define_method(cNtuple, "+", ntuple_add, 1);
#endif


  cRWNtuple = rb_define_class_under(mHBook2, "RWNtuple", cNtuple);

#ifdef HAVE_OBJECT_ALLOCATE
  rb_define_alloc_func(cRWNtuple, rwn_s_allocate);
#else
  rb_define_singleton_method(cRWNtuple, "new", rwn_s_new, -1);
#endif

#if 0
  rb_define_singleton_method(cRWNtuple, "read", rwn_s_read, 3);
#endif
  rb_define_method(cRWNtuple, "initialize", rwn_initialize, -1);
  rb_define_method(cRWNtuple, "members", rwn_members, 0);
  rb_define_method(cRWNtuple, "min", rwn_min, 1);
  rb_define_method(cRWNtuple, "max", rwn_max, 1);
  rb_define_method(cRWNtuple, "copy", rwn_copy, -1);
  rb_define_method(cRWNtuple, "get_event", rwn_get_event, 1);
  rb_define_method(cRWNtuple, "[]", rwn_get_event, 1);
  rb_define_method(cRWNtuple, "fill", rwn_fill, 1);
  rb_define_method(cRWNtuple, "<<", rwn_fill, 1);
  rb_define_method(cRWNtuple, "each", rwn_each, 0);
  rb_define_method(cRWNtuple, "fill_hist1", rwn_fill_hist1, -1);
  rb_define_method(cRWNtuple, "fill_hist2", rwn_fill_hist2, -1);
  rb_define_method(cRWNtuple, "projection", rwn_projection, 1);


  cCWNtuple = rb_define_class_under(mHBook2, "CWNtuple", cNtuple);

#ifdef HAVE_OBJECT_ALLOCATE
  rb_define_alloc_func(cCWNtuple, cwn_s_allocate);
#else
  rb_define_singleton_method(cCWNtuple, "new", cwn_s_new, -1);
#endif

  rb_define_method(cCWNtuple, "initialize", cwn_initialize, 3);
  rb_define_method(cCWNtuple, "set_block", cwn_set_block, 1);
  rb_define_method(cCWNtuple, "blocks", cwn_blocks, 0);
  rb_define_method(cCWNtuple, "fill", cwn_fill, 1);
  rb_define_method(cCWNtuple, "<<", cwn_fill, 1);
  rb_define_method(cCWNtuple, "fill_all", cwn_fill_all, 0);
  rb_define_method(cCWNtuple, "[]", cwn_get_event_all, 1);
  rb_define_method(cCWNtuple, "get_event", cwn_get_event, -1);
  rb_define_method(cCWNtuple, "each", cwn_each, 0);


  cCWNBlock = rb_define_class_under(mHBook2, "CWNBlock", rb_cData);

  rb_include_module(cCWNBlock, rb_mEnumerable);

  rb_define_singleton_method(cCWNBlock, "new", cwnblock_s_def_class, -1);
  rb_define_method(cCWNBlock, "inspect", cwnblock_inspect, 0);
  rb_define_method(cCWNBlock, "==", cwnblock_equal, 1);
  rb_define_method(cCWNBlock, "size", cwnblock_size, 0);
  rb_define_method(cCWNBlock, "length", cwnblock_size, 0);
  rb_define_method(cCWNBlock, "to_a", cwnblock_to_a, 0);
  rb_define_method(cCWNBlock, "values", cwnblock_to_a, 0);
  rb_define_method(cCWNBlock, "each", cwnblock_each, 0);
  rb_define_method(cCWNBlock, "members", cwnblock_members, 0);
}
