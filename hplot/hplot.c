#include <ruby.h>
#include "cernlib_util.h"


static VALUE wrap_mCERN;
VALUE wrap_mHPlot;


extern void hplabl_(int*, int*, char*, int);
extern void hplaer_(float*, float*, float*, float*, float*, float*, int*, char*, int*, float*, int);
extern void hplarc_(float*, float*, float*, float*, float*);
extern void hplax_(char*, char*, int, int);
extern void hplbox_(float*, float*, float*, float*, char*, int);
extern void hplcap_(int*);
extern void hplcom_(float*, float*, char*, int);
extern void hplcon_(int*, int*, int*);
extern void hpldo_(int*);
extern void hplego_(int*, float*, float*);
extern void hplend_();
extern void hplerr_(float*, float*, float*, float*, int*, char*, int*, float*, int);
extern void hplfra_(float*, float*, float*, float*, char*, int);
extern void hplfun_(float*, float*, int*, char*, int);
extern void hplgiv_(float*, float*, float*, float*);
extern void hpline_(float*, float*, int*, char*, int);
extern void hplint_(int*);
extern void hplkey_(float*, float*, int*, char*, int);
extern void hplnul_();
extern void hploc_(int*, int*, float*, float*, int*, int*, int*, int*);
extern void hplopt_(char*, int*, int);
extern void hplot_(int*, char*, char*, int*, int, int);
extern void hplpro_(int*, char*, char*, int, int);
extern void hplpto_(char*, char*, int, int);
extern void hplset_(char*, float*, int);
extern void hplsof_(float*, float*, char*, float*, float*, float*, int*, int);
extern void hplsur_(int*, float*, float*, int*);
extern void hplsym_(float*, float*, int*, int*, float*, char*, int);
extern void hpltab_(int*, int*, float*, char*, int);
extern void hpltit_(char*, int);
extern void hplwir_(char*, float*, float*, char*, int, int);
extern void hplzom_(int*, char*, int*, int*, int);
extern void hplzon_(int*, int*, int*, char*, int);
extern void hplsiz_(float*, float*, char*, int);
extern void hrin_(int*, int*, int*);
extern void hgiven_(int*, char*, int*, char*, float*, float*, int, int);
extern void hplnt_(int*, int*, float(*)(float*,int*), int*, int*, int*, int*);


static VALUE _wrap_hplabl(VALUE self, VALUE arg0, VALUE arg2)
{
  int carg0;
  int carg1;
  int len2;
  char *carg2;

  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = NUM2INT(arg0);
  carg1 = len2;
  carg2 = ALLOCA_N(char, 32 * len2 + 1);
  util_str_ary_rb2f(arg2, 32, carg2);
  hplabl_(&carg0, &carg1, carg2, 32);

  return Qnil;
}

static VALUE _wrap_hplaer(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg7, VALUE arg8, VALUE arg9)
{
  int i0, len0;
  float *carg0;
  int i1, len1;
  float *carg1;
  int i2, len2;
  float *carg2;
  int i3, len3;
  float *carg3;
  int i4, len4;
  float *carg4;
  int i5, len5;
  float *carg5;
  int carg6;
  int len7;
  char *carg7;
  int carg8;
  float carg9;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  Check_Type(arg3, T_ARRAY);
  len3 = RARRAY(arg3)->len;
  Check_Type(arg4, T_ARRAY);
  len4 = RARRAY(arg4)->len;
  Check_Type(arg5, T_ARRAY);
  len5 = RARRAY(arg5)->len;
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  carg3 = ALLOCA_N(float, len3);
  for (i3 = 0; i3 < len3; i3++)
    carg3[i3] = NUM2DBL(RARRAY(arg3)->ptr[i3]);
  carg4 = ALLOCA_N(float, len4);
  for (i4 = 0; i4 < len4; i4++)
    carg4[i4] = NUM2DBL(RARRAY(arg4)->ptr[i4]);
  carg5 = ALLOCA_N(float, len5);
  for (i5 = 0; i5 < len5; i5++)
    carg5[i5] = NUM2DBL(RARRAY(arg5)->ptr[i5]);
  carg6 = len0;
  Check_Type(arg7, T_STRING);
  len7 = RSTRING(arg7)->len;
  carg7 = ALLOCA_N(char, len7 + 1);
  strcpy(carg7, STR2CSTR(arg7));
  carg8 = NUM2INT(arg8);
  carg9 = NUM2DBL(arg9);
  hplaer_(carg0, carg1, carg2, carg3, carg4, carg5, &carg6, carg7, &carg8, &carg9, len7);

  return Qnil;
}

