/*
 *  hist.c  - Histogram classes under HBook2 module
 *    This program is a part of Ruby/CERNLIB package
 *  (c) 1999 - 2003  TAKAHASHI Hitoshi <hitoshi.takahashi@kek.jp>
 */

#include <ruby.h>
#include <math.h>
#include <ctype.h>
#include "hbook2.h"

static VALUE hist_operate(VALUE klass, HistData *src1, HistData *src2,
			  char *operater, float const1, float const2);

extern struct {
  double par[24];
  double fit_fun;
} hcfitd_;

static void
free_hist(HistData *data)
{
  if (! data->deleted && hexist_(&data->id))
    hdelet_(&data->id);
  if (data->title)
    free(data->title);
  free(data);
}

HistData *
hbook2_get_hist_data(VALUE obj)
{
  HistData *data;

  Data_Get_Struct(obj, HistData, data);
  if (data->deleted)
    rb_raise(rb_eRuntimeError, "Hist ID#%d was deleted!\n", data->title);
  return data;
}

static void
init_histogram(HistData *data, VALUE klass, int id, char *title,
	       int xbin, float xmin, float xmax,
	       int ybin, float ymin, float ymax, char *option)
{
  int len_title = strlen(title);

#if 0
  if (hexist_(&id))
    rb_raise(rb_eRuntimeError, "histogram#%d already exists", id);
#endif

  data->id = id;
  data->xbin = xbin;
  data->xmin = xmin;
  data->xmax = xmax;
  data->ybin = ybin;
  data->ymin = ymin;
  data->ymax = ymax;
  data->title = ALLOC_N(char, len_title + 1);
  strcpy(data->title, title);
  data->deleted = 0;

  if (klass == cHist1)
    hbook1_(&data->id, data->title, &data->xbin, &data->xmin, &data->xmax,
	    &zero, len_title);
  else if (klass == cHist2)
    hbook2_(&data->id, data->title, &data->xbin, &data->xmin, &data->xmax,
	    &data->ybin, &data->ymin, &data->ymax, &zero, len_title);
  else if (klass == cProfile)
    hbprof_(&data->id, data->title, &data->xbin, &data->xmin, &data->xmax,
	    &data->ymin, &data->ymax, option, len_title, 1);
  else
    rb_raise(rb_eRuntimeError, "Unknown histogram type");
}

VALUE
hbook2_make_histogram(VALUE klass, int id, char *title,
		      int xbin, float xmin, float xmax,
		      int ybin, float ymin, float ymax, char *option)
{
  HistData *data;
  VALUE obj = Data_Make_Struct(klass, HistData, 0, free_hist, data);
  init_histogram(data, klass, id, title, xbin, xmin, xmax,
		 ybin, ymin, ymax, option);
  return obj;
}

VALUE
hbook2_make_histogram_from_data(VALUE klass, int hid)
{
  int i, nwt, loc;
  HistData *data;
  char title[MAX_TITLE_LENGTH + 1];
  VALUE obj = Data_Make_Struct(klass, HistData, 0, free_hist, data);

  data->id = hid;
  hgive_(&data->id, title, &data->xbin, &data->xmin, &data->xmax,
	 &data->ybin, &data->ymin, &data->ymax, &nwt, &loc, MAX_TITLE_LENGTH);
  for (i = MAX_TITLE_LENGTH - 1; title[i] == ' ' && i >= 0; i--);
  title[i + 1] = '\0';
  data->title = ALLOC_N(char, i + 2);
  strcpy(data->title, title);
  data->deleted = 0;

  return obj;
}


/*** functions for BasicHist class ***/

static VALUE
hist_s_allocate(VALUE klass)
{
  HistData *data;
  return Data_Make_Struct(klass, HistData, 0, free_hist, data);
}

#ifdef HAVE_OBJECT_ALLOCATE
#define hist_s_new rb_class_new_instance
#else
static VALUE
hist_s_new(int argc, VALUE *argv, VALUE klass)
{
  VALUE obj = hist_s_allocate(klass);
  rb_obj_call_init(obj, argc, argv);
  return obj;
}
#endif

static VALUE
hist_deleted_p(VALUE obj)
{
  HistData *data;

  Data_Get_Struct(obj, HistData, data);
  return data->deleted ? Qtrue : Qfalse;
}

static VALUE
hist_delete(VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);

  hdelet_(&data->id);
  data->deleted = 1;
  return Qnil;
}

static VALUE
hist_inspect(VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);
  char *klass = rb_class2name(CLASS_OF(obj));
  char *str = ALLOCA_N(char, strlen(klass) + strlen(data->title)
		              + ((int) log10(data->id)) + 10);

  sprintf(str, "#<%s:%d,\"%s\">",
	  klass, data->id, data->title);
  return rb_str_new2(str);
}

static VALUE
hist_reset(int argc, VALUE *argv, VALUE obj)
{
  VALUE title;
  HistData *data = hbook2_get_hist_data(obj);
  char *ptitle = " ";

  if (rb_scan_args(argc, argv, "01", &title) == 1)
    ptitle = STR2CSTR(title);
  hreset_(&data->id, ptitle, strlen(ptitle));
  return Qnil;
}

