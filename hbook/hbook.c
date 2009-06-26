#include <ruby.h>
#include "cernlib_util.h"

#define NWPAWC 100000
int pawc_[NWPAWC];

static VALUE wrap_mCERN;
VALUE wrap_mHBook;


extern void hbandx_(int*, float*, float*, float*);
extern void hbandy_(int*, float*, float*, float*);
extern void hbarx_(int*);
extern void hbary_(int*);
extern void hbar2_(int*);
extern void hbfun1_(int*, char*, int*, float*, float*, float (*)(float*), int);
extern void hbfun2_(int*, char*, int*, float*, float*, int*, float*, float*, float (*)(float*, float*), int);
extern void hbigbi_(int*, int*);
extern void hrenid_(int*, int*);
extern void hbinsz_(char*, int);
extern void hntdup_(int*, int*, int*, char*, char*, int, int);
extern void hbookn_(int*, char*, int*, char*, int*, char*, int, int, int);
extern void hbook1_(int*, char*, int*, float*, float*, float*, int);
extern void hbook2_(int*, char*, int*, float*, float*, int*, float*, float*, float*, int);
extern void hbpro_(int*, float*);
extern void hbprof_(int*, char*, int*, float*, float*, float*, float*, char*, int, int);
extern void hbprox_(int*, float*);
extern void hbproy_(int*, float*);
extern void hbset_(char*, int*, int*, int);
extern void hbslix_(int*, int*, float*);
extern void hbsliy_(int*, int*, float*);
extern void hcompa_(int*, int*);
extern void hcopy_(int*, int*, char*, int);
extern void hcopyr_(int*, int*, char*, int*, int*, int*, int*, char*, int, int);
extern void hdelet_(int*);
extern void hddir_(char*, int);
extern void hdump_(int*);
extern void hermes_(int*);
extern void hfc1_(int*, int*, char*, float*, char*, int, int);
extern void hfc2_(int*, int*, char*, int*, char*, float*, char*, int, int, int);
extern void hff1_(int*, int*, float*, float*);
extern void hff2_(int*, int*, float*, float*, float*);
extern void hfill_(int*, float*, float*, float*);
extern void hfinam_(int*, char*, int*, int);
extern void hfithn_(int*, char*, char*, int*, float*, float*, float*, float*, float*, float*, int, int);
extern void hfn_(int*, float*);
extern void hfpak1_(int*, int*, float*, int*);
extern void hf1_(int*, float*, float*);
extern void hf1e_(int*, float*, float*, float*);
extern void hf2_(int*, float*, float*, float*);
extern void hgive_(int*, char*, int*, float*, float*, int*, float*, float*, int*, int*, int);
extern void hgiven_(int*, char*, int*, char*, float*, float*, int, int);
extern void hkind_(int*, int*, char*, int);
extern void hgnpar_(int*, char*, int);
extern void hidall_(int*, int*);
extern void hidopt_(int*, char*, int);
extern void hid1_(int*, int*);
extern void hid2_(int*, int*);
extern void hijxy_(int*, int*, int*, float*, float*);
extern void hindex_();
extern void hipak1_(int*, int*, int*, int*);
extern void histdo_();
extern void hix_(int*, int*, float*);
extern void hldir_(char*, char*, int, int);
extern void hlimit_(int*);
extern void hlnext_(int*, char*, char*, char*, int, int, int);
extern void hlocat_(int*, int*);
extern void hmaxim_(int*, float*);
extern void hmerge_(int*, char*, char*, int, int);
extern void hmergin_();
extern void hmdir_(char*, char*, int, int);
extern void hminim_(int*, float*);
extern void hnoent_(int*, int*);
extern void hopera_(int*, char*, int*, int*, float*, float*, int);
extern void houtpu_(int*);
extern void hpagsz_(int*);
extern void hpak_(int*, float*);
extern void hpakad_(int*, float*);
extern void hpake_(int*, float*);
extern void hpchar_(char*, char*, int, int);
extern void hpdir_(char*, char*, int, int);
extern void hphist_(int*, char*, int*, int);
extern void hphs_(int*);
extern void hphst_(int*);
extern void hponce_();
extern void hprint_(int*);
extern void hprnt_(int*);
extern void hprot_(int*, char*, int*, int);
extern void hpscat_(int*);
extern void hptab_(int*);
extern void hrebin_(int*, float*, float*, float*, float*, int*, int*, int*);
extern void hrend_(char*, int);
extern void hreset_(int*, char*, int);
extern void hrename_(int*, char*, char*, int, int);
extern void hrfile_(int*, char*, char*, int, int);
extern void hrget_(int*, char*, char*, int, int);
extern void hrin_(int*, int*, int*);
extern void hrndm2_(int*, float*, float*);
extern void hropen_(int*, char*, char*, char*, int*, int*, int, int, int);
extern void hrout_(int*, int*, char*, int);
extern void hrput_(int*, char*, char*, int, int);
extern void hscale_(int*, float*);
extern void hscr_(int*, int*, char*, int);
extern void hsetpr_(char*, float*, int);
extern void hsmoof_(int*, int*, float*);
extern void hspli1_(int*, int*, int*, int*, float*);
extern void hspli2_(int*, int*, int*, int*, int*);
extern void hsquez_(char*, int);
extern void htitle_(char*, int);
extern void hunpak_(int*, float*, char*, int*, int);
extern void hunpke_(int*, float*, char*, int*, int);
extern void huwfun_(int*, int*, char*, int*, char*, int, int);
extern void hxi_(int*, float*, int*);
extern void hxyij_(int*, float*, float*, int*, int*);
extern int hexist_(int*);
extern float hi_(int*, int*);
extern float hie_(int*, int*);
extern float hij_(int*, int*, int*);
extern float hije_(int*, int*, int*);
extern float hmax_(int*);
extern float hmin_(int*);
extern float hrndm1_(int*);
extern float hspfun_(int*, float*, int*, int*);
extern void hstaf_(char*, int);
extern float hstati_(int*, int*, char*, int*, int);
extern float hsum_(int*);
extern float hx_(int*, float*);
extern float hxe_(int*, float*);
extern float hxy_(int*, float*, float*);
extern void hlimap_(int*, char*, int);
extern void hcdir_(char*, char*, int, int);
extern void hrdir_(int*, char*, int*, int);
extern void hlabel_(int*, int*, char*, char*, int, int);
extern void hrin_(int*, int*, int*);
extern void hgiven_(int*, char*, int*, char*, float*, float*, int, int);
extern void hproj1_(int*, int*, int*, float(*)(float*,int*), int*, int*, int*);
extern void hproj2_(int*, int*, int*, float(*)(float*,int*), int*, int*, int*, int*);


static VALUE _wrap_hbandx(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  float carg1;
  float carg2;
  float carg3;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  hbandx_(&carg0, &carg1, &carg2, &carg3);

  return Qnil;
}

static VALUE _wrap_hbandy(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  float carg1;
  float carg2;
  float carg3;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  hbandy_(&carg0, &carg1, &carg2, &carg3);

  return Qnil;
}

static VALUE _wrap_hbarx(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hbarx_(&carg0);

  return Qnil;
}

static VALUE _wrap_hbary(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hbary_(&carg0);

  return Qnil;
}