static VALUE _wrap_hplarc(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  hplarc_(&carg0, &carg1, &carg2, &carg3, &carg4);

  return Qnil;
}

static VALUE _wrap_hplax(VALUE self, VALUE arg0, VALUE arg1)
{
  int len0;
  char *carg0;
  int len1;
  char *carg1;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  hplax_(carg0, carg1, len0, len1);

  return Qnil;
}

static VALUE _wrap_hplbox(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  int len4;
  char *carg4;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  Check_Type(arg4, T_STRING);
  len4 = RSTRING(arg4)->len;
  carg4 = ALLOCA_N(char, len4 + 1);
  strcpy(carg4, STR2CSTR(arg4));
  hplbox_(&carg0, &carg1, &carg2, &carg3, carg4, len4);

  return Qnil;
}

static VALUE _wrap_hplcap(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hplcap_(&carg0);

  return Qnil;
}

static VALUE _wrap_hplcom(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  float carg0;
  float carg1;
  int len2;
  char *carg2;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  hplcom_(&carg0, &carg1, carg2, len2);

  return Qnil;
}

static VALUE _wrap_hplcon(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  int carg2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  hplcon_(&carg0, &carg1, &carg2);

  return Qnil;
}

static VALUE _wrap_hpldo(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hpldo_(&carg0);

  return Qnil;
}

static VALUE _wrap_hplego(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  float carg1;
  float carg2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  hplego_(&carg0, &carg1, &carg2);

  return Qnil;
}

static VALUE _wrap_hplend(VALUE self)
{

  hplend_();

  return Qnil;
}

static VALUE _wrap_hplerr(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg5, VALUE arg6, VALUE arg7)
{
  int i0, len0;
  float *carg0;
  int i1, len1;
  float *carg1;
  int i2, len2;
  float *carg2;
  int i3, len3;
  float *carg3;
  int carg4;
  int len5;
  char *carg5;
  int carg6;
  float carg7;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  Check_Type(arg3, T_ARRAY);
  len3 = RARRAY(arg3)->len;
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  carg3 = ALLOCA_N(float, len3);
  for (i3 = 0; i3 < len3; i3++)
    carg3[i3] = NUM2DBL(RARRAY(arg3)->ptr[i3]);
  carg4 = len0;
  Check_Type(arg5, T_STRING);
  len5 = RSTRING(arg5)->len;
  carg5 = ALLOCA_N(char, len5 + 1);
  strcpy(carg5, STR2CSTR(arg5));
  carg6 = NUM2INT(arg6);
  carg7 = NUM2DBL(arg7);
  hplerr_(carg0, carg1, carg2, carg3, &carg4, carg5, &carg6, &carg7, len5);

  return Qnil;
}

static VALUE _wrap_hplfra(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  int len4;
  char *carg4;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  Check_Type(arg4, T_STRING);
  len4 = RSTRING(arg4)->len;
  carg4 = ALLOCA_N(char, len4 + 1);
  strcpy(carg4, STR2CSTR(arg4));
  hplfra_(&carg0, &carg1, &carg2, &carg3, carg4, len4);

  return Qnil;
}