static VALUE
hist_copy(int argc, VALUE *argv, VALUE obj)
{
  VALUE id, title;
  char *ptitle;
  int len_title;
  HistData *src = hbook2_get_hist_data(obj);
  HistData *dest;
  VALUE return_obj = Data_Make_Struct(RBASIC(obj)->klass, HistData, 0,
				      free_hist, dest);

  if (rb_scan_args(argc, argv, "11", &id, &title) == 2)
    ptitle = STR2CSTR(title);
  else
    ptitle = src->title;
  len_title = strlen(ptitle);
  dest->id = NUM2INT(id);
  dest->xbin = src->xbin;
  dest->xmin = src->xmin;
  dest->xmax = src->xmax;
  dest->ybin = src->ybin;
  dest->ymin = src->ymin;
  dest->ymax = src->ymax;
  dest->title = ALLOC_N(char, len_title + 1);
  strcpy(dest->title, ptitle);
  dest->deleted = 0;

  hcopy_(&src->id, &dest->id, dest->title, len_title);

  return return_obj;
}

static VALUE
hist_get_id(VALUE obj)
{
  return INT2FIX(hbook2_get_hist_data(obj)->id);
}

static VALUE
hist_set_id(VALUE obj, VALUE id)
{
  HistData *data = hbook2_get_hist_data(obj);
  int new_id = NUM2INT(id);

#if 0  /* bug of HRENID ?? */
  hrenid_(&data->id, &new_id);
#else
  hcopy_(&data->id, &new_id, data->title, strlen(data->title));
  hdelet_(&data->id);
#endif
  data->id = new_id;
  return INT2FIX(data->id);
}

static VALUE
hist_title(VALUE obj)
{
  return rb_str_new2(hbook2_get_hist_data(obj)->title);
}

static VALUE
hist_xbin(obj)
     VALUE obj;
{
  return INT2NUM(hbook2_get_hist_data(obj)->xbin);
}

static VALUE
hist_ybin(VALUE obj)
{
  return INT2NUM(hbook2_get_hist_data(obj)->ybin);
}

static VALUE
hist_operate(VALUE klass, HistData *src1, HistData *src2, char *operater,
	     float const1, float const2)
{
  VALUE new_obj;
  char *title;
  int hid = HID_UNTITLED;

  if (src1->xbin != src2->xbin || src1->ybin != src2->ybin)
    rb_raise(rb_eArgError, "number of chunnels is't match");
  if (const2 == 1) {  /* Hist [+*-/] Hist */
    title = ALLOCA_N(char, strlen(src1->title) + strlen(src2->title) + 4);
    sprintf(title, "%s %s %s", src1->title, operater, src2->title);
  } else {  /* Hist * Numeric */
    title = ALLOCA_N(char, strlen(src1->title) + 100);
    sprintf(title, "%s * %g", src1->title, const1);
  }
  new_obj = hbook2_make_histogram(klass, hid, title,
				  src1->xbin, src1->xmin, src1->xmax,
				  src1->ybin, src1->ymin, src1->ymax, NULL);
  hopera_(&src1->id, operater, &src2->id, &hid, &const1, &const2,
	  strlen(operater));

  return new_obj;
}

static VALUE
hist_add(VALUE obj, VALUE other)
{
  return hist_operate(CLASS_OF(obj), hbook2_get_hist_data(obj),
		      hbook2_get_hist_data(other), "+", 1, 1);
}

static VALUE
hist_subtract(VALUE obj, VALUE other)
{
  return hist_operate(CLASS_OF(obj), hbook2_get_hist_data(obj),
		      hbook2_get_hist_data(other), "-", 1, 1);
}

static VALUE
hist_times(VALUE obj, VALUE other)
{
  HistData *src1 = hbook2_get_hist_data(obj);

  if (rb_obj_is_kind_of(other, rb_cNumeric)) {
    return hist_operate(CLASS_OF(obj), src1, src1, "+", NUM2DBL(other), 0);
  } else {
    return hist_operate(CLASS_OF(obj), src1, hbook2_get_hist_data(other),
			"*", 1, 1);
  }
}

static VALUE
hist_devide(VALUE obj, VALUE other)
{
  return hist_operate(CLASS_OF(obj), hbook2_get_hist_data(obj),
		      hbook2_get_hist_data(other), "/", 1, 1);
}

static VALUE
hist_entry(VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);
  int entry;

  hnoent_(&data->id, &entry);
  return INT2NUM(entry);
}

static VALUE
hist_write(VALUE obj, VALUE file)
{
  char *option = "N";
  HistData *data = hbook2_get_hist_data(obj);

  Check_SafeStr(file);
  hrput_(&data->id, STR2CSTR(file), option, RSTRING(file)->len, 1);
  return Qnil;
}

static VALUE
hist_max(VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);
  double cont = hmax_(&data->id);
  return rb_float_new(cont);
}

static VALUE
hist_min(VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);
  double cont = hmin_(&data->id);
  return rb_float_new(cont);
}

static VALUE
hist_sum(VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);
  double cont = hsum_(&data->id);
  return rb_float_new(cont);
}


/*** functions for Hist1 class ***/

static VALUE
hist1_initialize(VALUE obj, VALUE id, VALUE title, VALUE bin,
		 VALUE min, VALUE max)
{
  HistData *data = hbook2_get_hist_data(obj);
  init_histogram(data, cHist1, NUM2INT(id), STR2CSTR(title),
		 NUM2INT(bin), NUM2DBL(min), NUM2DBL(max),
		 0, 0, 0, NULL);
  return obj;
}

static VALUE
hist1_s_read(VALUE klass, VALUE id, VALUE file)
{
  int hid = NUM2INT(id);
  int kind[32];
  char *option = " ";

  Check_SafeStr(file);
  if (hbook2_read_file(hid, STR2CSTR(file)) < 0)
    return Qnil;

  hkind_(&hid, kind, option, 1);
  if (kind[0] != 1) {
    rb_raise(rb_eRuntimeError, "1D histgram ID#%d does not exist\n", hid);
    return Qnil;
  } else {
    return hbook2_make_histogram_from_data(klass, hid);
  }
}

