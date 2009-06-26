#include <ruby.h>
#include "cernlib_util.h"

static VALUE cComplex;
static ID cern_id_new, cern_id_real, cern_id_image;

static VALUE wrap_mCERN;
VALUE wrap_mMathlib;


extern void prmfct_(int*, int*, int*, int*, int*);
extern float rbinom_(float*, int*);
extern double dbinom_(double*, int*);
extern int kbinom_(int*, int*);
extern float atg_(float*, float*);
extern float asinh_(float*);
extern double dasinh_(double*);
extern float rplnml_(float*, int*, float*, int*);
extern double dplnml_(double*, int*, double*, int*);
extern void cplnml_(complex*, complex*, int*, complex*, int*);
extern void wplnml_(dcomplex*, dcomplex*, int*, dcomplex*, int*);
extern void rsrtnt_(int*, int*, float*, float*, float*, float*, float*, float*, int*);
extern void dsrtnt_(int*, int*, double*, double*, double*, double*, double*, double*, int*);
extern void rzerox_(float*, float*, float*, int*, float (*)(float*), int*);
extern double dzerox_(double*, double*, double*, int*, double (*)(double*), int*);
extern void rmullz_(float*, int*, int*, complex*);
extern void dmullz_(double*, int*, int*, dcomplex*);
extern void rrteq3_(float*, float*, float*, float*, float*);
extern void drteq3_(double*, double*, double*, double*, double*);
extern void rrteq4_(float*, float*, float*, float*, complex*, float*, int*);
extern void drteq4_(double*, double*, double*, double*, complex*, double*, int*);
extern void cpolyz_(complex*, int*, int*, complex*, float*);
extern void wpolyz_(dcomplex*, int*, int*, dcomplex*, double*);
extern float erf_(float*);
extern double derf_(double*);
extern float erfc_(float*);
extern double derfc_(double*);
extern float freq_(float*);
extern double dfreq_(double*);
extern float gamma_(float*);
extern double dgamma_(double*);
extern float gammf_(float*);
extern double dgammf_(double*);
extern float algama_(float*);
extern double dlgama_(double*);
extern void cgamma_(complex*, complex*);
extern void wgamma_(dcomplex*, dcomplex*);
extern void clgama_(complex*, complex*);
extern void wlgama_(dcomplex*, dcomplex*);
extern void cclbes_(complex*, complex*, complex*, int*, complex*, complex*, complex*, complex*, complex*, int*, int*, int*, int*);
extern void wclbes_(dcomplex*, dcomplex*, dcomplex*, int*, dcomplex*, dcomplex*, dcomplex*, dcomplex*, dcomplex*, int*, int*, int*, int*);
extern float besj0_(float*);
extern double dbesj0_(double*);
extern float besj1_(float*);
extern double dbesj1_(double*);
extern float besy0_(float*);
extern double dbesy0_(double*);
extern float besy1_(float*);
extern double dbesy1_(double*);
extern float besi0_(float*);
extern double dbesi0_(double*);
extern float ebesi0_(float*);
extern double debsi0_(double*);
extern float besi1_(float*);
extern double dbesi1_(double*);
extern float ebesi1_(float*);
extern double debsi1_(double*);
extern float besk0_(float*);
extern double dbesk0_(double*);
extern float ebesk0_(float*);
extern double debsk0_(double*);
extern float besk1_(float*);
extern double dbesk1_(double*);
extern float ebesk1_(float*);
extern double debsk1_(double*);
extern float rrizet_(float*);
extern double drizet_(double*);
extern float rpsipg_(float*, int*);
extern double dpsipg_(double*, int*);
extern void cpsipg_(complex*, complex*, int*);
extern void wpsipg_(dcomplex*, dcomplex*, int*);
extern void relfun_(float*, float*, float*, float*, float*);
extern void delfun_(double*, double*, double*, double*, double*);
extern void celfun_(complex*, float*, complex*, complex*, complex*);
extern void welfun_(dcomplex*, double*, dcomplex*, dcomplex*, dcomplex*);
extern void cgplg_(complex*, int*, int*, float*);
extern void wgplg_(dcomplex*, int*, int*, double*);
extern float rfrsin_(float*);
extern double dfrsin_(double*);
extern float rfrcos_(float*);
extern double dfrcos_(double*);
extern float rferdr_(float*, int*);
extern double dferdr_(double*, int*);
extern float ratani_(float*);
extern double datani_(double*);
extern float rclaus_(float*);
extern double dclaus_(double*);
extern float bsir4_(float*, int*);
extern double dbsir4_(double*, int*);
extern float bskr4_(float*, int*);
extern double dbskr4_(double*, int*);
extern float ebsir4_(float*, int*);
extern double debir4_(double*, int*);
extern float ebskr4_(float*, int*);
extern double debkr4_(double*, int*);
extern void cwhitm_(complex*, complex*, complex*, complex*);
extern void wwhitm_(dcomplex*, dcomplex*, dcomplex*, dcomplex*);
extern void raslgf_(int*, float*, int*, int*, float*);
extern void daslgf_(int*, double*, int*, int*, double*);
extern float rfconc_(float*, float*, int*);
extern double dfconc_(double*, double*, int*);
extern float rdilog_(float*);
extern double ddilog_(double*);
extern float rgapnc_(float*, float*);
extern double dgapnc_(double*, double*);
extern float rgagnc_(float*, float*);
extern double dgagnc_(double*, double*);
extern void cwerf_(complex*, complex*);
extern void wwerf_(dcomplex*, dcomplex*);
extern float rsinin_(float*);
extern double dsinin_(double*);
extern float rcosin_(float*);
extern double dcosin_(double*);
extern float rexpin_(float*);
extern double dexpin_(double*);
extern float rexpie_(float*);
extern double dexpie_(double*);
extern void cexpin_(complex*, complex*);
extern void wexpin_(dcomplex*, dcomplex*);
extern float rdawsn_(float*);
extern double ddawsn_(double*);
extern float bsir3_(float*, int*);
extern double dbsir3_(double*, int*);
extern float ebsir3_(float*, int*);
extern double debir3_(double*, int*);
extern float bskr3_(float*, int*);
extern double dbskr3_(double*, int*);
extern float ebskr3_(float*, int*);
extern double debkr3_(double*, int*);
extern void bska_(float*, int*, int*, int*, float*);
extern void dbska_(double*, int*, int*, int*, double*);
extern void ebska_(float*, int*, int*, int*, float*);
extern void debka_(double*, int*, int*, int*, double*);
extern float rstrh0_(float*);
extern double dstrh0_(double*);
extern float rstrh1_(float*);
extern double dstrh1_(double*);
extern void rbzejy_(float*, int*, int*, float*, float*);
extern void dbzejy_(double*, int*, int*, double*, double*);
extern float reli1_(float*, float*);
extern double deli1_(double*, double*);
extern float reli2_(float*, float*, float*, float*, int*);
extern double deli2_(double*, double*, double*, double*, int*);
extern float reli3_(float*, float*, float*);
extern double deli3_(double*, double*, double*);
extern float reli1c_(float*);
extern double deli1c_(double*);
extern float reli2c_(float*, float*, float*);
extern double deli2c_(double*, double*, double*);
extern float reli3c_(float*, float*, float*);
extern double deli3c_(double*, double*, double*);
extern float religc_(float*, float*, float*, float*);
extern double deligc_(double*, double*, double*, double*);
extern float reliec_(float*);
extern double deliec_(double*);
extern float relikc_(float*);
extern double delikc_(double*);
extern void celint_(complex*, complex*, float*, float*, float*);
extern void welint_(complex*, dcomplex*, double*, double*, double*);
extern float rtheta_(int*, float*, float*);
extern double dtheta_(int*, double*, double*);
extern float rsimps_(float*, float*, float*, int*);
extern double dsimps_(double*, double*, double*, int*);
extern void radapt_(float (*)(float*), float*, float*, int*, float*, float*, float*, float*);
extern void dadapt_(double (*)(double*), double*, double*, int*, double*, double*, double*, double*);
extern float gauss_(float (*)(float*), float*, float*, float*);
extern double dgauss_(double (*)(double*), double*, double*, double*);
extern float rcauch_(float (*)(float*), float*, float*, float*, float*);
extern double dcauch_(double (*)(double*), double*, double*, double*, double*);
extern float rtrint_(float (*)(float*, float*), int*, int*, float*, float*, float*, float*, float*, float*, float*);
extern double dtrint_(double (*)(double*, double*), int*, int*, double*, double*, double*, double*, double*, double*, double*);
extern void rgs56p_(float (*)(float*), float*, float*, float*, float*);
extern void dgs56p_(double (*)(double*), double*, double*, double*, double*);
extern void traper_(float*, float*, float*, int*, float*, float*, float*, float*);
extern void loren4_(float*, float*, float*);
extern void lorenf_(float*, float*, float*, float*);
extern void lorenb_(float*, float*, float*, float*);
extern float rwig3j_(float*, float*, float*, float*, float*, float*);
extern float rwig6j_(float*, float*, float*, float*, float*, float*);
extern float rwig9j_(float*, float*, float*, float*, float*, float*, float*, float*, float*);
extern float rclebg_(float*, float*, float*, float*, float*, float*);
extern float rracaw_(float*, float*, float*, float*, float*, float*);
extern float rjahnu_(float*, float*, float*, float*, float*, float*);
extern double dwig3j_(double*, double*, double*, double*, double*, double*);
extern double dwig6j_(double*, double*, double*, double*, double*, double*);
extern double dwig9j_(double*, double*, double*, double*, double*, double*, double*, double*, double*);
extern double dclebg_(double*, double*, double*, double*, double*, double*);
extern double dracaw_(double*, double*, double*, double*, double*, double*);
extern double djahnu_(double*, double*, double*, double*, double*, double*);
extern float rdjmnb_(float*, float*, float*, float*);
extern double ddjmnb_(double*, double*, double*, double*);
extern float rndm_(float*);
extern int irndm_(float*);
extern void rdmin_(float*);
extern void rdmout_(float*);
extern void nran_(float*, int*);
extern void nranin_(float*);
extern void nranut_(float*);
extern void ranmar_(float*, int*);
extern void rannor_(float*, float*);
extern void rmarin_(int*, int*, int*);
extern void rmarout_(int*, int*, int*);
extern void ranlux_(float*, int*);
extern void rluxgo_(int*, int*, int*, int*);
extern void rluxat_(int*, int*, int*, int*);
extern void rluxin_(int*);
extern void rluxut_(int*);
extern void rm48_(double*, int*);
extern void rm48in_(int*, int*, int*);
extern void rm48out_(int*, int*, int*);
extern void rnorml_(float*, int*);
extern void ran3d_(float*, float*, float*, float*);
extern void rn3dim_(float*, float*, float*, float*);
extern void rn2dim_(float*, float*, float*);
extern float rngama_(float*);
extern void rnpssn_(float*, int*, int*);
extern void rnpset_(float*);
extern void rnbnml_(int*, float*, int*, int*);
extern void rnmnml_(int*, int*, float*, int*, int*);
extern void rnhpre_(float*, int*);
extern void rnhran_(float*, int*, float*, float*, float*);
extern void hispre_(float*, int*);
extern void hisran_(float*, int*, float*, float*, float*);
extern void funpre_(float (*)(float*), float*, float*, float*);
extern void funran_(float*, float*);
extern void funlxp_(float (*)(float*), float*, float*, float*);
extern void funlux_(float*, float*, int*);
extern void permu_(int*, int*);
extern void permut_(int*, int*, int*);
extern float rvnspc_(float*, float*, float*);
extern double dvnspc_(double*, double*, double*);
extern void cdigam_(complex*, complex*);
extern void wdigam_(dcomplex*, dcomplex*);
extern void clogok_(complex*, complex*, int*, int*);
extern float crit_(complex*, complex*, float*);
extern void csqrtk_(complex*, complex*, int*, int*);
extern void hypgm_(complex*, complex*, complex*, complex*, complex*, float*, int*);
extern void legfn_(complex*, complex*, complex*, complex*, int*, int*);
extern float adigam_(float*);
extern int nic311_(float*);
extern void leg1_();
extern void legor_();
extern void legv_();
extern void legz_();
extern void qfunct_(float*, float*, float*);
extern void dtclgn_(int*, int*, int*, int*, int*, int*, double*, double*, int*);
extern void combi_(int*, int*, int*);