static VALUE _wrap_hplfun(VALUE self, VALUE arg0, VALUE arg1, VALUE arg3)
{
  int i0, len0;
  float *carg0;
  int i1, len1;
  float *carg1;
  int carg2;
  int len3;
  char *carg3;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  carg2 = len0;
  Check_Type(arg3, T_STRING);
  len3 = RSTRING(arg3)->len;
  carg3 = ALLOCA_N(char, len3 + 1);
  strcpy(carg3, STR2CSTR(arg3));
  hplfun_(carg0, carg1, &carg2, carg3, len3);

  return Qnil;
}

static VALUE _wrap_hplgiv(VALUE self)
{
  float carg0;
  VALUE value0;
  float carg1;
  VALUE value1;
  float carg2;
  VALUE value2;
  float carg3;
  VALUE value3;

  hplgiv_(&carg0, &carg1, &carg2, &carg3);
  value0 = rb_float_new(carg0);
  value1 = rb_float_new(carg1);
  value2 = rb_float_new(carg2);
  value3 = rb_float_new(carg3);

  return rb_ary_new3(4, value0, value1, value2, value3);
}

static VALUE _wrap_hpline(VALUE self, VALUE arg0, VALUE arg1, VALUE arg3)
{
  int i0, len0;
  float *carg0;
  int i1, len1;
  float *carg1;
  int carg2;
  int len3;
  char *carg3;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  carg2 = len0;
  Check_Type(arg3, T_STRING);
  len3 = RSTRING(arg3)->len;
  carg3 = ALLOCA_N(char, len3 + 1);
  strcpy(carg3, STR2CSTR(arg3));
  hpline_(carg0, carg1, &carg2, carg3, len3);

  return Qnil;
}

static VALUE _wrap_hplint(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hplint_(&carg0);

  return Qnil;
}

static VALUE _wrap_hplkey(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  float carg0;
  float carg1;
  int carg2;
  int len3;
  char *carg3;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2INT(arg2);
  Check_Type(arg3, T_STRING);
  len3 = RSTRING(arg3)->len;
  carg3 = ALLOCA_N(char, len3 + 1);
  strcpy(carg3, STR2CSTR(arg3));
  hplkey_(&carg0, &carg1, &carg2, carg3, len3);

  return Qnil;
}

static VALUE _wrap_hplnul(VALUE self)
{

  hplnul_();

  return Qnil;
}

static VALUE _wrap_hploc(VALUE self, VALUE arg0)
{
  int carg0;
  int carg1;
  VALUE value1;
  float carg2;
  VALUE value2;
  float carg3;
  VALUE value3;
  int carg4;
  VALUE value4;
  int carg5;
  VALUE value5;
  int carg6;
  VALUE value6;
  int carg7;
  VALUE value7;

  carg0 = NUM2INT(arg0);
  hploc_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7);
  value1 = INT2NUM(carg1);
  value2 = rb_float_new(carg2);
  value3 = rb_float_new(carg3);
  value4 = INT2NUM(carg4);
  value5 = INT2NUM(carg5);
  value6 = INT2NUM(carg6);
  value7 = INT2NUM(carg7);

  return rb_ary_new3(7, value1, value2, value3, value4, value5, value6, value7);
}

static VALUE _wrap_hplopt(VALUE self, VALUE arg0)
{
  int len0;
  char *carg0;
  int carg1;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(char, 4 * len0 + 1);
  util_str_ary_rb2f(arg0, 4, carg0);
  carg1 = len0;
  hplopt_(carg0, &carg1, 4);

  return Qnil;
}

static VALUE _wrap_hplot(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  int len1;
  char *carg1;
  int len2;
  char *carg2;
  int carg3;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  carg3 = NUM2INT(arg3);
  hplot_(&carg0, carg1, carg2, &carg3, len1, len2);

  return Qnil;
}