static VALUE hist1_fill_proc = Qnil;

float
hist1_fill_func_proc(float *x)
{
  static int call = 0;

  if (! call)
    call = rb_intern("call");
  return ((float) NUM2DBL(rb_funcall(hist1_fill_proc, call, 1, rb_float_new(*x))));
}

float
hist1_fill_func_with_block(float *x)
{
  return ((float) NUM2DBL(rb_yield(rb_float_new(*x))));
}

static VALUE
hist1_s_func(int argc, VALUE *argv, VALUE klass)
{
  VALUE id, title, bin, min, max, func;
  HistData *data;
  float (*function)(float*);
  VALUE obj = Data_Make_Struct(klass, HistData, 0, free_hist, data);
  int with_block = rb_block_given_p();

  if (rb_scan_args(argc, argv, "51", &id, &title, &bin, &min, &max, &func) == 5) {
    if (! with_block)
      rb_raise(rb_eArgError, "wrong # of arguments (%d for 6) or must call with block", argc);
    else
      function = hist1_fill_func_with_block;
  } else {
    with_block = 0;  /* if proc is given, block is ignored */
    function = hist1_fill_func_proc;
    hist1_fill_proc = func;
  }

  data->id = NUM2INT(id);
  data->xbin = NUM2INT(bin);
  data->xmin = (float) NUM2DBL(min);
  data->xmax = (float) NUM2DBL(max);
  data->ybin = 0;
  data->ymin = 0;
  data->ymax = 0;
  Check_Type(title, T_STRING);
  data->title = ALLOC_N(char, RSTRING(title)->len + 1);
  strcpy(data->title, STR2CSTR(title));
  data->deleted = 0;

  hbfun1_(&data->id, data->title, &data->xbin, &data->xmin, &data->xmax,
	  function, RSTRING(title)->len);
  if (! with_block)
    hist1_fill_proc = Qnil;

  return obj;
}

static VALUE
hist1_fill(int argc, VALUE *argv, VALUE obj)
{
  VALUE x, dn;
  HistData *data = hbook2_get_hist_data(obj);
  float inc = 1;

  if (rb_scan_args(argc, argv, "11", &x, &dn) == 2)
    inc = NUM2DBL(dn);
  if (TYPE(x) == T_ARRAY) {
    int i;
    float *farray;
    if (data->xbin > RARRAY(x)->len)
      rb_raise(rb_eArgError,
	       "Size of Array is less than the number of chunnels");
    farray = ALLOCA_N(float, data->xbin);
    for (i = 0; i < data->xbin; i++)
      farray[i] = NUM2DBL(RARRAY(x)->ptr[i]);
    hpakad_(&data->id, farray);
  } else {
    float value = NUM2DBL(x);
    hfill_(&data->id, &value, &zero, &inc);
  }
  return obj;
}

static VALUE
hist1_content(VALUE obj, VALUE ch)
{
  HistData *data = hbook2_get_hist_data(obj);
  double cont;
  int channel = NUM2INT(ch);

  if (channel < 0)
    channel = 0;
  else if (channel > data->xbin + 1)
    channel = data->xbin + 1;
  cont = hi_(&data->id, &channel);
  return rb_float_new(cont);
}

static VALUE
hist1_error(VALUE obj, VALUE ch)
{
  HistData *data = hbook2_get_hist_data(obj);
  int channel = NUM2INT(ch);
  double error = hie_(&data->id, &channel);
  return rb_float_new(error);
}

static VALUE
hist1_underflow(VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);
  int channel = 0;
  double cont = hi_(&data->id, &channel);
  return rb_float_new(cont);
}

static VALUE
hist1_overflow(VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);
  int channel = data->xbin + 1;
  double cont = hi_(&data->id, &channel);
  return rb_float_new(cont);
}

static VALUE
hist1_statics(VALUE obj, int icase)
{
  char *choice = "HIST";
  int num = 0;
  HistData *data = hbook2_get_hist_data(obj);
  double statics = hstati_(&data->id, &icase, choice, &num, strlen(choice));
  return rb_float_new(statics);
}

static VALUE
hist1_mean(VALUE obj)
{
  return hist1_statics(obj, 1);
}

static VALUE
hist1_sigma(VALUE obj)
{
  return hist1_statics(obj, 2);
}

static VALUE
hist1_equiv(VALUE obj)
{
  return hist1_statics(obj, 3);
}

static VALUE
hist1_get_vector(VALUE obj)
{
  char *choice = "HIST";
  int num = 0;
  int i;
  HistData *data = hbook2_get_hist_data(obj);
  float *farray = ALLOCA_N(float, data->xbin);
  VALUE array = rb_ary_new2(data->xbin);

  hunpak_(&data->id, farray, choice, &num, strlen(choice));
  for (i = 0; i < data->xbin; i++)
    rb_ary_store(array, i, rb_float_new(farray[i]));
  return array;
}

static VALUE
hist1_pack_vector(VALUE obj, VALUE array)
{
  int i;
  HistData *data = hbook2_get_hist_data(obj);
  float *farray;

  if (data->xbin > RARRAY(array)->len)
    rb_raise(rb_eArgError, "Size of Array is less than the number of chunnels");
  farray = ALLOCA_N(float, data->xbin);
  for (i = 0; i < data->xbin; i++)
    farray[i] = NUM2DBL(RARRAY(array)->ptr[i]);
  hpak_(&data->id, farray);
  return obj;
}