static VALUE _wrap_prmfct(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;
  int i2, *carg2;
  VALUE value2;
  int i3, *carg3;
  VALUE value3;
  int carg4;
  VALUE value4;

  carg1 = NUM2INT(arg1);
  carg0 = NUM2INT(arg0);
  carg2 = ALLOCA_N(int, carg1);
  carg3 = ALLOCA_N(int, carg1);
  prmfct_(&carg0, &carg1, carg2, carg3, &carg4);
  value2 = rb_ary_new2(carg1);
  for (i2 = 0; i2 < carg1; i2++)
    rb_ary_store(value2, i2, INT2NUM(carg2[i2]));
  value3 = rb_ary_new2(carg1);
  for (i3 = 0; i3 < carg1; i3++)
    rb_ary_store(value3, i3, INT2NUM(carg3[i3]));
  value4 = INT2NUM(carg4);

  return rb_ary_new3(3, value2, value3, value4);
}

static VALUE _wrap_rbinom(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  int carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = rbinom_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dbinom(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  int carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = dbinom_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_kbinom(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;
  int ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  ret = kbinom_(&carg0, &carg1);
  value = INT2NUM(ret);

  return value;
}

static VALUE _wrap_atg(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  float carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  ret = atg_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_asinh(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = asinh_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dasinh(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dasinh_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rplnml(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  float carg0;
  int carg1;
  int i2, len2;
  float *carg2;
  int carg3;
  float ret;
  VALUE value;

  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  carg3 = NUM2INT(arg3);
  ret = rplnml_(&carg0, &carg1, carg2, &carg3);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dplnml(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  double carg0;
  int carg1;
  int i2, len2;
  double *carg2;
  int carg3;
  double ret;
  VALUE value;

  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = ALLOCA_N(double, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  carg3 = NUM2INT(arg3);
  ret = dplnml_(&carg0, &carg1, carg2, &carg3);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_cplnml(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  complex carg0;
  int carg1;
  int i2, len2;
  complex *carg2;
  int carg3;
  complex ret;
  VALUE value;

  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1 = NUM2INT(arg1);
  carg2 = ALLOCA_N(complex, len2);
  for (i2 = 0; i2 < len2; i2++) {
    carg2[i2].r = NUM2DBL(rb_funcall(RARRAY(arg2)->ptr[i2], cern_id_real, 0));
    carg2[i2].i = NUM2DBL(rb_funcall(RARRAY(arg2)->ptr[i2], cern_id_image, 0));
  }
  carg3 = NUM2INT(arg3);
  cplnml_(&ret, &carg0, &carg1, carg2, &carg3);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_wplnml(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  dcomplex carg0;
  int carg1;
  int i2, len2;
  dcomplex *carg2;
  int carg3;
  dcomplex ret;
  VALUE value;

  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1 = NUM2INT(arg1);
  carg2 = ALLOCA_N(dcomplex, len2);
  for (i2 = 0; i2 < len2; i2++) {
    carg2[i2].r = NUM2DBL(rb_funcall(RARRAY(arg2)->ptr[i2], cern_id_real, 0));
    carg2[i2].i = NUM2DBL(rb_funcall(RARRAY(arg2)->ptr[i2], cern_id_image, 0));
  }
  carg3 = NUM2INT(arg3);
  wplnml_(&ret, &carg0, &carg1, carg2, &carg3);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_rsrtnt(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6)
{
  int carg0;
  int carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;
  float carg6;
  float carg7;
  VALUE value7;
  int carg8;
  VALUE value8;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2DBL(arg6);
  rsrtnt_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7, &carg8);
  value7 = rb_float_new(carg7);
  value8 = carg8 ? Qtrue : Qfalse;

  return rb_assoc_new(value7, value8);
}

static VALUE _wrap_dsrtnt(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6)
{
  int carg0;
  int carg1;
  double carg2;
  double carg3;
  double carg4;
  double carg5;
  double carg6;
  double carg7;
  VALUE value7;
  int carg8;
  VALUE value8;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2DBL(arg6);
  dsrtnt_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7, &carg8);
  value7 = rb_float_new(carg7);
  value8 = carg8 ? Qtrue : Qfalse;

  return rb_assoc_new(value7, value8);
}

static VALUE _wrap_rzerox(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg5)
{
  float carg0;
  float carg1;
  float carg2;
  int carg3;
  float (*carg4)(float*);
  int carg5;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2INT(arg3);
  carg4 = float_callback_float;
  carg5 = NUM2INT(arg5);
  rzerox_(&carg0, &carg1, &carg2, &carg3, carg4, &carg5);

  return Qnil;
}

static VALUE _wrap_dzerox(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg5)
{
  double carg0;
  double carg1;
  double carg2;
  int carg3;
  double (*carg4)(double*);
  int carg5;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2INT(arg3);
  carg4 = double_callback_double;
  carg5 = NUM2INT(arg5);
  ret = dzerox_(&carg0, &carg1, &carg2, &carg3, carg4, &carg5);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rmullz(VALUE self, VALUE arg0, VALUE arg2)
{
  int i0, len0;
  float *carg0;
  int carg1;
  int carg2;
  int i3;
  complex *carg3;
  VALUE value3;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = len0 - 1;
  carg2 = NUM2INT(arg2);
  carg3 = ALLOCA_N(complex, carg1);
  rmullz_(carg0, &carg1, &carg2, carg3);
  value3 = rb_ary_new2(carg1);
  for (i3 = 0; i3 < carg1; i3++)
    rb_ary_store(value3, i3, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg3[i3].r), rb_float_new(carg3[i3].i)));

  return value3;
}

static VALUE _wrap_dmullz(VALUE self, VALUE arg0, VALUE arg2)
{
  int i0, len0;
  double *carg0;
  int carg1;
  int carg2;
  int i3;
  dcomplex *carg3;
  VALUE value3;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(double, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = len0 - 1;
  carg2 = NUM2INT(arg2);
  carg3 = ALLOCA_N(dcomplex, carg1);
  dmullz_(carg0, &carg1, &carg2, carg3);
  value3 = rb_ary_new2(carg1);
  for (i3 = 0; i3 < carg1; i3++)
    rb_ary_store(value3, i3, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg3[i3].r), rb_float_new(carg3[i3].i)));

  return value3;
}

static VALUE _wrap_rrteq3(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  float carg0;
  float carg1;
  float carg2;
  int i3;
  float *carg3;
  VALUE value3;
  float carg4;
  VALUE value4;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = ALLOCA_N(float, 3);
  rrteq3_(&carg0, &carg1, &carg2, carg3, &carg4);
  value3 = rb_ary_new2(3);
  for (i3 = 0; i3 < 3; i3++)
    rb_ary_store(value3, i3, rb_float_new(carg3[i3]));
  value4 = rb_float_new(carg4);

  return rb_assoc_new(value3, value4);
}

static VALUE _wrap_drteq3(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  double carg0;
  double carg1;
  double carg2;
  int i3;
  double *carg3;
  VALUE value3;
  double carg4;
  VALUE value4;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = ALLOCA_N(double, 3);
  drteq3_(&carg0, &carg1, &carg2, carg3, &carg4);
  value3 = rb_ary_new2(3);
  for (i3 = 0; i3 < 3; i3++)
    rb_ary_store(value3, i3, rb_float_new(carg3[i3]));
  value4 = rb_float_new(carg4);

  return rb_assoc_new(value3, value4);
}

static VALUE _wrap_rrteq4(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  int i4;
  complex *carg4;
  VALUE value4;
  float carg5;
  VALUE value5;
  int carg6;
  VALUE value6;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = ALLOCA_N(complex, 4);
  rrteq4_(&carg0, &carg1, &carg2, &carg3, carg4, &carg5, &carg6);
  value4 = rb_ary_new2(4);
  for (i4 = 0; i4 < 4; i4++)
    rb_ary_store(value4, i4, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg4[i4].r), rb_float_new(carg4[i4].i)));
  value5 = rb_float_new(carg5);
  value6 = INT2NUM(carg6);

  return rb_ary_new3(3, value4, value5, value6);
}

static VALUE _wrap_drteq4(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  double carg0;
  double carg1;
  double carg2;
  double carg3;
  int i4;
  complex *carg4;
  VALUE value4;
  double carg5;
  VALUE value5;
  int carg6;
  VALUE value6;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = ALLOCA_N(complex, 4);
  drteq4_(&carg0, &carg1, &carg2, &carg3, carg4, &carg5, &carg6);
  value4 = rb_ary_new2(4);
  for (i4 = 0; i4 < 4; i4++)
    rb_ary_store(value4, i4, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg4[i4].r), rb_float_new(carg4[i4].i)));
  value5 = rb_float_new(carg5);
  value6 = INT2NUM(carg6);

  return rb_ary_new3(3, value4, value5, value6);
}

static VALUE _wrap_cpolyz(VALUE self, VALUE arg0, VALUE arg2, VALUE arg3)
{
  int i0, len0;
  complex *carg0;
  int carg1;
  int carg2;
  int i3, len3;
  complex *carg3;
  VALUE value3;
  float carg4;
  VALUE value4;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  Check_Type(arg3, T_ARRAY);
  len3 = RARRAY(arg3)->len;
  carg0 = ALLOCA_N(complex, len0);
  for (i0 = 0; i0 < len0; i0++) {
    carg0[i0].r = NUM2DBL(rb_funcall(RARRAY(arg0)->ptr[i0], cern_id_real, 0));
    carg0[i0].i = NUM2DBL(rb_funcall(RARRAY(arg0)->ptr[i0], cern_id_image, 0));
  }
  carg1 = len0 - 1;
  carg2 = NUM2INT(arg2);
  carg3 = ALLOCA_N(complex, len3);
  for (i3 = 0; i3 < len3; i3++) {
    carg3[i3].r = NUM2DBL(rb_funcall(RARRAY(arg3)->ptr[i3], cern_id_real, 0));
    carg3[i3].i = NUM2DBL(rb_funcall(RARRAY(arg3)->ptr[i3], cern_id_image, 0));
  }
  cpolyz_(carg0, &carg1, &carg2, carg3, &carg4);
  value3 = rb_ary_new2(len3);
  for (i3 = 0; i3 < len3; i3++)
    rb_ary_store(value3, i3, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg3[i3].r), rb_float_new(carg3[i3].i)));
  value4 = rb_float_new(carg4);

  return rb_assoc_new(value3, value4);
}

static VALUE _wrap_wpolyz(VALUE self, VALUE arg0, VALUE arg2, VALUE arg3)
{
  int i0, len0;
  dcomplex *carg0;
  int carg1;
  int carg2;
  int i3, len3;
  dcomplex *carg3;
  VALUE value3;
  int i4;
  double *carg4;
  VALUE value4;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  Check_Type(arg3, T_ARRAY);
  len3 = RARRAY(arg3)->len;
  carg0 = ALLOCA_N(dcomplex, len0);
  for (i0 = 0; i0 < len0; i0++) {
    carg0[i0].r = NUM2DBL(rb_funcall(RARRAY(arg0)->ptr[i0], cern_id_real, 0));
    carg0[i0].i = NUM2DBL(rb_funcall(RARRAY(arg0)->ptr[i0], cern_id_image, 0));
  }
  carg1 = len0 - 1;
  carg2 = NUM2INT(arg2);
  carg3 = ALLOCA_N(dcomplex, len3);
  for (i3 = 0; i3 < len3; i3++) {
    carg3[i3].r = NUM2DBL(rb_funcall(RARRAY(arg3)->ptr[i3], cern_id_real, 0));
    carg3[i3].i = NUM2DBL(rb_funcall(RARRAY(arg3)->ptr[i3], cern_id_image, 0));
  }
  carg4 = ALLOCA_N(double, carg1);
  wpolyz_(carg0, &carg1, &carg2, carg3, carg4);
  value3 = rb_ary_new2(len3);
  for (i3 = 0; i3 < len3; i3++)
    rb_ary_store(value3, i3, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg3[i3].r), rb_float_new(carg3[i3].i)));
  value4 = rb_ary_new2(carg1);
  for (i4 = 0; i4 < carg1; i4++)
    rb_ary_store(value4, i4, rb_float_new(carg4[i4]));

  return rb_assoc_new(value3, value4);
}