static VALUE _wrap_hplpro(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int len1;
  char *carg1;
  int len2;
  char *carg2;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  hplpro_(&carg0, carg1, carg2, len1, len2);

  return Qnil;
}

static VALUE _wrap_hplpto(VALUE self, VALUE arg0)
{
  int len0;
  char *carg0;
  int len1;
  char *carg1;
  VALUE value1;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  len1 = 1024;
  carg1 = ALLOCA_N(char, len1 + 1);
  hplpto_(carg0, carg1, len0, len1);
  len1 = util_str_f2c(carg1, len1);
  value1 = rb_str_new(carg1, len1);

  return value1;
}

static VALUE _wrap_hplset(VALUE self, VALUE arg0, VALUE arg1)
{
  int len0;
  char *carg0;
  float carg1;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  carg1 = NUM2DBL(arg1);
  hplset_(carg0, &carg1, len0);

  return Qnil;
}

static VALUE _wrap_hplsof(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6)
{
  float carg0;
  float carg1;
  int len2;
  char *carg2;
  float carg3;
  float carg4;
  float carg5;
  int carg6;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2INT(arg6);
  hplsof_(&carg0, &carg1, carg2, &carg3, &carg4, &carg5, &carg6, len2);

  return Qnil;
}

static VALUE _wrap_hplsur(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  float carg1;
  float carg2;
  int carg3;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2INT(arg3);
  hplsur_(&carg0, &carg1, &carg2, &carg3);

  return Qnil;
}

static VALUE _wrap_hplsym(VALUE self, VALUE arg0, VALUE arg1, VALUE arg3, VALUE arg4, VALUE arg5)
{
  int i0, len0;
  float *carg0;
  int i1, len1;
  float *carg1;
  int carg2;
  int carg3;
  float carg4;
  int len5;
  char *carg5;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  carg2 = len0;
  carg3 = NUM2INT(arg3);
  carg4 = NUM2DBL(arg4);
  Check_Type(arg5, T_STRING);
  len5 = RSTRING(arg5)->len;
  carg5 = ALLOCA_N(char, len5 + 1);
  strcpy(carg5, STR2CSTR(arg5));
  hplsym_(carg0, carg1, &carg2, &carg3, &carg4, carg5, len5);

  return Qnil;
}

static VALUE _wrap_hpltab(VALUE self, VALUE arg0, VALUE arg2, VALUE arg3)
{
  int carg0;
  int carg1;
  int i2, len2;
  float *carg2;
  int len3;
  char *carg3;

  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = NUM2INT(arg0);
  carg1 = len2;
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  Check_Type(arg3, T_STRING);
  len3 = RSTRING(arg3)->len;
  carg3 = ALLOCA_N(char, len3 + 1);
  strcpy(carg3, STR2CSTR(arg3));
  hpltab_(&carg0, &carg1, carg2, carg3, len3);

  return Qnil;
}

static VALUE _wrap_hpltit(VALUE self, VALUE arg0)
{
  int len0;
  char *carg0;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  hpltit_(carg0, len0);

  return Qnil;
}

static VALUE _wrap_hplwir(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int len0;
  char *carg0;
  float carg1;
  float carg2;
  int len3;
  char *carg3;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  Check_Type(arg3, T_STRING);
  len3 = RSTRING(arg3)->len;
  carg3 = ALLOCA_N(char, len3 + 1);
  strcpy(carg3, STR2CSTR(arg3));
  hplwir_(carg0, &carg1, &carg2, carg3, len0, len3);

  return Qnil;
}

static VALUE _wrap_hplzom(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  int len1;
  char *carg1;
  int carg2;
  int carg3;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  carg3 = NUM2INT(arg3);
  hplzom_(&carg0, carg1, &carg2, &carg3, len1);

  return Qnil;
}