static VALUE
hist1_get_error_vector(VALUE obj)
{
  char *choice = "HIST";
  int num = 0;
  int i;
  HistData *data = hbook2_get_hist_data(obj);
  float *farray = ALLOCA_N(float, data->xbin);
  VALUE array = rb_ary_new2(data->xbin);

  hunpke_(&data->id, farray, choice, &num, strlen(choice));
  for (i = 0; i < data->xbin; i++)
    rb_ary_store(array, i, rb_float_new(farray[i]));
  return array;
}

static VALUE
hist1_pack_error_vector(VALUE obj, VALUE array)
{
  int i;
  HistData *data = hbook2_get_hist_data(obj);
  float *farray;

  Check_Type(array, T_ARRAY);
  if (data->xbin > RARRAY(array)->len)
    rb_raise(rb_eArgError, "Size of Array is less than the number of chunnels");
  farray = ALLOCA_N(float, data->xbin);
  for (i = 0; i < data->xbin; i++)
    farray[i] = NUM2DBL(RARRAY(array)->ptr[i]);
  hpake_(&data->id, farray);
  return obj;
}

float
fitting_func_block(float *x)
{
  int i;
  VALUE ary_par = rb_ary_new2(24);

  for (i = 0; i < 24; i++)
    rb_ary_store(ary_par, i, rb_float_new(hcfitd_.par[i]));
  hcfitd_.fit_fun = NUM2DBL(rb_yield(rb_assoc_new(rb_float_new(*x), ary_par)));
  return hcfitd_.fit_fun;
}

static float
hist1_fit_with_block(HistData *data, int num_par, float *parameter,
		     float *par_sigma, char *option)
{
  float chi2;
  float *step = ALLOCA_N(float, num_par);
  float *par_min = ALLOCA_N(float, num_par);
  float *par_max = ALLOCA_N(float, num_par);
  float (*func)(float*) = fitting_func_block;

  hfith_(&data->id, func, option, &num_par, parameter,
	 step, par_min, par_max, par_sigma, &chi2, strlen(option));
  return chi2;
}

static VALUE fitting_proc = Qnil;

float
fitting_func_proc(float *x)
{
  int i;
  static int call = 0;
  VALUE ary_par = rb_ary_new2(24);

  if (! call)
    call = rb_intern("call");
  for (i = 0; i < 24; i++)
    rb_ary_store(ary_par, i, rb_float_new(hcfitd_.par[i]));
  hcfitd_.fit_fun = NUM2DBL(rb_funcall(fitting_proc, call, 2, rb_float_new(*x), ary_par));
  return hcfitd_.fit_fun;
}

static float
hist1_fit_with_proc(HistData *data, int num_par, float *parameter,
		    float *par_sigma, VALUE function, char *option)
{
  float chi2;
  float *step = ALLOCA_N(float, num_par);
  float *par_min = ALLOCA_N(float, num_par);
  float *par_max = ALLOCA_N(float, num_par);
  float (*func)(float*) = fitting_func_proc;

  fitting_proc = function;
  hfith_(&data->id, func, option, &num_par, parameter,
	 step, par_min, par_max, par_sigma, &chi2, strlen(option));
  fitting_proc = Qnil;
  return chi2;
}

static float
hist1_fit_with_special_func(HistData *data, int num_par, float *parameter,
			    float *par_sigma, char *function, char *option)
{
  float chi2;
  float *step = ALLOCA_N(float, num_par);
  float *par_min = ALLOCA_N(float, num_par);
  float *par_max = ALLOCA_N(float, num_par);

  hfithn_(&data->id, function, option, &num_par, parameter,
	  step, par_min, par_max, par_sigma, &chi2,
	  strlen(function), strlen(option));
  return chi2;
}

static VALUE
hist1_fit(int argc, VALUE *argv, VALUE obj)
{
  int i;
  HistData *data = hbook2_get_hist_data(obj);
  VALUE par, opt, func, dpar, new_par;
  float *parameter, *par_sigma;
  float chi2;
  int num_par;
  int with_block = 0;
#if 0
  char *option = "D";
#else
  char *option = " ";
#endif

  if (rb_block_given_p()) {
    with_block = 1;
    if (rb_scan_args(argc, argv, "11", &par, &opt) == 2)
      option = STR2CSTR(opt);
  } else {
    with_block = 0;
    if (rb_scan_args(argc, argv, "21", &par, &func, &opt) == 3)
      option = STR2CSTR(opt);
  }
  if ((num_par = RARRAY(par)->len) > 24)
    rb_raise(rb_eArgError, "too many parameters for fitting: %d", num_par);
  parameter = ALLOCA_N(float, num_par);
  par_sigma = ALLOCA_N(float, num_par);
  for (i = 0; i < num_par; i++)
    parameter[i] = (float) NUM2DBL(RARRAY(par)->ptr[i]);
#if 0
  if (strchr(option, 'D') == NULL && strchr(option, 'd') == NULL) {
    option = ALLOCA_N(char, RSTRING(opt)->len + 2);
    option[0] = 'D';
    strcpy(&option[1], STR2CSTR(opt));
  }
#endif
  if (with_block) {
    chi2 = hist1_fit_with_block(data, num_par, parameter, par_sigma, option);
  } else if (TYPE(func) == T_STRING) {
    chi2 = hist1_fit_with_special_func(data, num_par, parameter, par_sigma,
				       STR2CSTR(func), option);
  } else {
    chi2 = hist1_fit_with_proc(data, num_par, parameter, par_sigma,
			       func, option);
  }
  new_par = rb_ary_new2(num_par);
  dpar = rb_ary_new2(num_par);
  for (i = 0; i < num_par; i++) {
    rb_ary_store(new_par, i, rb_float_new(parameter[i]));
    rb_ary_store(dpar, i, rb_float_new(par_sigma[i]));
  }
  return rb_ary_new3(3, new_par, dpar, rb_float_new(chi2));
}