static VALUE _wrap_erf(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = erf_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_derf(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = derf_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_erfc(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = erfc_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_derfc(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = derfc_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_freq(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = freq_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dfreq(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dfreq_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_gamma(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = gamma_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dgamma(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dgamma_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_gammf(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = gammf_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dgammf(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dgammf_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_algama(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = algama_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dlgama(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dlgama_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_cgamma(VALUE self, VALUE arg0)
{
  complex carg0;
  complex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  cgamma_(&ret, &carg0);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_wgamma(VALUE self, VALUE arg0)
{
  dcomplex carg0;
  dcomplex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  wgamma_(&ret, &carg0);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_clgama(VALUE self, VALUE arg0)
{
  complex carg0;
  complex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  clgama_(&ret, &carg0);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_wlgama(VALUE self, VALUE arg0)
{
  dcomplex carg0;
  dcomplex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  wlgama_(&ret, &carg0);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_cclbes(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg9, VALUE arg10, VALUE arg12)
{
  complex carg0;
  complex carg1;
  complex carg2;
  int carg3;
  int i4;
  complex *carg4;
  VALUE value4;
  int i5;
  complex *carg5;
  VALUE value5;
  int i6;
  complex *carg6;
  VALUE value6;
  int i7;
  complex *carg7;
  VALUE value7;
  int i8;
  complex *carg8;
  VALUE value8;
  int carg9;
  int carg10;
  int carg11;
  VALUE value11;
  int carg12;

  carg3 = NUM2INT(arg3);
  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1.r = NUM2DBL(rb_funcall(arg1, cern_id_real, 0));
  carg1.i = NUM2DBL(rb_funcall(arg1, cern_id_image, 0));
  carg2.r = NUM2DBL(rb_funcall(arg2, cern_id_real, 0));
  carg2.i = NUM2DBL(rb_funcall(arg2, cern_id_image, 0));
  carg9 = NUM2INT(arg9);
  carg10 = NUM2INT(arg10);
  carg12 = NUM2INT(arg12);
  carg4 = ALLOCA_N(complex, carg3 + 1);
  carg5 = ALLOCA_N(complex, carg3 + 1);
  carg6 = ALLOCA_N(complex, carg3 + 1);
  carg7 = ALLOCA_N(complex, carg3 + 1);
  carg8 = ALLOCA_N(complex, carg3 + 1);
  cclbes_(&carg0, &carg1, &carg2, &carg3, carg4, carg5, carg6, carg7, carg8, &carg9, &carg10, &carg11, &carg12);
  value4 = rb_ary_new2(carg3 + 1);
  for (i4 = 0; i4 < carg3 + 1; i4++)
    rb_ary_store(value4, i4, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg4[i4].r), rb_float_new(carg4[i4].i)));
  value5 = rb_ary_new2(carg3 + 1);
  for (i5 = 0; i5 < carg3 + 1; i5++)
    rb_ary_store(value5, i5, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg5[i5].r), rb_float_new(carg5[i5].i)));
  value6 = rb_ary_new2(carg3 + 1);
  for (i6 = 0; i6 < carg3 + 1; i6++)
    rb_ary_store(value6, i6, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg6[i6].r), rb_float_new(carg6[i6].i)));
  value7 = rb_ary_new2(carg3 + 1);
  for (i7 = 0; i7 < carg3 + 1; i7++)
    rb_ary_store(value7, i7, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg7[i7].r), rb_float_new(carg7[i7].i)));
  value8 = rb_ary_new2(carg3 + 1);
  for (i8 = 0; i8 < carg3 + 1; i8++)
    rb_ary_store(value8, i8, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg8[i8].r), rb_float_new(carg8[i8].i)));
  value11 = INT2NUM(carg11);

  return rb_ary_new3(6, value4, value5, value6, value7, value8, value11);
}

static VALUE _wrap_wclbes(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg9, VALUE arg10, VALUE arg12)
{
  dcomplex carg0;
  dcomplex carg1;
  dcomplex carg2;
  int carg3;
  int i4;
  dcomplex *carg4;
  VALUE value4;
  int i5;
  dcomplex *carg5;
  VALUE value5;
  int i6;
  dcomplex *carg6;
  VALUE value6;
  int i7;
  dcomplex *carg7;
  VALUE value7;
  int i8;
  dcomplex *carg8;
  VALUE value8;
  int carg9;
  int carg10;
  int carg11;
  VALUE value11;
  int carg12;

  carg3 = NUM2INT(arg3);
  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1.r = NUM2DBL(rb_funcall(arg1, cern_id_real, 0));
  carg1.i = NUM2DBL(rb_funcall(arg1, cern_id_image, 0));
  carg2.r = NUM2DBL(rb_funcall(arg2, cern_id_real, 0));
  carg2.i = NUM2DBL(rb_funcall(arg2, cern_id_image, 0));
  carg9 = NUM2INT(arg9);
  carg10 = NUM2INT(arg10);
  carg12 = NUM2INT(arg12);
  carg4 = ALLOCA_N(dcomplex, carg3 + 1);
  carg5 = ALLOCA_N(dcomplex, carg3 + 1);
  carg6 = ALLOCA_N(dcomplex, carg3 + 1);
  carg7 = ALLOCA_N(dcomplex, carg3 + 1);
  carg8 = ALLOCA_N(dcomplex, carg3 + 1);
  wclbes_(&carg0, &carg1, &carg2, &carg3, carg4, carg5, carg6, carg7, carg8, &carg9, &carg10, &carg11, &carg12);
  value4 = rb_ary_new2(carg3 + 1);
  for (i4 = 0; i4 < carg3 + 1; i4++)
    rb_ary_store(value4, i4, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg4[i4].r), rb_float_new(carg4[i4].i)));
  value5 = rb_ary_new2(carg3 + 1);
  for (i5 = 0; i5 < carg3 + 1; i5++)
    rb_ary_store(value5, i5, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg5[i5].r), rb_float_new(carg5[i5].i)));
  value6 = rb_ary_new2(carg3 + 1);
  for (i6 = 0; i6 < carg3 + 1; i6++)
    rb_ary_store(value6, i6, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg6[i6].r), rb_float_new(carg6[i6].i)));
  value7 = rb_ary_new2(carg3 + 1);
  for (i7 = 0; i7 < carg3 + 1; i7++)
    rb_ary_store(value7, i7, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg7[i7].r), rb_float_new(carg7[i7].i)));
  value8 = rb_ary_new2(carg3 + 1);
  for (i8 = 0; i8 < carg3 + 1; i8++)
    rb_ary_store(value8, i8, rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg8[i8].r), rb_float_new(carg8[i8].i)));
  value11 = INT2NUM(carg11);

  return rb_ary_new3(6, value4, value5, value6, value7, value8, value11);
}

