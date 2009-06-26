#include <ruby.h>
#include "cernlib_util.h"

#define NWPAWC 100000
int pawc_[NWPAWC];

static VALUE wrap_mCERN;
VALUE wrap_mHIGZ;


extern void mzebra_(int*);
extern void mzpaw_(int*, char*, int);
extern void iacwk_(int*);
extern void iclks_();
extern void iclrwk_(int*, int*);
extern void iclwk_(int*);
extern void idawk_(int*);
extern void ifa_(int*, float*, float*);
extern void igarc_(float*, float*, float*, float*, float*, float*);
extern void igaxis_(float*, float*, float*, float*, float*, float*, int*, char*, int);
extern void igbox_(float*, float*, float*, float*);
extern void igend_();
extern void igfbox_(float*, float*, float*, float*, float*, float*, float*, float*);
extern void iginit_(int*);
extern void iglbl_(int*, char*, int);
extern void igloc_(int*, int*, int*, float*, float*, float*, float*);
extern void igloc2_(int*, int*, float*, float*, float*, float*, int*, char*, int);
extern void igmeta_(int*, int*);
extern void igpave_(float*, float*, float*, float*, float*, int*, int*, char*, int);
extern void igpie_(float*, float*, float*, int*, float*, char*, int*, int*, int*, int);
extern void igraph_(int*, float*, float*, char*, int);
extern void igrng_(float*, float*);
extern void igrtoh_(float*, float*, float*, float*, float*, float*);
extern void ightor_(float*, float*, float*, float*, float*, float*);
extern void igsa_(int*);
extern void igset_(char*, float*, int);
extern void igsg_(int*);
extern void igsse_(int*, int*);
extern void igterm_();
extern void igwkty_(int*);
extern void iopks_(int*);
extern void iopwk_(int*, int*, int*);
extern void iml_(int*, float*, float*);
extern void ipl_(int*, float*, float*);
extern void ipm_(int*, float*, float*);
extern void irqlc_(int*, int*, int*, int*, float*, float*);
extern void ischh_(float*);
extern void ischup_(float*, float*);
extern void isclip_(int*);
extern void iscr_(int*, int*, float*, float*, float*);
extern void iselnt_(int*);
extern void isfaci_(int*);
extern void isfais_(int*);
extern void isfasi_(int*);
extern void isln_(int*);
extern void islwsc_(float*);
extern void ismk_(int*);
extern void ismksc_(float*);
extern void isplci_(int*);
extern void ispmci_(int*);
extern void istxal_(int*, int*);
extern void istxci_(int*);
extern void istxfp_(int*, int*);
extern void isvp_(int*, float*, float*, float*, float*);
extern void iswkvp_(int*, float*, float*, float*, float*);
extern void iswkwn_(int*, float*, float*, float*, float*);
extern void iswn_(int*, float*, float*, float*, float*);
extern void itx_(float*, float*, char*, int);
extern void iuwk_(int*, int*);


static VALUE _wrap_mzebra(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  mzebra_(&carg0);

  return Qnil;
}

static VALUE _wrap_mzpaw(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int len1;
  char *carg1;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  mzpaw_(&carg0, carg1, len1);

  return Qnil;
}

static VALUE _wrap_iacwk(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  iacwk_(&carg0);

  return Qnil;
}

static VALUE _wrap_iclks(VALUE self)
{

  iclks_();

  return Qnil;
}

static VALUE _wrap_iclrwk(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  iclrwk_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_iclwk(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  iclwk_(&carg0);

  return Qnil;
}

static VALUE _wrap_idawk(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  idawk_(&carg0);

  return Qnil;
}

static VALUE _wrap_ifa(VALUE self, VALUE arg1, VALUE arg2)
{
  int carg0;
  int i1, len1;
  float *carg1;
  int i2, len2;
  float *carg2;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = len1;
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  ifa_(&carg0, carg1, carg2);

  return Qnil;
}

static VALUE _wrap_igarc(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  igarc_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);

  return Qnil;
}

static VALUE _wrap_igaxis(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;
  int carg6;
  int len7;
  char *carg7;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2INT(arg6);
  Check_Type(arg7, T_STRING);
  len7 = RSTRING(arg7)->len;
  carg7 = ALLOCA_N(char, len7 + 1);
  strcpy(carg7, STR2CSTR(arg7));
  igaxis_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, carg7, len7);

  return Qnil;
}