static VALUE
hist1_random(VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);
  double rnd = hrndm1_(&data->id);
  return rb_float_new(rnd);
}


/*** functions for Hist2 class ***/

static VALUE
hist2_initialize(VALUE obj, VALUE id, VALUE title,
		 VALUE xbin, VALUE xmin, VALUE xmax,
		 VALUE ybin, VALUE ymin, VALUE ymax)
{
  HistData *data = hbook2_get_hist_data(obj);
  init_histogram(data, cHist2, NUM2INT(id), STR2CSTR(title),
		 NUM2INT(xbin), NUM2DBL(xmin), NUM2DBL(xmax),
		 NUM2INT(ybin), NUM2DBL(ymin), NUM2DBL(ymax), NULL);
  return obj;
}

static VALUE
hist2_s_read(VALUE klass, VALUE id, VALUE file)
{
  int hid = NUM2INT(id);
  int kind[32];
  char *option = " ";

  Check_SafeStr(file);
  if (hbook2_read_file(hid, STR2CSTR(file)) < 0)
    return Qnil;

  hkind_(&hid, kind, option, 1);
  if (kind[0] != 2) {
    rb_raise(rb_eRuntimeError, "2D histgram ID#%d does not exist\n", hid);
    return Qnil;
  } else {
    return hbook2_make_histogram_from_data(klass, hid);
  }
}

static VALUE
hist2_fill(int argc, VALUE *argv, VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);

  if (argc == 1) {
    int i, j;
    float *farray, *ptr;
    Check_Type(argv[0], T_ARRAY);
    if (data->ybin > RARRAY(argv[0])->len)
      rb_raise(rb_eArgError, "Size of Array is less than the number of Y chunnels");
    ptr = farray = ALLOCA_N(float, data->xbin * data->ybin);
    for (i = 0; i < data->ybin; i++) {
      VALUE ary = RARRAY(argv[0])->ptr[i];
      Check_Type(ary, T_ARRAY);
      if (data->xbin > RARRAY(ary)->len)
	rb_raise(rb_eArgError, "Size of Array is less than the number of X chunnels");
      for (j = 0; j < data->xbin; j++)
	*(ptr++) = NUM2DBL(RARRAY(ary)->ptr[j]);
    }
    hpakad_(&data->id, farray);
  } else {
    float inc = 1;
    float xvalue, yvalue;
    VALUE x, y, dn;
    if (rb_scan_args(argc, argv, "21", &x, &y, &dn) == 3)
      inc = NUM2DBL(dn);
    xvalue = NUM2DBL(x);
    yvalue = NUM2DBL(y);
    hfill_(&data->id, &xvalue, &yvalue, &inc);
  }
  return Qnil;
}

static VALUE
hist2_content(VALUE obj, VALUE xch, VALUE ych)
{
  HistData *data = hbook2_get_hist_data(obj);
  double cont;
  int xchannel = NUM2INT(xch);
  int ychannel = NUM2INT(ych);

  if (xchannel < 0)
    xchannel = 0;
  else if (xchannel > data->xbin + 1)
    xchannel = data->xbin + 1;
  if (ychannel < 0)
    ychannel = 0;
  else if (ychannel > data->ybin + 1)
    ychannel = data->ybin + 1;
  cont = hij_(&data->id, &xchannel, &ychannel);
  return rb_float_new(cont);
}

static VALUE
hist2_error(VALUE obj, VALUE xch, VALUE ych)
{
  HistData *data = hbook2_get_hist_data(obj);
  double error;
  int xchannel = NUM2INT(xch);
  int ychannel = NUM2INT(ych);

  if (xchannel < 0)
    xchannel = 0;
  else if (xchannel > data->xbin + 1)
    xchannel = data->xbin + 1;
  if (ychannel < 0)
    ychannel = 0;
  else if (ychannel > data->ybin + 1)
    ychannel = data->ybin + 1;
  error = hije_(&data->id, &xchannel, &ychannel);
  return rb_float_new(error);
}

static void
str_upcase(char *str)
{
  register char *s;

  for (s = str; *s; s++) {
    if (islower(*s))
      *s = toupper(*s);
  }
}

static VALUE
hist2_get_vector(int argc, VALUE *argv, VALUE obj)
{
  VALUE opt, number;
  char *choice = "HIST";
  int num = 0;
  int i, j;
  HistData *data = hbook2_get_hist_data(obj);
  float *farray;
  VALUE array = rb_ary_new2(data->ybin);
  VALUE sub_array;
  int n;

  n = rb_scan_args(argc, argv, "02", &opt, &number);
  if (n > 0) {
    Check_Type(opt, T_STRING);
    choice = ALLOCA_N(char, RSTRING(opt)->len + 1);
    strcpy(choice, RSTRING(opt)->ptr);
    str_upcase(choice);
  }
  if (n > 1)
    num = NUM2INT(number);
  if (strcmp(choice, "HIST") == 0) {
    farray = ALLOCA_N(float, data->xbin * data->ybin);
    hunpak_(&data->id, farray, choice, &num, strlen(choice));
    for (i = 0; i < data->ybin; i++) {
      sub_array = rb_ary_new2(data->xbin);
      for (j = 0; j < data->xbin; j++)
	rb_ary_store(sub_array, j, rb_float_new(*(farray++)));
      rb_ary_store(array, i, sub_array);
    }
  } else if (strcmp(choice, "PROX") == 0 || strcmp(choice, "BANX") == 0 ||
	     strcmp(choice, "SLIX") == 0) {
    farray = ALLOCA_N(float, data->xbin);
    hunpak_(&data->id, farray, choice, &num, strlen(choice));
    for (i = 0; i < data->xbin; i++) {
      rb_ary_store(array, i, rb_float_new(farray[i]));
    }
  } else if (strcmp(choice, "PROY") == 0 || strcmp(choice, "BANY") == 0 ||
	     strcmp(choice, "SLIY") == 0) {
    farray = ALLOCA_N(float, data->ybin);
    hunpak_(&data->id, farray, choice, &num, strlen(choice));
    for (i = 0; i < data->ybin; i++) {
      rb_ary_store(array, i, rb_float_new(farray[i]));
    }
  } else {
    rb_raise(rb_eArgError, "Invalid option for Hist2#to_a: %s", choice);
  }
  return array;
}