static VALUE _wrap_besj0(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = besj0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dbesj0(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dbesj0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_besj1(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = besj1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dbesj1(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dbesj1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_besy0(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = besy0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dbesy0(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dbesy0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_besy1(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = besy1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dbesy1(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dbesy1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_besi0(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = besi0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dbesi0(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dbesi0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_ebesi0(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = ebesi0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_debsi0(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = debsi0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_besi1(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = besi1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dbesi1(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dbesi1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_ebesi1(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = ebesi1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_debsi1(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = debsi1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_besk0(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = besk0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dbesk0(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dbesk0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_ebesk0(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = ebesk0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_debsk0(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = debsk0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_besk1(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = besk1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dbesk1(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dbesk1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_ebesk1(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = ebesk1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_debsk1(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = debsk1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rrizet(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rrizet_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_drizet(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = drizet_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rpsipg(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  int carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = rpsipg_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dpsipg(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  int carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = dpsipg_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_cpsipg(VALUE self, VALUE arg0, VALUE arg1)
{
  complex carg0;
  int carg1;
  complex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1 = NUM2INT(arg1);
  cpsipg_(&ret, &carg0, &carg1);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_wpsipg(VALUE self, VALUE arg0, VALUE arg1)
{
  dcomplex carg0;
  int carg1;
  dcomplex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1 = NUM2INT(arg1);
  wpsipg_(&ret, &carg0, &carg1);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_relfun(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  float carg1;
  float carg2;
  VALUE value2;
  float carg3;
  VALUE value3;
  float carg4;
  VALUE value4;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  relfun_(&carg0, &carg1, &carg2, &carg3, &carg4);
  value2 = rb_float_new(carg2);
  value3 = rb_float_new(carg3);
  value4 = rb_float_new(carg4);

  return rb_ary_new3(3, value2, value3, value4);
}

static VALUE _wrap_delfun(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  double carg1;
  double carg2;
  VALUE value2;
  double carg3;
  VALUE value3;
  double carg4;
  VALUE value4;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  delfun_(&carg0, &carg1, &carg2, &carg3, &carg4);
  value2 = rb_float_new(carg2);
  value3 = rb_float_new(carg3);
  value4 = rb_float_new(carg4);

  return rb_ary_new3(3, value2, value3, value4);
}

static VALUE _wrap_celfun(VALUE self, VALUE arg0, VALUE arg1)
{
  complex carg0;
  float carg1;
  complex carg2;
  VALUE value2;
  complex carg3;
  VALUE value3;
  complex carg4;
  VALUE value4;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1 = NUM2DBL(arg1);
  celfun_(&carg0, &carg1, &carg2, &carg3, &carg4);
  value2 = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg2.r), rb_float_new(carg2.i));
  value3 = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg3.r), rb_float_new(carg3.i));
  value4 = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg4.r), rb_float_new(carg4.i));

  return rb_ary_new3(3, value2, value3, value4);
}

static VALUE _wrap_welfun(VALUE self, VALUE arg0, VALUE arg1)
{
  dcomplex carg0;
  double carg1;
  dcomplex carg2;
  VALUE value2;
  dcomplex carg3;
  VALUE value3;
  dcomplex carg4;
  VALUE value4;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1 = NUM2DBL(arg1);
  welfun_(&carg0, &carg1, &carg2, &carg3, &carg4);
  value2 = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg2.r), rb_float_new(carg2.i));
  value3 = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg3.r), rb_float_new(carg3.i));
  value4 = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg4.r), rb_float_new(carg4.i));

  return rb_ary_new3(3, value2, value3, value4);
}

static VALUE _wrap_cgplg(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  float carg2;
  complex ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2DBL(arg2);
  cgplg_(&ret, &carg0, &carg1, &carg2);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_wgplg(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  double carg2;
  dcomplex ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2DBL(arg2);
  wgplg_(&ret, &carg0, &carg1, &carg2);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_rfrsin(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rfrsin_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dfrsin(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dfrsin_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rfrcos(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rfrcos_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dfrcos(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dfrcos_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rferdr(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  int carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = rferdr_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dferdr(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  int carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = dferdr_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_ratani(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = ratani_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_datani(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = datani_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rclaus(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rclaus_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dclaus(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dclaus_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_bsir4(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  int carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = bsir4_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dbsir4(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  int carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = dbsir4_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_bskr4(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  int carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = bskr4_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dbskr4(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  int carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = dbskr4_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_ebsir4(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  int carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = ebsir4_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_debir4(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  int carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = debir4_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_ebskr4(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  int carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = ebskr4_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_debkr4(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  int carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = debkr4_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_cwhitm(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  complex carg0;
  complex carg1;
  complex carg2;
  complex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1.r = NUM2DBL(rb_funcall(arg1, cern_id_real, 0));
  carg1.i = NUM2DBL(rb_funcall(arg1, cern_id_image, 0));
  carg2.r = NUM2DBL(rb_funcall(arg2, cern_id_real, 0));
  carg2.i = NUM2DBL(rb_funcall(arg2, cern_id_image, 0));
  cwhitm_(&ret, &carg0, &carg1, &carg2);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_wwhitm(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  dcomplex carg0;
  dcomplex carg1;
  dcomplex carg2;
  dcomplex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1.r = NUM2DBL(rb_funcall(arg1, cern_id_real, 0));
  carg1.i = NUM2DBL(rb_funcall(arg1, cern_id_image, 0));
  carg2.r = NUM2DBL(rb_funcall(arg2, cern_id_real, 0));
  carg2.i = NUM2DBL(rb_funcall(arg2, cern_id_image, 0));
  wwhitm_(&ret, &carg0, &carg1, &carg2);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_raslgf(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  float carg1;
  int carg2;
  int carg3;
  int i4;
  float *carg4;
  VALUE value4;

  carg3 = NUM2INT(arg3);
  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2INT(arg2);
  carg4 = ALLOCA_N(float, carg3 + 1);
  raslgf_(&carg0, &carg1, &carg2, &carg3, carg4);
  value4 = rb_ary_new2(carg3 + 1);
  for (i4 = 0; i4 < carg3 + 1; i4++)
    rb_ary_store(value4, i4, rb_float_new(carg4[i4]));

  return value4;
}

static VALUE _wrap_daslgf(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  double carg1;
  int carg2;
  int carg3;
  int i4;
  double *carg4;
  VALUE value4;

  carg3 = NUM2INT(arg3);
  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2INT(arg2);
  carg4 = ALLOCA_N(double, carg3 + 1);
  daslgf_(&carg0, &carg1, &carg2, &carg3, carg4);
  value4 = rb_ary_new2(carg3 + 1);
  for (i4 = 0; i4 < carg3 + 1; i4++)
    rb_ary_store(value4, i4, rb_float_new(carg4[i4]));

  return value4;
}

static VALUE _wrap_rfconc(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  float carg0;
  float carg1;
  int carg2;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2INT(arg2);
  ret = rfconc_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dfconc(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  double carg0;
  double carg1;
  int carg2;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2INT(arg2);
  ret = dfconc_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rdilog(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rdilog_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_ddilog(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = ddilog_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rgapnc(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  float carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  ret = rgapnc_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dgapnc(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  double carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  ret = dgapnc_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rgagnc(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  float carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  ret = rgagnc_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dgagnc(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  double carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  ret = dgagnc_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_cwerf(VALUE self, VALUE arg0)
{
  complex carg0;
  complex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  cwerf_(&ret, &carg0);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_wwerf(VALUE self, VALUE arg0)
{
  dcomplex carg0;
  dcomplex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  wwerf_(&ret, &carg0);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_rsinin(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rsinin_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dsinin(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dsinin_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rcosin(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rcosin_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dcosin(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dcosin_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rexpin(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rexpin_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dexpin(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dexpin_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rexpie(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rexpie_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dexpie(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dexpie_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_cexpin(VALUE self, VALUE arg0)
{
  complex carg0;
  complex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  cexpin_(&ret, &carg0);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_wexpin(VALUE self, VALUE arg0)
{
  dcomplex carg0;
  dcomplex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  wexpin_(&ret, &carg0);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_rdawsn(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rdawsn_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_ddawsn(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = ddawsn_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_bsir3(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  int carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = bsir3_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dbsir3(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  int carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = dbsir3_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_ebsir3(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  int carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = ebsir3_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_debir3(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  int carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = debir3_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_bskr3(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  int carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = bskr3_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dbskr3(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  int carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = dbskr3_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_ebskr3(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  int carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = ebskr3_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_debkr3(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  int carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  ret = debkr3_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_bska(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  float carg0;
  int carg1;
  int carg2;
  int carg3;
  int i4;
  float *carg4;
  VALUE value4;

  carg3 = NUM2INT(arg3);
  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  carg4 = ALLOCA_N(float, carg3 + 1);
  bska_(&carg0, &carg1, &carg2, &carg3, carg4);
  value4 = rb_ary_new2(carg3 + 1);
  for (i4 = 0; i4 < carg3 + 1; i4++)
    rb_ary_store(value4, i4, rb_float_new(carg4[i4]));

  return value4;
}

static VALUE _wrap_dbska(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  double carg0;
  int carg1;
  int carg2;
  int carg3;
  int i4;
  double *carg4;
  VALUE value4;

  carg3 = NUM2INT(arg3);
  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  carg4 = ALLOCA_N(double, carg3 + 1);
  dbska_(&carg0, &carg1, &carg2, &carg3, carg4);
  value4 = rb_ary_new2(carg3 + 1);
  for (i4 = 0; i4 < carg3 + 1; i4++)
    rb_ary_store(value4, i4, rb_float_new(carg4[i4]));

  return value4;
}

static VALUE _wrap_ebska(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  float carg0;
  int carg1;
  int carg2;
  int carg3;
  int i4;
  float *carg4;
  VALUE value4;

  carg3 = NUM2INT(arg3);
  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  carg4 = ALLOCA_N(float, carg3 + 1);
  ebska_(&carg0, &carg1, &carg2, &carg3, carg4);
  value4 = rb_ary_new2(carg3 + 1);
  for (i4 = 0; i4 < carg3 + 1; i4++)
    rb_ary_store(value4, i4, rb_float_new(carg4[i4]));

  return value4;
}

static VALUE _wrap_debka(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  double carg0;
  int carg1;
  int carg2;
  int carg3;
  int i4;
  double *carg4;
  VALUE value4;

  carg3 = NUM2INT(arg3);
  carg0 = NUM2DBL(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  carg4 = ALLOCA_N(double, carg3 + 1);
  debka_(&carg0, &carg1, &carg2, &carg3, carg4);
  value4 = rb_ary_new2(carg3 + 1);
  for (i4 = 0; i4 < carg3 + 1; i4++)
    rb_ary_store(value4, i4, rb_float_new(carg4[i4]));

  return value4;
}

static VALUE _wrap_rstrh0(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rstrh0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dstrh0(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dstrh0_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rstrh1(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rstrh1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dstrh1(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = dstrh1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rbzejy(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  float carg0;
  int carg1;
  int carg2;
  float carg3;
  int i4;
  float *carg4;
  VALUE value4;

  carg1 = NUM2INT(arg1);
  carg0 = NUM2DBL(arg0);
  carg2 = NUM2INT(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = ALLOCA_N(float, carg1);
  rbzejy_(&carg0, &carg1, &carg2, &carg3, carg4);
  value4 = rb_ary_new2(carg1);
  for (i4 = 0; i4 < carg1; i4++)
    rb_ary_store(value4, i4, rb_float_new(carg4[i4]));

  return value4;
}

static VALUE _wrap_dbzejy(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  double carg0;
  int carg1;
  int carg2;
  double carg3;
  int i4;
  double *carg4;
  VALUE value4;

  carg1 = NUM2INT(arg1);
  carg0 = NUM2DBL(arg0);
  carg2 = NUM2INT(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = ALLOCA_N(double, carg1);
  dbzejy_(&carg0, &carg1, &carg2, &carg3, carg4);
  value4 = rb_ary_new2(carg1);
  for (i4 = 0; i4 < carg1; i4++)
    rb_ary_store(value4, i4, rb_float_new(carg4[i4]));

  return value4;
}

static VALUE _wrap_reli1(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  float carg1;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  ret = reli1_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_deli1(VALUE self, VALUE arg0, VALUE arg1)
{
  double carg0;
  double carg1;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  ret = deli1_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_reli2(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  int carg4;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2INT(arg4);
  ret = reli2_(&carg0, &carg1, &carg2, &carg3, &carg4);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_deli2(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  double carg0;
  double carg1;
  double carg2;
  double carg3;
  int carg4;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2INT(arg4);
  ret = deli2_(&carg0, &carg1, &carg2, &carg3, &carg4);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_reli3(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  float carg0;
  float carg1;
  float carg2;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  ret = reli3_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_deli3(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  double carg0;
  double carg1;
  double carg2;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  ret = deli3_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_reli1c(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = reli1c_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_deli1c(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = deli1c_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_reli2c(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  float carg0;
  float carg1;
  float carg2;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  ret = reli2c_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_deli2c(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  double carg0;
  double carg1;
  double carg2;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  ret = deli2c_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_reli3c(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  float carg0;
  float carg1;
  float carg2;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  ret = reli3c_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_deli3c(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  double carg0;
  double carg1;
  double carg2;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  ret = deli3c_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_religc(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  ret = religc_(&carg0, &carg1, &carg2, &carg3);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_deligc(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  double carg0;
  double carg1;
  double carg2;
  double carg3;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  ret = deligc_(&carg0, &carg1, &carg2, &carg3);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_reliec(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = reliec_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_deliec(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = deliec_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_relikc(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = relikc_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_delikc(VALUE self, VALUE arg0)
{
  double carg0;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = delikc_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_celint(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  complex carg0;
  float carg1;
  float carg2;
  float carg3;
  complex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  celint_(&ret, &carg0, &carg1, &carg2, &carg3);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_welint(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  dcomplex carg0;
  double carg1;
  double carg2;
  double carg3;
  complex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  welint_(&ret, &carg0, &carg1, &carg2, &carg3);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_rtheta(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  float carg1;
  float carg2;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  ret = rtheta_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dtheta(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  double carg1;
  double carg2;
  double ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  ret = dtheta_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rsimps(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int i0, len0;
  float *carg0;
  float carg1;
  float carg2;
  int carg3;
  float ret;
  VALUE value;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = len0 - 1;
  ret = rsimps_(carg0, &carg1, &carg2, &carg3);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dsimps(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int i0, len0;
  double *carg0;
  double carg1;
  double carg2;
  int carg3;
  double ret;
  VALUE value;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(double, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = len0 - 1;
  ret = dsimps_(carg0, &carg1, &carg2, &carg3);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_radapt(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  float (*carg0)(float*);
  float carg1;
  float carg2;
  int carg3;
  float carg4;
  float carg5;
  float carg6;
  VALUE value6;
  float carg7;
  VALUE value7;

  carg0 = float_callback_float;
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2INT(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  radapt_(carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7);
  value6 = rb_float_new(carg6);
  value7 = rb_float_new(carg7);

  return rb_assoc_new(value6, value7);
}

static VALUE _wrap_dadapt(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  double (*carg0)(double*);
  double carg1;
  double carg2;
  int carg3;
  double carg4;
  double carg5;
  double carg6;
  VALUE value6;
  double carg7;
  VALUE value7;

  carg0 = double_callback_double;
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2INT(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  dadapt_(carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7);
  value6 = rb_float_new(carg6);
  value7 = rb_float_new(carg7);

  return rb_assoc_new(value6, value7);
}

static VALUE _wrap_gauss(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3)
{
  float (*carg0)(float*);
  float carg1;
  float carg2;
  float carg3;
  float ret;
  VALUE value;

  carg0 = float_callback_float;
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  ret = gauss_(carg0, &carg1, &carg2, &carg3);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dgauss(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3)
{
  double (*carg0)(double*);
  double carg1;
  double carg2;
  double carg3;
  double ret;
  VALUE value;

  carg0 = double_callback_double;
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  ret = dgauss_(carg0, &carg1, &carg2, &carg3);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rcauch(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  float (*carg0)(float*);
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  float ret;
  VALUE value;

  carg0 = float_callback_float;
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  ret = rcauch_(carg0, &carg1, &carg2, &carg3, &carg4);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dcauch(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  double (*carg0)(double*);
  double carg1;
  double carg2;
  double carg3;
  double carg4;
  double ret;
  VALUE value;

  carg0 = double_callback_double;
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  ret = dcauch_(carg0, &carg1, &carg2, &carg3, &carg4);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rtrint(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7, VALUE arg8, VALUE arg9)
{
  float (*carg0)(float*, float*);
  int carg1;
  int carg2;
  float carg3;
  float carg4;
  float carg5;
  float carg6;
  float carg7;
  float carg8;
  float carg9;
  float ret;
  VALUE value;

  carg0 = float_callback_float_float;
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2DBL(arg6);
  carg7 = NUM2DBL(arg7);
  carg8 = NUM2DBL(arg8);
  carg9 = NUM2DBL(arg9);
  ret = rtrint_(carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7, &carg8, &carg9);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dtrint(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7, VALUE arg8, VALUE arg9)
{
  double (*carg0)(double*, double*);
  int carg1;
  int carg2;
  double carg3;
  double carg4;
  double carg5;
  double carg6;
  double carg7;
  double carg8;
  double carg9;
  double ret;
  VALUE value;

  carg0 = double_callback_double_double;
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2DBL(arg6);
  carg7 = NUM2DBL(arg7);
  carg8 = NUM2DBL(arg8);
  carg9 = NUM2DBL(arg9);
  ret = dtrint_(carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7, &carg8, &carg9);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rgs56p(VALUE self, VALUE arg1, VALUE arg2)
{
  float (*carg0)(float*);
  float carg1;
  float carg2;
  float carg3;
  VALUE value3;
  float carg4;
  VALUE value4;

  carg0 = float_callback_float;
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  rgs56p_(carg0, &carg1, &carg2, &carg3, &carg4);
  value3 = rb_float_new(carg3);
  value4 = rb_float_new(carg4);

  return rb_assoc_new(value3, value4);
}

static VALUE _wrap_dgs56p(VALUE self, VALUE arg1, VALUE arg2)
{
  double (*carg0)(double*);
  double carg1;
  double carg2;
  double carg3;
  VALUE value3;
  double carg4;
  VALUE value4;

  carg0 = double_callback_double;
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  dgs56p_(carg0, &carg1, &carg2, &carg3, &carg4);
  value3 = rb_float_new(carg3);
  value4 = rb_float_new(carg4);

  return rb_assoc_new(value3, value4);
}

static VALUE _wrap_traper(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg4, VALUE arg5)
{
  int i0, len0;
  float *carg0;
  int i1, len1;
  float *carg1;
  int i2, len2;
  float *carg2;
  int carg3;
  float carg4;
  float carg5;
  float carg6;
  VALUE value6;
  float carg7;
  VALUE value7;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  carg3 = len0;
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  traper_(carg0, carg1, carg2, &carg3, &carg4, &carg5, &carg6, &carg7);
  value6 = rb_float_new(carg6);
  value7 = rb_float_new(carg7);

  return rb_assoc_new(value6, value7);
}

static VALUE _wrap_loren4(VALUE self, VALUE arg0, VALUE arg1)
{
  int i0, len0;
  float *carg0;
  int i1, len1;
  float *carg1;
  int i2;
  float *carg2;
  VALUE value2;

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
  carg2 = ALLOCA_N(float, 4);
  loren4_(carg0, carg1, carg2);
  value2 = rb_ary_new2(4);
  for (i2 = 0; i2 < 4; i2++)
    rb_ary_store(value2, i2, rb_float_new(carg2[i2]));

  return value2;
}

static VALUE _wrap_lorenf(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  float carg0;
  int i1, len1;
  float *carg1;
  int i2, len2;
  float *carg2;
  int i3;
  float *carg3;
  VALUE value3;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = NUM2DBL(arg0);
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  carg3 = ALLOCA_N(float, 4);
  lorenf_(&carg0, carg1, carg2, carg3);
  value3 = rb_ary_new2(4);
  for (i3 = 0; i3 < 4; i3++)
    rb_ary_store(value3, i3, rb_float_new(carg3[i3]));

  return value3;
}

static VALUE _wrap_lorenb(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  float carg0;
  int i1, len1;
  float *carg1;
  int i2, len2;
  float *carg2;
  int i3;
  float *carg3;
  VALUE value3;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = NUM2DBL(arg0);
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  carg3 = ALLOCA_N(float, 4);
  lorenb_(&carg0, carg1, carg2, carg3);
  value3 = rb_ary_new2(4);
  for (i3 = 0; i3 < 4; i3++)
    rb_ary_store(value3, i3, rb_float_new(carg3[i3]));

  return value3;
}

static VALUE _wrap_rwig3j(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  ret = rwig3j_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rwig6j(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  ret = rwig6j_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rwig9j(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7, VALUE arg8)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;
  float carg6;
  float carg7;
  float carg8;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2DBL(arg6);
  carg7 = NUM2DBL(arg7);
  carg8 = NUM2DBL(arg8);
  ret = rwig9j_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7, &carg8);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rclebg(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  ret = rclebg_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rracaw(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  ret = rracaw_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rjahnu(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  ret = rjahnu_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dwig3j(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  double carg0;
  double carg1;
  double carg2;
  double carg3;
  double carg4;
  double carg5;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  ret = dwig3j_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dwig6j(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  double carg0;
  double carg1;
  double carg2;
  double carg3;
  double carg4;
  double carg5;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  ret = dwig6j_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dwig9j(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7, VALUE arg8)
{
  double carg0;
  double carg1;
  double carg2;
  double carg3;
  double carg4;
  double carg5;
  double carg6;
  double carg7;
  double carg8;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2DBL(arg6);
  carg7 = NUM2DBL(arg7);
  carg8 = NUM2DBL(arg8);
  ret = dwig9j_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7, &carg8);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dclebg(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  double carg0;
  double carg1;
  double carg2;
  double carg3;
  double carg4;
  double carg5;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  ret = dclebg_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dracaw(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  double carg0;
  double carg1;
  double carg2;
  double carg3;
  double carg4;
  double carg5;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  ret = dracaw_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_djahnu(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  double carg0;
  double carg1;
  double carg2;
  double carg3;
  double carg4;
  double carg5;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  ret = djahnu_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rdjmnb(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  ret = rdjmnb_(&carg0, &carg1, &carg2, &carg3);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_ddjmnb(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  double carg0;
  double carg1;
  double carg2;
  double carg3;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  ret = ddjmnb_(&carg0, &carg1, &carg2, &carg3);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rndm(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rndm_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_irndm(VALUE self, VALUE arg0)
{
  float carg0;
  int ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = irndm_(&carg0);
  value = INT2NUM(ret);

  return value;
}

static VALUE _wrap_rdmin(VALUE self, VALUE arg0)
{
  float carg0;

  carg0 = NUM2DBL(arg0);
  rdmin_(&carg0);

  return Qnil;
}

static VALUE _wrap_rdmout(VALUE self)
{
  float carg0;
  VALUE value0;

  rdmout_(&carg0);
  value0 = rb_float_new(carg0);

  return value0;
}

static VALUE _wrap_nran(VALUE self, VALUE arg1)
{
  int i0;
  float *carg0;
  VALUE value0;
  int carg1;

  carg1 = NUM2INT(arg1);
  carg0 = ALLOCA_N(float, carg1);
  nran_(carg0, &carg1);
  value0 = rb_ary_new2(carg1);
  for (i0 = 0; i0 < carg1; i0++)
    rb_ary_store(value0, i0, rb_float_new(carg0[i0]));

  return value0;
}

static VALUE _wrap_nranin(VALUE self, VALUE arg0)
{
  float carg0;

  carg0 = NUM2DBL(arg0);
  nranin_(&carg0);

  return Qnil;
}

static VALUE _wrap_nranut(VALUE self)
{
  float carg0;
  VALUE value0;

  nranut_(&carg0);
  value0 = rb_float_new(carg0);

  return value0;
}

static VALUE _wrap_ranmar(VALUE self, VALUE arg1)
{
  int i0;
  float *carg0;
  VALUE value0;
  int carg1;

  carg1 = NUM2INT(arg1);
  carg0 = ALLOCA_N(float, carg1);
  ranmar_(carg0, &carg1);
  value0 = rb_ary_new2(carg1);
  for (i0 = 0; i0 < carg1; i0++)
    rb_ary_store(value0, i0, rb_float_new(carg0[i0]));

  return value0;
}

static VALUE _wrap_rannor(VALUE self)
{
  float carg0;
  VALUE value0;
  float carg1;
  VALUE value1;

  rannor_(&carg0, &carg1);
  value0 = rb_float_new(carg0);
  value1 = rb_float_new(carg1);

  return rb_assoc_new(value0, value1);
}

static VALUE _wrap_rmarin(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  int carg2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  rmarin_(&carg0, &carg1, &carg2);

  return Qnil;
}

static VALUE _wrap_rmarout(VALUE self)
{
  int carg0;
  VALUE value0;
  int carg1;
  VALUE value1;
  int carg2;
  VALUE value2;

  rmarout_(&carg0, &carg1, &carg2);
  value0 = INT2NUM(carg0);
  value1 = INT2NUM(carg1);
  value2 = INT2NUM(carg2);

  return rb_ary_new3(3, value0, value1, value2);
}

static VALUE _wrap_ranlux(VALUE self, VALUE arg1)
{
  int i0;
  float *carg0;
  VALUE value0;
  int carg1;

  carg1 = NUM2INT(arg1);
  carg0 = ALLOCA_N(float, carg1);
  ranlux_(carg0, &carg1);
  value0 = rb_ary_new2(carg1);
  for (i0 = 0; i0 < carg1; i0++)
    rb_ary_store(value0, i0, rb_float_new(carg0[i0]));

  return value0;
}

static VALUE _wrap_rluxgo(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  int carg1;
  int carg2;
  int carg3;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  carg3 = NUM2INT(arg3);
  rluxgo_(&carg0, &carg1, &carg2, &carg3);

  return Qnil;
}

static VALUE _wrap_rluxat(VALUE self)
{
  int carg0;
  VALUE value0;
  int carg1;
  VALUE value1;
  int carg2;
  VALUE value2;
  int carg3;
  VALUE value3;

  rluxat_(&carg0, &carg1, &carg2, &carg3);
  value0 = INT2NUM(carg0);
  value1 = INT2NUM(carg1);
  value2 = INT2NUM(carg2);
  value3 = INT2NUM(carg3);

  return rb_ary_new3(4, value0, value1, value2, value3);
}

static VALUE _wrap_rluxin(VALUE self, VALUE arg0)
{
  int i0, len0, *carg0;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(int, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2INT(RARRAY(arg0)->ptr[i0]);
  rluxin_(carg0);

  return Qnil;
}

static VALUE _wrap_rluxut(VALUE self)
{
  int i0, *carg0;
  VALUE value0;

  carg0 = ALLOCA_N(int, 25);
  rluxut_(carg0);
  value0 = rb_ary_new2(25);
  for (i0 = 0; i0 < 25; i0++)
    rb_ary_store(value0, i0, INT2NUM(carg0[i0]));

  return value0;
}

static VALUE _wrap_rm48(VALUE self, VALUE arg1)
{
  int i0;
  double *carg0;
  VALUE value0;
  int carg1;

  carg1 = NUM2INT(arg1);
  carg0 = ALLOCA_N(double, carg1);
  rm48_(carg0, &carg1);
  value0 = rb_ary_new2(carg1);
  for (i0 = 0; i0 < carg1; i0++)
    rb_ary_store(value0, i0, rb_float_new(carg0[i0]));

  return value0;
}

static VALUE _wrap_rm48in(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  int carg2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  rm48in_(&carg0, &carg1, &carg2);

  return Qnil;
}

static VALUE _wrap_rm48out(VALUE self)
{
  int carg0;
  VALUE value0;
  int carg1;
  VALUE value1;
  int carg2;
  VALUE value2;

  rm48out_(&carg0, &carg1, &carg2);
  value0 = INT2NUM(carg0);
  value1 = INT2NUM(carg1);
  value2 = INT2NUM(carg2);

  return rb_ary_new3(3, value0, value1, value2);
}

static VALUE _wrap_rnorml(VALUE self, VALUE arg1)
{
  int i0;
  float *carg0;
  VALUE value0;
  int carg1;

  carg1 = NUM2INT(arg1);
  carg0 = ALLOCA_N(float, carg1);
  rnorml_(carg0, &carg1);
  value0 = rb_ary_new2(carg1);
  for (i0 = 0; i0 < carg1; i0++)
    rb_ary_store(value0, i0, rb_float_new(carg0[i0]));

  return value0;
}

static VALUE _wrap_ran3d(VALUE self, VALUE arg3)
{
  float carg0;
  VALUE value0;
  float carg1;
  VALUE value1;
  float carg2;
  VALUE value2;
  float carg3;

  carg3 = NUM2DBL(arg3);
  ran3d_(&carg0, &carg1, &carg2, &carg3);
  value0 = rb_float_new(carg0);
  value1 = rb_float_new(carg1);
  value2 = rb_float_new(carg2);

  return rb_ary_new3(3, value0, value1, value2);
}

static VALUE _wrap_rn3dim(VALUE self, VALUE arg3)
{
  float carg0;
  VALUE value0;
  float carg1;
  VALUE value1;
  float carg2;
  VALUE value2;
  float carg3;

  carg3 = NUM2DBL(arg3);
  rn3dim_(&carg0, &carg1, &carg2, &carg3);
  value0 = rb_float_new(carg0);
  value1 = rb_float_new(carg1);
  value2 = rb_float_new(carg2);

  return rb_ary_new3(3, value0, value1, value2);
}

static VALUE _wrap_rn2dim(VALUE self, VALUE arg2)
{
  float carg0;
  VALUE value0;
  float carg1;
  VALUE value1;
  float carg2;

  carg2 = NUM2DBL(arg2);
  rn2dim_(&carg0, &carg1, &carg2);
  value0 = rb_float_new(carg0);
  value1 = rb_float_new(carg1);

  return rb_assoc_new(value0, value1);
}

static VALUE _wrap_rngama(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = rngama_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_rnpssn(VALUE self, VALUE arg0)
{
  float carg0;
  int carg1;
  VALUE value1;
  int carg2;
  VALUE value2;

  carg0 = NUM2DBL(arg0);
  rnpssn_(&carg0, &carg1, &carg2);
  value1 = INT2NUM(carg1);
  value2 = INT2NUM(carg2);

  return rb_assoc_new(value1, value2);
}

static VALUE _wrap_rnpset(VALUE self, VALUE arg0)
{
  float carg0;

  carg0 = NUM2DBL(arg0);
  rnpset_(&carg0);

  return Qnil;
}

static VALUE _wrap_rnbnml(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  float carg1;
  int carg2;
  VALUE value2;
  int carg3;
  VALUE value3;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  rnbnml_(&carg0, &carg1, &carg2, &carg3);
  value2 = INT2NUM(carg2);
  value3 = INT2NUM(carg3);

  return rb_assoc_new(value2, value3);
}

static VALUE _wrap_rnmnml(VALUE self, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  int i2, len2;
  float *carg2;
  int i3, *carg3;
  VALUE value3;
  int carg4;
  VALUE value4;

  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = len2;
  carg1 = NUM2INT(arg1);
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  carg3 = ALLOCA_N(int, carg0);
  rnmnml_(&carg0, &carg1, carg2, carg3, &carg4);
  value3 = rb_ary_new2(carg0);
  for (i3 = 0; i3 < carg0; i3++)
    rb_ary_store(value3, i3, INT2NUM(carg3[i3]));
  value4 = INT2NUM(carg4);

  return rb_assoc_new(value3, value4);
}

static VALUE _wrap_rnhpre(VALUE self, VALUE arg0)
{
  int i0, len0;
  float *carg0;
  int carg1;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = len0;
  rnhpre_(carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_rnhran(VALUE self, VALUE arg0, VALUE arg2, VALUE arg3)
{
  int i0, len0;
  float *carg0;
  int carg1;
  float carg2;
  float carg3;
  float carg4;
  VALUE value4;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = len0;
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  rnhran_(carg0, &carg1, &carg2, &carg3, &carg4);
  value4 = rb_float_new(carg4);

  return value4;
}

static VALUE _wrap_hispre(VALUE self, VALUE arg0)
{
  int i0, len0;
  float *carg0;
  int carg1;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = len0;
  hispre_(carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_hisran(VALUE self, VALUE arg0, VALUE arg2, VALUE arg3)
{
  int i0, len0;
  float *carg0;
  int carg1;
  float carg2;
  float carg3;
  float carg4;
  VALUE value4;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = len0;
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  hisran_(carg0, &carg1, &carg2, &carg3, &carg4);
  value4 = rb_float_new(carg4);

  return value4;
}

static VALUE _wrap_funpre(VALUE self, VALUE arg2, VALUE arg3)
{
  float (*carg0)(float*);
  int i1;
  float *carg1;
  VALUE value1;
  float carg2;
  float carg3;

  carg0 = float_callback_float;
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg1 = ALLOCA_N(float, 100);
  funpre_(carg0, carg1, &carg2, &carg3);
  value1 = rb_ary_new2(100);
  for (i1 = 0; i1 < 100; i1++)
    rb_ary_store(value1, i1, rb_float_new(carg1[i1]));

  return value1;
}

static VALUE _wrap_funran(VALUE self, VALUE arg0)
{
  int i0, len0;
  float *carg0;
  float carg1;
  VALUE value1;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  funran_(carg0, &carg1);
  value1 = rb_float_new(carg1);

  return value1;
}

static VALUE _wrap_funlxp(VALUE self, VALUE arg2, VALUE arg3)
{
  float (*carg0)(float*);
  int i1;
  float *carg1;
  VALUE value1;
  float carg2;
  float carg3;

  carg0 = float_callback_float;
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg1 = ALLOCA_N(float, 200);
  funlxp_(carg0, carg1, &carg2, &carg3);
  value1 = rb_ary_new2(200);
  for (i1 = 0; i1 < 200; i1++)
    rb_ary_store(value1, i1, rb_float_new(carg1[i1]));

  return value1;
}

static VALUE _wrap_funlux(VALUE self, VALUE arg0, VALUE arg2)
{
  int i0, len0;
  float *carg0;
  int i1;
  float *carg1;
  VALUE value1;
  int carg2;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg2 = NUM2INT(arg2);
  carg0 = ALLOCA_N(float, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2DBL(RARRAY(arg0)->ptr[i0]);
  carg1 = ALLOCA_N(float, carg2);
  funlux_(carg0, carg1, &carg2);
  value1 = rb_ary_new2(carg2);
  for (i1 = 0; i1 < carg2; i1++)
    rb_ary_store(value1, i1, rb_float_new(carg1[i1]));

  return value1;
}

static VALUE _wrap_permu(VALUE self, VALUE arg0)
{
  int i0, *carg0, len0;
  VALUE value0;
  int carg1;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(int, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2INT(RARRAY(arg0)->ptr[i0]);
  carg1 = len0;
  permu_(carg0, &carg1);
  value0 = rb_ary_new2(len0);
  for (i0 = 0; i0 < len0; i0++)
    rb_ary_store(value0, i0, INT2NUM(carg0[i0]));

  return value0;
}

static VALUE _wrap_permut(VALUE self, VALUE arg0, VALUE arg2)
{
  int carg0;
  int carg1;
  int i2, *carg2, len2;
  VALUE value2;

  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = NUM2INT(arg0);
  carg1 = len2;
  carg2 = ALLOCA_N(int, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2INT(RARRAY(arg2)->ptr[i2]);
  permut_(&carg0, &carg1, carg2);
  value2 = rb_ary_new2(len2);
  for (i2 = 0; i2 < len2; i2++)
    rb_ary_store(value2, i2, INT2NUM(carg2[i2]));

  return value2;
}

static VALUE _wrap_rvnspc(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  float carg0;
  float carg1;
  float carg2;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  ret = rvnspc_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_dvnspc(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  double carg0;
  double carg1;
  double carg2;
  double ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  ret = dvnspc_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_cdigam(VALUE self, VALUE arg0)
{
  complex carg0;
  complex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  cdigam_(&ret, &carg0);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_wdigam(VALUE self, VALUE arg0)
{
  dcomplex carg0;
  dcomplex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  wdigam_(&ret, &carg0);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_clogok(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  complex carg0;
  int carg1;
  int carg2;
  complex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  clogok_(&ret, &carg0, &carg1, &carg2);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_crit(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  complex carg0;
  complex carg1;
  float carg2;
  float ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1.r = NUM2DBL(rb_funcall(arg1, cern_id_real, 0));
  carg1.i = NUM2DBL(rb_funcall(arg1, cern_id_image, 0));
  carg2 = NUM2DBL(arg2);
  ret = crit_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_csqrtk(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  complex carg0;
  int carg1;
  int carg2;
  complex ret;
  VALUE value;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  csqrtk_(&ret, &carg0, &carg1, &carg2);
  value = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(ret.r), rb_float_new(ret.i));

  return value;
}

static VALUE _wrap_hypgm(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg5)
{
  complex carg0;
  complex carg1;
  complex carg2;
  complex carg3;
  complex carg4;
  VALUE value4;
  float carg5;
  int carg6;
  VALUE value6;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1.r = NUM2DBL(rb_funcall(arg1, cern_id_real, 0));
  carg1.i = NUM2DBL(rb_funcall(arg1, cern_id_image, 0));
  carg2.r = NUM2DBL(rb_funcall(arg2, cern_id_real, 0));
  carg2.i = NUM2DBL(rb_funcall(arg2, cern_id_image, 0));
  carg3.r = NUM2DBL(rb_funcall(arg3, cern_id_real, 0));
  carg3.i = NUM2DBL(rb_funcall(arg3, cern_id_image, 0));
  carg5 = NUM2DBL(arg5);
  hypgm_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6);
  value4 = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg4.r), rb_float_new(carg4.i));
  value6 = INT2NUM(carg6);

  return rb_assoc_new(value4, value6);
}

static VALUE _wrap_legfn(VALUE self, VALUE arg0, VALUE arg1, VALUE arg5)
{
  complex carg0;
  complex carg1;
  complex carg2;
  VALUE value2;
  complex carg3;
  VALUE value3;
  int carg4;
  VALUE value4;
  int carg5;

  carg0.r = NUM2DBL(rb_funcall(arg0, cern_id_real, 0));
  carg0.i = NUM2DBL(rb_funcall(arg0, cern_id_image, 0));
  carg1.r = NUM2DBL(rb_funcall(arg1, cern_id_real, 0));
  carg1.i = NUM2DBL(rb_funcall(arg1, cern_id_image, 0));
  carg5 = NUM2INT(arg5);
  legfn_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5);
  value2 = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg2.r), rb_float_new(carg2.i));
  value3 = rb_funcall(cComplex, cern_id_new, 2, rb_float_new(carg3.r), rb_float_new(carg3.i));
  value4 = INT2NUM(carg4);

  return rb_ary_new3(3, value2, value3, value4);
}

static VALUE _wrap_adigam(VALUE self, VALUE arg0)
{
  float carg0;
  float ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = adigam_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_nic311(VALUE self, VALUE arg0)
{
  float carg0;
  int ret;
  VALUE value;

  carg0 = NUM2DBL(arg0);
  ret = nic311_(&carg0);
  value = INT2NUM(ret);

  return value;
}

static VALUE _wrap_leg1(VALUE self)
{

  leg1_();

  return Qnil;
}

static VALUE _wrap_legor(VALUE self)
{

  legor_();

  return Qnil;
}

static VALUE _wrap_legv(VALUE self)
{

  legv_();

  return Qnil;
}

static VALUE _wrap_legz(VALUE self)
{

  legz_();

  return Qnil;
}

static VALUE _wrap_qfunct(VALUE self, VALUE arg0)
{
  float carg0;
  float carg1;
  VALUE value1;
  float carg2;
  VALUE value2;

  carg0 = NUM2DBL(arg0);
  qfunct_(&carg0, &carg1, &carg2);
  value1 = rb_float_new(carg1);
  value2 = rb_float_new(carg2);

  return rb_assoc_new(value1, value2);
}

static VALUE _wrap_dtclgn(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  int carg0;
  int carg1;
  int carg2;
  int carg3;
  int carg4;
  int carg5;
  double carg6;
  VALUE value6;
  double carg7;
  VALUE value7;
  int i8, *carg8;
  VALUE value8;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  carg3 = NUM2INT(arg3);
  carg4 = NUM2INT(arg4);
  carg5 = NUM2INT(arg5);
  carg8 = ALLOCA_N(int, 40);
  dtclgn_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7, carg8);
  value6 = rb_float_new(carg6);
  value7 = rb_float_new(carg7);
  value8 = rb_ary_new2(40);
  for (i8 = 0; i8 < 40; i8++)
    rb_ary_store(value8, i8, INT2NUM(carg8[i8]));

  return rb_ary_new3(3, value6, value7, value8);
}

static VALUE _wrap_combi(VALUE self, VALUE ary, VALUE set)
{
  VALUE value;
  int i, *cary, len;
  int cset = NUM2INT(set);

  Check_Type(ary, T_ARRAY);
  len = RARRAY(ary)->len;
  cary = ALLOCA_N(int, cset + 1);
  for (i = 0; i < len; i++)
    cary[i] = NUM2INT(RARRAY(ary)->ptr[i]);
  combi_(cary, &cset, &len);
  value = rb_ary_new2(len);
  for (i = 0; i < len; i++)
    rb_ary_store(value, i, INT2NUM(cary[i]));

  return value;
}



void Init_mathlib()
{
  rb_require("complex");
  cComplex = rb_const_get(rb_mKernel, rb_intern("Complex"));

  cern_id_new = rb_intern("new");
  cern_id_real = rb_intern("real");
  cern_id_image = rb_intern("image");

  wrap_mCERN = rb_define_module("CERN");
  wrap_mMathlib = rb_define_module_under(wrap_mCERN, "Mathlib");

  rb_define_module_function(wrap_mMathlib, "prmfct", _wrap_prmfct, 2);
  rb_define_module_function(wrap_mMathlib, "rbinom", _wrap_rbinom, 2);
  rb_define_module_function(wrap_mMathlib, "dbinom", _wrap_dbinom, 2);
  rb_define_module_function(wrap_mMathlib, "kbinom", _wrap_kbinom, 2);
  rb_define_module_function(wrap_mMathlib, "atg", _wrap_atg, 2);
  rb_define_module_function(wrap_mMathlib, "asinh", _wrap_asinh, 1);
  rb_define_module_function(wrap_mMathlib, "dasinh", _wrap_dasinh, 1);
  rb_define_module_function(wrap_mMathlib, "rplnml", _wrap_rplnml, 4);
  rb_define_module_function(wrap_mMathlib, "dplnml", _wrap_dplnml, 4);
  rb_define_module_function(wrap_mMathlib, "cplnml", _wrap_cplnml, 4);
  rb_define_module_function(wrap_mMathlib, "wplnml", _wrap_wplnml, 4);
  rb_define_module_function(wrap_mMathlib, "rsrtnt", _wrap_rsrtnt, 7);
  rb_define_module_function(wrap_mMathlib, "dsrtnt", _wrap_dsrtnt, 7);
  rb_define_module_function(wrap_mMathlib, "rzerox", _wrap_rzerox, 5);
  rb_define_module_function(wrap_mMathlib, "dzerox", _wrap_dzerox, 5);
  rb_define_module_function(wrap_mMathlib, "rmullz", _wrap_rmullz, 2);
  rb_define_module_function(wrap_mMathlib, "dmullz", _wrap_dmullz, 2);
  rb_define_module_function(wrap_mMathlib, "rrteq3", _wrap_rrteq3, 3);
  rb_define_module_function(wrap_mMathlib, "drteq3", _wrap_drteq3, 3);
  rb_define_module_function(wrap_mMathlib, "rrteq4", _wrap_rrteq4, 4);
  rb_define_module_function(wrap_mMathlib, "drteq4", _wrap_drteq4, 4);
  rb_define_module_function(wrap_mMathlib, "cpolyz", _wrap_cpolyz, 3);
  rb_define_module_function(wrap_mMathlib, "wpolyz", _wrap_wpolyz, 3);
  rb_define_module_function(wrap_mMathlib, "erf", _wrap_erf, 1);
  rb_define_module_function(wrap_mMathlib, "derf", _wrap_derf, 1);
  rb_define_module_function(wrap_mMathlib, "erfc", _wrap_erfc, 1);
  rb_define_module_function(wrap_mMathlib, "derfc", _wrap_derfc, 1);
  rb_define_module_function(wrap_mMathlib, "freq", _wrap_freq, 1);
  rb_define_module_function(wrap_mMathlib, "dfreq", _wrap_dfreq, 1);
  rb_define_module_function(wrap_mMathlib, "gamma", _wrap_gamma, 1);
  rb_define_module_function(wrap_mMathlib, "dgamma", _wrap_dgamma, 1);
  rb_define_module_function(wrap_mMathlib, "gammf", _wrap_gammf, 1);
  rb_define_module_function(wrap_mMathlib, "dgammf", _wrap_dgammf, 1);
  rb_define_module_function(wrap_mMathlib, "algama", _wrap_algama, 1);
  rb_define_module_function(wrap_mMathlib, "dlgama", _wrap_dlgama, 1);
  rb_define_module_function(wrap_mMathlib, "cgamma", _wrap_cgamma, 1);
  rb_define_module_function(wrap_mMathlib, "wgamma", _wrap_wgamma, 1);
  rb_define_module_function(wrap_mMathlib, "clgama", _wrap_clgama, 1);
  rb_define_module_function(wrap_mMathlib, "wlgama", _wrap_wlgama, 1);
  rb_define_module_function(wrap_mMathlib, "cclbes", _wrap_cclbes, 7);
  rb_define_module_function(wrap_mMathlib, "wclbes", _wrap_wclbes, 7);
  rb_define_module_function(wrap_mMathlib, "besj0", _wrap_besj0, 1);
  rb_define_module_function(wrap_mMathlib, "dbesj0", _wrap_dbesj0, 1);
  rb_define_module_function(wrap_mMathlib, "besj1", _wrap_besj1, 1);
  rb_define_module_function(wrap_mMathlib, "dbesj1", _wrap_dbesj1, 1);
  rb_define_module_function(wrap_mMathlib, "besy0", _wrap_besy0, 1);
  rb_define_module_function(wrap_mMathlib, "dbesy0", _wrap_dbesy0, 1);
  rb_define_module_function(wrap_mMathlib, "besy1", _wrap_besy1, 1);
  rb_define_module_function(wrap_mMathlib, "dbesy1", _wrap_dbesy1, 1);
  rb_define_module_function(wrap_mMathlib, "besi0", _wrap_besi0, 1);
  rb_define_module_function(wrap_mMathlib, "dbesi0", _wrap_dbesi0, 1);
  rb_define_module_function(wrap_mMathlib, "ebesi0", _wrap_ebesi0, 1);
  rb_define_module_function(wrap_mMathlib, "debsi0", _wrap_debsi0, 1);
  rb_define_module_function(wrap_mMathlib, "besi1", _wrap_besi1, 1);
  rb_define_module_function(wrap_mMathlib, "dbesi1", _wrap_dbesi1, 1);
  rb_define_module_function(wrap_mMathlib, "ebesi1", _wrap_ebesi1, 1);
  rb_define_module_function(wrap_mMathlib, "debsi1", _wrap_debsi1, 1);
  rb_define_module_function(wrap_mMathlib, "besk0", _wrap_besk0, 1);
  rb_define_module_function(wrap_mMathlib, "dbesk0", _wrap_dbesk0, 1);
  rb_define_module_function(wrap_mMathlib, "ebesk0", _wrap_ebesk0, 1);
  rb_define_module_function(wrap_mMathlib, "debsk0", _wrap_debsk0, 1);
  rb_define_module_function(wrap_mMathlib, "besk1", _wrap_besk1, 1);
  rb_define_module_function(wrap_mMathlib, "dbesk1", _wrap_dbesk1, 1);
  rb_define_module_function(wrap_mMathlib, "ebesk1", _wrap_ebesk1, 1);
  rb_define_module_function(wrap_mMathlib, "debsk1", _wrap_debsk1, 1);
  rb_define_module_function(wrap_mMathlib, "rrizet", _wrap_rrizet, 1);
  rb_define_module_function(wrap_mMathlib, "drizet", _wrap_drizet, 1);
  rb_define_module_function(wrap_mMathlib, "rpsipg", _wrap_rpsipg, 2);
  rb_define_module_function(wrap_mMathlib, "dpsipg", _wrap_dpsipg, 2);
  rb_define_module_function(wrap_mMathlib, "cpsipg", _wrap_cpsipg, 2);
  rb_define_module_function(wrap_mMathlib, "wpsipg", _wrap_wpsipg, 2);
  rb_define_module_function(wrap_mMathlib, "relfun", _wrap_relfun, 2);
  rb_define_module_function(wrap_mMathlib, "delfun", _wrap_delfun, 2);
  rb_define_module_function(wrap_mMathlib, "celfun", _wrap_celfun, 2);
  rb_define_module_function(wrap_mMathlib, "welfun", _wrap_welfun, 2);
  rb_define_module_function(wrap_mMathlib, "cgplg", _wrap_cgplg, 3);
  rb_define_module_function(wrap_mMathlib, "wgplg", _wrap_wgplg, 3);
  rb_define_module_function(wrap_mMathlib, "rfrsin", _wrap_rfrsin, 1);
  rb_define_module_function(wrap_mMathlib, "dfrsin", _wrap_dfrsin, 1);
  rb_define_module_function(wrap_mMathlib, "rfrcos", _wrap_rfrcos, 1);
  rb_define_module_function(wrap_mMathlib, "dfrcos", _wrap_dfrcos, 1);
  rb_define_module_function(wrap_mMathlib, "rferdr", _wrap_rferdr, 2);
  rb_define_module_function(wrap_mMathlib, "dferdr", _wrap_dferdr, 2);
  rb_define_module_function(wrap_mMathlib, "ratani", _wrap_ratani, 1);
  rb_define_module_function(wrap_mMathlib, "datani", _wrap_datani, 1);
  rb_define_module_function(wrap_mMathlib, "rclaus", _wrap_rclaus, 1);
  rb_define_module_function(wrap_mMathlib, "dclaus", _wrap_dclaus, 1);
  rb_define_module_function(wrap_mMathlib, "bsir4", _wrap_bsir4, 2);
  rb_define_module_function(wrap_mMathlib, "dbsir4", _wrap_dbsir4, 2);
  rb_define_module_function(wrap_mMathlib, "bskr4", _wrap_bskr4, 2);
  rb_define_module_function(wrap_mMathlib, "dbskr4", _wrap_dbskr4, 2);
  rb_define_module_function(wrap_mMathlib, "ebsir4", _wrap_ebsir4, 2);
  rb_define_module_function(wrap_mMathlib, "debir4", _wrap_debir4, 2);
  rb_define_module_function(wrap_mMathlib, "ebskr4", _wrap_ebskr4, 2);
  rb_define_module_function(wrap_mMathlib, "debkr4", _wrap_debkr4, 2);
  rb_define_module_function(wrap_mMathlib, "cwhitm", _wrap_cwhitm, 3);
  rb_define_module_function(wrap_mMathlib, "wwhitm", _wrap_wwhitm, 3);
  rb_define_module_function(wrap_mMathlib, "raslgf", _wrap_raslgf, 4);
  rb_define_module_function(wrap_mMathlib, "daslgf", _wrap_daslgf, 4);
  rb_define_module_function(wrap_mMathlib, "rfconc", _wrap_rfconc, 3);
  rb_define_module_function(wrap_mMathlib, "dfconc", _wrap_dfconc, 3);
  rb_define_module_function(wrap_mMathlib, "rdilog", _wrap_rdilog, 1);
  rb_define_module_function(wrap_mMathlib, "ddilog", _wrap_ddilog, 1);
  rb_define_module_function(wrap_mMathlib, "rgapnc", _wrap_rgapnc, 2);
  rb_define_module_function(wrap_mMathlib, "dgapnc", _wrap_dgapnc, 2);
  rb_define_module_function(wrap_mMathlib, "rgagnc", _wrap_rgagnc, 2);
  rb_define_module_function(wrap_mMathlib, "dgagnc", _wrap_dgagnc, 2);
  rb_define_module_function(wrap_mMathlib, "cwerf", _wrap_cwerf, 1);
  rb_define_module_function(wrap_mMathlib, "wwerf", _wrap_wwerf, 1);
  rb_define_module_function(wrap_mMathlib, "rsinin", _wrap_rsinin, 1);
  rb_define_module_function(wrap_mMathlib, "dsinin", _wrap_dsinin, 1);
  rb_define_module_function(wrap_mMathlib, "rcosin", _wrap_rcosin, 1);
  rb_define_module_function(wrap_mMathlib, "dcosin", _wrap_dcosin, 1);
  rb_define_module_function(wrap_mMathlib, "rexpin", _wrap_rexpin, 1);
  rb_define_module_function(wrap_mMathlib, "dexpin", _wrap_dexpin, 1);
  rb_define_module_function(wrap_mMathlib, "rexpie", _wrap_rexpie, 1);
  rb_define_module_function(wrap_mMathlib, "dexpie", _wrap_dexpie, 1);
  rb_define_module_function(wrap_mMathlib, "cexpin", _wrap_cexpin, 1);
  rb_define_module_function(wrap_mMathlib, "wexpin", _wrap_wexpin, 1);
  rb_define_module_function(wrap_mMathlib, "rdawsn", _wrap_rdawsn, 1);
  rb_define_module_function(wrap_mMathlib, "ddawsn", _wrap_ddawsn, 1);
  rb_define_module_function(wrap_mMathlib, "bsir3", _wrap_bsir3, 2);
  rb_define_module_function(wrap_mMathlib, "dbsir3", _wrap_dbsir3, 2);
  rb_define_module_function(wrap_mMathlib, "ebsir3", _wrap_ebsir3, 2);
  rb_define_module_function(wrap_mMathlib, "debir3", _wrap_debir3, 2);
  rb_define_module_function(wrap_mMathlib, "bskr3", _wrap_bskr3, 2);
  rb_define_module_function(wrap_mMathlib, "dbskr3", _wrap_dbskr3, 2);
  rb_define_module_function(wrap_mMathlib, "ebskr3", _wrap_ebskr3, 2);
  rb_define_module_function(wrap_mMathlib, "debkr3", _wrap_debkr3, 2);
  rb_define_module_function(wrap_mMathlib, "bska", _wrap_bska, 4);
  rb_define_module_function(wrap_mMathlib, "dbska", _wrap_dbska, 4);
  rb_define_module_function(wrap_mMathlib, "ebska", _wrap_ebska, 4);
  rb_define_module_function(wrap_mMathlib, "debka", _wrap_debka, 4);
  rb_define_module_function(wrap_mMathlib, "rstrh0", _wrap_rstrh0, 1);
  rb_define_module_function(wrap_mMathlib, "dstrh0", _wrap_dstrh0, 1);
  rb_define_module_function(wrap_mMathlib, "rstrh1", _wrap_rstrh1, 1);
  rb_define_module_function(wrap_mMathlib, "dstrh1", _wrap_dstrh1, 1);
  rb_define_module_function(wrap_mMathlib, "rbzejy", _wrap_rbzejy, 4);
  rb_define_module_function(wrap_mMathlib, "dbzejy", _wrap_dbzejy, 4);
  rb_define_module_function(wrap_mMathlib, "reli1", _wrap_reli1, 2);
  rb_define_module_function(wrap_mMathlib, "deli1", _wrap_deli1, 2);
  rb_define_module_function(wrap_mMathlib, "reli2", _wrap_reli2, 5);
  rb_define_module_function(wrap_mMathlib, "deli2", _wrap_deli2, 5);
  rb_define_module_function(wrap_mMathlib, "reli3", _wrap_reli3, 3);
  rb_define_module_function(wrap_mMathlib, "deli3", _wrap_deli3, 3);
  rb_define_module_function(wrap_mMathlib, "reli1c", _wrap_reli1c, 1);
  rb_define_module_function(wrap_mMathlib, "deli1c", _wrap_deli1c, 1);
  rb_define_module_function(wrap_mMathlib, "reli2c", _wrap_reli2c, 3);
  rb_define_module_function(wrap_mMathlib, "deli2c", _wrap_deli2c, 3);
  rb_define_module_function(wrap_mMathlib, "reli3c", _wrap_reli3c, 3);
  rb_define_module_function(wrap_mMathlib, "deli3c", _wrap_deli3c, 3);
  rb_define_module_function(wrap_mMathlib, "religc", _wrap_religc, 4);
  rb_define_module_function(wrap_mMathlib, "deligc", _wrap_deligc, 4);
  rb_define_module_function(wrap_mMathlib, "reliec", _wrap_reliec, 1);
  rb_define_module_function(wrap_mMathlib, "deliec", _wrap_deliec, 1);
  rb_define_module_function(wrap_mMathlib, "relikc", _wrap_relikc, 1);
  rb_define_module_function(wrap_mMathlib, "delikc", _wrap_delikc, 1);
  rb_define_module_function(wrap_mMathlib, "celint", _wrap_celint, 4);
  rb_define_module_function(wrap_mMathlib, "welint", _wrap_welint, 4);
  rb_define_module_function(wrap_mMathlib, "rtheta", _wrap_rtheta, 3);
  rb_define_module_function(wrap_mMathlib, "dtheta", _wrap_dtheta, 3);
  rb_define_module_function(wrap_mMathlib, "rsimps", _wrap_rsimps, 3);
  rb_define_module_function(wrap_mMathlib, "dsimps", _wrap_dsimps, 3);
  rb_define_module_function(wrap_mMathlib, "radapt", _wrap_radapt, 5);
  rb_define_module_function(wrap_mMathlib, "dadapt", _wrap_dadapt, 5);
  rb_define_module_function(wrap_mMathlib, "gauss", _wrap_gauss, 3);
  rb_define_module_function(wrap_mMathlib, "dgauss", _wrap_dgauss, 3);
  rb_define_module_function(wrap_mMathlib, "rcauch", _wrap_rcauch, 4);
  rb_define_module_function(wrap_mMathlib, "dcauch", _wrap_dcauch, 4);
  rb_define_module_function(wrap_mMathlib, "rtrint", _wrap_rtrint, 9);
  rb_define_module_function(wrap_mMathlib, "dtrint", _wrap_dtrint, 9);
  rb_define_module_function(wrap_mMathlib, "rgs56p", _wrap_rgs56p, 2);
  rb_define_module_function(wrap_mMathlib, "dgs56p", _wrap_dgs56p, 2);
  rb_define_module_function(wrap_mMathlib, "traper", _wrap_traper, 5);
  rb_define_module_function(wrap_mMathlib, "loren4", _wrap_loren4, 2);
  rb_define_module_function(wrap_mMathlib, "lorenf", _wrap_lorenf, 3);
  rb_define_module_function(wrap_mMathlib, "lorenb", _wrap_lorenb, 3);
  rb_define_module_function(wrap_mMathlib, "rwig3j", _wrap_rwig3j, 6);
  rb_define_module_function(wrap_mMathlib, "rwig6j", _wrap_rwig6j, 6);
  rb_define_module_function(wrap_mMathlib, "rwig9j", _wrap_rwig9j, 9);
  rb_define_module_function(wrap_mMathlib, "rclebg", _wrap_rclebg, 6);
  rb_define_module_function(wrap_mMathlib, "rracaw", _wrap_rracaw, 6);
  rb_define_module_function(wrap_mMathlib, "rjahnu", _wrap_rjahnu, 6);
  rb_define_module_function(wrap_mMathlib, "dwig3j", _wrap_dwig3j, 6);
  rb_define_module_function(wrap_mMathlib, "dwig6j", _wrap_dwig6j, 6);
  rb_define_module_function(wrap_mMathlib, "dwig9j", _wrap_dwig9j, 9);
  rb_define_module_function(wrap_mMathlib, "dclebg", _wrap_dclebg, 6);
  rb_define_module_function(wrap_mMathlib, "dracaw", _wrap_dracaw, 6);
  rb_define_module_function(wrap_mMathlib, "djahnu", _wrap_djahnu, 6);
  rb_define_module_function(wrap_mMathlib, "rdjmnb", _wrap_rdjmnb, 4);
  rb_define_module_function(wrap_mMathlib, "ddjmnb", _wrap_ddjmnb, 4);
  rb_define_module_function(wrap_mMathlib, "rndm", _wrap_rndm, 1);
  rb_define_module_function(wrap_mMathlib, "irndm", _wrap_irndm, 1);
  rb_define_module_function(wrap_mMathlib, "rdmin", _wrap_rdmin, 1);
  rb_define_module_function(wrap_mMathlib, "rdmout", _wrap_rdmout, 0);
  rb_define_module_function(wrap_mMathlib, "nran", _wrap_nran, 1);
  rb_define_module_function(wrap_mMathlib, "nranin", _wrap_nranin, 1);
  rb_define_module_function(wrap_mMathlib, "nranut", _wrap_nranut, 0);
  rb_define_module_function(wrap_mMathlib, "ranmar", _wrap_ranmar, 1);
  rb_define_module_function(wrap_mMathlib, "rannor", _wrap_rannor, 0);
  rb_define_module_function(wrap_mMathlib, "rmarin", _wrap_rmarin, 3);
  rb_define_module_function(wrap_mMathlib, "rmarout", _wrap_rmarout, 0);
  rb_define_module_function(wrap_mMathlib, "ranlux", _wrap_ranlux, 1);
  rb_define_module_function(wrap_mMathlib, "rluxgo", _wrap_rluxgo, 4);
  rb_define_module_function(wrap_mMathlib, "rluxat", _wrap_rluxat, 0);
  rb_define_module_function(wrap_mMathlib, "rluxin", _wrap_rluxin, 1);
  rb_define_module_function(wrap_mMathlib, "rluxut", _wrap_rluxut, 0);
  rb_define_module_function(wrap_mMathlib, "rm48", _wrap_rm48, 1);
  rb_define_module_function(wrap_mMathlib, "rm48in", _wrap_rm48in, 3);
  rb_define_module_function(wrap_mMathlib, "rm48out", _wrap_rm48out, 0);
  rb_define_module_function(wrap_mMathlib, "rnorml", _wrap_rnorml, 1);
  rb_define_module_function(wrap_mMathlib, "ran3d", _wrap_ran3d, 1);
  rb_define_module_function(wrap_mMathlib, "rn3dim", _wrap_rn3dim, 1);
  rb_define_module_function(wrap_mMathlib, "rn2dim", _wrap_rn2dim, 1);
  rb_define_module_function(wrap_mMathlib, "rngama", _wrap_rngama, 1);
  rb_define_module_function(wrap_mMathlib, "rnpssn", _wrap_rnpssn, 1);
  rb_define_module_function(wrap_mMathlib, "rnpset", _wrap_rnpset, 1);
  rb_define_module_function(wrap_mMathlib, "rnbnml", _wrap_rnbnml, 2);
  rb_define_module_function(wrap_mMathlib, "rnmnml", _wrap_rnmnml, 2);
  rb_define_module_function(wrap_mMathlib, "rnhpre", _wrap_rnhpre, 1);
  rb_define_module_function(wrap_mMathlib, "rnhran", _wrap_rnhran, 3);
  rb_define_module_function(wrap_mMathlib, "hispre", _wrap_hispre, 1);
  rb_define_module_function(wrap_mMathlib, "hisran", _wrap_hisran, 3);
  rb_define_module_function(wrap_mMathlib, "funpre", _wrap_funpre, 2);
  rb_define_module_function(wrap_mMathlib, "funran", _wrap_funran, 1);
  rb_define_module_function(wrap_mMathlib, "funlxp", _wrap_funlxp, 2);
  rb_define_module_function(wrap_mMathlib, "funlux", _wrap_funlux, 2);
  rb_define_module_function(wrap_mMathlib, "permu", _wrap_permu, 1);
  rb_define_module_function(wrap_mMathlib, "permut", _wrap_permut, 2);
  rb_define_module_function(wrap_mMathlib, "rvnspc", _wrap_rvnspc, 3);
  rb_define_module_function(wrap_mMathlib, "dvnspc", _wrap_dvnspc, 3);
  rb_define_module_function(wrap_mMathlib, "cdigam", _wrap_cdigam, 1);
  rb_define_module_function(wrap_mMathlib, "wdigam", _wrap_wdigam, 1);
  rb_define_module_function(wrap_mMathlib, "clogok", _wrap_clogok, 3);
  rb_define_module_function(wrap_mMathlib, "crit", _wrap_crit, 3);
  rb_define_module_function(wrap_mMathlib, "csqrtk", _wrap_csqrtk, 3);
  rb_define_module_function(wrap_mMathlib, "hypgm", _wrap_hypgm, 5);
  rb_define_module_function(wrap_mMathlib, "legfn", _wrap_legfn, 3);
  rb_define_module_function(wrap_mMathlib, "adigam", _wrap_adigam, 1);
  rb_define_module_function(wrap_mMathlib, "nic311", _wrap_nic311, 1);
  rb_define_module_function(wrap_mMathlib, "leg1", _wrap_leg1, 0);
  rb_define_module_function(wrap_mMathlib, "legor", _wrap_legor, 0);
  rb_define_module_function(wrap_mMathlib, "legv", _wrap_legv, 0);
  rb_define_module_function(wrap_mMathlib, "legz", _wrap_legz, 0);
  rb_define_module_function(wrap_mMathlib, "qfunct", _wrap_qfunct, 1);
  rb_define_module_function(wrap_mMathlib, "dtclgn", _wrap_dtclgn, 6);
  rb_define_module_function(wrap_mMathlib, "combi", _wrap_combi, 2);

  rb_define_alias(wrap_mMathlib, "binom", "rbinom");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "binom", "rbinom");
  rb_define_alias(wrap_mMathlib, "zerox", "rzerox");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "zerox", "rzerox");
  rb_define_alias(wrap_mMathlib, "rteq3", "rrteq3");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "rteq3", "rrteq3");
  rb_define_alias(wrap_mMathlib, "rteq4", "rrteq4");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "rteq4", "rrteq4");
  rb_define_alias(wrap_mMathlib, "alogam", "algama");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "alogam", "algama");
  rb_define_alias(wrap_mMathlib, "dlogam", "dlgama");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "dlogam", "dlgama");
  rb_define_alias(wrap_mMathlib, "elfun", "relfun");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "elfun", "relfun");
  rb_define_alias(wrap_mMathlib, "frsin", "rfrsin");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "frsin", "rfrsin");
  rb_define_alias(wrap_mMathlib, "frcos", "rfrcos");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "frcos", "rfrcos");
  rb_define_alias(wrap_mMathlib, "ferdr", "rferdr");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "ferdr", "rferdr");
  rb_define_alias(wrap_mMathlib, "atani", "ratani");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "atani", "ratani");
  rb_define_alias(wrap_mMathlib, "aslgf", "raslgf");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "aslgf", "raslgf");
  rb_define_alias(wrap_mMathlib, "fconc", "rfconc");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "fconc", "rfconc");
  rb_define_alias(wrap_mMathlib, "dilog", "rdilog");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "dilog", "rdilog");
  rb_define_alias(wrap_mMathlib, "gapnc", "rgapnc");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "gapnc", "rgapnc");
  rb_define_alias(wrap_mMathlib, "gagnc", "rgagnc");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "gagnc", "rgagnc");
  rb_define_alias(wrap_mMathlib, "sinint", "rsinin");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "sinint", "rsinin");
  rb_define_alias(wrap_mMathlib, "cosint", "rcosin");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "cosint", "rcosin");
  rb_define_alias(wrap_mMathlib, "expint", "rexpin");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "expint", "rexpin");
  rb_define_alias(wrap_mMathlib, "dawson", "rdawsn");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "dawson", "rdawsn");
  rb_define_alias(wrap_mMathlib, "strh0", "rstrh0");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "strh0", "rstrh0");
  rb_define_alias(wrap_mMathlib, "strh1", "rstrh1");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "strh1", "rstrh1");
  rb_define_alias(wrap_mMathlib, "bzejy", "rbzejy");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "bzejy", "rbzejy");
  rb_define_alias(wrap_mMathlib, "ellice", "reliec");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "ellice", "reliec");
  rb_define_alias(wrap_mMathlib, "dellie", "deliec");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "dellie", "deliec");
  rb_define_alias(wrap_mMathlib, "ellick", "relikc");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "ellick", "relikc");
  rb_define_alias(wrap_mMathlib, "dellik", "delikc");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "dellik", "delikc");
  rb_define_alias(wrap_mMathlib, "simps", "rsimps");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "simps", "rsimps");
  rb_define_alias(wrap_mMathlib, "cauchy", "rcauch");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "cauchy", "rcauch");
  rb_define_alias(wrap_mMathlib, "triint", "rtrint");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "triint", "rtrint");
  rb_define_alias(wrap_mMathlib, "djmnb", "rdjmnb");
  rb_define_alias(rb_singleton_class(wrap_mMathlib), "djmnb", "rdjmnb");

}