static VALUE _wrap_hplzon(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  int carg1;
  int carg2;
  int len3;
  char *carg3;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  Check_Type(arg3, T_STRING);
  len3 = RSTRING(arg3)->len;
  carg3 = ALLOCA_N(char, len3 + 1);
  strcpy(carg3, STR2CSTR(arg3));
  hplzon_(&carg0, &carg1, &carg2, carg3, len3);

  return Qnil;
}

static VALUE _wrap_hplsiz(int argc, VALUE *argv, VALUE self)
{
  char *opt;
  float xsize, ysize;
  if (argc == 1) {
    opt = STR2CSTR(argv[0]);
    if (strncmp(opt, "r", 1) != 0 && strncmp(opt, "R", 1) != 0)
      rb_raise(rb_eArgError, "wrong # of arguments -- hplsiz('R')/hplsiz(x,y,' ')");
    hplsiz_(&xsize, &ysize, opt, 1);
    return rb_assoc_new(rb_float_new(xsize), rb_float_new(ysize));
  } else if (argc == 3) {
    xsize = NUM2DBL(argv[0]);
    ysize = NUM2DBL(argv[1]);
    opt = STR2CSTR(argv[2]);
    if (strncmp(opt, " ", 1) != 0)
      rb_raise(rb_eArgError, "wrong # of arguments -- hplsiz('R')/hplsiz(x,y,' ')");
    hplsiz_(&xsize, &ysize, opt, 1);
    return Qnil;
  } else {
    rb_raise(rb_eArgError, "wrong # of arguments -- hplsiz('R')/hplsiz(x,y,' ')");
  }
}

#define MAX_NUM_VARIABLES 512
#define MAX_VARNAME_LENGTH 8
#define MAX_TITLE_LENGTH 100

static int get_number_of_ntuple_members(int id)
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
  return nvar;
}

static int current_nt_nvar;