static VALUE _wrap_igbox(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  igbox_(&carg0, &carg1, &carg2, &carg3);

  return Qnil;
}

static VALUE _wrap_igend(VALUE self)
{

  igend_();

  return Qnil;
}

static VALUE _wrap_igfbox(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;
  float carg6;
  float carg7;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2DBL(arg6);
  carg7 = NUM2DBL(arg7);
  igfbox_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7);

  return Qnil;
}

static VALUE _wrap_iginit(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  iginit_(&carg0);

  return Qnil;
}

static VALUE _wrap_iglbl(VALUE self, VALUE arg1)
{
  int carg0;
  int len1;
  char *carg1;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  carg0 = len1;
  carg1 = ALLOCA_N(char, 32 * len1 + 1);
  util_str_ary_rb2f(arg1, 32, carg1);
  iglbl_(&carg0, carg1, 32);

  return Qnil;
}

static VALUE _wrap_igloc(VALUE self, VALUE arg0)
{
  int carg0;
  int carg1;
  VALUE value1;
  int carg2;
  VALUE value2;
  float carg3;
  VALUE value3;
  float carg4;
  VALUE value4;
  float carg5;
  VALUE value5;
  float carg6;
  VALUE value6;

  carg0 = NUM2INT(arg0);
  igloc_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6);
  value1 = INT2NUM(carg1);
  value2 = INT2NUM(carg2);
  value3 = rb_float_new(carg3);
  value4 = rb_float_new(carg4);
  value5 = rb_float_new(carg5);
  value6 = rb_float_new(carg6);

  return rb_ary_new3(6, value1, value2, value3, value4, value5, value6);
}

static VALUE _wrap_igloc2(VALUE self, VALUE arg0, VALUE arg1, VALUE arg7)
{
  int carg0;
  int carg1;
  VALUE value1;
  float carg2;
  VALUE value2;
  float carg3;
  VALUE value3;
  float carg4;
  VALUE value4;
  float carg5;
  VALUE value5;
  int carg6;
  VALUE value6;
  int len7;
  char *carg7;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  Check_Type(arg7, T_STRING);
  len7 = RSTRING(arg7)->len;
  carg7 = ALLOCA_N(char, len7 + 1);
  strcpy(carg7, STR2CSTR(arg7));
  igloc2_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, carg7, len7);
  value1 = INT2NUM(carg1);
  value2 = rb_float_new(carg2);
  value3 = rb_float_new(carg3);
  value4 = rb_float_new(carg4);
  value5 = rb_float_new(carg5);
  value6 = INT2NUM(carg6);

  return rb_ary_new3(6, value1, value2, value3, value4, value5, value6);
}

static VALUE _wrap_igmeta(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  igmeta_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_igpave(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  int carg5;
  int carg6;
  int len7;
  char *carg7;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2INT(arg5);
  carg6 = NUM2INT(arg6);
  Check_Type(arg7, T_STRING);
  len7 = RSTRING(arg7)->len;
  carg7 = ALLOCA_N(char, len7 + 1);
  strcpy(carg7, STR2CSTR(arg7));
  igpave_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, carg7, len7);

  return Qnil;
}

static VALUE _wrap_igpie(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7, VALUE arg8)
{
  float carg0;
  float carg1;
  float carg2;
  int carg3;
  int i4, len4;
  float *carg4;
  int len5;
  char *carg5;
  int i6, len6, *carg6;
  int i7, len7, *carg7;
  int i8, len8, *carg8;

  Check_Type(arg4, T_ARRAY);
  len4 = RARRAY(arg4)->len;
  Check_Type(arg6, T_ARRAY);
  len6 = RARRAY(arg6)->len;
  Check_Type(arg7, T_ARRAY);
  len7 = RARRAY(arg7)->len;
  Check_Type(arg8, T_ARRAY);
  len8 = RARRAY(arg8)->len;
  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = len4;
  carg4 = ALLOCA_N(float, len4);
  for (i4 = 0; i4 < len4; i4++)
    carg4[i4] = NUM2DBL(RARRAY(arg4)->ptr[i4]);
  Check_Type(arg5, T_STRING);
  len5 = RSTRING(arg5)->len;
  carg5 = ALLOCA_N(char, len5 + 1);
  strcpy(carg5, STR2CSTR(arg5));
  carg6 = ALLOCA_N(int, len6);
  for (i6 = 0; i6 < len6; i6++)
    carg6[i6] = NUM2INT(RARRAY(arg6)->ptr[i6]);
  carg7 = ALLOCA_N(int, len7);
  for (i7 = 0; i7 < len7; i7++)
    carg7[i7] = NUM2INT(RARRAY(arg7)->ptr[i7]);
  carg8 = ALLOCA_N(int, len8);
  for (i8 = 0; i8 < len8; i8++)
    carg8[i8] = NUM2INT(RARRAY(arg8)->ptr[i8]);
  igpie_(&carg0, &carg1, &carg2, &carg3, carg4, carg5, carg6, carg7, carg8, len5);

  return Qnil;
}