static VALUE
hist2_pack_vector(VALUE obj, VALUE array)
{
  int i, j;
  HistData *data = hbook2_get_hist_data(obj);
  float *farray, *ptr;

  Check_Type(array, T_ARRAY);
  if (data->ybin > RARRAY(array)->len)
    rb_raise(rb_eArgError, "Size of Array is less than the number of Y chunnels");
  ptr = farray = ALLOCA_N(float, data->xbin * data->ybin);
  for (i = 0; i < data->ybin; i++) {
    VALUE ary = RARRAY(array)->ptr[i];
    Check_Type(ary, T_ARRAY);
    if (data->xbin > RARRAY(ary)->len)
      rb_raise(rb_eArgError, "Size of Array is less than the number of X chunnels");
    for (j = 0; j < data->xbin; j++)
      *(ptr++) = NUM2DBL(RARRAY(ary)->ptr[j]);
  }
  hpak_(&data->id, farray);
  return obj;
}

static VALUE
hist2_get_error_vector(int argc, VALUE *argv, VALUE obj)
{
  VALUE opt, number;
  char *choice = "HIST";
  int num = 0;
  int i, j;
  HistData *data = hbook2_get_hist_data(obj);
  float *farray;
  VALUE array = rb_ary_new2(data->ybin);
  VALUE sub_array;
  int n;

  n = rb_scan_args(argc, argv, "02", &opt, &number);
  if (n > 0) {
    Check_Type(opt, T_STRING);
    choice = ALLOCA_N(char, RSTRING(opt)->len + 1);
    strcpy(choice, RSTRING(opt)->ptr);
    str_upcase(choice);
  }
  if (n > 1)
    num = NUM2INT(number);
  if (strcmp(choice, "HIST") == 0) {
    farray = ALLOCA_N(float, data->xbin * data->ybin);
    hunpke_(&data->id, farray, choice, &num, strlen(choice));
    for (i = 0; i < data->ybin; i++) {
      sub_array = rb_ary_new2(data->xbin);
      for (j = 0; j < data->xbin; j++)
	rb_ary_store(sub_array, j, rb_float_new(*(farray++)));
      rb_ary_store(array, i, sub_array);
    }
  } else if (strcmp(choice, "PROX") == 0 || strcmp(choice, "BANX") == 0 ||
	     strcmp(choice, "SLIX") == 0) {
    farray = ALLOCA_N(float, data->xbin);
    hunpke_(&data->id, farray, choice, &num, strlen(choice));
    for (i = 0; i < data->xbin; i++) {
      rb_ary_store(array, i, rb_float_new(farray[i]));
    }
  } else if (strcmp(choice, "PROY") == 0 || strcmp(choice, "BANY") == 0 ||
	     strcmp(choice, "SLIY") == 0) {
    farray = ALLOCA_N(float, data->ybin);
    hunpke_(&data->id, farray, choice, &num, strlen(choice));
    for (i = 0; i < data->ybin; i++) {
      rb_ary_store(array, i, rb_float_new(farray[i]));
    }
  } else {
    rb_raise(rb_eArgError, "Invalid option for Hist2#err2a: %s", choice);
  }
  return array;
}

static VALUE
hist2_pack_error_vector(VALUE obj, VALUE array)
{
  int i, j;
  HistData *data = hbook2_get_hist_data(obj);
  float *farray, *ptr;

  Check_Type(array, T_ARRAY);
  if (data->ybin > RARRAY(array)->len)
    rb_raise(rb_eArgError, "Size of Array is less than the number of Y chunnels");
  ptr = farray = ALLOCA_N(float, data->xbin * data->ybin);
  for (i = 0; i < data->ybin; i++) {
    VALUE ary = RARRAY(array)->ptr[i];
    Check_Type(ary, T_ARRAY);
    if (data->xbin > RARRAY(ary)->len)
      rb_raise(rb_eArgError, "Size of Array is less than the number of X chunnels");
    for (j = 0; j < data->xbin; j++)
      *(ptr++) = NUM2DBL(RARRAY(ary)->ptr[j]);
  }
  hpake_(&data->id, farray);
  return obj;
}

static VALUE
hist2_book_xproj(VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);
  float vmx = 0;

  hbprox_(&data->id, &vmx);
  return obj;
}

static VALUE
hist2_book_yproj(VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);
  float vmx = 0;

  hbproy_(&data->id, &vmx);
  return obj;
}

static VALUE
hist2_book_xband(VALUE obj, VALUE min, VALUE max)
{
  HistData *data = hbook2_get_hist_data(obj);
  float minimum = NUM2DBL(min);
  float maximum = NUM2DBL(max);
  float vmx = 0;

  hbandx_(&data->id, &minimum, &maximum, &vmx);
  return obj;
}