static float uwfunc_hplnt(float *x, int *isel)
{
  int i;
  VALUE result;
  VALUE ary = rb_ary_new2(current_nt_nvar);
  for (i = 0; i < current_nt_nvar; i++)
    rb_ary_store(ary, i, rb_float_new(x[i]));
  result = rb_yield(rb_assoc_new(ary, INT2NUM(*isel)));
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

static VALUE _wrap_hplnt(VALUE self, VALUE id, VALUE flag,
			 VALUE from, VALUE to, VALUE x, VALUE y)
{
  int cid = NUM2INT(id);
  int cflag = NUM2INT(flag);
  int cfrom = NUM2INT(from);
  int cto = NUM2INT(to);
  int cx = NUM2INT(x);
  int cy = NUM2INT(y);
  if (rb_block_given_p()) {
    current_nt_nvar = get_number_of_ntuple_members(cid);
    hplnt_(&cid, &cflag, uwfunc_hplnt, &cfrom, &cto, &cx, &cy);
  } else {
    hplnt_(&cid, &cflag, NULL, &cfrom, &cto, &cx, &cy);
  }
  return Qnil;
}

static VALUE _wrap_hplusr_proc = Qnil;

void hplusr_(int *id, char *chcase, int *kid, int len)
{
  static int call = 0;
  if (! NIL_P(_wrap_hplusr_proc)) {
    if (! call)
      call = rb_intern("call");
    rb_funcall(_wrap_hplusr_proc, call, 3,
	       INT2NUM(*id), rb_str_new(chcase, len), INT2NUM(*kid));
  }
}

static VALUE _wrap_hplusr(VALUE self)
{
  _wrap_hplusr_proc = rb_f_lambda();
  return Qnil;
}

static VALUE _wrap_hplnxt_proc = Qnil;

void hplnxt_()
{
  static int call = 0;
  if (! NIL_P(_wrap_hplnxt_proc)) {
    if (! call)
      call = rb_intern("call");
    rb_funcall(_wrap_hplnxt_proc, call, 0);
  }
}

static VALUE _wrap_hplnxt(VALUE self)
{
  _wrap_hplnxt_proc = rb_f_lambda();
  return Qnil;
}



void Init_hplot()
{
  wrap_mCERN = rb_define_module("CERN");
  wrap_mHPlot = rb_define_module_under(wrap_mCERN, "HPlot");

  rb_define_module_function(wrap_mHPlot, "hplabl", _wrap_hplabl, 2);
  rb_define_module_function(wrap_mHPlot, "hplaer", _wrap_hplaer, 9);
  rb_define_module_function(wrap_mHPlot, "hplarc", _wrap_hplarc, 5);
  rb_define_module_function(wrap_mHPlot, "hplax", _wrap_hplax, 2);
  rb_define_module_function(wrap_mHPlot, "hplbox", _wrap_hplbox, 5);
  rb_define_module_function(wrap_mHPlot, "hplcap", _wrap_hplcap, 1);
  rb_define_module_function(wrap_mHPlot, "hplcom", _wrap_hplcom, 3);
  rb_define_module_function(wrap_mHPlot, "hplcon", _wrap_hplcon, 3);
  rb_define_module_function(wrap_mHPlot, "hpldo", _wrap_hpldo, 1);
  rb_define_module_function(wrap_mHPlot, "hplego", _wrap_hplego, 3);
  rb_define_module_function(wrap_mHPlot, "hplend", _wrap_hplend, 0);
  rb_define_module_function(wrap_mHPlot, "hplerr", _wrap_hplerr, 7);
  rb_define_module_function(wrap_mHPlot, "hplfra", _wrap_hplfra, 5);
  rb_define_module_function(wrap_mHPlot, "hplfun", _wrap_hplfun, 3);
  rb_define_module_function(wrap_mHPlot, "hplgiv", _wrap_hplgiv, 0);
  rb_define_module_function(wrap_mHPlot, "hpline", _wrap_hpline, 3);
  rb_define_module_function(wrap_mHPlot, "hplint", _wrap_hplint, 1);
  rb_define_module_function(wrap_mHPlot, "hplkey", _wrap_hplkey, 4);
  rb_define_module_function(wrap_mHPlot, "hplnul", _wrap_hplnul, 0);
  rb_define_module_function(wrap_mHPlot, "hploc", _wrap_hploc, 1);
  rb_define_module_function(wrap_mHPlot, "hplopt", _wrap_hplopt, 1);
  rb_define_module_function(wrap_mHPlot, "hplot", _wrap_hplot, 4);
  rb_define_module_function(wrap_mHPlot, "hplpro", _wrap_hplpro, 3);
  rb_define_module_function(wrap_mHPlot, "hplpto", _wrap_hplpto, 1);
  rb_define_module_function(wrap_mHPlot, "hplset", _wrap_hplset, 2);
  rb_define_module_function(wrap_mHPlot, "hplsof", _wrap_hplsof, 7);
  rb_define_module_function(wrap_mHPlot, "hplsur", _wrap_hplsur, 4);
  rb_define_module_function(wrap_mHPlot, "hplsym", _wrap_hplsym, 5);
  rb_define_module_function(wrap_mHPlot, "hpltab", _wrap_hpltab, 3);
  rb_define_module_function(wrap_mHPlot, "hpltit", _wrap_hpltit, 1);
  rb_define_module_function(wrap_mHPlot, "hplwir", _wrap_hplwir, 4);
  rb_define_module_function(wrap_mHPlot, "hplzom", _wrap_hplzom, 4);
  rb_define_module_function(wrap_mHPlot, "hplzon", _wrap_hplzon, 4);
  rb_define_module_function(wrap_mHPlot, "hplsiz", _wrap_hplsiz, -1);
  rb_define_module_function(wrap_mHPlot, "hplnt", _wrap_hplnt, 6);
  rb_define_module_function(wrap_mHPlot, "hplusr", _wrap_hplusr, 0);
  rb_define_module_function(wrap_mHPlot, "hplnxt", _wrap_hplnxt, 0);


}