static VALUE _wrap_igraph(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  int i1, len1;
  float *carg1;
  int i2, len2;
  float *carg2;
  int len3;
  char *carg3;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = len1;
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  Check_Type(arg3, T_STRING);
  len3 = RSTRING(arg3)->len;
  carg3 = ALLOCA_N(char, len3 + 1);
  strcpy(carg3, STR2CSTR(arg3));
  igraph_(&carg0, carg1, carg2, carg3, len3);

  return Qnil;
}

static VALUE _wrap_igrng(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  float carg1;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  igrng_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_igrtoh(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  VALUE value3;
  float carg4;
  VALUE value4;
  float carg5;
  VALUE value5;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  igrtoh_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value3 = rb_float_new(carg3);
  value4 = rb_float_new(carg4);
  value5 = rb_float_new(carg5);

  return rb_ary_new3(3, value3, value4, value5);
}

static VALUE _wrap_ightor(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  VALUE value3;
  float carg4;
  VALUE value4;
  float carg5;
  VALUE value5;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  ightor_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value3 = rb_float_new(carg3);
  value4 = rb_float_new(carg4);
  value5 = rb_float_new(carg5);

  return rb_ary_new3(3, value3, value4, value5);
}

static VALUE _wrap_igsa(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  igsa_(&carg0);

  return Qnil;
}

static VALUE _wrap_igset(VALUE self, VALUE arg0, VALUE arg1)
{
  int len0;
  char *carg0;
  float carg1;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  carg1 = NUM2DBL(arg1);
  igset_(carg0, &carg1, len0);

  return Qnil;
}

static VALUE _wrap_igsg(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  igsg_(&carg0);

  return Qnil;
}

static VALUE _wrap_igsse(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  igsse_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_igterm(VALUE self)
{

  igterm_();

  return Qnil;
}

static VALUE _wrap_igwkty(VALUE self)
{
  int carg0;
  VALUE value0;

  igwkty_(&carg0);
  value0 = INT2NUM(carg0);

  return value0;
}

static VALUE _wrap_iopks(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  iopks_(&carg0);

  return Qnil;
}

static VALUE _wrap_iopwk(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  int carg2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  iopwk_(&carg0, &carg1, &carg2);

  return Qnil;
}

static VALUE _wrap_iml(VALUE self, VALUE arg1, VALUE arg2)
{
  int carg0;
  int i1, len1;
  float *carg1;
  int i2, len2;
  float *carg2;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = len1;
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  iml_(&carg0, carg1, carg2);

  return Qnil;
}

static VALUE _wrap_ipl(VALUE self, VALUE arg1, VALUE arg2)
{
  int carg0;
  int i1, len1;
  float *carg1;
  int i2, len2;
  float *carg2;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = len1;
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  ipl_(&carg0, carg1, carg2);

  return Qnil;
}

static VALUE _wrap_ipm(VALUE self, VALUE arg1, VALUE arg2)
{
  int carg0;
  int i1, len1;
  float *carg1;
  int i2, len2;
  float *carg2;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = len1;
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  ipm_(&carg0, carg1, carg2);

  return Qnil;
}

static VALUE _wrap_irqlc(VALUE self, VALUE arg0, VALUE arg1, VALUE arg4, VALUE arg5)
{
  int carg0;
  int carg1;
  int carg2;
  VALUE value2;
  int carg3;
  VALUE value3;
  float carg4;
  VALUE value4;
  float carg5;
  VALUE value5;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  irqlc_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value2 = INT2NUM(carg2);
  value3 = INT2NUM(carg3);
  value4 = rb_float_new(carg4);
  value5 = rb_float_new(carg5);

  return rb_ary_new3(4, value2, value3, value4, value5);
}

static VALUE _wrap_ischh(VALUE self, VALUE arg0)
{
  float carg0;

  carg0 = NUM2DBL(arg0);
  ischh_(&carg0);

  return Qnil;
}

static VALUE _wrap_ischup(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  float carg1;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  ischup_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_isclip(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  isclip_(&carg0);

  return Qnil;
}

static VALUE _wrap_iscr(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  int carg0;
  int carg1;
  float carg2;
  float carg3;
  float carg4;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  iscr_(&carg0, &carg1, &carg2, &carg3, &carg4);

  return Qnil;
}

static VALUE _wrap_iselnt(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  iselnt_(&carg0);

  return Qnil;
}

static VALUE _wrap_isfaci(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  isfaci_(&carg0);

  return Qnil;
}

static VALUE _wrap_isfais(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  isfais_(&carg0);

  return Qnil;
}

static VALUE _wrap_isfasi(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  isfasi_(&carg0);

  return Qnil;
}

static VALUE _wrap_isln(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  isln_(&carg0);

  return Qnil;
}

static VALUE _wrap_islwsc(VALUE self, VALUE arg0)
{
  float carg0;

  carg0 = NUM2DBL(arg0);
  islwsc_(&carg0);

  return Qnil;
}

static VALUE _wrap_ismk(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  ismk_(&carg0);

  return Qnil;
}

static VALUE _wrap_ismksc(VALUE self, VALUE arg0)
{
  float carg0;

  carg0 = NUM2DBL(arg0);
  ismksc_(&carg0);

  return Qnil;
}

static VALUE _wrap_isplci(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  isplci_(&carg0);

  return Qnil;
}

static VALUE _wrap_ispmci(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  ispmci_(&carg0);

  return Qnil;
}

static VALUE _wrap_istxal(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  istxal_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_istxci(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  istxci_(&carg0);

  return Qnil;
}

static VALUE _wrap_istxfp(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  istxfp_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_isvp(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  int carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  isvp_(&carg0, &carg1, &carg2, &carg3, &carg4);

  return Qnil;
}

static VALUE _wrap_iswkvp(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  int carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  iswkvp_(&carg0, &carg1, &carg2, &carg3, &carg4);

  return Qnil;
}

static VALUE _wrap_iswkwn(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  int carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  iswkwn_(&carg0, &carg1, &carg2, &carg3, &carg4);

  return Qnil;
}

static VALUE _wrap_iswn(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  int carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  iswn_(&carg0, &carg1, &carg2, &carg3, &carg4);

  return Qnil;
}

static VALUE _wrap_itx(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
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
  itx_(&carg0, &carg1, carg2, len2);

  return Qnil;
}

static VALUE _wrap_iuwk(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  iuwk_(&carg0, &carg1);

  return Qnil;
}



void Init_higz()
{
  wrap_mCERN = rb_define_module("CERN");
  wrap_mHIGZ = rb_define_module_under(wrap_mCERN, "HIGZ");

  rb_define_module_function(wrap_mHIGZ, "mzebra", _wrap_mzebra, 1);
  rb_define_module_function(wrap_mHIGZ, "mzpaw", _wrap_mzpaw, 2);
  rb_define_module_function(wrap_mHIGZ, "iacwk", _wrap_iacwk, 1);
  rb_define_module_function(wrap_mHIGZ, "iclks", _wrap_iclks, 0);
  rb_define_module_function(wrap_mHIGZ, "iclrwk", _wrap_iclrwk, 2);
  rb_define_module_function(wrap_mHIGZ, "iclwk", _wrap_iclwk, 1);
  rb_define_module_function(wrap_mHIGZ, "idawk", _wrap_idawk, 1);
  rb_define_module_function(wrap_mHIGZ, "ifa", _wrap_ifa, 2);
  rb_define_module_function(wrap_mHIGZ, "igarc", _wrap_igarc, 6);
  rb_define_module_function(wrap_mHIGZ, "igaxis", _wrap_igaxis, 8);
  rb_define_module_function(wrap_mHIGZ, "igbox", _wrap_igbox, 4);
  rb_define_module_function(wrap_mHIGZ, "igend", _wrap_igend, 0);
  rb_define_module_function(wrap_mHIGZ, "igfbox", _wrap_igfbox, 8);
  rb_define_module_function(wrap_mHIGZ, "iginit", _wrap_iginit, 1);
  rb_define_module_function(wrap_mHIGZ, "iglbl", _wrap_iglbl, 1);
  rb_define_module_function(wrap_mHIGZ, "igloc", _wrap_igloc, 1);
  rb_define_module_function(wrap_mHIGZ, "igloc2", _wrap_igloc2, 3);
  rb_define_module_function(wrap_mHIGZ, "igmeta", _wrap_igmeta, 2);
  rb_define_module_function(wrap_mHIGZ, "igpave", _wrap_igpave, 8);
  rb_define_module_function(wrap_mHIGZ, "igpie", _wrap_igpie, 8);
  rb_define_module_function(wrap_mHIGZ, "igraph", _wrap_igraph, 3);
  rb_define_module_function(wrap_mHIGZ, "igrng", _wrap_igrng, 2);
  rb_define_module_function(wrap_mHIGZ, "igrtoh", _wrap_igrtoh, 3);
  rb_define_module_function(wrap_mHIGZ, "ightor", _wrap_ightor, 3);
  rb_define_module_function(wrap_mHIGZ, "igsa", _wrap_igsa, 1);
  rb_define_module_function(wrap_mHIGZ, "igset", _wrap_igset, 2);
  rb_define_module_function(wrap_mHIGZ, "igsg", _wrap_igsg, 1);
  rb_define_module_function(wrap_mHIGZ, "igsse", _wrap_igsse, 2);
  rb_define_module_function(wrap_mHIGZ, "igterm", _wrap_igterm, 0);
  rb_define_module_function(wrap_mHIGZ, "igwkty", _wrap_igwkty, 0);
  rb_define_module_function(wrap_mHIGZ, "iopks", _wrap_iopks, 1);
  rb_define_module_function(wrap_mHIGZ, "iopwk", _wrap_iopwk, 3);
  rb_define_module_function(wrap_mHIGZ, "iml", _wrap_iml, 2);
  rb_define_module_function(wrap_mHIGZ, "ipl", _wrap_ipl, 2);
  rb_define_module_function(wrap_mHIGZ, "ipm", _wrap_ipm, 2);
  rb_define_module_function(wrap_mHIGZ, "irqlc", _wrap_irqlc, 4);
  rb_define_module_function(wrap_mHIGZ, "ischh", _wrap_ischh, 1);
  rb_define_module_function(wrap_mHIGZ, "ischup", _wrap_ischup, 2);
  rb_define_module_function(wrap_mHIGZ, "isclip", _wrap_isclip, 1);
  rb_define_module_function(wrap_mHIGZ, "iscr", _wrap_iscr, 5);
  rb_define_module_function(wrap_mHIGZ, "iselnt", _wrap_iselnt, 1);
  rb_define_module_function(wrap_mHIGZ, "isfaci", _wrap_isfaci, 1);
  rb_define_module_function(wrap_mHIGZ, "isfais", _wrap_isfais, 1);
  rb_define_module_function(wrap_mHIGZ, "isfasi", _wrap_isfasi, 1);
  rb_define_module_function(wrap_mHIGZ, "isln", _wrap_isln, 1);
  rb_define_module_function(wrap_mHIGZ, "islwsc", _wrap_islwsc, 1);
  rb_define_module_function(wrap_mHIGZ, "ismk", _wrap_ismk, 1);
  rb_define_module_function(wrap_mHIGZ, "ismksc", _wrap_ismksc, 1);
  rb_define_module_function(wrap_mHIGZ, "isplci", _wrap_isplci, 1);
  rb_define_module_function(wrap_mHIGZ, "ispmci", _wrap_ispmci, 1);
  rb_define_module_function(wrap_mHIGZ, "istxal", _wrap_istxal, 2);
  rb_define_module_function(wrap_mHIGZ, "istxci", _wrap_istxci, 1);
  rb_define_module_function(wrap_mHIGZ, "istxfp", _wrap_istxfp, 2);
  rb_define_module_function(wrap_mHIGZ, "isvp", _wrap_isvp, 5);
  rb_define_module_function(wrap_mHIGZ, "iswkvp", _wrap_iswkvp, 5);
  rb_define_module_function(wrap_mHIGZ, "iswkwn", _wrap_iswkwn, 5);
  rb_define_module_function(wrap_mHIGZ, "iswn", _wrap_iswn, 5);
  rb_define_module_function(wrap_mHIGZ, "itx", _wrap_itx, 3);
  rb_define_module_function(wrap_mHIGZ, "iuwk", _wrap_iuwk, 2);


  rb_define_const(wrap_mHIGZ, "NWPAWC", INT2NUM(NWPAWC));
}