static VALUE _wrap_hbar2(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hbar2_(&carg0);

  return Qnil;
}

static VALUE _wrap_hbfun1(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  int carg0;
  int len1;
  char *carg1;
  int carg2;
  float carg3;
  float carg4;
  float (*carg5)(float*);

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = float_callback_float;
  hbfun1_(&carg0, carg1, &carg2, &carg3, &carg4, carg5, len1);

  return Qnil;
}

static VALUE _wrap_hbfun2(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7)
{
  int carg0;
  int len1;
  char *carg1;
  int carg2;
  float carg3;
  float carg4;
  int carg5;
  float carg6;
  float carg7;
  float (*carg8)(float*, float*);

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2INT(arg5);
  carg6 = NUM2DBL(arg6);
  carg7 = NUM2DBL(arg7);
  carg8 = float_callback_float_float;
  hbfun2_(&carg0, carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7, carg8, len1);

  return Qnil;
}

static VALUE _wrap_hbigbi(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  hbigbi_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_hrenid(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  hrenid_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_hbinsz(VALUE self, VALUE arg0)
{
  int len0;
  char *carg0;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  hbinsz_(carg0, len0);

  return Qnil;
}

static VALUE _wrap_hntdup(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  int carg0;
  int carg1;
  int carg2;
  int len3;
  char *carg3;
  int len4;
  char *carg4;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  Check_Type(arg3, T_STRING);
  len3 = RSTRING(arg3)->len;
  carg3 = ALLOCA_N(char, len3 + 1);
  strcpy(carg3, STR2CSTR(arg3));
  Check_Type(arg4, T_STRING);
  len4 = RSTRING(arg4)->len;
  carg4 = ALLOCA_N(char, len4 + 1);
  strcpy(carg4, STR2CSTR(arg4));
  hntdup_(&carg0, &carg1, &carg2, carg3, carg4, len3, len4);

  return Qnil;
}

static VALUE _wrap_hbookn(VALUE self, VALUE arg0, VALUE arg1, VALUE arg3, VALUE arg4, VALUE arg5)
{
  int carg0;
  int len1;
  char *carg1;
  int carg2;
  int len3;
  char *carg3;
  int carg4;
  int len5;
  char *carg5;

  Check_Type(arg5, T_ARRAY);
  len5 = RARRAY(arg5)->len;
  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = len5;
  Check_Type(arg3, T_STRING);
  len3 = RSTRING(arg3)->len;
  carg3 = ALLOCA_N(char, len3 + 1);
  strcpy(carg3, STR2CSTR(arg3));
  carg4 = NUM2INT(arg4);
  carg5 = ALLOCA_N(char, 8 * len5 + 1);
  util_str_ary_rb2f(arg5, 8, carg5);
  hbookn_(&carg0, carg1, &carg2, carg3, &carg4, carg5, len1, len3, 8);

  return Qnil;
}

static VALUE _wrap_hbook1(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  int carg0;
  int len1;
  char *carg1;
  int carg2;
  float carg3;
  float carg4;
  float carg5;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  hbook1_(&carg0, carg1, &carg2, &carg3, &carg4, &carg5, len1);

  return Qnil;
}

static VALUE _wrap_hbook2(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7, VALUE arg8)
{
  int carg0;
  int len1;
  char *carg1;
  int carg2;
  float carg3;
  float carg4;
  int carg5;
  float carg6;
  float carg7;
  float carg8;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2INT(arg5);
  carg6 = NUM2DBL(arg6);
  carg7 = NUM2DBL(arg7);
  carg8 = NUM2DBL(arg8);
  hbook2_(&carg0, carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7, &carg8, len1);

  return Qnil;
}

static VALUE _wrap_hbpro(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  float carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  hbpro_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_hbprof(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7)
{
  int carg0;
  int len1;
  char *carg1;
  int carg2;
  float carg3;
  float carg4;
  float carg5;
  float carg6;
  int len7;
  char *carg7;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2DBL(arg6);
  Check_Type(arg7, T_STRING);
  len7 = RSTRING(arg7)->len;
  carg7 = ALLOCA_N(char, len7 + 1);
  strcpy(carg7, STR2CSTR(arg7));
  hbprof_(&carg0, carg1, &carg2, &carg3, &carg4, &carg5, &carg6, carg7, len1, len7);

  return Qnil;
}

static VALUE _wrap_hbprox(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  float carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  hbprox_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_hbproy(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  float carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  hbproy_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_hbset(VALUE self, VALUE arg0, VALUE arg1)
{
  int len0;
  char *carg0;
  int carg1;
  int carg2;
  VALUE value2;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  carg1 = NUM2INT(arg1);
  hbset_(carg0, &carg1, &carg2, len0);
  value2 = INT2NUM(carg2);

  return value2;
}

static VALUE _wrap_hbslix(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  float carg2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2DBL(arg2);
  hbslix_(&carg0, &carg1, &carg2);

  return Qnil;
}

static VALUE _wrap_hbsliy(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  float carg2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2DBL(arg2);
  hbsliy_(&carg0, &carg1, &carg2);

  return Qnil;
}

static VALUE _wrap_hcompa(VALUE self, VALUE arg0)
{
  int i0, len0, *carg0;
  int carg1;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(int, len0);
  for (i0 = 0; i0 < len0; i0++)
    carg0[i0] = NUM2INT(RARRAY(arg0)->ptr[i0]);
  carg1 = len0;
  hcompa_(carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_hcopy(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  int len2;
  char *carg2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  hcopy_(&carg0, &carg1, carg2, len2);

  return Qnil;
}

static VALUE _wrap_hcopyr(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7)
{
  int carg0;
  int carg1;
  int len2;
  char *carg2;
  int carg3;
  int carg4;
  int carg5;
  int carg6;
  int len7;
  char *carg7;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  carg3 = NUM2INT(arg3);
  carg4 = NUM2INT(arg4);
  carg5 = NUM2INT(arg5);
  carg6 = NUM2INT(arg6);
  Check_Type(arg7, T_STRING);
  len7 = RSTRING(arg7)->len;
  carg7 = ALLOCA_N(char, len7 + 1);
  strcpy(carg7, STR2CSTR(arg7));
  hcopyr_(&carg0, &carg1, carg2, &carg3, &carg4, &carg5, &carg6, carg7, len2, len7);

  return Qnil;
}

static VALUE _wrap_hdelet(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hdelet_(&carg0);

  return Qnil;
}

static VALUE _wrap_hddir(VALUE self, VALUE arg0)
{
  int len0;
  char *carg0;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  hddir_(carg0, len0);

  return Qnil;
}

static VALUE _wrap_hdump(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hdump_(&carg0);

  return Qnil;
}

static VALUE _wrap_hermes(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hermes_(&carg0);

  return Qnil;
}

static VALUE _wrap_hfc1(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  int carg0;
  int carg1;
  int len2;
  char *carg2;
  float carg3;
  int len4;
  char *carg4;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  carg3 = NUM2DBL(arg3);
  Check_Type(arg4, T_STRING);
  len4 = RSTRING(arg4)->len;
  carg4 = ALLOCA_N(char, len4 + 1);
  strcpy(carg4, STR2CSTR(arg4));
  hfc1_(&carg0, &carg1, carg2, &carg3, carg4, len2, len4);

  return Qnil;
}

static VALUE _wrap_hfc2(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6)
{
  int carg0;
  int carg1;
  int len2;
  char *carg2;
  int carg3;
  int len4;
  char *carg4;
  float carg5;
  int len6;
  char *carg6;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  carg3 = NUM2INT(arg3);
  Check_Type(arg4, T_STRING);
  len4 = RSTRING(arg4)->len;
  carg4 = ALLOCA_N(char, len4 + 1);
  strcpy(carg4, STR2CSTR(arg4));
  carg5 = NUM2DBL(arg5);
  Check_Type(arg6, T_STRING);
  len6 = RSTRING(arg6)->len;
  carg6 = ALLOCA_N(char, len6 + 1);
  strcpy(carg6, STR2CSTR(arg6));
  hfc2_(&carg0, &carg1, carg2, &carg3, carg4, &carg5, carg6, len2, len4, len6);

  return Qnil;
}

static VALUE _wrap_hff1(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  int carg1;
  VALUE value1;
  float carg2;
  float carg3;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  hff1_(&carg0, &carg1, &carg2, &carg3);
  value1 = INT2NUM(carg1);

  return value1;
}

static VALUE _wrap_hff2(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  int carg0;
  int carg1;
  VALUE value1;
  float carg2;
  float carg3;
  float carg4;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  hff2_(&carg0, &carg1, &carg2, &carg3, &carg4);
  value1 = INT2NUM(carg1);

  return value1;
}

static VALUE _wrap_hfill(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  float carg1;
  float carg2;
  float carg3;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  hfill_(&carg0, &carg1, &carg2, &carg3);

  return Qnil;
}

static VALUE _wrap_hfinam(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int len1;
  char *carg1;
  int carg2;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  carg0 = NUM2INT(arg0);
  carg1 = ALLOCA_N(char, 0 * len1 + 1);
  util_str_ary_rb2f(arg1, 0, carg1);
  carg2 = len1;
  hfinam_(&carg0, carg1, &carg2, 0);

  return Qnil;
}

static VALUE _wrap_hfithn(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7)
{
  int carg0;
  int len1;
  char *carg1;
  int len2;
  char *carg2;
  int carg3;
  int i4, len4;
  float *carg4;
  VALUE value4;
  int i5, len5;
  float *carg5;
  int i6, len6;
  float *carg6;
  int i7, len7;
  float *carg7;
  int i8;
  float *carg8;
  VALUE value8;
  float carg9;
  VALUE value9;

  Check_Type(arg4, T_ARRAY);
  len4 = RARRAY(arg4)->len;
  Check_Type(arg5, T_ARRAY);
  len5 = RARRAY(arg5)->len;
  Check_Type(arg6, T_ARRAY);
  len6 = RARRAY(arg6)->len;
  Check_Type(arg7, T_ARRAY);
  len7 = RARRAY(arg7)->len;
  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  carg3 = len4;
  carg4 = ALLOCA_N(float, len4);
  for (i4 = 0; i4 < len4; i4++)
    carg4[i4] = NUM2DBL(RARRAY(arg4)->ptr[i4]);
  carg5 = ALLOCA_N(float, len5);
  for (i5 = 0; i5 < len5; i5++)
    carg5[i5] = NUM2DBL(RARRAY(arg5)->ptr[i5]);
  carg6 = ALLOCA_N(float, len6);
  for (i6 = 0; i6 < len6; i6++)
    carg6[i6] = NUM2DBL(RARRAY(arg6)->ptr[i6]);
  carg7 = ALLOCA_N(float, len7);
  for (i7 = 0; i7 < len7; i7++)
    carg7[i7] = NUM2DBL(RARRAY(arg7)->ptr[i7]);
  carg8 = ALLOCA_N(float, carg3);
  hfithn_(&carg0, carg1, carg2, &carg3, carg4, carg5, carg6, carg7, carg8, &carg9, len1, len2);
  value4 = rb_ary_new2(len4);
  for (i4 = 0; i4 < len4; i4++)
    rb_ary_store(value4, i4, rb_float_new(carg4[i4]));
  value8 = rb_ary_new2(carg3);
  for (i8 = 0; i8 < carg3; i8++)
    rb_ary_store(value8, i8, rb_float_new(carg8[i8]));
  value9 = rb_float_new(carg9);

  return rb_ary_new3(3, value4, value8, value9);
}

static VALUE _wrap_hfn(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int i1, len1;
  float *carg1;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  carg0 = NUM2INT(arg0);
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  hfn_(&carg0, carg1);

  return Qnil;
}

static VALUE _wrap_hfpak1(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  VALUE value1;
  int i2, len2;
  float *carg2;
  int carg3;

  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  carg3 = len2;
  hfpak1_(&carg0, &carg1, carg2, &carg3);
  value1 = INT2NUM(carg1);

  return value1;
}

static VALUE _wrap_hf1(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  float carg1;
  float carg2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  hf1_(&carg0, &carg1, &carg2);

  return Qnil;
}

static VALUE _wrap_hf1e(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  float carg1;
  float carg2;
  float carg3;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  hf1e_(&carg0, &carg1, &carg2, &carg3);

  return Qnil;
}

static VALUE _wrap_hf2(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  float carg1;
  float carg2;
  float carg3;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  hf2_(&carg0, &carg1, &carg2, &carg3);

  return Qnil;
}

static VALUE _wrap_hgive(VALUE self, VALUE arg0)
{
  int carg0;
  int len1;
  char *carg1;
  VALUE value1;
  int carg2;
  VALUE value2;
  float carg3;
  VALUE value3;
  float carg4;
  VALUE value4;
  int carg5;
  VALUE value5;
  float carg6;
  VALUE value6;
  float carg7;
  VALUE value7;
  int carg8;
  VALUE value8;
  int carg9;
  VALUE value9;

  carg0 = NUM2INT(arg0);
  len1 = 100;
  carg1 = ALLOCA_N(char, len1 + 1);
  hgive_(&carg0, carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7, &carg8, &carg9, len1);
  len1 = util_str_f2c(carg1, len1);
  value1 = rb_str_new(carg1, len1);
  value2 = INT2NUM(carg2);
  value3 = rb_float_new(carg3);
  value4 = rb_float_new(carg4);
  value5 = INT2NUM(carg5);
  value6 = rb_float_new(carg6);
  value7 = rb_float_new(carg7);
  value8 = INT2NUM(carg8);
  value9 = INT2NUM(carg9);

  return rb_ary_new3(9, value1, value2, value3, value4, value5, value6, value7, value8, value9);
}

static VALUE _wrap_hgiven(VALUE self, VALUE arg0, VALUE arg2)
{
  int carg0;
  int len1;
  char *carg1;
  VALUE value1;
  int carg2;
  int len3;
  char *carg3;
  VALUE value3;
  int i4;
  float *carg4;
  VALUE value4;
  int i5;
  float *carg5;
  VALUE value5;

  carg2 = NUM2INT(arg2);
  len3 = 8;
  carg0 = NUM2INT(arg0);
  len1 = 100;
  carg1 = ALLOCA_N(char, len1 + 1);
  carg3 = ALLOCA_N(char, len3 * (carg2) + 1);
  carg4 = ALLOCA_N(float, carg2);
  carg5 = ALLOCA_N(float, carg2);
  hgiven_(&carg0, carg1, &carg2, carg3, carg4, carg5, len1, len3);
  len1 = util_str_f2c(carg1, len1);
  value1 = rb_str_new(carg1, len1);
  value3 = util_str_ary_f2rb(carg3, len3, carg2);
  value4 = rb_ary_new2(carg2);
  for (i4 = 0; i4 < carg2; i4++)
    rb_ary_store(value4, i4, rb_float_new(carg4[i4]));
  value5 = rb_ary_new2(carg2);
  for (i5 = 0; i5 < carg2; i5++)
    rb_ary_store(value5, i5, rb_float_new(carg5[i5]));

  return rb_ary_new3(4, value1, value3, value4, value5);
}

static VALUE _wrap_hkind(VALUE self, VALUE arg0, VALUE arg2)
{
  int carg0;
  int i1, *carg1;
  VALUE value1;
  int len2;
  char *carg2;

  carg0 = NUM2INT(arg0);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  carg1 = ALLOCA_N(int, 32);
  hkind_(&carg0, carg1, carg2, len2);
  value1 = rb_ary_new2(32);
  for (i1 = 0; i1 < 32; i1++)
    rb_ary_store(value1, i1, INT2NUM(carg1[i1]));

  return value1;
}

static VALUE _wrap_hgnpar(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int len1;
  char *carg1;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  hgnpar_(&carg0, carg1, len1);

  return Qnil;
}

static VALUE _wrap_hidall(VALUE self, VALUE arg1)
{
  int i0, *carg0;
  VALUE value0;
  int carg1;

  carg1 = NUM2INT(arg1);
  carg0 = ALLOCA_N(int, carg1);
  hidall_(carg0, &carg1);
  value0 = rb_ary_new2(carg1);
  for (i0 = 0; i0 < carg1; i0++)
    rb_ary_store(value0, i0, INT2NUM(carg0[i0]));

  return value0;
}

static VALUE _wrap_hidopt(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int len1;
  char *carg1;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  hidopt_(&carg0, carg1, len1);

  return Qnil;
}

static VALUE _wrap_hid1(VALUE self, VALUE arg1)
{
  int i0, *carg0;
  VALUE value0;
  int carg1;

  carg1 = NUM2INT(arg1);
  carg0 = ALLOCA_N(int, carg1);
  hid1_(carg0, &carg1);
  value0 = rb_ary_new2(carg1);
  for (i0 = 0; i0 < carg1; i0++)
    rb_ary_store(value0, i0, INT2NUM(carg0[i0]));

  return value0;
}

static VALUE _wrap_hid2(VALUE self, VALUE arg1)
{
  int i0, *carg0;
  VALUE value0;
  int carg1;

  carg1 = NUM2INT(arg1);
  carg0 = ALLOCA_N(int, carg1);
  hid2_(carg0, &carg1);
  value0 = rb_ary_new2(carg1);
  for (i0 = 0; i0 < carg1; i0++)
    rb_ary_store(value0, i0, INT2NUM(carg0[i0]));

  return value0;
}

static VALUE _wrap_hijxy(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  int carg2;
  float carg3;
  VALUE value3;
  float carg4;
  VALUE value4;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  hijxy_(&carg0, &carg1, &carg2, &carg3, &carg4);
  value3 = rb_float_new(carg3);
  value4 = rb_float_new(carg4);

  return rb_assoc_new(value3, value4);
}

static VALUE _wrap_hindex(VALUE self)
{

  hindex_();

  return Qnil;
}

static VALUE _wrap_hipak1(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  VALUE value1;
  int i2, len2, *carg2;
  int carg3;

  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = ALLOCA_N(int, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2INT(RARRAY(arg2)->ptr[i2]);
  carg3 = len2;
  hipak1_(&carg0, &carg1, carg2, &carg3);
  value1 = INT2NUM(carg1);

  return value1;
}

static VALUE _wrap_histdo(VALUE self)
{

  histdo_();

  return Qnil;
}

static VALUE _wrap_hix(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;
  float carg2;
  VALUE value2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  hix_(&carg0, &carg1, &carg2);
  value2 = rb_float_new(carg2);

  return value2;
}

static VALUE _wrap_hldir(VALUE self, VALUE arg0, VALUE arg1)
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
  hldir_(carg0, carg1, len0, len1);

  return Qnil;
}

static VALUE _wrap_hlimit(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hlimit_(&carg0);

  return Qnil;
}

static VALUE _wrap_hlnext(VALUE self, VALUE arg0, VALUE arg3)
{
  int carg0;
  VALUE value0;
  int len1;
  char *carg1;
  VALUE value1;
  int len2;
  char *carg2;
  VALUE value2;
  int len3;
  char *carg3;

  carg0 = NUM2INT(arg0);
  len1 = 0;
  carg1 = ALLOCA_N(char, len1 + 1);
  len2 = 0;
  carg2 = ALLOCA_N(char, len2 + 1);
  Check_Type(arg3, T_STRING);
  len3 = RSTRING(arg3)->len;
  carg3 = ALLOCA_N(char, len3 + 1);
  strcpy(carg3, STR2CSTR(arg3));
  hlnext_(&carg0, carg1, carg2, carg3, len1, len2, len3);
  value0 = INT2NUM(carg0);
  len1 = util_str_f2c(carg1, len1);
  value1 = rb_str_new(carg1, len1);
  len2 = util_str_f2c(carg2, len2);
  value2 = rb_str_new(carg2, len2);

  return rb_ary_new3(3, value0, value1, value2);
}

static VALUE _wrap_hlocat(VALUE self, VALUE arg0)
{
  int carg0;
  int carg1;
  VALUE value1;

  carg0 = NUM2INT(arg0);
  hlocat_(&carg0, &carg1);
  value1 = INT2NUM(carg1);

  return value1;
}

static VALUE _wrap_hmaxim(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  float carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  hmaxim_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_hmerge(VALUE self, VALUE arg1, VALUE arg2)
{
  int carg0;
  int len1;
  char *carg1;
  int len2;
  char *carg2;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  carg0 = len1;
  carg1 = ALLOCA_N(char, 8 * len1 + 1);
  util_str_ary_rb2f(arg1, 8, carg1);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  hmerge_(&carg0, carg1, carg2, 8, len2);

  return Qnil;
}

static VALUE _wrap_hmergin(VALUE self)
{

  hmergin_();

  return Qnil;
}

static VALUE _wrap_hmdir(VALUE self, VALUE arg0, VALUE arg1)
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
  hmdir_(carg0, carg1, len0, len1);

  return Qnil;
}

static VALUE _wrap_hminim(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  float carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  hminim_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_hnoent(VALUE self, VALUE arg0)
{
  int carg0;
  int carg1;
  VALUE value1;

  carg0 = NUM2INT(arg0);
  hnoent_(&carg0, &carg1);
  value1 = INT2NUM(carg1);

  return value1;
}

static VALUE _wrap_hopera(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5)
{
  int carg0;
  int len1;
  char *carg1;
  int carg2;
  int carg3;
  float carg4;
  float carg5;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  carg3 = NUM2INT(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  hopera_(&carg0, carg1, &carg2, &carg3, &carg4, &carg5, len1);

  return Qnil;
}

static VALUE _wrap_houtpu(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  houtpu_(&carg0);

  return Qnil;
}

static VALUE _wrap_hpagsz(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hpagsz_(&carg0);

  return Qnil;
}

static VALUE _wrap_hpak(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int i1, len1;
  float *carg1;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  carg0 = NUM2INT(arg0);
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  hpak_(&carg0, carg1);

  return Qnil;
}

static VALUE _wrap_hpakad(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int i1, len1;
  float *carg1;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  carg0 = NUM2INT(arg0);
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  hpakad_(&carg0, carg1);

  return Qnil;
}

static VALUE _wrap_hpake(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int i1, len1;
  float *carg1;

  Check_Type(arg1, T_ARRAY);
  len1 = RARRAY(arg1)->len;
  carg0 = NUM2INT(arg0);
  carg1 = ALLOCA_N(float, len1);
  for (i1 = 0; i1 < len1; i1++)
    carg1[i1] = NUM2DBL(RARRAY(arg1)->ptr[i1]);
  hpake_(&carg0, carg1);

  return Qnil;
}

static VALUE _wrap_hpchar(VALUE self, VALUE arg0, VALUE arg1)
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
  hpchar_(carg0, carg1, len0, len1);

  return Qnil;
}

static VALUE _wrap_hpdir(VALUE self, VALUE arg0, VALUE arg1)
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
  hpdir_(carg0, carg1, len0, len1);

  return Qnil;
}

static VALUE _wrap_hphist(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int len1;
  char *carg1;
  int carg2;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  hphist_(&carg0, carg1, &carg2, len1);

  return Qnil;
}

static VALUE _wrap_hphs(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hphs_(&carg0);

  return Qnil;
}

static VALUE _wrap_hphst(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hphst_(&carg0);

  return Qnil;
}

static VALUE _wrap_hponce(VALUE self)
{

  hponce_();

  return Qnil;
}

static VALUE _wrap_hprint(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hprint_(&carg0);

  return Qnil;
}

static VALUE _wrap_hprnt(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hprnt_(&carg0);

  return Qnil;
}

static VALUE _wrap_hprot(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int len1;
  char *carg1;
  int carg2;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  hprot_(&carg0, carg1, &carg2, len1);

  return Qnil;
}

static VALUE _wrap_hpscat(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hpscat_(&carg0);

  return Qnil;
}

static VALUE _wrap_hptab(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  hptab_(&carg0);

  return Qnil;
}

static VALUE _wrap_hrebin(VALUE self, VALUE arg0, VALUE arg5, VALUE arg6, VALUE arg7)
{
  int carg0;
  int i1;
  float *carg1;
  VALUE value1;
  int i2;
  float *carg2;
  VALUE value2;
  int i3;
  float *carg3;
  VALUE value3;
  int i4;
  float *carg4;
  VALUE value4;
  int carg5;
  int carg6;
  int carg7;

  carg5 = NUM2INT(arg5);
  carg0 = NUM2INT(arg0);
  carg6 = NUM2INT(arg6);
  carg7 = NUM2INT(arg7);
  carg1 = ALLOCA_N(float, carg5);
  carg2 = ALLOCA_N(float, carg5);
  carg3 = ALLOCA_N(float, carg5);
  carg4 = ALLOCA_N(float, carg5);
  hrebin_(&carg0, carg1, carg2, carg3, carg4, &carg5, &carg6, &carg7);
  value1 = rb_ary_new2(carg5);
  for (i1 = 0; i1 < carg5; i1++)
    rb_ary_store(value1, i1, rb_float_new(carg1[i1]));
  value2 = rb_ary_new2(carg5);
  for (i2 = 0; i2 < carg5; i2++)
    rb_ary_store(value2, i2, rb_float_new(carg2[i2]));
  value3 = rb_ary_new2(carg5);
  for (i3 = 0; i3 < carg5; i3++)
    rb_ary_store(value3, i3, rb_float_new(carg3[i3]));
  value4 = rb_ary_new2(carg5);
  for (i4 = 0; i4 < carg5; i4++)
    rb_ary_store(value4, i4, rb_float_new(carg4[i4]));

  return rb_ary_new3(4, value1, value2, value3, value4);
}

static VALUE _wrap_hrend(VALUE self, VALUE arg0)
{
  int len0;
  char *carg0;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  hrend_(carg0, len0);

  return Qnil;
}

static VALUE _wrap_hreset(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int len1;
  char *carg1;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  hreset_(&carg0, carg1, len1);

  return Qnil;
}

static VALUE _wrap_hrename(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
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
  hrename_(&carg0, carg1, carg2, len1, len2);

  return Qnil;
}

static VALUE _wrap_hrfile(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
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
  hrfile_(&carg0, carg1, carg2, len1, len2);

  return Qnil;
}

static VALUE _wrap_hrget(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
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
  hrget_(&carg0, carg1, carg2, len1, len2);

  return Qnil;
}

static VALUE _wrap_hrin(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  int carg2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  hrin_(&carg0, &carg1, &carg2);

  return Qnil;
}

static VALUE _wrap_hrndm2(VALUE self, VALUE arg0)
{
  int carg0;
  float carg1;
  VALUE value1;
  float carg2;
  VALUE value2;

  carg0 = NUM2INT(arg0);
  hrndm2_(&carg0, &carg1, &carg2);
  value1 = rb_float_new(carg1);
  value2 = rb_float_new(carg2);

  return rb_assoc_new(value1, value2);
}

static VALUE _wrap_hropen(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  int carg0;
  int len1;
  char *carg1;
  int len2;
  char *carg2;
  int len3;
  char *carg3;
  int carg4;
  int carg5;
  VALUE value5;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  Check_Type(arg3, T_STRING);
  len3 = RSTRING(arg3)->len;
  carg3 = ALLOCA_N(char, len3 + 1);
  strcpy(carg3, STR2CSTR(arg3));
  carg4 = NUM2INT(arg4);
  hropen_(&carg0, carg1, carg2, carg3, &carg4, &carg5, len1, len2, len3);
  value5 = INT2NUM(carg5);

  return value5;
}

static VALUE _wrap_hrout(VALUE self, VALUE arg0, VALUE arg2)
{
  int carg0;
  int carg1;
  VALUE value1;
  int len2;
  char *carg2;

  carg0 = NUM2INT(arg0);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  hrout_(&carg0, &carg1, carg2, len2);
  value1 = INT2NUM(carg1);

  return value1;
}

static VALUE _wrap_hrput(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
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
  hrput_(&carg0, carg1, carg2, len1, len2);

  return Qnil;
}

static VALUE _wrap_hscale(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  float carg1;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  hscale_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_hscr(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  int len2;
  char *carg2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  hscr_(&carg0, &carg1, carg2, len2);

  return Qnil;
}

static VALUE _wrap_hsetpr(VALUE self, VALUE arg0, VALUE arg1)
{
  int len0;
  char *carg0;
  float carg1;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  carg1 = NUM2DBL(arg1);
  hsetpr_(carg0, &carg1, len0);

  return Qnil;
}

static VALUE _wrap_hsmoof(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;
  float carg2;
  VALUE value2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  hsmoof_(&carg0, &carg1, &carg2);
  value2 = rb_float_new(carg2);

  return value2;
}

static VALUE _wrap_hspli1(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  int carg1;
  int carg2;
  int carg3;
  float carg4;
  VALUE value4;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  carg3 = NUM2INT(arg3);
  hspli1_(&carg0, &carg1, &carg2, &carg3, &carg4);
  value4 = rb_float_new(carg4);

  return value4;
}

static VALUE _wrap_hspli2(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  int carg0;
  int carg1;
  int carg2;
  int carg3;
  int carg4;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  carg3 = NUM2INT(arg3);
  carg4 = NUM2INT(arg4);
  hspli2_(&carg0, &carg1, &carg2, &carg3, &carg4);

  return Qnil;
}

static VALUE _wrap_hsquez(VALUE self, VALUE arg0)
{
  int len0;
  char *carg0;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  hsquez_(carg0, len0);

  return Qnil;
}

static VALUE _wrap_htitle(VALUE self, VALUE arg0)
{
  int len0;
  char *carg0;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  htitle_(carg0, len0);

  return Qnil;
}

static VALUE _wrap_hunpak(VALUE self, VALUE arg0, VALUE arg2, VALUE arg3)
{
  int carg0;
  int i1;
  float *carg1;
  VALUE value1;
  int len2;
  char *carg2;
  int carg3;

  carg3 = NUM2INT(arg3);
  carg0 = NUM2INT(arg0);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  carg1 = ALLOCA_N(float, carg3);
  hunpak_(&carg0, carg1, carg2, &carg3, len2);
  value1 = rb_ary_new2(carg3);
  for (i1 = 0; i1 < carg3; i1++)
    rb_ary_store(value1, i1, rb_float_new(carg1[i1]));

  return value1;
}

static VALUE _wrap_hunpke(VALUE self, VALUE arg0, VALUE arg2, VALUE arg3)
{
  int carg0;
  int i1;
  float *carg1;
  VALUE value1;
  int len2;
  char *carg2;
  int carg3;

  carg3 = NUM2INT(arg3);
  carg0 = NUM2INT(arg0);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  carg1 = ALLOCA_N(float, carg3);
  hunpke_(&carg0, carg1, carg2, &carg3, len2);
  value1 = rb_ary_new2(carg3);
  for (i1 = 0; i1 < carg3; i1++)
    rb_ary_store(value1, i1, rb_float_new(carg1[i1]));

  return value1;
}

static VALUE _wrap_huwfun(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
{
  int carg0;
  int carg1;
  int len2;
  char *carg2;
  int carg3;
  int len4;
  char *carg4;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  carg3 = NUM2INT(arg3);
  Check_Type(arg4, T_STRING);
  len4 = RSTRING(arg4)->len;
  carg4 = ALLOCA_N(char, len4 + 1);
  strcpy(carg4, STR2CSTR(arg4));
  huwfun_(&carg0, &carg1, carg2, &carg3, carg4, len2, len4);

  return Qnil;
}

static VALUE _wrap_hxi(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  float carg1;
  int carg2;
  VALUE value2;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  hxi_(&carg0, &carg1, &carg2);
  value2 = INT2NUM(carg2);

  return value2;
}

static VALUE _wrap_hxyij(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  float carg1;
  float carg2;
  int carg3;
  VALUE value3;
  int carg4;
  VALUE value4;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  hxyij_(&carg0, &carg1, &carg2, &carg3, &carg4);
  value3 = INT2NUM(carg3);
  value4 = INT2NUM(carg4);

  return rb_assoc_new(value3, value4);
}

static VALUE _wrap_hexist(VALUE self, VALUE arg0)
{
  int carg0;
  int ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  ret = hexist_(&carg0);
  value = ret ? Qtrue : Qfalse;

  return value;
}

static VALUE _wrap_hi(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  ret = hi_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_hie(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int carg1;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  ret = hie_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_hij(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  int carg2;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  ret = hij_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_hije(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int carg1;
  int carg2;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  carg2 = NUM2INT(arg2);
  ret = hije_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_hmax(VALUE self, VALUE arg0)
{
  int carg0;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  ret = hmax_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_hmin(VALUE self, VALUE arg0)
{
  int carg0;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  ret = hmin_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_hrndm1(VALUE self, VALUE arg0)
{
  int carg0;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  ret = hrndm1_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_hspfun(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  float carg1;
  int carg2;
  int carg3;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2INT(arg2);
  carg3 = NUM2INT(arg3);
  ret = hspfun_(&carg0, &carg1, &carg2, &carg3);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_hstaf(VALUE self, VALUE arg0)
{
  int len0;
  char *carg0;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  hstaf_(carg0, len0);

  return Qnil;
}

static VALUE _wrap_hstati(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int carg0;
  int carg1;
  int len2;
  char *carg2;
  int carg3;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2INT(arg1);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  carg3 = NUM2INT(arg3);
  ret = hstati_(&carg0, &carg1, carg2, &carg3, len2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_hsum(VALUE self, VALUE arg0)
{
  int carg0;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  ret = hsum_(&carg0);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_hx(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  float carg1;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  ret = hx_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_hxe(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  float carg1;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  ret = hxe_(&carg0, &carg1);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_hxy(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  float carg1;
  float carg2;
  float ret;
  VALUE value;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  ret = hxy_(&carg0, &carg1, &carg2);
  value = rb_float_new(ret);

  return value;
}

static VALUE _wrap_hlimap(VALUE self, VALUE arg0, VALUE arg1)
{
  int carg0;
  int len1;
  char *carg1;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  hlimap_(&carg0, carg1, len1);

  return Qnil;
}

static VALUE _wrap_hcdir(int argc, VALUE *argv, VALUE self)
{
  if (argc == 1) {
    int len;
    char dir[1024];
    char *opt = STR2CSTR(argv[0]);
    if (strncmp(opt, "r", 1) != 0 && strncmp(opt, "R", 1) != 0)
      rb_raise(rb_eArgError, "wrong # of arguments -- hcdir('R')/hcdir(dir,' ')");
    hcdir_(dir, opt, sizeof(dir), 1);
    len = util_str_f2c(dir, sizeof(dir));
    return rb_str_new(dir, len);
  } else if (argc == 2) {
    char *dir = STR2CSTR(argv[0]);
    char *opt = STR2CSTR(argv[1]);
    if (strncmp(opt, " ", 1) != 0)
      rb_raise(rb_eArgError, "wrong # of arguments -- hcdir('R')/hcdir(dir,' ')");
    hcdir_(dir, opt, strlen(dir), 1);
    return Qnil;
  } else {
    rb_raise(rb_eArgError, "wrong # of arguments -- hcdir('R')/hcdir(dir,' ')");
  }
}

static VALUE _wrap_hrdir(VALUE self, VALUE maxlen)
{
  int num;
  int cmaxlen = NUM2INT(maxlen);
  char *dir = ALLOCA_N(char, 16 * cmaxlen);
  hrdir_(&cmaxlen, dir, &num, 16);
  return util_str_ary_f2rb(dir, 16, num);
}

static VALUE _wrap_hlabel(VALUE self, VALUE id, VALUE label, VALUE opt)
{
  char *clabel;
  int nlabel;
  int cid = NUM2INT(id);
  char *copt = STR2CSTR(opt);
  if (strchr(copt, 'r') != NULL || strchr(copt, 'R') != NULL) {
    nlabel = NUM2INT(label);
    clabel = ALLOCA_N(char, nlabel * 16);
    hlabel_(&cid, &nlabel, clabel, copt, 16, strlen(copt));
    return util_str_ary_f2rb(clabel, 16, nlabel);
  } else {
    Check_Type(label, T_ARRAY);
    nlabel = RARRAY(label)->len;
    clabel = ALLOCA_N(char, nlabel * 16);
    util_str_ary_rb2f(label, 16, clabel);
    hlabel_(&cid, &nlabel, clabel, copt, 16, strlen(copt));
    return Qnil;
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

static float uwfunc_hproj(float *x, int *isel)
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

static VALUE _wrap_hproj1(VALUE self, VALUE hid, VALUE ntid, VALUE flag,
			  VALUE from, VALUE to, VALUE x)
{
  int chid = NUM2INT(hid);
  int cntid = NUM2INT(ntid);
  int cflag = NUM2INT(flag);
  int cfrom = NUM2INT(from);
  int cto = NUM2INT(to);
  int cx = NUM2INT(x);
  if (rb_block_given_p()) {
    current_nt_nvar = get_number_of_ntuple_members(cntid);
    hproj1_(&chid, &cntid, &cflag, uwfunc_hproj, &cfrom, &cto, &cx);
  } else {
    hproj1_(&chid, &cntid, &cflag, NULL, &cfrom, &cto, &cx);
  }
  return Qnil;
}

static VALUE _wrap_hproj2(VALUE self, VALUE hid, VALUE ntid, VALUE flag,
			  VALUE from, VALUE to, VALUE x, VALUE y)
{
  int chid = NUM2INT(hid);
  int cntid = NUM2INT(ntid);
  int cflag = NUM2INT(flag);
  int cfrom = NUM2INT(from);
  int cto = NUM2INT(to);
  int cx = NUM2INT(x);
  int cy = NUM2INT(y);
  if (rb_block_given_p()) {
    current_nt_nvar = get_number_of_ntuple_members(cntid);
    hproj2_(&chid, &cntid, &cflag, uwfunc_hproj, &cfrom, &cto, &cx, &cy);
  } else {
    hproj2_(&chid, &cntid, &cflag, NULL, &cfrom, &cto, &cx, &cy);
  }
  return Qnil;
}



void Init_hbook()
{
  wrap_mCERN = rb_define_module("CERN");
  wrap_mHBook = rb_define_module_under(wrap_mCERN, "HBook");

  rb_define_module_function(wrap_mHBook, "hbandx", _wrap_hbandx, 4);
  rb_define_module_function(wrap_mHBook, "hbandy", _wrap_hbandy, 4);
  rb_define_module_function(wrap_mHBook, "hbarx", _wrap_hbarx, 1);
  rb_define_module_function(wrap_mHBook, "hbary", _wrap_hbary, 1);
  rb_define_module_function(wrap_mHBook, "hbar2", _wrap_hbar2, 1);
  rb_define_module_function(wrap_mHBook, "hbfun1", _wrap_hbfun1, 5);
  rb_define_module_function(wrap_mHBook, "hbfun2", _wrap_hbfun2, 8);
  rb_define_module_function(wrap_mHBook, "hbigbi", _wrap_hbigbi, 2);
  rb_define_module_function(wrap_mHBook, "hrenid", _wrap_hrenid, 2);
  rb_define_module_function(wrap_mHBook, "hbinsz", _wrap_hbinsz, 1);
  rb_define_module_function(wrap_mHBook, "hntdup", _wrap_hntdup, 5);
  rb_define_module_function(wrap_mHBook, "hbookn", _wrap_hbookn, 5);
  rb_define_module_function(wrap_mHBook, "hbook1", _wrap_hbook1, 6);
  rb_define_module_function(wrap_mHBook, "hbook2", _wrap_hbook2, 9);
  rb_define_module_function(wrap_mHBook, "hbpro", _wrap_hbpro, 2);
  rb_define_module_function(wrap_mHBook, "hbprof", _wrap_hbprof, 8);
  rb_define_module_function(wrap_mHBook, "hbprox", _wrap_hbprox, 2);
  rb_define_module_function(wrap_mHBook, "hbproy", _wrap_hbproy, 2);
  rb_define_module_function(wrap_mHBook, "hbset", _wrap_hbset, 2);
  rb_define_module_function(wrap_mHBook, "hbslix", _wrap_hbslix, 3);
  rb_define_module_function(wrap_mHBook, "hbsliy", _wrap_hbsliy, 3);
  rb_define_module_function(wrap_mHBook, "hcompa", _wrap_hcompa, 1);
  rb_define_module_function(wrap_mHBook, "hcopy", _wrap_hcopy, 3);
  rb_define_module_function(wrap_mHBook, "hcopyr", _wrap_hcopyr, 8);
  rb_define_module_function(wrap_mHBook, "hdelet", _wrap_hdelet, 1);
  rb_define_module_function(wrap_mHBook, "hddir", _wrap_hddir, 1);
  rb_define_module_function(wrap_mHBook, "hdump", _wrap_hdump, 1);
  rb_define_module_function(wrap_mHBook, "hermes", _wrap_hermes, 1);
  rb_define_module_function(wrap_mHBook, "hfc1", _wrap_hfc1, 5);
  rb_define_module_function(wrap_mHBook, "hfc2", _wrap_hfc2, 7);
  rb_define_module_function(wrap_mHBook, "hff1", _wrap_hff1, 4);
  rb_define_module_function(wrap_mHBook, "hff2", _wrap_hff2, 5);
  rb_define_module_function(wrap_mHBook, "hfill", _wrap_hfill, 4);
  rb_define_module_function(wrap_mHBook, "hfinam", _wrap_hfinam, 2);
  rb_define_module_function(wrap_mHBook, "hfithn", _wrap_hfithn, 7);
  rb_define_module_function(wrap_mHBook, "hfn", _wrap_hfn, 2);
  rb_define_module_function(wrap_mHBook, "hfpak1", _wrap_hfpak1, 3);
  rb_define_module_function(wrap_mHBook, "hf1", _wrap_hf1, 3);
  rb_define_module_function(wrap_mHBook, "hf1e", _wrap_hf1e, 4);
  rb_define_module_function(wrap_mHBook, "hf2", _wrap_hf2, 4);
  rb_define_module_function(wrap_mHBook, "hgive", _wrap_hgive, 1);
  rb_define_module_function(wrap_mHBook, "hgiven", _wrap_hgiven, 2);
  rb_define_module_function(wrap_mHBook, "hkind", _wrap_hkind, 2);
  rb_define_module_function(wrap_mHBook, "hgnpar", _wrap_hgnpar, 2);
  rb_define_module_function(wrap_mHBook, "hidall", _wrap_hidall, 1);
  rb_define_module_function(wrap_mHBook, "hidopt", _wrap_hidopt, 2);
  rb_define_module_function(wrap_mHBook, "hid1", _wrap_hid1, 1);
  rb_define_module_function(wrap_mHBook, "hid2", _wrap_hid2, 1);
  rb_define_module_function(wrap_mHBook, "hijxy", _wrap_hijxy, 3);
  rb_define_module_function(wrap_mHBook, "hindex", _wrap_hindex, 0);
  rb_define_module_function(wrap_mHBook, "hipak1", _wrap_hipak1, 3);
  rb_define_module_function(wrap_mHBook, "histdo", _wrap_histdo, 0);
  rb_define_module_function(wrap_mHBook, "hix", _wrap_hix, 2);
  rb_define_module_function(wrap_mHBook, "hldir", _wrap_hldir, 2);
  rb_define_module_function(wrap_mHBook, "hlimit", _wrap_hlimit, 1);
  rb_define_module_function(wrap_mHBook, "hlnext", _wrap_hlnext, 2);
  rb_define_module_function(wrap_mHBook, "hlocat", _wrap_hlocat, 1);
  rb_define_module_function(wrap_mHBook, "hmaxim", _wrap_hmaxim, 2);
  rb_define_module_function(wrap_mHBook, "hmerge", _wrap_hmerge, 2);
  rb_define_module_function(wrap_mHBook, "hmergin", _wrap_hmergin, 0);
  rb_define_module_function(wrap_mHBook, "hmdir", _wrap_hmdir, 2);
  rb_define_module_function(wrap_mHBook, "hminim", _wrap_hminim, 2);
  rb_define_module_function(wrap_mHBook, "hnoent", _wrap_hnoent, 1);
  rb_define_module_function(wrap_mHBook, "hopera", _wrap_hopera, 6);
  rb_define_module_function(wrap_mHBook, "houtpu", _wrap_houtpu, 1);
  rb_define_module_function(wrap_mHBook, "hpagsz", _wrap_hpagsz, 1);
  rb_define_module_function(wrap_mHBook, "hpak", _wrap_hpak, 2);
  rb_define_module_function(wrap_mHBook, "hpakad", _wrap_hpakad, 2);
  rb_define_module_function(wrap_mHBook, "hpake", _wrap_hpake, 2);
  rb_define_module_function(wrap_mHBook, "hpchar", _wrap_hpchar, 2);
  rb_define_module_function(wrap_mHBook, "hpdir", _wrap_hpdir, 2);
  rb_define_module_function(wrap_mHBook, "hphist", _wrap_hphist, 3);
  rb_define_module_function(wrap_mHBook, "hphs", _wrap_hphs, 1);
  rb_define_module_function(wrap_mHBook, "hphst", _wrap_hphst, 1);
  rb_define_module_function(wrap_mHBook, "hponce", _wrap_hponce, 0);
  rb_define_module_function(wrap_mHBook, "hprint", _wrap_hprint, 1);
  rb_define_module_function(wrap_mHBook, "hprnt", _wrap_hprnt, 1);
  rb_define_module_function(wrap_mHBook, "hprot", _wrap_hprot, 3);
  rb_define_module_function(wrap_mHBook, "hpscat", _wrap_hpscat, 1);
  rb_define_module_function(wrap_mHBook, "hptab", _wrap_hptab, 1);
  rb_define_module_function(wrap_mHBook, "hrebin", _wrap_hrebin, 4);
  rb_define_module_function(wrap_mHBook, "hrend", _wrap_hrend, 1);
  rb_define_module_function(wrap_mHBook, "hreset", _wrap_hreset, 2);
  rb_define_module_function(wrap_mHBook, "hrename", _wrap_hrename, 3);
  rb_define_module_function(wrap_mHBook, "hrfile", _wrap_hrfile, 3);
  rb_define_module_function(wrap_mHBook, "hrget", _wrap_hrget, 3);
  rb_define_module_function(wrap_mHBook, "hrin", _wrap_hrin, 3);
  rb_define_module_function(wrap_mHBook, "hrndm2", _wrap_hrndm2, 1);
  rb_define_module_function(wrap_mHBook, "hropen", _wrap_hropen, 5);
  rb_define_module_function(wrap_mHBook, "hrout", _wrap_hrout, 2);
  rb_define_module_function(wrap_mHBook, "hrput", _wrap_hrput, 3);
  rb_define_module_function(wrap_mHBook, "hscale", _wrap_hscale, 2);
  rb_define_module_function(wrap_mHBook, "hscr", _wrap_hscr, 3);
  rb_define_module_function(wrap_mHBook, "hsetpr", _wrap_hsetpr, 2);
  rb_define_module_function(wrap_mHBook, "hsmoof", _wrap_hsmoof, 2);
  rb_define_module_function(wrap_mHBook, "hspli1", _wrap_hspli1, 4);
  rb_define_module_function(wrap_mHBook, "hspli2", _wrap_hspli2, 5);
  rb_define_module_function(wrap_mHBook, "hsquez", _wrap_hsquez, 1);
  rb_define_module_function(wrap_mHBook, "htitle", _wrap_htitle, 1);
  rb_define_module_function(wrap_mHBook, "hunpak", _wrap_hunpak, 3);
  rb_define_module_function(wrap_mHBook, "hunpke", _wrap_hunpke, 3);
  rb_define_module_function(wrap_mHBook, "huwfun", _wrap_huwfun, 5);
  rb_define_module_function(wrap_mHBook, "hxi", _wrap_hxi, 2);
  rb_define_module_function(wrap_mHBook, "hxyij", _wrap_hxyij, 3);
  rb_define_module_function(wrap_mHBook, "hexist", _wrap_hexist, 1);
  rb_define_module_function(wrap_mHBook, "hi", _wrap_hi, 2);
  rb_define_module_function(wrap_mHBook, "hie", _wrap_hie, 2);
  rb_define_module_function(wrap_mHBook, "hij", _wrap_hij, 3);
  rb_define_module_function(wrap_mHBook, "hije", _wrap_hije, 3);
  rb_define_module_function(wrap_mHBook, "hmax", _wrap_hmax, 1);
  rb_define_module_function(wrap_mHBook, "hmin", _wrap_hmin, 1);
  rb_define_module_function(wrap_mHBook, "hrndm1", _wrap_hrndm1, 1);
  rb_define_module_function(wrap_mHBook, "hspfun", _wrap_hspfun, 4);
  rb_define_module_function(wrap_mHBook, "hstaf", _wrap_hstaf, 1);
  rb_define_module_function(wrap_mHBook, "hstati", _wrap_hstati, 4);
  rb_define_module_function(wrap_mHBook, "hsum", _wrap_hsum, 1);
  rb_define_module_function(wrap_mHBook, "hx", _wrap_hx, 2);
  rb_define_module_function(wrap_mHBook, "hxe", _wrap_hxe, 2);
  rb_define_module_function(wrap_mHBook, "hxy", _wrap_hxy, 3);
  rb_define_module_function(wrap_mHBook, "hlimap", _wrap_hlimap, 2);
  rb_define_module_function(wrap_mHBook, "hcdir", _wrap_hcdir, -1);
  rb_define_module_function(wrap_mHBook, "hrdir", _wrap_hrdir, 1);
  rb_define_module_function(wrap_mHBook, "hlabel", _wrap_hlabel, 3);
  rb_define_module_function(wrap_mHBook, "hproj1", _wrap_hproj1, 6);
  rb_define_module_function(wrap_mHBook, "hproj2", _wrap_hproj2, 7);


  rb_define_const(wrap_mHBook, "NWPAWC", INT2NUM(NWPAWC));
}