static VALUE
hist2_book_yband(VALUE obj, VALUE min, VALUE max)
{
  HistData *data = hbook2_get_hist_data(obj);
  float minimum = NUM2DBL(min);
  float maximum = NUM2DBL(max);
  float vmx = 0;

  hbandy_(&data->id, &minimum, &maximum, &vmx);
  return obj;
}

static VALUE
hist2_book_xslice(VALUE obj, VALUE num)
{
  HistData *data = hbook2_get_hist_data(obj);
  int num_slice = NUM2INT(num);
  float vmx = 0;

  hbslix_(&data->id, &num_slice, &vmx);
  return obj;
}

static VALUE
hist2_book_yslice(VALUE obj, VALUE num)
{
  HistData *data = hbook2_get_hist_data(obj);
  int num_slice = NUM2INT(num);
  float vmx = 0;

  hbsliy_(&data->id, &num_slice, &vmx);
  return obj;
}

static VALUE
hist2_xproj(VALUE obj, VALUE id, VALUE title)
{
  HistData *data = hbook2_get_hist_data(obj);
  float *contents = ALLOCA_N(float, data->xbin);
  char *choice = "HIST";
  float *array = ALLOCA_N(float, data->xbin * data->ybin);
  int i, j;
  int hid = NUM2INT(id);
  VALUE new_obj;

  for (i = 0; i < data->xbin; i++)
    contents[i] = 0;
  hunpak_(&data->id, array, choice, &zero, strlen(choice));
  for (i = 0; i < data->ybin; i++) {
    for (j = 0; j < data->xbin; j++)
      contents[j] += *(array++);
  }
  new_obj = hbook2_make_histogram(cHist1, hid, STR2CSTR(title),
				  data->xbin, data->xmin, data->xmax,
				  0, 0, 0, NULL);
  hpak_(&hid, contents);
  return new_obj;
}

static VALUE
hist2_yproj(VALUE obj, VALUE id, VALUE title)
{
  HistData *data = hbook2_get_hist_data(obj);
  float *contents = ALLOCA_N(float, data->ybin);
  char *choice = "HIST";
  float *array = ALLOCA_N(float, data->xbin * data->ybin);
  int i, j;
  int hid = NUM2INT(id);
  VALUE new_obj;

  for (i = 0; i < data->ybin; i++)
    contents[i] = 0;
  hunpak_(&data->id, array, choice, &zero, strlen(choice));
  for (i = 0; i < data->ybin; i++) {
    for (j = 0; j < data->xbin; j++)
      contents[i] += *(array++);
  }
  new_obj = hbook2_make_histogram(cHist1, hid, STR2CSTR(title),
				  data->ybin, data->ymin, data->ymax,
				  0, 0, 0, NULL);
  hpak_(&hid, contents);
  return new_obj;
}

static VALUE
hist2_random(VALUE obj)
{
  float x, y;
  HistData *data = hbook2_get_hist_data(obj);
  hrndm2_(&data->id, &x, &y);
  return rb_assoc_new(rb_float_new(x), rb_float_new(y));
}


/*** functions for Profile class ***/

static VALUE
prof_initialize(int argc, VALUE *argv, VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);
  char *option;
  VALUE id, title, xbin, xmin, xmax, ymin, ymax, opt;

  if (rb_scan_args(argc, argv, "71",
		   &id, &title, &xbin, &xmin, &xmax, &ymin, &ymax, &opt) == 7)
    option = " ";
  else
    option = STR2CSTR(opt);
  init_histogram(data, cProfile, NUM2INT(id), STR2CSTR(title),
		 NUM2INT(xbin), NUM2DBL(xmin), NUM2DBL(xmax),
		 0, NUM2DBL(ymin), NUM2DBL(ymax), option);
  return obj;
}

static VALUE
prof_s_read(VALUE klass, VALUE id, VALUE file)
{
  int hid = NUM2INT(id);
  int kind[32];
  char *option = " ";

  Check_SafeStr(file);
  if (hbook2_read_file(hid, STR2CSTR(file)) < 0)
    return Qnil;

  hkind_(&hid, kind, option, 1);
  if (kind[0] != 8) {
    rb_raise(rb_eRuntimeError, "profile histgram ID#%d does not exist\n", hid);
    return Qnil;
  } else {
    return hbook2_make_histogram_from_data(klass, hid);
  }
}

static VALUE
prof_fill(int argc, VALUE *argv, VALUE obj)
{
  HistData *data = hbook2_get_hist_data(obj);
  float inc = 1;
  float xvalue, yvalue;
  VALUE x, y, dn;

  if (rb_scan_args(argc, argv, "21", &x, &y, &dn) == 3)
    inc = NUM2DBL(dn);
  xvalue = NUM2DBL(x);
  yvalue = NUM2DBL(y);
  hfill_(&data->id, &xvalue, &yvalue, &inc);
  return Qnil;
}


