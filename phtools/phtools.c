#include <ruby.h>
#include "cernlib_util.h"

static ID cern_id_id;

static VALUE wrap_mCERN;
VALUE wrap_mPHTools;


struct {
  int np;
  float tecm;
  float amass[18];
  int kgenev;
} genin_;

struct {
  float pcm[18][5];
  float wt;
} genout_;

extern void genbod_();


static VALUE _wrap_genbod(VALUE self)
{

  genbod_();

  return Qnil;
}


static VALUE _wrap_genin_np_set(VALUE self, VALUE arg)
{
  genin_.np = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_genin_np_get(VALUE self)
{
  return INT2NUM(genin_.np);
}

static VALUE _wrap_genin_tecm_set(VALUE self, VALUE arg)
{
  genin_.tecm = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_genin_tecm_get(VALUE self)
{
  return rb_float_new(genin_.tecm);
}

static VALUE _wrap_genin_amass_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  genin_.amass[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_genin_amass_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "amass");
  if (NIL_P(value)) {
    value = rb_ary_new2(18);
    for (i = 0; i < 18; i++)
      rb_ary_store(value, i, rb_float_new(genin_.amass[i]));
    rb_define_singleton_method(value, "[]=", _wrap_genin_amass_set, 2);
    rb_iv_set(self, "amass", value);
  } else {
    for (i = 0; i < 18; i++)
      rb_ary_store(value, i, rb_float_new(genin_.amass[i]));
  }
  return value;
}

static VALUE _wrap_genin_kgenev_set(VALUE self, VALUE arg)
{
  genin_.kgenev = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_genin_kgenev_get(VALUE self)
{
  return INT2NUM(genin_.kgenev);
}

static VALUE _wrap_genout_pcm_set(VALUE self, VALUE index, VALUE arg)
{
  int id1 = NUM2INT(rb_ivar_get(self, cern_id_id));
  int id2 = NUM2INT(index);
  genout_.pcm[id1][id2] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_genout_pcm_get(VALUE self)
{
  int i, j;
  VALUE value = rb_iv_get(self, "pcm");
  if (NIL_P(value)) {
    value = rb_ary_new2(18);
    for (i = 0; i < 18; i++) {
      VALUE ary = rb_ary_new2(5);
      for (j = 0; j < 5; j++)
	rb_ary_store(ary, j, rb_float_new(genout_.pcm[i][j]));
      rb_define_singleton_method(ary, "[]=", _wrap_genout_pcm_set, 2);
      rb_ivar_set(ary, cern_id_id, INT2NUM(i));
      rb_ary_store(value, i, ary);
    }
    rb_iv_set(self, "pcm", value);
  } else {
    for (i = 0; i < 18; i++) {
      for (j = 0; j < 5; j++)
	rb_ary_store(RARRAY(value)->ptr[i], j, rb_float_new(genout_.pcm[i][j]));
    }
  }
  return value;
}

static VALUE _wrap_genout_wt_set(VALUE self, VALUE arg)
{
  genout_.wt = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_genout_wt_get(VALUE self)
{
  return rb_float_new(genout_.wt);
}


void Init_phtools()
{
  VALUE wrap_sGENIN, wrap_sGENOUT;

  cern_id_id = rb_intern("id");

  wrap_mCERN = rb_define_module("CERN");
  wrap_mPHTools = rb_define_module_under(wrap_mCERN, "PHTools");

  rb_define_module_function(wrap_mPHTools, "genbod", _wrap_genbod, 0);


  wrap_sGENIN = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGENIN, "np", _wrap_genin_np_get, 0);
  rb_define_singleton_method(wrap_sGENIN, "np=", _wrap_genin_np_set, 1);
  rb_define_singleton_method(wrap_sGENIN, "tecm", _wrap_genin_tecm_get, 0);
  rb_define_singleton_method(wrap_sGENIN, "tecm=", _wrap_genin_tecm_set, 1);
  rb_define_singleton_method(wrap_sGENIN, "amass", _wrap_genin_amass_get, 0);
  rb_define_singleton_method(wrap_sGENIN, "kgenev", _wrap_genin_kgenev_get, 0);
  rb_define_singleton_method(wrap_sGENIN, "kgenev=", _wrap_genin_kgenev_set, 1);
  rb_define_const(wrap_mPHTools, "GENIN", wrap_sGENIN);

  wrap_sGENOUT = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGENOUT, "pcm", _wrap_genout_pcm_get, 0);
  rb_define_singleton_method(wrap_sGENOUT, "wt", _wrap_genout_wt_get, 0);
  rb_define_singleton_method(wrap_sGENOUT, "wt=", _wrap_genout_wt_set, 1);
  rb_define_const(wrap_mPHTools, "GENOUT", wrap_sGENOUT);

}