void
Init_hbook2_hist()
{
  cBasicHist = rb_define_class_under(mHBook2, "BasicHist", rb_cData);

#ifdef HAVE_OBJECT_ALLOCATE
  rb_define_alloc_func(cBasicHist, hist_s_allocate);
#else
  rb_define_singleton_method(cBasicHist, "new", hist_s_new, -1);
#endif

  rb_define_method(cBasicHist, "delete", hist_delete, 0);
  rb_define_method(cBasicHist, "deleted?", hist_deleted_p, 0);
  rb_define_method(cBasicHist, "inspect", hist_inspect, 0);
  rb_define_method(cBasicHist, "reset", hist_reset, -1);
  rb_define_method(cBasicHist, "hist_id", hist_get_id, 0);
  rb_define_method(cBasicHist, "hist_id=", hist_set_id, 1);
  rb_define_method(cBasicHist, "title", hist_title, 0);
  rb_define_method(cBasicHist, "xbin", hist_xbin, 0);
  rb_define_method(cBasicHist, "ybin", hist_ybin, 0);
  rb_define_method(cBasicHist, "copy", hist_copy, -1);
  rb_define_method(cBasicHist, "write", hist_write, 1);
  rb_define_method(cBasicHist, "entry", hist_entry, 0);
  rb_define_method(cBasicHist, "+", hist_add, 1);
  rb_define_method(cBasicHist, "-", hist_subtract, 1);
  rb_define_method(cBasicHist, "*", hist_times, 1);
  rb_define_method(cBasicHist, "/", hist_devide, 1);
  rb_define_method(cBasicHist, "max", hist_max, 0);
  rb_define_method(cBasicHist, "min", hist_min, 0);
  rb_define_method(cBasicHist, "sum", hist_sum, 0);


  cHist1 = rb_define_class_under(mHBook2, "Hist1", cBasicHist);

  rb_define_singleton_method(cHist1, "read", hist1_s_read, 2);
  rb_define_singleton_method(cHist1, "func", hist1_s_func, -1);
  rb_define_method(cHist1, "initialize", hist1_initialize, 5);
  rb_define_method(cHist1, "fill", hist1_fill, -1);
  rb_define_method(cHist1, "<<", hist1_fill, -1);
  rb_define_method(cHist1, "content", hist1_content, 1);
  rb_define_method(cHist1, "[]", hist1_content, 1);
  rb_define_method(cHist1, "error", hist1_error, 1);
  rb_define_method(cHist1, "underflow", hist1_underflow, 0);
  rb_define_method(cHist1, "overflow", hist1_overflow, 0);
  rb_define_method(cHist1, "mean", hist1_mean, 0);
  rb_define_method(cHist1, "sigma", hist1_sigma, 0);
  rb_define_method(cHist1, "equiv", hist1_equiv, 0);
  rb_define_method(cHist1, "to_a", hist1_get_vector, 0);
  rb_define_method(cHist1, "unpack", hist1_get_vector, 0);
  rb_define_method(cHist1, "pack", hist1_pack_vector, 1);
  rb_define_method(cHist1, "err2a", hist1_get_error_vector, 0);
  rb_define_method(cHist1, "unpack_err", hist1_get_error_vector, 0);
  rb_define_method(cHist1, "pack_err", hist1_pack_error_vector, 1);
  rb_define_method(cHist1, "fit", hist1_fit, -1);
  rb_define_method(cHist1, "random", hist1_random, 0);


  cHist2 = rb_define_class_under(mHBook2, "Hist2", cBasicHist);

  rb_define_singleton_method(cHist2, "read", hist2_s_read, 2);
  rb_define_method(cHist2, "initialize", hist2_initialize, 8);
  rb_define_method(cHist2, "fill", hist2_fill, -1);
  rb_define_method(cHist2, "content", hist2_content, 2);
  rb_define_method(cHist2, "[]", hist2_content, 2);
  rb_define_method(cHist2, "error", hist2_error, 2);
  rb_define_method(cHist2, "to_a", hist2_get_vector, -1);
  rb_define_method(cHist2, "unpack", hist2_get_vector, -1);
  rb_define_method(cHist2, "pack", hist2_pack_vector, 1);
  rb_define_method(cHist2, "err2a", hist2_get_error_vector, -1);
  rb_define_method(cHist2, "unpack_err", hist2_get_error_vector, -1);
  rb_define_method(cHist2, "pack_err", hist2_pack_error_vector, 1);
  rb_define_method(cHist2, "book_xproj", hist2_book_xproj, 0);
  rb_define_method(cHist2, "book_yproj", hist2_book_yproj, 0);
  rb_define_method(cHist2, "book_xband", hist2_book_xband, 2);
  rb_define_method(cHist2, "book_yband", hist2_book_yband, 2);
  rb_define_method(cHist2, "book_xslice", hist2_book_xslice, 1);
  rb_define_method(cHist2, "book_yslice", hist2_book_yslice, 1);
  rb_define_method(cHist2, "xproj", hist2_xproj, 2);
  rb_define_method(cHist2, "yproj", hist2_yproj, 2);
#if 0
  rb_define_method(cHist2, "profile", hist2_profile, 1);
#endif
  rb_define_method(cHist2, "random", hist2_random, 0);


  cProfile = rb_define_class_under(mHBook2, "Profile", cBasicHist);

  rb_define_singleton_method(cProfile, "read", prof_s_read, 2);
  rb_define_method(cProfile, "initialize", prof_initialize, -1);
  rb_define_method(cProfile, "fill", prof_fill, -1);
  rb_define_method(cProfile, "content", hist1_content, 1);
  rb_define_method(cProfile, "[]", hist1_content, 1);
  rb_define_method(cProfile, "error", hist1_error, 1);
  rb_define_method(cProfile, "to_a", hist1_get_vector, 0);
  rb_define_method(cProfile, "unpack", hist1_get_vector, 0);
  rb_define_method(cProfile, "err2a", hist1_get_error_vector, 0);
  rb_define_method(cProfile, "unpack_err", hist1_get_error_vector, 0);
  rb_define_method(cProfile, "fit", hist1_fit, -1);


  cTable = rb_define_class_under(mHBook2, "Table", cBasicHist);
}
