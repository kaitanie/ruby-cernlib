#include <ruby.h>
#include "cernlib_util.h"

#define NWPAWC 1000000
#define NGCBANK 10000000

struct {
  float q[NGCBANK];
} gcbank_;
struct {
  float h[NWPAWC];
} pawc_;

static ID cern_id_id;

static VALUE wrap_mCERN;
VALUE wrap_mGEANT;


struct {
  int idebug;
  int idemin;
  int idemax;
  int itest;
  int idrun;
  int idevt;
  int ieorun;
  int ieotri;
  int ievent;
  int iswit[10];
  int ifinit[20];
  int nevent;
  int nrndm[2];
} gcflag_;

struct {
  int nhsta;
  int nget;
  int nsave;
  int nsets;
  int nprin;
  int ngeom;
  int nview;
  int nplot;
  int nstat;
  int lhsta[20];
  int lget[20];
  int lsave[20];
  int lsets[20];
  int lprin[20];
  int lgeom[20];
  int lview[20];
  int lplot[20];
  int lstat[20];
} gclist_;

struct {
  float pi;
  float twopi;
  float piby2;
  float degrad;
  float raddeg;
  float clight;
  float big;
  float emass;
} gconst_;

struct {
  int ikine;
  float pkine[10];
  int itra;
  int istak;
  int ivert;
  int ipart;
  int itrtyp;
  int napart[5];
  float amass;
  float charge;
  float tlife;
  float vert[3];
  float pvert[4];
  int ipaold;
} gckine_;

struct {
  int ihset;
  int ihdet;
  int iset;
  int idet;
  int idtype;
  int nvname;
  int numbv[20];
} gcsets_;

struct {
  int numed;
  int natmed[5];
  int isvol;
  int ifield;
  float fieldm;
  float tmaxfd;
  float dmaxms;
  float deemax;
  float epsil;
  float stmin;
  float cfield;
  float prec;
  int iupd;
  int istpar;
  int numold;
} gctmed_;

struct {
  int kcase;
  int ngkine;
  float gkin[5][100];
  float tofd[100];
  int iflgk[100];
} gcking_;

struct {
  int ngphoto;
  float xphoto[11][800];
} gckin2_;

struct {
  float gpos[3][100];
} gckin3_;

struct {
  float vect[7];
  float getot;
  float gekin;
  float vout[7];
  int nmec;
  int lmec[30];
  int namec[30];
  int nstep;
  int maxnst;
  float destep;
  float destel;
  float safety;
  float sleng;
  float step;
  float snext;
  float sfield;
  float tofg;
  float gekrat;
  float upwght;
  int ignext;
  int inwvol;
  int istop;
  int igauto;
  int iekbin;
  int ilosl;
  int imull;
  int ingoto;
  int nldown;
  int nlevin;
  int nlvsav;
  int istory;
} gctrak_;

struct {
  int nlevel;
  int names[15];
  int number[15];
  int lvolum[15];
  int lindex[15];
  int infrom;
  int nlevmx;
  int nldev[15];
  int linmx[15];
  float gtran[3][15];
  float grmat[10][15];
  float gonly[15];
  float glx[3];
} gcvolu_;

struct {
  float cutgam;
  float cutele;
  float cutneu;
  float cuthad;
  float cutmuo;
  float bcute;
  float bcutm;
  float dcute;
  float dcutm;
  float ppcutm;
  float tofmax;
  float gcuts[5];
} gccuts_;

struct {
  int numnod;
  int maxnod;
  int numnd1;
  int levver;
  int levhor;
  int maxv;
  int ipick;
  int mlevv;
  int mlevh;
  int nwcut;
  int jnam;
  int jmot;
  int jxon;
  int jbro;
  int jdup;
  int jsca;
  int jdvm;
  int jpsm;
  int jnam1;
  int jmot1;
  int jxon1;
  int jbro1;
  int jdup1;
  int jsca1;
  int julev;
  int jvlev;
  int looktb[16];
  float grmat0[10];
  float gtran0[3];
  int idrnum;
  float gsin[41];
  float gcos[41];
  float sinpsi;
  float cospsi;
  float gtheta;
  float gphi;
  float gpsi;
  float gu0;
  float gv0;
  float gscu;
  float gscv;
  int ngview;
  int icutfl;
  int icut;
  float ctheta;
  float cphi;
  float dcut;
  int nsurf;
  int isurf;
  float gzua;
  float gzva;
  float gzub;
  float gzvb;
  float gzuc;
  float gzvc;
  float pltrnx;
  float pltrny;
  int linatt;
  int linatp;
  int itxatt;
  int ithrz;
  int iprj;
  float dpers;
  int itr3d;
  int ipkhit;
  int iobj;
  int linbumaxgu;
  int morgu;
  int maxgs;
  int morgs;
  int maxtu;
  int mortu;
  int maxts;
  int morts;
  int igu;
  int igs;
  int itu;
  int its;
  int nkview;
  int idview;
  int nopen;
  int igmr;
  int ipions;
  int itrkop;
  int ihiden;
  float zzfu;
  float zzfv;
  int myisel;
  float ddummy[15];
} gcdraw_;

struct {
  int nmat;
  int namate[5];
  float a;
  float z;
  float dens;
  float radl;
  float absl;
} gcmate_;

struct {
  int nmate;
  int nvolum;
  int nrotm;
  int ntmed;
  int ntmult;
  int ntrack;
  int npart;
  int nstmax;
  int nvertx;
  int nhead;
  int nbit;
} gcnum_;

struct {
  int ipair;
  float spair;
  float slpair;
  float zintpa;
  float steppa;
  int icomp;
  float scomp;
  float slcomp;
  float zintco;
  float stepco;
  int iphot;
  float sphot;
  float slphot;
  float zintph;
  float stepph;
  int ipfis;
  float spfis;
  float slpfis;
  float zintpf;
  float steppf;
  int idray;
  float sdray;
  float sldray;
  float zintdr;
  float stepdr;
  int ianni;
  float sanni;
  float slanni;
  float zintan;
  float stepan;
  int ibrem;
  float sbrem;
  float slbrem;
  float zintbr;
  float stepbr;
  int ihadr;
  float shadr;
  float slhadr;
  float zintha;
  float stepha;
  int imunu;
  float smunu;
  float slmunu;
  float zintmu;
  float stepmu;
  int idcay;
  float sdcay;
  float slife;
  float sumlif;
  float dphys1;
  int iloss;
  float sloss;
  float soloss;
  float stloss;
  float dphys2;
  int imuls;
  float smuls;
  float somuls;
  float stmuls;
  float dphys3;
  int irayl;
  float srayl;
  float slrayl;
  float zintra;
  float stepra;
} gcphys_;

struct {
  int ilabs;
  float slabs;
  float sllabs;
  float zintla;
  float stepla;
  int isync;
  int istra;
} gcphlt_;

struct {
  int iparam;
  float pcutga;
  float pcutel;
  float pcutne;
  float pcutha;
  float pcutmu;
  int nspara;
  int mpstak;
  int npgene;
} gcparm_;

struct {
  float epsix0[5000];
  int idrphi[5000];
  int idrtet[5000];
  int idrout[5000];
  int jplost[5000];
  int iphtmp[5000];
  float bitphi[5000];
  float bittet[5000];
  float bitpot[5000];
  int jjlost;
  int jjfill;
  int jentry;
  int jempty;
  float epsmax;
  int jjtemp;
  int jjwork;
  int jjstk1;
  int j1temp;
  int j1stk1;
  int ifounp;
  int ifount;
  int ifnpot;
  float symphi;
  float symteu;
  float symted;
} gcpara_;

struct {
  float aiel[20];
  float aiin[20];
  float aifi[20];
  float aica[20];
  float alam;
  int k0flag;
} gsecti_;

extern void gdaxis_(float*, float*, float*, float*);
extern void gdclos_();
extern void gdhead_(int*, char*, float*, int);
extern void gdinit_();
extern void gdman_(float*, float*);
extern void gdopen_(int*);
extern void gdopt_(char*, char*, int, int);
extern void gdraw_(char*, float*, float*, float*, float*, float*, float*, float*, int);
extern void gdrawc_(char*, int*, float*, float*, float*, float*, float*, int);
extern void gdrawt_(float*, float*, char*, float*, float*, int*, int*, int);
extern void gdrawv_(float*, float*, int*);
extern void gdrawx_(char*, float*, float*, float*, float*, float*, float*, float*, float*, float*, int);
extern void gdscal_(float*, float*);
extern void gdshow_(int*);
extern void gdwmn1_(float*, float*);
extern void gdwmn2_(float*, float*);
extern void gdwmn3_(float*, float*);
extern void gffgo_();
extern void ggclos_();
extern void ginit_();
extern void gmate_();
extern void gpart_();
extern void gphysi_();
extern void gprint_(char*, int*, int);
extern void grun_();
extern void gsatt_(char*, char*, int*, int, int);
extern void gsdet_(char*, char*, int*, char*, int*, int*, int*, int*, int*, int*, int, int, int);
extern void gsdvn_(char*, char*, int*, int*, int, int);
extern void gsmixt_(int*, char*, float*, float*, float*, int*, float*, int);
extern void gspos_(char*, int*, char*, float*, float*, float*, int*, char*, int, int, int);
extern void gsrotm_(int*, float*, float*, float*, float*, float*, float*);
extern void gstmed_(int*, char*, int*, int*, int*, float*, float*, float*, float*, float*, float*, float*, int*, int);
extern void gsvolu_(char*, char*, int*, float*, int*, int*, int, int);
extern void gzebra_(int*);
extern void gzinit_();
extern void ffset_(char*, int*, int);
extern void gdfr_(float*, int*, float*, float*);


static VALUE _wrap_gdaxis(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  float carg0;
  float carg1;
  float carg2;
  float carg3;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  gdaxis_(&carg0, &carg1, &carg2, &carg3);

  return Qnil;
}

static VALUE _wrap_gdclos(VALUE self)
{

  gdclos_();

  return Qnil;
}

static VALUE _wrap_gdhead(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int carg0;
  int len1;
  char *carg1;
  float carg2;

  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2DBL(arg2);
  gdhead_(&carg0, carg1, &carg2, len1);

  return Qnil;
}

static VALUE _wrap_gdinit(VALUE self)
{

  gdinit_();

  return Qnil;
}

static VALUE _wrap_gdman(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  float carg1;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  gdman_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_gdopen(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  gdopen_(&carg0);

  return Qnil;
}

static VALUE _wrap_gdopt(VALUE self, VALUE arg0, VALUE arg1)
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
  gdopt_(carg0, carg1, len0, len1);

  return Qnil;
}

static VALUE _wrap_gdraw(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7)
{
  int len0;
  char *carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;
  float carg6;
  float carg7;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2DBL(arg6);
  carg7 = NUM2DBL(arg7);
  gdraw_(carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7, len0);

  return Qnil;
}

static VALUE _wrap_gdrawc(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6)
{
  int len0;
  char *carg0;
  int carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;
  float carg6;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  carg1 = NUM2INT(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2DBL(arg6);
  gdrawc_(carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, len0);

  return Qnil;
}

static VALUE _wrap_gdrawt(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6)
{
  float carg0;
  float carg1;
  int len2;
  char *carg2;
  float carg3;
  float carg4;
  int carg5;
  int carg6;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2INT(arg5);
  carg6 = NUM2INT(arg6);
  gdrawt_(&carg0, &carg1, carg2, &carg3, &carg4, &carg5, &carg6, len2);

  return Qnil;
}

static VALUE _wrap_gdrawv(VALUE self, VALUE arg0, VALUE arg1)
{
  int i0, len0;
  float *carg0;
  int i1, len1;
  float *carg1;
  int carg2;

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
  gdrawv_(carg0, carg1, &carg2);

  return Qnil;
}

static VALUE _wrap_gdrawx(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7, VALUE arg8, VALUE arg9)
{
  int len0;
  char *carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;
  float carg6;
  float carg7;
  float carg8;
  float carg9;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2DBL(arg6);
  carg7 = NUM2DBL(arg7);
  carg8 = NUM2DBL(arg8);
  carg9 = NUM2DBL(arg9);
  gdrawx_(carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7, &carg8, &carg9, len0);

  return Qnil;
}

static VALUE _wrap_gdscal(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  float carg1;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  gdscal_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_gdshow(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  gdshow_(&carg0);

  return Qnil;
}

static VALUE _wrap_gdwmn1(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  float carg1;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  gdwmn1_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_gdwmn2(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  float carg1;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  gdwmn2_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_gdwmn3(VALUE self, VALUE arg0, VALUE arg1)
{
  float carg0;
  float carg1;

  carg0 = NUM2DBL(arg0);
  carg1 = NUM2DBL(arg1);
  gdwmn3_(&carg0, &carg1);

  return Qnil;
}

static VALUE _wrap_gffgo(VALUE self)
{

  gffgo_();

  return Qnil;
}

static VALUE _wrap_ggclos(VALUE self)
{

  ggclos_();

  return Qnil;
}

static VALUE _wrap_ginit(VALUE self)
{

  ginit_();

  return Qnil;
}

static VALUE _wrap_gmate(VALUE self)
{

  gmate_();

  return Qnil;
}

static VALUE _wrap_gpart(VALUE self)
{

  gpart_();

  return Qnil;
}

static VALUE _wrap_gphysi(VALUE self)
{

  gphysi_();

  return Qnil;
}

static VALUE _wrap_gprint(VALUE self, VALUE arg0, VALUE arg1)
{
  int len0;
  char *carg0;
  int carg1;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  carg1 = NUM2INT(arg1);
  gprint_(carg0, &carg1, len0);

  return Qnil;
}

static VALUE _wrap_grun(VALUE self)
{

  grun_();

  return Qnil;
}

static VALUE _wrap_gsatt(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2)
{
  int len0;
  char *carg0;
  int len1;
  char *carg1;
  int carg2;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  gsatt_(carg0, carg1, &carg2, len0, len1);

  return Qnil;
}

static VALUE _wrap_gsdet(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7)
{
  int len0;
  char *carg0;
  int len1;
  char *carg1;
  int carg2;
  int len3;
  char *carg3;
  int i4, len4, *carg4;
  int carg5;
  int carg6;
  int carg7;
  int carg8;
  VALUE value8;
  int carg9;
  VALUE value9;

  Check_Type(arg4, T_ARRAY);
  len4 = RARRAY(arg4)->len;
  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  Check_Type(arg3, T_STRING);
  len3 = RSTRING(arg3)->len;
  carg3 = ALLOCA_N(char, len3 + 1);
  strcpy(carg3, STR2CSTR(arg3));
  carg4 = ALLOCA_N(int, len4);
  for (i4 = 0; i4 < len4; i4++)
    carg4[i4] = NUM2INT(RARRAY(arg4)->ptr[i4]);
  carg5 = NUM2INT(arg5);
  carg6 = NUM2INT(arg6);
  carg7 = NUM2INT(arg7);
  gsdet_(carg0, carg1, &carg2, carg3, carg4, &carg5, &carg6, &carg7, &carg8, &carg9, len0, len1, len3);
  value8 = INT2NUM(carg8);
  value9 = INT2NUM(carg9);

  return rb_assoc_new(value8, value9);
}

static VALUE _wrap_gsdvn(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int len0;
  char *carg0;
  int len1;
  char *carg1;
  int carg2;
  int carg3;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  carg3 = NUM2INT(arg3);
  gsdvn_(carg0, carg1, &carg2, &carg3, len0, len1);

  return Qnil;
}

static VALUE _wrap_gsmixt(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6)
{
  int carg0;
  int len1;
  char *carg1;
  int i2, len2;
  float *carg2;
  int i3, len3;
  float *carg3;
  float carg4;
  int carg5;
  int i6, len6;
  float *carg6;

  Check_Type(arg2, T_ARRAY);
  len2 = RARRAY(arg2)->len;
  Check_Type(arg3, T_ARRAY);
  len3 = RARRAY(arg3)->len;
  Check_Type(arg6, T_ARRAY);
  len6 = RARRAY(arg6)->len;
  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = ALLOCA_N(float, len2);
  for (i2 = 0; i2 < len2; i2++)
    carg2[i2] = NUM2DBL(RARRAY(arg2)->ptr[i2]);
  carg3 = ALLOCA_N(float, len3);
  for (i3 = 0; i3 < len3; i3++)
    carg3[i3] = NUM2DBL(RARRAY(arg3)->ptr[i3]);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2INT(arg5);
  carg6 = ALLOCA_N(float, len6);
  for (i6 = 0; i6 < len6; i6++)
    carg6[i6] = NUM2DBL(RARRAY(arg6)->ptr[i6]);
  gsmixt_(&carg0, carg1, carg2, carg3, &carg4, &carg5, carg6, len1);

  return Qnil;
}

static VALUE _wrap_gspos(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7)
{
  int len0;
  char *carg0;
  int carg1;
  int len2;
  char *carg2;
  float carg3;
  float carg4;
  float carg5;
  int carg6;
  int len7;
  char *carg7;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  carg1 = NUM2INT(arg1);
  Check_Type(arg2, T_STRING);
  len2 = RSTRING(arg2)->len;
  carg2 = ALLOCA_N(char, len2 + 1);
  strcpy(carg2, STR2CSTR(arg2));
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2INT(arg6);
  Check_Type(arg7, T_STRING);
  len7 = RSTRING(arg7)->len;
  carg7 = ALLOCA_N(char, len7 + 1);
  strcpy(carg7, STR2CSTR(arg7));
  gspos_(carg0, &carg1, carg2, &carg3, &carg4, &carg5, &carg6, carg7, len0, len2, len7);

  return Qnil;
}

static VALUE _wrap_gsrotm(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6)
{
  int carg0;
  float carg1;
  float carg2;
  float carg3;
  float carg4;
  float carg5;
  float carg6;

  carg0 = NUM2INT(arg0);
  carg1 = NUM2DBL(arg1);
  carg2 = NUM2DBL(arg2);
  carg3 = NUM2DBL(arg3);
  carg4 = NUM2DBL(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2DBL(arg6);
  gsrotm_(&carg0, &carg1, &carg2, &carg3, &carg4, &carg5, &carg6);

  return Qnil;
}

static VALUE _wrap_gstmed(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4, VALUE arg5, VALUE arg6, VALUE arg7, VALUE arg8, VALUE arg9, VALUE arg10, VALUE arg11)
{
  int carg0;
  int len1;
  char *carg1;
  int carg2;
  int carg3;
  int carg4;
  float carg5;
  float carg6;
  float carg7;
  float carg8;
  float carg9;
  float carg10;
  int i11, len11;
  float *carg11;
  int carg12;

  Check_Type(arg11, T_ARRAY);
  len11 = RARRAY(arg11)->len;
  carg0 = NUM2INT(arg0);
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  carg3 = NUM2INT(arg3);
  carg4 = NUM2INT(arg4);
  carg5 = NUM2DBL(arg5);
  carg6 = NUM2DBL(arg6);
  carg7 = NUM2DBL(arg7);
  carg8 = NUM2DBL(arg8);
  carg9 = NUM2DBL(arg9);
  carg10 = NUM2DBL(arg10);
  carg11 = ALLOCA_N(float, len11);
  for (i11 = 0; i11 < len11; i11++)
    carg11[i11] = NUM2DBL(RARRAY(arg11)->ptr[i11]);
  carg12 = len11;
  gstmed_(&carg0, carg1, &carg2, &carg3, &carg4, &carg5, &carg6, &carg7, &carg8, &carg9, &carg10, carg11, &carg12, len1);

  return Qnil;
}

static VALUE _wrap_gsvolu(VALUE self, VALUE arg0, VALUE arg1, VALUE arg2, VALUE arg3)
{
  int len0;
  char *carg0;
  int len1;
  char *carg1;
  int carg2;
  int i3, len3;
  float *carg3;
  int carg4;
  int carg5;
  VALUE value5;

  Check_Type(arg3, T_ARRAY);
  len3 = RARRAY(arg3)->len;
  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  Check_Type(arg1, T_STRING);
  len1 = RSTRING(arg1)->len;
  carg1 = ALLOCA_N(char, len1 + 1);
  strcpy(carg1, STR2CSTR(arg1));
  carg2 = NUM2INT(arg2);
  carg3 = ALLOCA_N(float, len3);
  for (i3 = 0; i3 < len3; i3++)
    carg3[i3] = NUM2DBL(RARRAY(arg3)->ptr[i3]);
  carg4 = len3;
  gsvolu_(carg0, carg1, &carg2, carg3, &carg4, &carg5, len0, len1);
  value5 = INT2NUM(carg5);

  return value5;
}

static VALUE _wrap_gzebra(VALUE self, VALUE arg0)
{
  int carg0;

  carg0 = NUM2INT(arg0);
  gzebra_(&carg0);

  return Qnil;
}

static VALUE _wrap_gzinit(VALUE self)
{

  gzinit_();

  return Qnil;
}

static VALUE _wrap_ffset(VALUE self, VALUE arg0, VALUE arg1)
{
  int len0;
  char *carg0;
  int carg1;

  Check_Type(arg0, T_STRING);
  len0 = RSTRING(arg0)->len;
  carg0 = ALLOCA_N(char, len0 + 1);
  strcpy(carg0, STR2CSTR(arg0));
  carg1 = NUM2INT(arg1);
  ffset_(carg0, &carg1, len0);

  return Qnil;
}

static VALUE _wrap_gdfr3d(VALUE self, VALUE arg0)
{
  int i0, len0;
  float *carg0;
  int carg1;
  int i2;
  float *carg2;
  VALUE value2;
  int i3;
  float *carg3;
  VALUE value3;

  Check_Type(arg0, T_ARRAY);
  len0 = RARRAY(arg0)->len;
  carg0 = ALLOCA_N(float, len0 * 3);
  for (i0 = 0; i0 < len0; i0++) {
    VALUE ary = RARRAY(arg0)->ptr[i0];
    Check_Type(ary, T_ARRAY);
    carg0[i0 * 3 + 0] = NUM2DBL(RARRAY(ary)->ptr[0]);
    carg0[i0 * 3 + 1] = NUM2DBL(RARRAY(ary)->ptr[1]);
    carg0[i0 * 3 + 2] = NUM2DBL(RARRAY(ary)->ptr[2]);
  }
  carg1 = len0;
  carg2 = ALLOCA_N(float, carg1);
  carg3 = ALLOCA_N(float, carg1);
  gdfr3d_(carg0, &carg1, carg2, carg3);
  value2 = rb_ary_new2(carg1);
  for (i2 = 0; i2 < carg1; i2++)
    rb_ary_store(value2, i2, rb_float_new(carg2[i2]));
  value3 = rb_ary_new2(carg1);
  for (i3 = 0; i3 < carg1; i3++)
    rb_ary_store(value3, i3, rb_float_new(carg3[i3]));

  return rb_assoc_new(value2, value3);
}


static VALUE _wrap_gcflag_idebug_set(VALUE self, VALUE arg)
{
  gcflag_.idebug = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcflag_idebug_get(VALUE self)
{
  return INT2NUM(gcflag_.idebug);
}

static VALUE _wrap_gcflag_idemin_set(VALUE self, VALUE arg)
{
  gcflag_.idemin = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcflag_idemin_get(VALUE self)
{
  return INT2NUM(gcflag_.idemin);
}

static VALUE _wrap_gcflag_idemax_set(VALUE self, VALUE arg)
{
  gcflag_.idemax = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcflag_idemax_get(VALUE self)
{
  return INT2NUM(gcflag_.idemax);
}

static VALUE _wrap_gcflag_itest_set(VALUE self, VALUE arg)
{
  gcflag_.itest = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcflag_itest_get(VALUE self)
{
  return INT2NUM(gcflag_.itest);
}

static VALUE _wrap_gcflag_idrun_set(VALUE self, VALUE arg)
{
  gcflag_.idrun = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcflag_idrun_get(VALUE self)
{
  return INT2NUM(gcflag_.idrun);
}

static VALUE _wrap_gcflag_idevt_set(VALUE self, VALUE arg)
{
  gcflag_.idevt = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcflag_idevt_get(VALUE self)
{
  return INT2NUM(gcflag_.idevt);
}

static VALUE _wrap_gcflag_ieorun_set(VALUE self, VALUE arg)
{
  gcflag_.ieorun = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcflag_ieorun_get(VALUE self)
{
  return INT2NUM(gcflag_.ieorun);
}

static VALUE _wrap_gcflag_ieotri_set(VALUE self, VALUE arg)
{
  gcflag_.ieotri = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcflag_ieotri_get(VALUE self)
{
  return INT2NUM(gcflag_.ieotri);
}

static VALUE _wrap_gcflag_ievent_set(VALUE self, VALUE arg)
{
  gcflag_.ievent = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcflag_ievent_get(VALUE self)
{
  return INT2NUM(gcflag_.ievent);
}

static VALUE _wrap_gcflag_iswit_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcflag_.iswit[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcflag_iswit_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "iswit");
  if (NIL_P(value)) {
    value = rb_ary_new2(10);
    for (i = 0; i < 10; i++)
      rb_ary_store(value, i, INT2NUM(gcflag_.iswit[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcflag_iswit_set, 2);
    rb_iv_set(self, "iswit", value);
  } else {
    for (i = 0; i < 10; i++)
      rb_ary_store(value, i, INT2NUM(gcflag_.iswit[i]));
  }
  return value;
}

static VALUE _wrap_gcflag_ifinit_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcflag_.ifinit[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcflag_ifinit_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "ifinit");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gcflag_.ifinit[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcflag_ifinit_set, 2);
    rb_iv_set(self, "ifinit", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gcflag_.ifinit[i]));
  }
  return value;
}

static VALUE _wrap_gcflag_nevent_set(VALUE self, VALUE arg)
{
  gcflag_.nevent = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcflag_nevent_get(VALUE self)
{
  return INT2NUM(gcflag_.nevent);
}

static VALUE _wrap_gcflag_nrndm_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcflag_.nrndm[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcflag_nrndm_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "nrndm");
  if (NIL_P(value)) {
    value = rb_ary_new2(2);
    for (i = 0; i < 2; i++)
      rb_ary_store(value, i, INT2NUM(gcflag_.nrndm[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcflag_nrndm_set, 2);
    rb_iv_set(self, "nrndm", value);
  } else {
    for (i = 0; i < 2; i++)
      rb_ary_store(value, i, INT2NUM(gcflag_.nrndm[i]));
  }
  return value;
}

static VALUE _wrap_gclist_nhsta_set(VALUE self, VALUE arg)
{
  gclist_.nhsta = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_nhsta_get(VALUE self)
{
  return INT2NUM(gclist_.nhsta);
}

static VALUE _wrap_gclist_nget_set(VALUE self, VALUE arg)
{
  gclist_.nget = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_nget_get(VALUE self)
{
  return INT2NUM(gclist_.nget);
}

static VALUE _wrap_gclist_nsave_set(VALUE self, VALUE arg)
{
  gclist_.nsave = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_nsave_get(VALUE self)
{
  return INT2NUM(gclist_.nsave);
}

static VALUE _wrap_gclist_nsets_set(VALUE self, VALUE arg)
{
  gclist_.nsets = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_nsets_get(VALUE self)
{
  return INT2NUM(gclist_.nsets);
}

static VALUE _wrap_gclist_nprin_set(VALUE self, VALUE arg)
{
  gclist_.nprin = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_nprin_get(VALUE self)
{
  return INT2NUM(gclist_.nprin);
}

static VALUE _wrap_gclist_ngeom_set(VALUE self, VALUE arg)
{
  gclist_.ngeom = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_ngeom_get(VALUE self)
{
  return INT2NUM(gclist_.ngeom);
}

static VALUE _wrap_gclist_nview_set(VALUE self, VALUE arg)
{
  gclist_.nview = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_nview_get(VALUE self)
{
  return INT2NUM(gclist_.nview);
}

static VALUE _wrap_gclist_nplot_set(VALUE self, VALUE arg)
{
  gclist_.nplot = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_nplot_get(VALUE self)
{
  return INT2NUM(gclist_.nplot);
}

static VALUE _wrap_gclist_nstat_set(VALUE self, VALUE arg)
{
  gclist_.nstat = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_nstat_get(VALUE self)
{
  return INT2NUM(gclist_.nstat);
}

static VALUE _wrap_gclist_lhsta_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gclist_.lhsta[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_lhsta_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "lhsta");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lhsta[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gclist_lhsta_set, 2);
    rb_iv_set(self, "lhsta", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lhsta[i]));
  }
  return value;
}

static VALUE _wrap_gclist_lget_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gclist_.lget[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_lget_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "lget");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lget[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gclist_lget_set, 2);
    rb_iv_set(self, "lget", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lget[i]));
  }
  return value;
}

static VALUE _wrap_gclist_lsave_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gclist_.lsave[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_lsave_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "lsave");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lsave[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gclist_lsave_set, 2);
    rb_iv_set(self, "lsave", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lsave[i]));
  }
  return value;
}

static VALUE _wrap_gclist_lsets_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gclist_.lsets[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_lsets_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "lsets");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lsets[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gclist_lsets_set, 2);
    rb_iv_set(self, "lsets", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lsets[i]));
  }
  return value;
}

static VALUE _wrap_gclist_lprin_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gclist_.lprin[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_lprin_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "lprin");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lprin[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gclist_lprin_set, 2);
    rb_iv_set(self, "lprin", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lprin[i]));
  }
  return value;
}

static VALUE _wrap_gclist_lgeom_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gclist_.lgeom[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_lgeom_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "lgeom");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lgeom[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gclist_lgeom_set, 2);
    rb_iv_set(self, "lgeom", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lgeom[i]));
  }
  return value;
}

static VALUE _wrap_gclist_lview_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gclist_.lview[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_lview_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "lview");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lview[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gclist_lview_set, 2);
    rb_iv_set(self, "lview", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lview[i]));
  }
  return value;
}

static VALUE _wrap_gclist_lplot_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gclist_.lplot[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_lplot_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "lplot");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lplot[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gclist_lplot_set, 2);
    rb_iv_set(self, "lplot", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lplot[i]));
  }
  return value;
}

static VALUE _wrap_gclist_lstat_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gclist_.lstat[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gclist_lstat_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "lstat");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lstat[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gclist_lstat_set, 2);
    rb_iv_set(self, "lstat", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gclist_.lstat[i]));
  }
  return value;
}

static VALUE _wrap_gconst_pi_set(VALUE self, VALUE arg)
{
  gconst_.pi = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gconst_pi_get(VALUE self)
{
  return rb_float_new(gconst_.pi);
}

static VALUE _wrap_gconst_twopi_set(VALUE self, VALUE arg)
{
  gconst_.twopi = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gconst_twopi_get(VALUE self)
{
  return rb_float_new(gconst_.twopi);
}

static VALUE _wrap_gconst_piby2_set(VALUE self, VALUE arg)
{
  gconst_.piby2 = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gconst_piby2_get(VALUE self)
{
  return rb_float_new(gconst_.piby2);
}

static VALUE _wrap_gconst_degrad_set(VALUE self, VALUE arg)
{
  gconst_.degrad = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gconst_degrad_get(VALUE self)
{
  return rb_float_new(gconst_.degrad);
}

static VALUE _wrap_gconst_raddeg_set(VALUE self, VALUE arg)
{
  gconst_.raddeg = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gconst_raddeg_get(VALUE self)
{
  return rb_float_new(gconst_.raddeg);
}

static VALUE _wrap_gconst_clight_set(VALUE self, VALUE arg)
{
  gconst_.clight = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gconst_clight_get(VALUE self)
{
  return rb_float_new(gconst_.clight);
}

static VALUE _wrap_gconst_big_set(VALUE self, VALUE arg)
{
  gconst_.big = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gconst_big_get(VALUE self)
{
  return rb_float_new(gconst_.big);
}

static VALUE _wrap_gconst_emass_set(VALUE self, VALUE arg)
{
  gconst_.emass = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gconst_emass_get(VALUE self)
{
  return rb_float_new(gconst_.emass);
}

static VALUE _wrap_gckine_ikine_set(VALUE self, VALUE arg)
{
  gckine_.ikine = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gckine_ikine_get(VALUE self)
{
  return INT2NUM(gckine_.ikine);
}

static VALUE _wrap_gckine_pkine_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gckine_.pkine[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gckine_pkine_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "pkine");
  if (NIL_P(value)) {
    value = rb_ary_new2(10);
    for (i = 0; i < 10; i++)
      rb_ary_store(value, i, rb_float_new(gckine_.pkine[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gckine_pkine_set, 2);
    rb_iv_set(self, "pkine", value);
  } else {
    for (i = 0; i < 10; i++)
      rb_ary_store(value, i, rb_float_new(gckine_.pkine[i]));
  }
  return value;
}

static VALUE _wrap_gckine_itra_set(VALUE self, VALUE arg)
{
  gckine_.itra = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gckine_itra_get(VALUE self)
{
  return INT2NUM(gckine_.itra);
}

static VALUE _wrap_gckine_istak_set(VALUE self, VALUE arg)
{
  gckine_.istak = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gckine_istak_get(VALUE self)
{
  return INT2NUM(gckine_.istak);
}

static VALUE _wrap_gckine_ivert_set(VALUE self, VALUE arg)
{
  gckine_.ivert = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gckine_ivert_get(VALUE self)
{
  return INT2NUM(gckine_.ivert);
}

static VALUE _wrap_gckine_ipart_set(VALUE self, VALUE arg)
{
  gckine_.ipart = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gckine_ipart_get(VALUE self)
{
  return INT2NUM(gckine_.ipart);
}

static VALUE _wrap_gckine_itrtyp_set(VALUE self, VALUE arg)
{
  gckine_.itrtyp = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gckine_itrtyp_get(VALUE self)
{
  return INT2NUM(gckine_.itrtyp);
}

static VALUE _wrap_gckine_napart_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gckine_.napart[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gckine_napart_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "napart");
  if (NIL_P(value)) {
    value = rb_ary_new2(5);
    for (i = 0; i < 5; i++)
      rb_ary_store(value, i, INT2NUM(gckine_.napart[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gckine_napart_set, 2);
    rb_iv_set(self, "napart", value);
  } else {
    for (i = 0; i < 5; i++)
      rb_ary_store(value, i, INT2NUM(gckine_.napart[i]));
  }
  return value;
}

static VALUE _wrap_gckine_amass_set(VALUE self, VALUE arg)
{
  gckine_.amass = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gckine_amass_get(VALUE self)
{
  return rb_float_new(gckine_.amass);
}

static VALUE _wrap_gckine_charge_set(VALUE self, VALUE arg)
{
  gckine_.charge = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gckine_charge_get(VALUE self)
{
  return rb_float_new(gckine_.charge);
}

static VALUE _wrap_gckine_tlife_set(VALUE self, VALUE arg)
{
  gckine_.tlife = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gckine_tlife_get(VALUE self)
{
  return rb_float_new(gckine_.tlife);
}

static VALUE _wrap_gckine_vert_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gckine_.vert[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gckine_vert_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "vert");
  if (NIL_P(value)) {
    value = rb_ary_new2(3);
    for (i = 0; i < 3; i++)
      rb_ary_store(value, i, rb_float_new(gckine_.vert[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gckine_vert_set, 2);
    rb_iv_set(self, "vert", value);
  } else {
    for (i = 0; i < 3; i++)
      rb_ary_store(value, i, rb_float_new(gckine_.vert[i]));
  }
  return value;
}

static VALUE _wrap_gckine_pvert_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gckine_.pvert[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gckine_pvert_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "pvert");
  if (NIL_P(value)) {
    value = rb_ary_new2(4);
    for (i = 0; i < 4; i++)
      rb_ary_store(value, i, rb_float_new(gckine_.pvert[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gckine_pvert_set, 2);
    rb_iv_set(self, "pvert", value);
  } else {
    for (i = 0; i < 4; i++)
      rb_ary_store(value, i, rb_float_new(gckine_.pvert[i]));
  }
  return value;
}

static VALUE _wrap_gckine_ipaold_set(VALUE self, VALUE arg)
{
  gckine_.ipaold = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gckine_ipaold_get(VALUE self)
{
  return INT2NUM(gckine_.ipaold);
}

static VALUE _wrap_gcsets_ihset_set(VALUE self, VALUE arg)
{
  gcsets_.ihset = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcsets_ihset_get(VALUE self)
{
  return INT2NUM(gcsets_.ihset);
}

static VALUE _wrap_gcsets_ihdet_set(VALUE self, VALUE arg)
{
  gcsets_.ihdet = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcsets_ihdet_get(VALUE self)
{
  return INT2NUM(gcsets_.ihdet);
}

static VALUE _wrap_gcsets_iset_set(VALUE self, VALUE arg)
{
  gcsets_.iset = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcsets_iset_get(VALUE self)
{
  return INT2NUM(gcsets_.iset);
}

static VALUE _wrap_gcsets_idet_set(VALUE self, VALUE arg)
{
  gcsets_.idet = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcsets_idet_get(VALUE self)
{
  return INT2NUM(gcsets_.idet);
}

static VALUE _wrap_gcsets_idtype_set(VALUE self, VALUE arg)
{
  gcsets_.idtype = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcsets_idtype_get(VALUE self)
{
  return INT2NUM(gcsets_.idtype);
}

static VALUE _wrap_gcsets_nvname_set(VALUE self, VALUE arg)
{
  gcsets_.nvname = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcsets_nvname_get(VALUE self)
{
  return INT2NUM(gcsets_.nvname);
}

static VALUE _wrap_gcsets_numbv_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcsets_.numbv[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcsets_numbv_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "numbv");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gcsets_.numbv[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcsets_numbv_set, 2);
    rb_iv_set(self, "numbv", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, INT2NUM(gcsets_.numbv[i]));
  }
  return value;
}

static VALUE _wrap_gctmed_numed_set(VALUE self, VALUE arg)
{
  gctmed_.numed = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctmed_numed_get(VALUE self)
{
  return INT2NUM(gctmed_.numed);
}

static VALUE _wrap_gctmed_natmed_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gctmed_.natmed[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctmed_natmed_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "natmed");
  if (NIL_P(value)) {
    value = rb_ary_new2(5);
    for (i = 0; i < 5; i++)
      rb_ary_store(value, i, INT2NUM(gctmed_.natmed[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gctmed_natmed_set, 2);
    rb_iv_set(self, "natmed", value);
  } else {
    for (i = 0; i < 5; i++)
      rb_ary_store(value, i, INT2NUM(gctmed_.natmed[i]));
  }
  return value;
}

static VALUE _wrap_gctmed_isvol_set(VALUE self, VALUE arg)
{
  gctmed_.isvol = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctmed_isvol_get(VALUE self)
{
  return INT2NUM(gctmed_.isvol);
}

static VALUE _wrap_gctmed_ifield_set(VALUE self, VALUE arg)
{
  gctmed_.ifield = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctmed_ifield_get(VALUE self)
{
  return INT2NUM(gctmed_.ifield);
}

static VALUE _wrap_gctmed_fieldm_set(VALUE self, VALUE arg)
{
  gctmed_.fieldm = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctmed_fieldm_get(VALUE self)
{
  return rb_float_new(gctmed_.fieldm);
}

static VALUE _wrap_gctmed_tmaxfd_set(VALUE self, VALUE arg)
{
  gctmed_.tmaxfd = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctmed_tmaxfd_get(VALUE self)
{
  return rb_float_new(gctmed_.tmaxfd);
}

static VALUE _wrap_gctmed_dmaxms_set(VALUE self, VALUE arg)
{
  gctmed_.dmaxms = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctmed_dmaxms_get(VALUE self)
{
  return rb_float_new(gctmed_.dmaxms);
}

static VALUE _wrap_gctmed_deemax_set(VALUE self, VALUE arg)
{
  gctmed_.deemax = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctmed_deemax_get(VALUE self)
{
  return rb_float_new(gctmed_.deemax);
}

static VALUE _wrap_gctmed_epsil_set(VALUE self, VALUE arg)
{
  gctmed_.epsil = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctmed_epsil_get(VALUE self)
{
  return rb_float_new(gctmed_.epsil);
}

static VALUE _wrap_gctmed_stmin_set(VALUE self, VALUE arg)
{
  gctmed_.stmin = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctmed_stmin_get(VALUE self)
{
  return rb_float_new(gctmed_.stmin);
}

static VALUE _wrap_gctmed_cfield_set(VALUE self, VALUE arg)
{
  gctmed_.cfield = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctmed_cfield_get(VALUE self)
{
  return rb_float_new(gctmed_.cfield);
}

static VALUE _wrap_gctmed_prec_set(VALUE self, VALUE arg)
{
  gctmed_.prec = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctmed_prec_get(VALUE self)
{
  return rb_float_new(gctmed_.prec);
}

static VALUE _wrap_gctmed_iupd_set(VALUE self, VALUE arg)
{
  gctmed_.iupd = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctmed_iupd_get(VALUE self)
{
  return INT2NUM(gctmed_.iupd);
}

static VALUE _wrap_gctmed_istpar_set(VALUE self, VALUE arg)
{
  gctmed_.istpar = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctmed_istpar_get(VALUE self)
{
  return INT2NUM(gctmed_.istpar);
}

static VALUE _wrap_gctmed_numold_set(VALUE self, VALUE arg)
{
  gctmed_.numold = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctmed_numold_get(VALUE self)
{
  return INT2NUM(gctmed_.numold);
}

static VALUE _wrap_gcking_kcase_set(VALUE self, VALUE arg)
{
  gcking_.kcase = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcking_kcase_get(VALUE self)
{
  return INT2NUM(gcking_.kcase);
}

static VALUE _wrap_gcking_ngkine_set(VALUE self, VALUE arg)
{
  gcking_.ngkine = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcking_ngkine_get(VALUE self)
{
  return INT2NUM(gcking_.ngkine);
}

static VALUE _wrap_gcking_gkin_set(VALUE self, VALUE index, VALUE arg)
{
  int id1 = NUM2INT(rb_ivar_get(self, cern_id_id));
  int id2 = NUM2INT(index);
  gcking_.gkin[id1][id2] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcking_gkin_get(VALUE self)
{
  int i, j;
  VALUE value = rb_iv_get(self, "gkin");
  if (NIL_P(value)) {
    value = rb_ary_new2(5);
    for (i = 0; i < 5; i++) {
      VALUE ary = rb_ary_new2(100);
      for (j = 0; j < 100; j++)
	rb_ary_store(ary, j, rb_float_new(gcking_.gkin[i][j]));
      rb_define_singleton_method(ary, "[]=", _wrap_gcking_gkin_set, 2);
      rb_ivar_set(ary, cern_id_id, INT2NUM(i));
      rb_ary_store(value, i, ary);
    }
    rb_iv_set(self, "gkin", value);
  } else {
    for (i = 0; i < 5; i++) {
      for (j = 0; j < 100; j++)
	rb_ary_store(RARRAY(value)->ptr[i], j, rb_float_new(gcking_.gkin[i][j]));
    }
  }
  return value;
}

static VALUE _wrap_gcking_tofd_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcking_.tofd[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcking_tofd_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "tofd");
  if (NIL_P(value)) {
    value = rb_ary_new2(100);
    for (i = 0; i < 100; i++)
      rb_ary_store(value, i, rb_float_new(gcking_.tofd[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcking_tofd_set, 2);
    rb_iv_set(self, "tofd", value);
  } else {
    for (i = 0; i < 100; i++)
      rb_ary_store(value, i, rb_float_new(gcking_.tofd[i]));
  }
  return value;
}

static VALUE _wrap_gcking_iflgk_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcking_.iflgk[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcking_iflgk_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "iflgk");
  if (NIL_P(value)) {
    value = rb_ary_new2(100);
    for (i = 0; i < 100; i++)
      rb_ary_store(value, i, INT2NUM(gcking_.iflgk[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcking_iflgk_set, 2);
    rb_iv_set(self, "iflgk", value);
  } else {
    for (i = 0; i < 100; i++)
      rb_ary_store(value, i, INT2NUM(gcking_.iflgk[i]));
  }
  return value;
}

static VALUE _wrap_gckin2_ngphoto_set(VALUE self, VALUE arg)
{
  gckin2_.ngphoto = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gckin2_ngphoto_get(VALUE self)
{
  return INT2NUM(gckin2_.ngphoto);
}

static VALUE _wrap_gckin2_xphoto_set(VALUE self, VALUE index, VALUE arg)
{
  int id1 = NUM2INT(rb_ivar_get(self, cern_id_id));
  int id2 = NUM2INT(index);
  gckin2_.xphoto[id1][id2] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gckin2_xphoto_get(VALUE self)
{
  int i, j;
  VALUE value = rb_iv_get(self, "xphoto");
  if (NIL_P(value)) {
    value = rb_ary_new2(11);
    for (i = 0; i < 11; i++) {
      VALUE ary = rb_ary_new2(800);
      for (j = 0; j < 800; j++)
	rb_ary_store(ary, j, rb_float_new(gckin2_.xphoto[i][j]));
      rb_define_singleton_method(ary, "[]=", _wrap_gckin2_xphoto_set, 2);
      rb_ivar_set(ary, cern_id_id, INT2NUM(i));
      rb_ary_store(value, i, ary);
    }
    rb_iv_set(self, "xphoto", value);
  } else {
    for (i = 0; i < 11; i++) {
      for (j = 0; j < 800; j++)
	rb_ary_store(RARRAY(value)->ptr[i], j, rb_float_new(gckin2_.xphoto[i][j]));
    }
  }
  return value;
}

static VALUE _wrap_gckin3_gpos_set(VALUE self, VALUE index, VALUE arg)
{
  int id1 = NUM2INT(rb_ivar_get(self, cern_id_id));
  int id2 = NUM2INT(index);
  gckin3_.gpos[id1][id2] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gckin3_gpos_get(VALUE self)
{
  int i, j;
  VALUE value = rb_iv_get(self, "gpos");
  if (NIL_P(value)) {
    value = rb_ary_new2(3);
    for (i = 0; i < 3; i++) {
      VALUE ary = rb_ary_new2(100);
      for (j = 0; j < 100; j++)
	rb_ary_store(ary, j, rb_float_new(gckin3_.gpos[i][j]));
      rb_define_singleton_method(ary, "[]=", _wrap_gckin3_gpos_set, 2);
      rb_ivar_set(ary, cern_id_id, INT2NUM(i));
      rb_ary_store(value, i, ary);
    }
    rb_iv_set(self, "gpos", value);
  } else {
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 100; j++)
	rb_ary_store(RARRAY(value)->ptr[i], j, rb_float_new(gckin3_.gpos[i][j]));
    }
  }
  return value;
}

static VALUE _wrap_gctrak_vect_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gctrak_.vect[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_vect_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "vect");
  if (NIL_P(value)) {
    value = rb_ary_new2(7);
    for (i = 0; i < 7; i++)
      rb_ary_store(value, i, rb_float_new(gctrak_.vect[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gctrak_vect_set, 2);
    rb_iv_set(self, "vect", value);
  } else {
    for (i = 0; i < 7; i++)
      rb_ary_store(value, i, rb_float_new(gctrak_.vect[i]));
  }
  return value;
}

static VALUE _wrap_gctrak_getot_set(VALUE self, VALUE arg)
{
  gctrak_.getot = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_getot_get(VALUE self)
{
  return rb_float_new(gctrak_.getot);
}

static VALUE _wrap_gctrak_gekin_set(VALUE self, VALUE arg)
{
  gctrak_.gekin = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_gekin_get(VALUE self)
{
  return rb_float_new(gctrak_.gekin);
}

static VALUE _wrap_gctrak_vout_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gctrak_.vout[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_vout_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "vout");
  if (NIL_P(value)) {
    value = rb_ary_new2(7);
    for (i = 0; i < 7; i++)
      rb_ary_store(value, i, rb_float_new(gctrak_.vout[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gctrak_vout_set, 2);
    rb_iv_set(self, "vout", value);
  } else {
    for (i = 0; i < 7; i++)
      rb_ary_store(value, i, rb_float_new(gctrak_.vout[i]));
  }
  return value;
}

static VALUE _wrap_gctrak_nmec_set(VALUE self, VALUE arg)
{
  gctrak_.nmec = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_nmec_get(VALUE self)
{
  return INT2NUM(gctrak_.nmec);
}

static VALUE _wrap_gctrak_lmec_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gctrak_.lmec[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_lmec_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "lmec");
  if (NIL_P(value)) {
    value = rb_ary_new2(30);
    for (i = 0; i < 30; i++)
      rb_ary_store(value, i, INT2NUM(gctrak_.lmec[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gctrak_lmec_set, 2);
    rb_iv_set(self, "lmec", value);
  } else {
    for (i = 0; i < 30; i++)
      rb_ary_store(value, i, INT2NUM(gctrak_.lmec[i]));
  }
  return value;
}

static VALUE _wrap_gctrak_namec_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gctrak_.namec[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_namec_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "namec");
  if (NIL_P(value)) {
    value = rb_ary_new2(30);
    for (i = 0; i < 30; i++)
      rb_ary_store(value, i, INT2NUM(gctrak_.namec[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gctrak_namec_set, 2);
    rb_iv_set(self, "namec", value);
  } else {
    for (i = 0; i < 30; i++)
      rb_ary_store(value, i, INT2NUM(gctrak_.namec[i]));
  }
  return value;
}

static VALUE _wrap_gctrak_nstep_set(VALUE self, VALUE arg)
{
  gctrak_.nstep = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_nstep_get(VALUE self)
{
  return INT2NUM(gctrak_.nstep);
}

static VALUE _wrap_gctrak_maxnst_set(VALUE self, VALUE arg)
{
  gctrak_.maxnst = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_maxnst_get(VALUE self)
{
  return INT2NUM(gctrak_.maxnst);
}

static VALUE _wrap_gctrak_destep_set(VALUE self, VALUE arg)
{
  gctrak_.destep = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_destep_get(VALUE self)
{
  return rb_float_new(gctrak_.destep);
}

static VALUE _wrap_gctrak_destel_set(VALUE self, VALUE arg)
{
  gctrak_.destel = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_destel_get(VALUE self)
{
  return rb_float_new(gctrak_.destel);
}

static VALUE _wrap_gctrak_safety_set(VALUE self, VALUE arg)
{
  gctrak_.safety = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_safety_get(VALUE self)
{
  return rb_float_new(gctrak_.safety);
}

static VALUE _wrap_gctrak_sleng_set(VALUE self, VALUE arg)
{
  gctrak_.sleng = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_sleng_get(VALUE self)
{
  return rb_float_new(gctrak_.sleng);
}

static VALUE _wrap_gctrak_step_set(VALUE self, VALUE arg)
{
  gctrak_.step = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_step_get(VALUE self)
{
  return rb_float_new(gctrak_.step);
}

static VALUE _wrap_gctrak_snext_set(VALUE self, VALUE arg)
{
  gctrak_.snext = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_snext_get(VALUE self)
{
  return rb_float_new(gctrak_.snext);
}

static VALUE _wrap_gctrak_sfield_set(VALUE self, VALUE arg)
{
  gctrak_.sfield = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_sfield_get(VALUE self)
{
  return rb_float_new(gctrak_.sfield);
}

static VALUE _wrap_gctrak_tofg_set(VALUE self, VALUE arg)
{
  gctrak_.tofg = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_tofg_get(VALUE self)
{
  return rb_float_new(gctrak_.tofg);
}

static VALUE _wrap_gctrak_gekrat_set(VALUE self, VALUE arg)
{
  gctrak_.gekrat = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_gekrat_get(VALUE self)
{
  return rb_float_new(gctrak_.gekrat);
}

static VALUE _wrap_gctrak_upwght_set(VALUE self, VALUE arg)
{
  gctrak_.upwght = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gctrak_upwght_get(VALUE self)
{
  return rb_float_new(gctrak_.upwght);
}

static VALUE _wrap_gctrak_ignext_set(VALUE self, VALUE arg)
{
  gctrak_.ignext = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_ignext_get(VALUE self)
{
  return INT2NUM(gctrak_.ignext);
}

static VALUE _wrap_gctrak_inwvol_set(VALUE self, VALUE arg)
{
  gctrak_.inwvol = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_inwvol_get(VALUE self)
{
  return INT2NUM(gctrak_.inwvol);
}

static VALUE _wrap_gctrak_istop_set(VALUE self, VALUE arg)
{
  gctrak_.istop = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_istop_get(VALUE self)
{
  return INT2NUM(gctrak_.istop);
}

static VALUE _wrap_gctrak_igauto_set(VALUE self, VALUE arg)
{
  gctrak_.igauto = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_igauto_get(VALUE self)
{
  return INT2NUM(gctrak_.igauto);
}

static VALUE _wrap_gctrak_iekbin_set(VALUE self, VALUE arg)
{
  gctrak_.iekbin = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_iekbin_get(VALUE self)
{
  return INT2NUM(gctrak_.iekbin);
}

static VALUE _wrap_gctrak_ilosl_set(VALUE self, VALUE arg)
{
  gctrak_.ilosl = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_ilosl_get(VALUE self)
{
  return INT2NUM(gctrak_.ilosl);
}

static VALUE _wrap_gctrak_imull_set(VALUE self, VALUE arg)
{
  gctrak_.imull = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_imull_get(VALUE self)
{
  return INT2NUM(gctrak_.imull);
}

static VALUE _wrap_gctrak_ingoto_set(VALUE self, VALUE arg)
{
  gctrak_.ingoto = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_ingoto_get(VALUE self)
{
  return INT2NUM(gctrak_.ingoto);
}

static VALUE _wrap_gctrak_nldown_set(VALUE self, VALUE arg)
{
  gctrak_.nldown = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_nldown_get(VALUE self)
{
  return INT2NUM(gctrak_.nldown);
}

static VALUE _wrap_gctrak_nlevin_set(VALUE self, VALUE arg)
{
  gctrak_.nlevin = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_nlevin_get(VALUE self)
{
  return INT2NUM(gctrak_.nlevin);
}

static VALUE _wrap_gctrak_nlvsav_set(VALUE self, VALUE arg)
{
  gctrak_.nlvsav = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_nlvsav_get(VALUE self)
{
  return INT2NUM(gctrak_.nlvsav);
}

static VALUE _wrap_gctrak_istory_set(VALUE self, VALUE arg)
{
  gctrak_.istory = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gctrak_istory_get(VALUE self)
{
  return INT2NUM(gctrak_.istory);
}

static VALUE _wrap_gcvolu_nlevel_set(VALUE self, VALUE arg)
{
  gcvolu_.nlevel = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcvolu_nlevel_get(VALUE self)
{
  return INT2NUM(gcvolu_.nlevel);
}

static VALUE _wrap_gcvolu_names_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcvolu_.names[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcvolu_names_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "names");
  if (NIL_P(value)) {
    value = rb_ary_new2(15);
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, INT2NUM(gcvolu_.names[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcvolu_names_set, 2);
    rb_iv_set(self, "names", value);
  } else {
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, INT2NUM(gcvolu_.names[i]));
  }
  return value;
}

static VALUE _wrap_gcvolu_number_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcvolu_.number[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcvolu_number_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "number");
  if (NIL_P(value)) {
    value = rb_ary_new2(15);
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, INT2NUM(gcvolu_.number[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcvolu_number_set, 2);
    rb_iv_set(self, "number", value);
  } else {
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, INT2NUM(gcvolu_.number[i]));
  }
  return value;
}

static VALUE _wrap_gcvolu_lvolum_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcvolu_.lvolum[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcvolu_lvolum_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "lvolum");
  if (NIL_P(value)) {
    value = rb_ary_new2(15);
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, INT2NUM(gcvolu_.lvolum[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcvolu_lvolum_set, 2);
    rb_iv_set(self, "lvolum", value);
  } else {
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, INT2NUM(gcvolu_.lvolum[i]));
  }
  return value;
}

static VALUE _wrap_gcvolu_lindex_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcvolu_.lindex[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcvolu_lindex_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "lindex");
  if (NIL_P(value)) {
    value = rb_ary_new2(15);
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, INT2NUM(gcvolu_.lindex[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcvolu_lindex_set, 2);
    rb_iv_set(self, "lindex", value);
  } else {
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, INT2NUM(gcvolu_.lindex[i]));
  }
  return value;
}

static VALUE _wrap_gcvolu_infrom_set(VALUE self, VALUE arg)
{
  gcvolu_.infrom = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcvolu_infrom_get(VALUE self)
{
  return INT2NUM(gcvolu_.infrom);
}

static VALUE _wrap_gcvolu_nlevmx_set(VALUE self, VALUE arg)
{
  gcvolu_.nlevmx = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcvolu_nlevmx_get(VALUE self)
{
  return INT2NUM(gcvolu_.nlevmx);
}

static VALUE _wrap_gcvolu_nldev_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcvolu_.nldev[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcvolu_nldev_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "nldev");
  if (NIL_P(value)) {
    value = rb_ary_new2(15);
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, INT2NUM(gcvolu_.nldev[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcvolu_nldev_set, 2);
    rb_iv_set(self, "nldev", value);
  } else {
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, INT2NUM(gcvolu_.nldev[i]));
  }
  return value;
}

static VALUE _wrap_gcvolu_linmx_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcvolu_.linmx[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcvolu_linmx_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "linmx");
  if (NIL_P(value)) {
    value = rb_ary_new2(15);
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, INT2NUM(gcvolu_.linmx[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcvolu_linmx_set, 2);
    rb_iv_set(self, "linmx", value);
  } else {
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, INT2NUM(gcvolu_.linmx[i]));
  }
  return value;
}

static VALUE _wrap_gcvolu_gtran_set(VALUE self, VALUE index, VALUE arg)
{
  int id1 = NUM2INT(rb_ivar_get(self, cern_id_id));
  int id2 = NUM2INT(index);
  gcvolu_.gtran[id1][id2] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcvolu_gtran_get(VALUE self)
{
  int i, j;
  VALUE value = rb_iv_get(self, "gtran");
  if (NIL_P(value)) {
    value = rb_ary_new2(3);
    for (i = 0; i < 3; i++) {
      VALUE ary = rb_ary_new2(15);
      for (j = 0; j < 15; j++)
	rb_ary_store(ary, j, rb_float_new(gcvolu_.gtran[i][j]));
      rb_define_singleton_method(ary, "[]=", _wrap_gcvolu_gtran_set, 2);
      rb_ivar_set(ary, cern_id_id, INT2NUM(i));
      rb_ary_store(value, i, ary);
    }
    rb_iv_set(self, "gtran", value);
  } else {
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 15; j++)
	rb_ary_store(RARRAY(value)->ptr[i], j, rb_float_new(gcvolu_.gtran[i][j]));
    }
  }
  return value;
}

static VALUE _wrap_gcvolu_grmat_set(VALUE self, VALUE index, VALUE arg)
{
  int id1 = NUM2INT(rb_ivar_get(self, cern_id_id));
  int id2 = NUM2INT(index);
  gcvolu_.grmat[id1][id2] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcvolu_grmat_get(VALUE self)
{
  int i, j;
  VALUE value = rb_iv_get(self, "grmat");
  if (NIL_P(value)) {
    value = rb_ary_new2(10);
    for (i = 0; i < 10; i++) {
      VALUE ary = rb_ary_new2(15);
      for (j = 0; j < 15; j++)
	rb_ary_store(ary, j, rb_float_new(gcvolu_.grmat[i][j]));
      rb_define_singleton_method(ary, "[]=", _wrap_gcvolu_grmat_set, 2);
      rb_ivar_set(ary, cern_id_id, INT2NUM(i));
      rb_ary_store(value, i, ary);
    }
    rb_iv_set(self, "grmat", value);
  } else {
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 15; j++)
	rb_ary_store(RARRAY(value)->ptr[i], j, rb_float_new(gcvolu_.grmat[i][j]));
    }
  }
  return value;
}

static VALUE _wrap_gcvolu_gonly_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcvolu_.gonly[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcvolu_gonly_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "gonly");
  if (NIL_P(value)) {
    value = rb_ary_new2(15);
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, rb_float_new(gcvolu_.gonly[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcvolu_gonly_set, 2);
    rb_iv_set(self, "gonly", value);
  } else {
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, rb_float_new(gcvolu_.gonly[i]));
  }
  return value;
}

static VALUE _wrap_gcvolu_glx_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcvolu_.glx[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcvolu_glx_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "glx");
  if (NIL_P(value)) {
    value = rb_ary_new2(3);
    for (i = 0; i < 3; i++)
      rb_ary_store(value, i, rb_float_new(gcvolu_.glx[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcvolu_glx_set, 2);
    rb_iv_set(self, "glx", value);
  } else {
    for (i = 0; i < 3; i++)
      rb_ary_store(value, i, rb_float_new(gcvolu_.glx[i]));
  }
  return value;
}

static VALUE _wrap_gccuts_cutgam_set(VALUE self, VALUE arg)
{
  gccuts_.cutgam = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gccuts_cutgam_get(VALUE self)
{
  return rb_float_new(gccuts_.cutgam);
}

static VALUE _wrap_gccuts_cutele_set(VALUE self, VALUE arg)
{
  gccuts_.cutele = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gccuts_cutele_get(VALUE self)
{
  return rb_float_new(gccuts_.cutele);
}

static VALUE _wrap_gccuts_cutneu_set(VALUE self, VALUE arg)
{
  gccuts_.cutneu = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gccuts_cutneu_get(VALUE self)
{
  return rb_float_new(gccuts_.cutneu);
}

static VALUE _wrap_gccuts_cuthad_set(VALUE self, VALUE arg)
{
  gccuts_.cuthad = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gccuts_cuthad_get(VALUE self)
{
  return rb_float_new(gccuts_.cuthad);
}

static VALUE _wrap_gccuts_cutmuo_set(VALUE self, VALUE arg)
{
  gccuts_.cutmuo = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gccuts_cutmuo_get(VALUE self)
{
  return rb_float_new(gccuts_.cutmuo);
}

static VALUE _wrap_gccuts_bcute_set(VALUE self, VALUE arg)
{
  gccuts_.bcute = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gccuts_bcute_get(VALUE self)
{
  return rb_float_new(gccuts_.bcute);
}

static VALUE _wrap_gccuts_bcutm_set(VALUE self, VALUE arg)
{
  gccuts_.bcutm = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gccuts_bcutm_get(VALUE self)
{
  return rb_float_new(gccuts_.bcutm);
}

static VALUE _wrap_gccuts_dcute_set(VALUE self, VALUE arg)
{
  gccuts_.dcute = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gccuts_dcute_get(VALUE self)
{
  return rb_float_new(gccuts_.dcute);
}

static VALUE _wrap_gccuts_dcutm_set(VALUE self, VALUE arg)
{
  gccuts_.dcutm = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gccuts_dcutm_get(VALUE self)
{
  return rb_float_new(gccuts_.dcutm);
}

static VALUE _wrap_gccuts_ppcutm_set(VALUE self, VALUE arg)
{
  gccuts_.ppcutm = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gccuts_ppcutm_get(VALUE self)
{
  return rb_float_new(gccuts_.ppcutm);
}

static VALUE _wrap_gccuts_tofmax_set(VALUE self, VALUE arg)
{
  gccuts_.tofmax = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gccuts_tofmax_get(VALUE self)
{
  return rb_float_new(gccuts_.tofmax);
}

static VALUE _wrap_gccuts_gcuts_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gccuts_.gcuts[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gccuts_gcuts_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "gcuts");
  if (NIL_P(value)) {
    value = rb_ary_new2(5);
    for (i = 0; i < 5; i++)
      rb_ary_store(value, i, rb_float_new(gccuts_.gcuts[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gccuts_gcuts_set, 2);
    rb_iv_set(self, "gcuts", value);
  } else {
    for (i = 0; i < 5; i++)
      rb_ary_store(value, i, rb_float_new(gccuts_.gcuts[i]));
  }
  return value;
}

static VALUE _wrap_gcdraw_numnod_set(VALUE self, VALUE arg)
{
  gcdraw_.numnod = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_numnod_get(VALUE self)
{
  return INT2NUM(gcdraw_.numnod);
}

static VALUE _wrap_gcdraw_maxnod_set(VALUE self, VALUE arg)
{
  gcdraw_.maxnod = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_maxnod_get(VALUE self)
{
  return INT2NUM(gcdraw_.maxnod);
}

static VALUE _wrap_gcdraw_numnd1_set(VALUE self, VALUE arg)
{
  gcdraw_.numnd1 = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_numnd1_get(VALUE self)
{
  return INT2NUM(gcdraw_.numnd1);
}

static VALUE _wrap_gcdraw_levver_set(VALUE self, VALUE arg)
{
  gcdraw_.levver = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_levver_get(VALUE self)
{
  return INT2NUM(gcdraw_.levver);
}

static VALUE _wrap_gcdraw_levhor_set(VALUE self, VALUE arg)
{
  gcdraw_.levhor = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_levhor_get(VALUE self)
{
  return INT2NUM(gcdraw_.levhor);
}

static VALUE _wrap_gcdraw_maxv_set(VALUE self, VALUE arg)
{
  gcdraw_.maxv = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_maxv_get(VALUE self)
{
  return INT2NUM(gcdraw_.maxv);
}

static VALUE _wrap_gcdraw_ipick_set(VALUE self, VALUE arg)
{
  gcdraw_.ipick = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_ipick_get(VALUE self)
{
  return INT2NUM(gcdraw_.ipick);
}

static VALUE _wrap_gcdraw_mlevv_set(VALUE self, VALUE arg)
{
  gcdraw_.mlevv = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_mlevv_get(VALUE self)
{
  return INT2NUM(gcdraw_.mlevv);
}

static VALUE _wrap_gcdraw_mlevh_set(VALUE self, VALUE arg)
{
  gcdraw_.mlevh = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_mlevh_get(VALUE self)
{
  return INT2NUM(gcdraw_.mlevh);
}

static VALUE _wrap_gcdraw_nwcut_set(VALUE self, VALUE arg)
{
  gcdraw_.nwcut = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_nwcut_get(VALUE self)
{
  return INT2NUM(gcdraw_.nwcut);
}

static VALUE _wrap_gcdraw_jnam_set(VALUE self, VALUE arg)
{
  gcdraw_.jnam = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jnam_get(VALUE self)
{
  return INT2NUM(gcdraw_.jnam);
}

static VALUE _wrap_gcdraw_jmot_set(VALUE self, VALUE arg)
{
  gcdraw_.jmot = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jmot_get(VALUE self)
{
  return INT2NUM(gcdraw_.jmot);
}

static VALUE _wrap_gcdraw_jxon_set(VALUE self, VALUE arg)
{
  gcdraw_.jxon = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jxon_get(VALUE self)
{
  return INT2NUM(gcdraw_.jxon);
}

static VALUE _wrap_gcdraw_jbro_set(VALUE self, VALUE arg)
{
  gcdraw_.jbro = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jbro_get(VALUE self)
{
  return INT2NUM(gcdraw_.jbro);
}

static VALUE _wrap_gcdraw_jdup_set(VALUE self, VALUE arg)
{
  gcdraw_.jdup = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jdup_get(VALUE self)
{
  return INT2NUM(gcdraw_.jdup);
}

static VALUE _wrap_gcdraw_jsca_set(VALUE self, VALUE arg)
{
  gcdraw_.jsca = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jsca_get(VALUE self)
{
  return INT2NUM(gcdraw_.jsca);
}

static VALUE _wrap_gcdraw_jdvm_set(VALUE self, VALUE arg)
{
  gcdraw_.jdvm = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jdvm_get(VALUE self)
{
  return INT2NUM(gcdraw_.jdvm);
}

static VALUE _wrap_gcdraw_jpsm_set(VALUE self, VALUE arg)
{
  gcdraw_.jpsm = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jpsm_get(VALUE self)
{
  return INT2NUM(gcdraw_.jpsm);
}

static VALUE _wrap_gcdraw_jnam1_set(VALUE self, VALUE arg)
{
  gcdraw_.jnam1 = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jnam1_get(VALUE self)
{
  return INT2NUM(gcdraw_.jnam1);
}

static VALUE _wrap_gcdraw_jmot1_set(VALUE self, VALUE arg)
{
  gcdraw_.jmot1 = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jmot1_get(VALUE self)
{
  return INT2NUM(gcdraw_.jmot1);
}

static VALUE _wrap_gcdraw_jxon1_set(VALUE self, VALUE arg)
{
  gcdraw_.jxon1 = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jxon1_get(VALUE self)
{
  return INT2NUM(gcdraw_.jxon1);
}

static VALUE _wrap_gcdraw_jbro1_set(VALUE self, VALUE arg)
{
  gcdraw_.jbro1 = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jbro1_get(VALUE self)
{
  return INT2NUM(gcdraw_.jbro1);
}

static VALUE _wrap_gcdraw_jdup1_set(VALUE self, VALUE arg)
{
  gcdraw_.jdup1 = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jdup1_get(VALUE self)
{
  return INT2NUM(gcdraw_.jdup1);
}

static VALUE _wrap_gcdraw_jsca1_set(VALUE self, VALUE arg)
{
  gcdraw_.jsca1 = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jsca1_get(VALUE self)
{
  return INT2NUM(gcdraw_.jsca1);
}

static VALUE _wrap_gcdraw_julev_set(VALUE self, VALUE arg)
{
  gcdraw_.julev = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_julev_get(VALUE self)
{
  return INT2NUM(gcdraw_.julev);
}

static VALUE _wrap_gcdraw_jvlev_set(VALUE self, VALUE arg)
{
  gcdraw_.jvlev = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_jvlev_get(VALUE self)
{
  return INT2NUM(gcdraw_.jvlev);
}

static VALUE _wrap_gcdraw_looktb_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcdraw_.looktb[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_looktb_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "looktb");
  if (NIL_P(value)) {
    value = rb_ary_new2(16);
    for (i = 0; i < 16; i++)
      rb_ary_store(value, i, INT2NUM(gcdraw_.looktb[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcdraw_looktb_set, 2);
    rb_iv_set(self, "looktb", value);
  } else {
    for (i = 0; i < 16; i++)
      rb_ary_store(value, i, INT2NUM(gcdraw_.looktb[i]));
  }
  return value;
}

static VALUE _wrap_gcdraw_grmat0_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcdraw_.grmat0[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_grmat0_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "grmat0");
  if (NIL_P(value)) {
    value = rb_ary_new2(10);
    for (i = 0; i < 10; i++)
      rb_ary_store(value, i, rb_float_new(gcdraw_.grmat0[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcdraw_grmat0_set, 2);
    rb_iv_set(self, "grmat0", value);
  } else {
    for (i = 0; i < 10; i++)
      rb_ary_store(value, i, rb_float_new(gcdraw_.grmat0[i]));
  }
  return value;
}

static VALUE _wrap_gcdraw_gtran0_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcdraw_.gtran0[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gtran0_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "gtran0");
  if (NIL_P(value)) {
    value = rb_ary_new2(3);
    for (i = 0; i < 3; i++)
      rb_ary_store(value, i, rb_float_new(gcdraw_.gtran0[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcdraw_gtran0_set, 2);
    rb_iv_set(self, "gtran0", value);
  } else {
    for (i = 0; i < 3; i++)
      rb_ary_store(value, i, rb_float_new(gcdraw_.gtran0[i]));
  }
  return value;
}

static VALUE _wrap_gcdraw_idrnum_set(VALUE self, VALUE arg)
{
  gcdraw_.idrnum = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_idrnum_get(VALUE self)
{
  return INT2NUM(gcdraw_.idrnum);
}

static VALUE _wrap_gcdraw_gsin_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcdraw_.gsin[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gsin_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "gsin");
  if (NIL_P(value)) {
    value = rb_ary_new2(41);
    for (i = 0; i < 41; i++)
      rb_ary_store(value, i, rb_float_new(gcdraw_.gsin[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcdraw_gsin_set, 2);
    rb_iv_set(self, "gsin", value);
  } else {
    for (i = 0; i < 41; i++)
      rb_ary_store(value, i, rb_float_new(gcdraw_.gsin[i]));
  }
  return value;
}

static VALUE _wrap_gcdraw_gcos_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcdraw_.gcos[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gcos_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "gcos");
  if (NIL_P(value)) {
    value = rb_ary_new2(41);
    for (i = 0; i < 41; i++)
      rb_ary_store(value, i, rb_float_new(gcdraw_.gcos[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcdraw_gcos_set, 2);
    rb_iv_set(self, "gcos", value);
  } else {
    for (i = 0; i < 41; i++)
      rb_ary_store(value, i, rb_float_new(gcdraw_.gcos[i]));
  }
  return value;
}

static VALUE _wrap_gcdraw_sinpsi_set(VALUE self, VALUE arg)
{
  gcdraw_.sinpsi = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_sinpsi_get(VALUE self)
{
  return rb_float_new(gcdraw_.sinpsi);
}

static VALUE _wrap_gcdraw_cospsi_set(VALUE self, VALUE arg)
{
  gcdraw_.cospsi = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_cospsi_get(VALUE self)
{
  return rb_float_new(gcdraw_.cospsi);
}

static VALUE _wrap_gcdraw_gtheta_set(VALUE self, VALUE arg)
{
  gcdraw_.gtheta = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gtheta_get(VALUE self)
{
  return rb_float_new(gcdraw_.gtheta);
}

static VALUE _wrap_gcdraw_gphi_set(VALUE self, VALUE arg)
{
  gcdraw_.gphi = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gphi_get(VALUE self)
{
  return rb_float_new(gcdraw_.gphi);
}

static VALUE _wrap_gcdraw_gpsi_set(VALUE self, VALUE arg)
{
  gcdraw_.gpsi = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gpsi_get(VALUE self)
{
  return rb_float_new(gcdraw_.gpsi);
}

static VALUE _wrap_gcdraw_gu0_set(VALUE self, VALUE arg)
{
  gcdraw_.gu0 = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gu0_get(VALUE self)
{
  return rb_float_new(gcdraw_.gu0);
}

static VALUE _wrap_gcdraw_gv0_set(VALUE self, VALUE arg)
{
  gcdraw_.gv0 = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gv0_get(VALUE self)
{
  return rb_float_new(gcdraw_.gv0);
}

static VALUE _wrap_gcdraw_gscu_set(VALUE self, VALUE arg)
{
  gcdraw_.gscu = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gscu_get(VALUE self)
{
  return rb_float_new(gcdraw_.gscu);
}

static VALUE _wrap_gcdraw_gscv_set(VALUE self, VALUE arg)
{
  gcdraw_.gscv = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gscv_get(VALUE self)
{
  return rb_float_new(gcdraw_.gscv);
}

static VALUE _wrap_gcdraw_ngview_set(VALUE self, VALUE arg)
{
  gcdraw_.ngview = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_ngview_get(VALUE self)
{
  return INT2NUM(gcdraw_.ngview);
}

static VALUE _wrap_gcdraw_icutfl_set(VALUE self, VALUE arg)
{
  gcdraw_.icutfl = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_icutfl_get(VALUE self)
{
  return INT2NUM(gcdraw_.icutfl);
}

static VALUE _wrap_gcdraw_icut_set(VALUE self, VALUE arg)
{
  gcdraw_.icut = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_icut_get(VALUE self)
{
  return INT2NUM(gcdraw_.icut);
}

static VALUE _wrap_gcdraw_ctheta_set(VALUE self, VALUE arg)
{
  gcdraw_.ctheta = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_ctheta_get(VALUE self)
{
  return rb_float_new(gcdraw_.ctheta);
}

static VALUE _wrap_gcdraw_cphi_set(VALUE self, VALUE arg)
{
  gcdraw_.cphi = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_cphi_get(VALUE self)
{
  return rb_float_new(gcdraw_.cphi);
}

static VALUE _wrap_gcdraw_dcut_set(VALUE self, VALUE arg)
{
  gcdraw_.dcut = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_dcut_get(VALUE self)
{
  return rb_float_new(gcdraw_.dcut);
}

static VALUE _wrap_gcdraw_nsurf_set(VALUE self, VALUE arg)
{
  gcdraw_.nsurf = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_nsurf_get(VALUE self)
{
  return INT2NUM(gcdraw_.nsurf);
}

static VALUE _wrap_gcdraw_isurf_set(VALUE self, VALUE arg)
{
  gcdraw_.isurf = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_isurf_get(VALUE self)
{
  return INT2NUM(gcdraw_.isurf);
}

static VALUE _wrap_gcdraw_gzua_set(VALUE self, VALUE arg)
{
  gcdraw_.gzua = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gzua_get(VALUE self)
{
  return rb_float_new(gcdraw_.gzua);
}

static VALUE _wrap_gcdraw_gzva_set(VALUE self, VALUE arg)
{
  gcdraw_.gzva = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gzva_get(VALUE self)
{
  return rb_float_new(gcdraw_.gzva);
}

static VALUE _wrap_gcdraw_gzub_set(VALUE self, VALUE arg)
{
  gcdraw_.gzub = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gzub_get(VALUE self)
{
  return rb_float_new(gcdraw_.gzub);
}

static VALUE _wrap_gcdraw_gzvb_set(VALUE self, VALUE arg)
{
  gcdraw_.gzvb = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gzvb_get(VALUE self)
{
  return rb_float_new(gcdraw_.gzvb);
}

static VALUE _wrap_gcdraw_gzuc_set(VALUE self, VALUE arg)
{
  gcdraw_.gzuc = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gzuc_get(VALUE self)
{
  return rb_float_new(gcdraw_.gzuc);
}

static VALUE _wrap_gcdraw_gzvc_set(VALUE self, VALUE arg)
{
  gcdraw_.gzvc = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_gzvc_get(VALUE self)
{
  return rb_float_new(gcdraw_.gzvc);
}

static VALUE _wrap_gcdraw_pltrnx_set(VALUE self, VALUE arg)
{
  gcdraw_.pltrnx = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_pltrnx_get(VALUE self)
{
  return rb_float_new(gcdraw_.pltrnx);
}

static VALUE _wrap_gcdraw_pltrny_set(VALUE self, VALUE arg)
{
  gcdraw_.pltrny = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_pltrny_get(VALUE self)
{
  return rb_float_new(gcdraw_.pltrny);
}

static VALUE _wrap_gcdraw_linatt_set(VALUE self, VALUE arg)
{
  gcdraw_.linatt = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_linatt_get(VALUE self)
{
  return INT2NUM(gcdraw_.linatt);
}

static VALUE _wrap_gcdraw_linatp_set(VALUE self, VALUE arg)
{
  gcdraw_.linatp = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_linatp_get(VALUE self)
{
  return INT2NUM(gcdraw_.linatp);
}

static VALUE _wrap_gcdraw_itxatt_set(VALUE self, VALUE arg)
{
  gcdraw_.itxatt = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_itxatt_get(VALUE self)
{
  return INT2NUM(gcdraw_.itxatt);
}

static VALUE _wrap_gcdraw_ithrz_set(VALUE self, VALUE arg)
{
  gcdraw_.ithrz = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_ithrz_get(VALUE self)
{
  return INT2NUM(gcdraw_.ithrz);
}

static VALUE _wrap_gcdraw_iprj_set(VALUE self, VALUE arg)
{
  gcdraw_.iprj = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_iprj_get(VALUE self)
{
  return INT2NUM(gcdraw_.iprj);
}

static VALUE _wrap_gcdraw_dpers_set(VALUE self, VALUE arg)
{
  gcdraw_.dpers = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_dpers_get(VALUE self)
{
  return rb_float_new(gcdraw_.dpers);
}

static VALUE _wrap_gcdraw_itr3d_set(VALUE self, VALUE arg)
{
  gcdraw_.itr3d = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_itr3d_get(VALUE self)
{
  return INT2NUM(gcdraw_.itr3d);
}

static VALUE _wrap_gcdraw_ipkhit_set(VALUE self, VALUE arg)
{
  gcdraw_.ipkhit = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_ipkhit_get(VALUE self)
{
  return INT2NUM(gcdraw_.ipkhit);
}

static VALUE _wrap_gcdraw_iobj_set(VALUE self, VALUE arg)
{
  gcdraw_.iobj = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_iobj_get(VALUE self)
{
  return INT2NUM(gcdraw_.iobj);
}

static VALUE _wrap_gcdraw_linbumaxgu_set(VALUE self, VALUE arg)
{
  gcdraw_.linbumaxgu = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_linbumaxgu_get(VALUE self)
{
  return INT2NUM(gcdraw_.linbumaxgu);
}

static VALUE _wrap_gcdraw_morgu_set(VALUE self, VALUE arg)
{
  gcdraw_.morgu = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_morgu_get(VALUE self)
{
  return INT2NUM(gcdraw_.morgu);
}

static VALUE _wrap_gcdraw_maxgs_set(VALUE self, VALUE arg)
{
  gcdraw_.maxgs = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_maxgs_get(VALUE self)
{
  return INT2NUM(gcdraw_.maxgs);
}

static VALUE _wrap_gcdraw_morgs_set(VALUE self, VALUE arg)
{
  gcdraw_.morgs = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_morgs_get(VALUE self)
{
  return INT2NUM(gcdraw_.morgs);
}

static VALUE _wrap_gcdraw_maxtu_set(VALUE self, VALUE arg)
{
  gcdraw_.maxtu = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_maxtu_get(VALUE self)
{
  return INT2NUM(gcdraw_.maxtu);
}

static VALUE _wrap_gcdraw_mortu_set(VALUE self, VALUE arg)
{
  gcdraw_.mortu = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_mortu_get(VALUE self)
{
  return INT2NUM(gcdraw_.mortu);
}

static VALUE _wrap_gcdraw_maxts_set(VALUE self, VALUE arg)
{
  gcdraw_.maxts = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_maxts_get(VALUE self)
{
  return INT2NUM(gcdraw_.maxts);
}

static VALUE _wrap_gcdraw_morts_set(VALUE self, VALUE arg)
{
  gcdraw_.morts = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_morts_get(VALUE self)
{
  return INT2NUM(gcdraw_.morts);
}

static VALUE _wrap_gcdraw_igu_set(VALUE self, VALUE arg)
{
  gcdraw_.igu = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_igu_get(VALUE self)
{
  return INT2NUM(gcdraw_.igu);
}

static VALUE _wrap_gcdraw_igs_set(VALUE self, VALUE arg)
{
  gcdraw_.igs = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_igs_get(VALUE self)
{
  return INT2NUM(gcdraw_.igs);
}

static VALUE _wrap_gcdraw_itu_set(VALUE self, VALUE arg)
{
  gcdraw_.itu = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_itu_get(VALUE self)
{
  return INT2NUM(gcdraw_.itu);
}

static VALUE _wrap_gcdraw_its_set(VALUE self, VALUE arg)
{
  gcdraw_.its = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_its_get(VALUE self)
{
  return INT2NUM(gcdraw_.its);
}

static VALUE _wrap_gcdraw_nkview_set(VALUE self, VALUE arg)
{
  gcdraw_.nkview = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_nkview_get(VALUE self)
{
  return INT2NUM(gcdraw_.nkview);
}

static VALUE _wrap_gcdraw_idview_set(VALUE self, VALUE arg)
{
  gcdraw_.idview = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_idview_get(VALUE self)
{
  return INT2NUM(gcdraw_.idview);
}

static VALUE _wrap_gcdraw_nopen_set(VALUE self, VALUE arg)
{
  gcdraw_.nopen = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_nopen_get(VALUE self)
{
  return INT2NUM(gcdraw_.nopen);
}

static VALUE _wrap_gcdraw_igmr_set(VALUE self, VALUE arg)
{
  gcdraw_.igmr = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_igmr_get(VALUE self)
{
  return INT2NUM(gcdraw_.igmr);
}

static VALUE _wrap_gcdraw_ipions_set(VALUE self, VALUE arg)
{
  gcdraw_.ipions = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_ipions_get(VALUE self)
{
  return INT2NUM(gcdraw_.ipions);
}

static VALUE _wrap_gcdraw_itrkop_set(VALUE self, VALUE arg)
{
  gcdraw_.itrkop = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_itrkop_get(VALUE self)
{
  return INT2NUM(gcdraw_.itrkop);
}

static VALUE _wrap_gcdraw_ihiden_set(VALUE self, VALUE arg)
{
  gcdraw_.ihiden = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_ihiden_get(VALUE self)
{
  return INT2NUM(gcdraw_.ihiden);
}

static VALUE _wrap_gcdraw_zzfu_set(VALUE self, VALUE arg)
{
  gcdraw_.zzfu = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_zzfu_get(VALUE self)
{
  return rb_float_new(gcdraw_.zzfu);
}

static VALUE _wrap_gcdraw_zzfv_set(VALUE self, VALUE arg)
{
  gcdraw_.zzfv = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_zzfv_get(VALUE self)
{
  return rb_float_new(gcdraw_.zzfv);
}

static VALUE _wrap_gcdraw_myisel_set(VALUE self, VALUE arg)
{
  gcdraw_.myisel = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcdraw_myisel_get(VALUE self)
{
  return INT2NUM(gcdraw_.myisel);
}

static VALUE _wrap_gcdraw_ddummy_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcdraw_.ddummy[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcdraw_ddummy_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "ddummy");
  if (NIL_P(value)) {
    value = rb_ary_new2(15);
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, rb_float_new(gcdraw_.ddummy[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcdraw_ddummy_set, 2);
    rb_iv_set(self, "ddummy", value);
  } else {
    for (i = 0; i < 15; i++)
      rb_ary_store(value, i, rb_float_new(gcdraw_.ddummy[i]));
  }
  return value;
}

static VALUE _wrap_gcmate_nmat_set(VALUE self, VALUE arg)
{
  gcmate_.nmat = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcmate_nmat_get(VALUE self)
{
  return INT2NUM(gcmate_.nmat);
}

static VALUE _wrap_gcmate_namate_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcmate_.namate[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcmate_namate_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "namate");
  if (NIL_P(value)) {
    value = rb_ary_new2(5);
    for (i = 0; i < 5; i++)
      rb_ary_store(value, i, INT2NUM(gcmate_.namate[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcmate_namate_set, 2);
    rb_iv_set(self, "namate", value);
  } else {
    for (i = 0; i < 5; i++)
      rb_ary_store(value, i, INT2NUM(gcmate_.namate[i]));
  }
  return value;
}

static VALUE _wrap_gcmate_a_set(VALUE self, VALUE arg)
{
  gcmate_.a = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcmate_a_get(VALUE self)
{
  return rb_float_new(gcmate_.a);
}

static VALUE _wrap_gcmate_z_set(VALUE self, VALUE arg)
{
  gcmate_.z = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcmate_z_get(VALUE self)
{
  return rb_float_new(gcmate_.z);
}

static VALUE _wrap_gcmate_dens_set(VALUE self, VALUE arg)
{
  gcmate_.dens = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcmate_dens_get(VALUE self)
{
  return rb_float_new(gcmate_.dens);
}

static VALUE _wrap_gcmate_radl_set(VALUE self, VALUE arg)
{
  gcmate_.radl = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcmate_radl_get(VALUE self)
{
  return rb_float_new(gcmate_.radl);
}

static VALUE _wrap_gcmate_absl_set(VALUE self, VALUE arg)
{
  gcmate_.absl = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcmate_absl_get(VALUE self)
{
  return rb_float_new(gcmate_.absl);
}

static VALUE _wrap_gcnum_nmate_set(VALUE self, VALUE arg)
{
  gcnum_.nmate = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcnum_nmate_get(VALUE self)
{
  return INT2NUM(gcnum_.nmate);
}

static VALUE _wrap_gcnum_nvolum_set(VALUE self, VALUE arg)
{
  gcnum_.nvolum = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcnum_nvolum_get(VALUE self)
{
  return INT2NUM(gcnum_.nvolum);
}

static VALUE _wrap_gcnum_nrotm_set(VALUE self, VALUE arg)
{
  gcnum_.nrotm = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcnum_nrotm_get(VALUE self)
{
  return INT2NUM(gcnum_.nrotm);
}

static VALUE _wrap_gcnum_ntmed_set(VALUE self, VALUE arg)
{
  gcnum_.ntmed = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcnum_ntmed_get(VALUE self)
{
  return INT2NUM(gcnum_.ntmed);
}

static VALUE _wrap_gcnum_ntmult_set(VALUE self, VALUE arg)
{
  gcnum_.ntmult = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcnum_ntmult_get(VALUE self)
{
  return INT2NUM(gcnum_.ntmult);
}

static VALUE _wrap_gcnum_ntrack_set(VALUE self, VALUE arg)
{
  gcnum_.ntrack = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcnum_ntrack_get(VALUE self)
{
  return INT2NUM(gcnum_.ntrack);
}

static VALUE _wrap_gcnum_npart_set(VALUE self, VALUE arg)
{
  gcnum_.npart = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcnum_npart_get(VALUE self)
{
  return INT2NUM(gcnum_.npart);
}

static VALUE _wrap_gcnum_nstmax_set(VALUE self, VALUE arg)
{
  gcnum_.nstmax = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcnum_nstmax_get(VALUE self)
{
  return INT2NUM(gcnum_.nstmax);
}

static VALUE _wrap_gcnum_nvertx_set(VALUE self, VALUE arg)
{
  gcnum_.nvertx = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcnum_nvertx_get(VALUE self)
{
  return INT2NUM(gcnum_.nvertx);
}

static VALUE _wrap_gcnum_nhead_set(VALUE self, VALUE arg)
{
  gcnum_.nhead = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcnum_nhead_get(VALUE self)
{
  return INT2NUM(gcnum_.nhead);
}

static VALUE _wrap_gcnum_nbit_set(VALUE self, VALUE arg)
{
  gcnum_.nbit = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcnum_nbit_get(VALUE self)
{
  return INT2NUM(gcnum_.nbit);
}

static VALUE _wrap_gcphys_ipair_set(VALUE self, VALUE arg)
{
  gcphys_.ipair = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphys_ipair_get(VALUE self)
{
  return INT2NUM(gcphys_.ipair);
}

static VALUE _wrap_gcphys_spair_set(VALUE self, VALUE arg)
{
  gcphys_.spair = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_spair_get(VALUE self)
{
  return rb_float_new(gcphys_.spair);
}

static VALUE _wrap_gcphys_slpair_set(VALUE self, VALUE arg)
{
  gcphys_.slpair = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_slpair_get(VALUE self)
{
  return rb_float_new(gcphys_.slpair);
}

static VALUE _wrap_gcphys_zintpa_set(VALUE self, VALUE arg)
{
  gcphys_.zintpa = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_zintpa_get(VALUE self)
{
  return rb_float_new(gcphys_.zintpa);
}

static VALUE _wrap_gcphys_steppa_set(VALUE self, VALUE arg)
{
  gcphys_.steppa = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_steppa_get(VALUE self)
{
  return rb_float_new(gcphys_.steppa);
}

static VALUE _wrap_gcphys_icomp_set(VALUE self, VALUE arg)
{
  gcphys_.icomp = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphys_icomp_get(VALUE self)
{
  return INT2NUM(gcphys_.icomp);
}

static VALUE _wrap_gcphys_scomp_set(VALUE self, VALUE arg)
{
  gcphys_.scomp = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_scomp_get(VALUE self)
{
  return rb_float_new(gcphys_.scomp);
}

static VALUE _wrap_gcphys_slcomp_set(VALUE self, VALUE arg)
{
  gcphys_.slcomp = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_slcomp_get(VALUE self)
{
  return rb_float_new(gcphys_.slcomp);
}

static VALUE _wrap_gcphys_zintco_set(VALUE self, VALUE arg)
{
  gcphys_.zintco = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_zintco_get(VALUE self)
{
  return rb_float_new(gcphys_.zintco);
}

static VALUE _wrap_gcphys_stepco_set(VALUE self, VALUE arg)
{
  gcphys_.stepco = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_stepco_get(VALUE self)
{
  return rb_float_new(gcphys_.stepco);
}

static VALUE _wrap_gcphys_iphot_set(VALUE self, VALUE arg)
{
  gcphys_.iphot = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphys_iphot_get(VALUE self)
{
  return INT2NUM(gcphys_.iphot);
}

static VALUE _wrap_gcphys_sphot_set(VALUE self, VALUE arg)
{
  gcphys_.sphot = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_sphot_get(VALUE self)
{
  return rb_float_new(gcphys_.sphot);
}

static VALUE _wrap_gcphys_slphot_set(VALUE self, VALUE arg)
{
  gcphys_.slphot = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_slphot_get(VALUE self)
{
  return rb_float_new(gcphys_.slphot);
}

static VALUE _wrap_gcphys_zintph_set(VALUE self, VALUE arg)
{
  gcphys_.zintph = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_zintph_get(VALUE self)
{
  return rb_float_new(gcphys_.zintph);
}

static VALUE _wrap_gcphys_stepph_set(VALUE self, VALUE arg)
{
  gcphys_.stepph = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_stepph_get(VALUE self)
{
  return rb_float_new(gcphys_.stepph);
}

static VALUE _wrap_gcphys_ipfis_set(VALUE self, VALUE arg)
{
  gcphys_.ipfis = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphys_ipfis_get(VALUE self)
{
  return INT2NUM(gcphys_.ipfis);
}

static VALUE _wrap_gcphys_spfis_set(VALUE self, VALUE arg)
{
  gcphys_.spfis = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_spfis_get(VALUE self)
{
  return rb_float_new(gcphys_.spfis);
}

static VALUE _wrap_gcphys_slpfis_set(VALUE self, VALUE arg)
{
  gcphys_.slpfis = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_slpfis_get(VALUE self)
{
  return rb_float_new(gcphys_.slpfis);
}

static VALUE _wrap_gcphys_zintpf_set(VALUE self, VALUE arg)
{
  gcphys_.zintpf = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_zintpf_get(VALUE self)
{
  return rb_float_new(gcphys_.zintpf);
}

static VALUE _wrap_gcphys_steppf_set(VALUE self, VALUE arg)
{
  gcphys_.steppf = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_steppf_get(VALUE self)
{
  return rb_float_new(gcphys_.steppf);
}

static VALUE _wrap_gcphys_idray_set(VALUE self, VALUE arg)
{
  gcphys_.idray = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphys_idray_get(VALUE self)
{
  return INT2NUM(gcphys_.idray);
}

static VALUE _wrap_gcphys_sdray_set(VALUE self, VALUE arg)
{
  gcphys_.sdray = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_sdray_get(VALUE self)
{
  return rb_float_new(gcphys_.sdray);
}

static VALUE _wrap_gcphys_sldray_set(VALUE self, VALUE arg)
{
  gcphys_.sldray = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_sldray_get(VALUE self)
{
  return rb_float_new(gcphys_.sldray);
}

static VALUE _wrap_gcphys_zintdr_set(VALUE self, VALUE arg)
{
  gcphys_.zintdr = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_zintdr_get(VALUE self)
{
  return rb_float_new(gcphys_.zintdr);
}

static VALUE _wrap_gcphys_stepdr_set(VALUE self, VALUE arg)
{
  gcphys_.stepdr = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_stepdr_get(VALUE self)
{
  return rb_float_new(gcphys_.stepdr);
}

static VALUE _wrap_gcphys_ianni_set(VALUE self, VALUE arg)
{
  gcphys_.ianni = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphys_ianni_get(VALUE self)
{
  return INT2NUM(gcphys_.ianni);
}

static VALUE _wrap_gcphys_sanni_set(VALUE self, VALUE arg)
{
  gcphys_.sanni = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_sanni_get(VALUE self)
{
  return rb_float_new(gcphys_.sanni);
}

static VALUE _wrap_gcphys_slanni_set(VALUE self, VALUE arg)
{
  gcphys_.slanni = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_slanni_get(VALUE self)
{
  return rb_float_new(gcphys_.slanni);
}

static VALUE _wrap_gcphys_zintan_set(VALUE self, VALUE arg)
{
  gcphys_.zintan = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_zintan_get(VALUE self)
{
  return rb_float_new(gcphys_.zintan);
}

static VALUE _wrap_gcphys_stepan_set(VALUE self, VALUE arg)
{
  gcphys_.stepan = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_stepan_get(VALUE self)
{
  return rb_float_new(gcphys_.stepan);
}

static VALUE _wrap_gcphys_ibrem_set(VALUE self, VALUE arg)
{
  gcphys_.ibrem = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphys_ibrem_get(VALUE self)
{
  return INT2NUM(gcphys_.ibrem);
}

static VALUE _wrap_gcphys_sbrem_set(VALUE self, VALUE arg)
{
  gcphys_.sbrem = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_sbrem_get(VALUE self)
{
  return rb_float_new(gcphys_.sbrem);
}

static VALUE _wrap_gcphys_slbrem_set(VALUE self, VALUE arg)
{
  gcphys_.slbrem = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_slbrem_get(VALUE self)
{
  return rb_float_new(gcphys_.slbrem);
}

static VALUE _wrap_gcphys_zintbr_set(VALUE self, VALUE arg)
{
  gcphys_.zintbr = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_zintbr_get(VALUE self)
{
  return rb_float_new(gcphys_.zintbr);
}

static VALUE _wrap_gcphys_stepbr_set(VALUE self, VALUE arg)
{
  gcphys_.stepbr = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_stepbr_get(VALUE self)
{
  return rb_float_new(gcphys_.stepbr);
}

static VALUE _wrap_gcphys_ihadr_set(VALUE self, VALUE arg)
{
  gcphys_.ihadr = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphys_ihadr_get(VALUE self)
{
  return INT2NUM(gcphys_.ihadr);
}

static VALUE _wrap_gcphys_shadr_set(VALUE self, VALUE arg)
{
  gcphys_.shadr = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_shadr_get(VALUE self)
{
  return rb_float_new(gcphys_.shadr);
}

static VALUE _wrap_gcphys_slhadr_set(VALUE self, VALUE arg)
{
  gcphys_.slhadr = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_slhadr_get(VALUE self)
{
  return rb_float_new(gcphys_.slhadr);
}

static VALUE _wrap_gcphys_zintha_set(VALUE self, VALUE arg)
{
  gcphys_.zintha = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_zintha_get(VALUE self)
{
  return rb_float_new(gcphys_.zintha);
}

static VALUE _wrap_gcphys_stepha_set(VALUE self, VALUE arg)
{
  gcphys_.stepha = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_stepha_get(VALUE self)
{
  return rb_float_new(gcphys_.stepha);
}

static VALUE _wrap_gcphys_imunu_set(VALUE self, VALUE arg)
{
  gcphys_.imunu = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphys_imunu_get(VALUE self)
{
  return INT2NUM(gcphys_.imunu);
}

static VALUE _wrap_gcphys_smunu_set(VALUE self, VALUE arg)
{
  gcphys_.smunu = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_smunu_get(VALUE self)
{
  return rb_float_new(gcphys_.smunu);
}

static VALUE _wrap_gcphys_slmunu_set(VALUE self, VALUE arg)
{
  gcphys_.slmunu = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_slmunu_get(VALUE self)
{
  return rb_float_new(gcphys_.slmunu);
}

static VALUE _wrap_gcphys_zintmu_set(VALUE self, VALUE arg)
{
  gcphys_.zintmu = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_zintmu_get(VALUE self)
{
  return rb_float_new(gcphys_.zintmu);
}

static VALUE _wrap_gcphys_stepmu_set(VALUE self, VALUE arg)
{
  gcphys_.stepmu = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_stepmu_get(VALUE self)
{
  return rb_float_new(gcphys_.stepmu);
}

static VALUE _wrap_gcphys_idcay_set(VALUE self, VALUE arg)
{
  gcphys_.idcay = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphys_idcay_get(VALUE self)
{
  return INT2NUM(gcphys_.idcay);
}

static VALUE _wrap_gcphys_sdcay_set(VALUE self, VALUE arg)
{
  gcphys_.sdcay = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_sdcay_get(VALUE self)
{
  return rb_float_new(gcphys_.sdcay);
}

static VALUE _wrap_gcphys_slife_set(VALUE self, VALUE arg)
{
  gcphys_.slife = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_slife_get(VALUE self)
{
  return rb_float_new(gcphys_.slife);
}

static VALUE _wrap_gcphys_sumlif_set(VALUE self, VALUE arg)
{
  gcphys_.sumlif = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_sumlif_get(VALUE self)
{
  return rb_float_new(gcphys_.sumlif);
}

static VALUE _wrap_gcphys_dphys1_set(VALUE self, VALUE arg)
{
  gcphys_.dphys1 = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_dphys1_get(VALUE self)
{
  return rb_float_new(gcphys_.dphys1);
}

static VALUE _wrap_gcphys_iloss_set(VALUE self, VALUE arg)
{
  gcphys_.iloss = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphys_iloss_get(VALUE self)
{
  return INT2NUM(gcphys_.iloss);
}

static VALUE _wrap_gcphys_sloss_set(VALUE self, VALUE arg)
{
  gcphys_.sloss = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_sloss_get(VALUE self)
{
  return rb_float_new(gcphys_.sloss);
}

static VALUE _wrap_gcphys_soloss_set(VALUE self, VALUE arg)
{
  gcphys_.soloss = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_soloss_get(VALUE self)
{
  return rb_float_new(gcphys_.soloss);
}

static VALUE _wrap_gcphys_stloss_set(VALUE self, VALUE arg)
{
  gcphys_.stloss = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_stloss_get(VALUE self)
{
  return rb_float_new(gcphys_.stloss);
}

static VALUE _wrap_gcphys_dphys2_set(VALUE self, VALUE arg)
{
  gcphys_.dphys2 = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_dphys2_get(VALUE self)
{
  return rb_float_new(gcphys_.dphys2);
}

static VALUE _wrap_gcphys_imuls_set(VALUE self, VALUE arg)
{
  gcphys_.imuls = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphys_imuls_get(VALUE self)
{
  return INT2NUM(gcphys_.imuls);
}

static VALUE _wrap_gcphys_smuls_set(VALUE self, VALUE arg)
{
  gcphys_.smuls = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_smuls_get(VALUE self)
{
  return rb_float_new(gcphys_.smuls);
}

static VALUE _wrap_gcphys_somuls_set(VALUE self, VALUE arg)
{
  gcphys_.somuls = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_somuls_get(VALUE self)
{
  return rb_float_new(gcphys_.somuls);
}

static VALUE _wrap_gcphys_stmuls_set(VALUE self, VALUE arg)
{
  gcphys_.stmuls = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_stmuls_get(VALUE self)
{
  return rb_float_new(gcphys_.stmuls);
}

static VALUE _wrap_gcphys_dphys3_set(VALUE self, VALUE arg)
{
  gcphys_.dphys3 = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_dphys3_get(VALUE self)
{
  return rb_float_new(gcphys_.dphys3);
}

static VALUE _wrap_gcphys_irayl_set(VALUE self, VALUE arg)
{
  gcphys_.irayl = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphys_irayl_get(VALUE self)
{
  return INT2NUM(gcphys_.irayl);
}

static VALUE _wrap_gcphys_srayl_set(VALUE self, VALUE arg)
{
  gcphys_.srayl = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_srayl_get(VALUE self)
{
  return rb_float_new(gcphys_.srayl);
}

static VALUE _wrap_gcphys_slrayl_set(VALUE self, VALUE arg)
{
  gcphys_.slrayl = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_slrayl_get(VALUE self)
{
  return rb_float_new(gcphys_.slrayl);
}

static VALUE _wrap_gcphys_zintra_set(VALUE self, VALUE arg)
{
  gcphys_.zintra = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_zintra_get(VALUE self)
{
  return rb_float_new(gcphys_.zintra);
}

static VALUE _wrap_gcphys_stepra_set(VALUE self, VALUE arg)
{
  gcphys_.stepra = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphys_stepra_get(VALUE self)
{
  return rb_float_new(gcphys_.stepra);
}

static VALUE _wrap_gcphlt_ilabs_set(VALUE self, VALUE arg)
{
  gcphlt_.ilabs = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphlt_ilabs_get(VALUE self)
{
  return INT2NUM(gcphlt_.ilabs);
}

static VALUE _wrap_gcphlt_slabs_set(VALUE self, VALUE arg)
{
  gcphlt_.slabs = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphlt_slabs_get(VALUE self)
{
  return rb_float_new(gcphlt_.slabs);
}

static VALUE _wrap_gcphlt_sllabs_set(VALUE self, VALUE arg)
{
  gcphlt_.sllabs = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphlt_sllabs_get(VALUE self)
{
  return rb_float_new(gcphlt_.sllabs);
}

static VALUE _wrap_gcphlt_zintla_set(VALUE self, VALUE arg)
{
  gcphlt_.zintla = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphlt_zintla_get(VALUE self)
{
  return rb_float_new(gcphlt_.zintla);
}

static VALUE _wrap_gcphlt_stepla_set(VALUE self, VALUE arg)
{
  gcphlt_.stepla = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcphlt_stepla_get(VALUE self)
{
  return rb_float_new(gcphlt_.stepla);
}

static VALUE _wrap_gcphlt_isync_set(VALUE self, VALUE arg)
{
  gcphlt_.isync = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphlt_isync_get(VALUE self)
{
  return INT2NUM(gcphlt_.isync);
}

static VALUE _wrap_gcphlt_istra_set(VALUE self, VALUE arg)
{
  gcphlt_.istra = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcphlt_istra_get(VALUE self)
{
  return INT2NUM(gcphlt_.istra);
}

static VALUE _wrap_gcparm_iparam_set(VALUE self, VALUE arg)
{
  gcparm_.iparam = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcparm_iparam_get(VALUE self)
{
  return INT2NUM(gcparm_.iparam);
}

static VALUE _wrap_gcparm_pcutga_set(VALUE self, VALUE arg)
{
  gcparm_.pcutga = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcparm_pcutga_get(VALUE self)
{
  return rb_float_new(gcparm_.pcutga);
}

static VALUE _wrap_gcparm_pcutel_set(VALUE self, VALUE arg)
{
  gcparm_.pcutel = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcparm_pcutel_get(VALUE self)
{
  return rb_float_new(gcparm_.pcutel);
}

static VALUE _wrap_gcparm_pcutne_set(VALUE self, VALUE arg)
{
  gcparm_.pcutne = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcparm_pcutne_get(VALUE self)
{
  return rb_float_new(gcparm_.pcutne);
}

static VALUE _wrap_gcparm_pcutha_set(VALUE self, VALUE arg)
{
  gcparm_.pcutha = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcparm_pcutha_get(VALUE self)
{
  return rb_float_new(gcparm_.pcutha);
}

static VALUE _wrap_gcparm_pcutmu_set(VALUE self, VALUE arg)
{
  gcparm_.pcutmu = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcparm_pcutmu_get(VALUE self)
{
  return rb_float_new(gcparm_.pcutmu);
}

static VALUE _wrap_gcparm_nspara_set(VALUE self, VALUE arg)
{
  gcparm_.nspara = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcparm_nspara_get(VALUE self)
{
  return INT2NUM(gcparm_.nspara);
}

static VALUE _wrap_gcparm_mpstak_set(VALUE self, VALUE arg)
{
  gcparm_.mpstak = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcparm_mpstak_get(VALUE self)
{
  return INT2NUM(gcparm_.mpstak);
}

static VALUE _wrap_gcparm_npgene_set(VALUE self, VALUE arg)
{
  gcparm_.npgene = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcparm_npgene_get(VALUE self)
{
  return INT2NUM(gcparm_.npgene);
}

static VALUE _wrap_gcpara_epsix0_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcpara_.epsix0[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcpara_epsix0_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "epsix0");
  if (NIL_P(value)) {
    value = rb_ary_new2(5000);
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, rb_float_new(gcpara_.epsix0[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcpara_epsix0_set, 2);
    rb_iv_set(self, "epsix0", value);
  } else {
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, rb_float_new(gcpara_.epsix0[i]));
  }
  return value;
}

static VALUE _wrap_gcpara_idrphi_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcpara_.idrphi[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_idrphi_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "idrphi");
  if (NIL_P(value)) {
    value = rb_ary_new2(5000);
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, INT2NUM(gcpara_.idrphi[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcpara_idrphi_set, 2);
    rb_iv_set(self, "idrphi", value);
  } else {
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, INT2NUM(gcpara_.idrphi[i]));
  }
  return value;
}

static VALUE _wrap_gcpara_idrtet_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcpara_.idrtet[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_idrtet_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "idrtet");
  if (NIL_P(value)) {
    value = rb_ary_new2(5000);
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, INT2NUM(gcpara_.idrtet[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcpara_idrtet_set, 2);
    rb_iv_set(self, "idrtet", value);
  } else {
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, INT2NUM(gcpara_.idrtet[i]));
  }
  return value;
}

static VALUE _wrap_gcpara_idrout_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcpara_.idrout[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_idrout_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "idrout");
  if (NIL_P(value)) {
    value = rb_ary_new2(5000);
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, INT2NUM(gcpara_.idrout[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcpara_idrout_set, 2);
    rb_iv_set(self, "idrout", value);
  } else {
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, INT2NUM(gcpara_.idrout[i]));
  }
  return value;
}

static VALUE _wrap_gcpara_jplost_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcpara_.jplost[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_jplost_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "jplost");
  if (NIL_P(value)) {
    value = rb_ary_new2(5000);
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, INT2NUM(gcpara_.jplost[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcpara_jplost_set, 2);
    rb_iv_set(self, "jplost", value);
  } else {
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, INT2NUM(gcpara_.jplost[i]));
  }
  return value;
}

static VALUE _wrap_gcpara_iphtmp_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcpara_.iphtmp[id] = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_iphtmp_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "iphtmp");
  if (NIL_P(value)) {
    value = rb_ary_new2(5000);
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, INT2NUM(gcpara_.iphtmp[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcpara_iphtmp_set, 2);
    rb_iv_set(self, "iphtmp", value);
  } else {
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, INT2NUM(gcpara_.iphtmp[i]));
  }
  return value;
}

static VALUE _wrap_gcpara_bitphi_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcpara_.bitphi[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcpara_bitphi_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "bitphi");
  if (NIL_P(value)) {
    value = rb_ary_new2(5000);
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, rb_float_new(gcpara_.bitphi[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcpara_bitphi_set, 2);
    rb_iv_set(self, "bitphi", value);
  } else {
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, rb_float_new(gcpara_.bitphi[i]));
  }
  return value;
}

static VALUE _wrap_gcpara_bittet_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcpara_.bittet[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcpara_bittet_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "bittet");
  if (NIL_P(value)) {
    value = rb_ary_new2(5000);
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, rb_float_new(gcpara_.bittet[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcpara_bittet_set, 2);
    rb_iv_set(self, "bittet", value);
  } else {
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, rb_float_new(gcpara_.bittet[i]));
  }
  return value;
}

static VALUE _wrap_gcpara_bitpot_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gcpara_.bitpot[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcpara_bitpot_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "bitpot");
  if (NIL_P(value)) {
    value = rb_ary_new2(5000);
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, rb_float_new(gcpara_.bitpot[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gcpara_bitpot_set, 2);
    rb_iv_set(self, "bitpot", value);
  } else {
    for (i = 0; i < 5000; i++)
      rb_ary_store(value, i, rb_float_new(gcpara_.bitpot[i]));
  }
  return value;
}

static VALUE _wrap_gcpara_jjlost_set(VALUE self, VALUE arg)
{
  gcpara_.jjlost = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_jjlost_get(VALUE self)
{
  return INT2NUM(gcpara_.jjlost);
}

static VALUE _wrap_gcpara_jjfill_set(VALUE self, VALUE arg)
{
  gcpara_.jjfill = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_jjfill_get(VALUE self)
{
  return INT2NUM(gcpara_.jjfill);
}

static VALUE _wrap_gcpara_jentry_set(VALUE self, VALUE arg)
{
  gcpara_.jentry = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_jentry_get(VALUE self)
{
  return INT2NUM(gcpara_.jentry);
}

static VALUE _wrap_gcpara_jempty_set(VALUE self, VALUE arg)
{
  gcpara_.jempty = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_jempty_get(VALUE self)
{
  return INT2NUM(gcpara_.jempty);
}

static VALUE _wrap_gcpara_epsmax_set(VALUE self, VALUE arg)
{
  gcpara_.epsmax = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcpara_epsmax_get(VALUE self)
{
  return rb_float_new(gcpara_.epsmax);
}

static VALUE _wrap_gcpara_jjtemp_set(VALUE self, VALUE arg)
{
  gcpara_.jjtemp = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_jjtemp_get(VALUE self)
{
  return INT2NUM(gcpara_.jjtemp);
}

static VALUE _wrap_gcpara_jjwork_set(VALUE self, VALUE arg)
{
  gcpara_.jjwork = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_jjwork_get(VALUE self)
{
  return INT2NUM(gcpara_.jjwork);
}

static VALUE _wrap_gcpara_jjstk1_set(VALUE self, VALUE arg)
{
  gcpara_.jjstk1 = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_jjstk1_get(VALUE self)
{
  return INT2NUM(gcpara_.jjstk1);
}

static VALUE _wrap_gcpara_j1temp_set(VALUE self, VALUE arg)
{
  gcpara_.j1temp = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_j1temp_get(VALUE self)
{
  return INT2NUM(gcpara_.j1temp);
}

static VALUE _wrap_gcpara_j1stk1_set(VALUE self, VALUE arg)
{
  gcpara_.j1stk1 = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_j1stk1_get(VALUE self)
{
  return INT2NUM(gcpara_.j1stk1);
}

static VALUE _wrap_gcpara_ifounp_set(VALUE self, VALUE arg)
{
  gcpara_.ifounp = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_ifounp_get(VALUE self)
{
  return INT2NUM(gcpara_.ifounp);
}

static VALUE _wrap_gcpara_ifount_set(VALUE self, VALUE arg)
{
  gcpara_.ifount = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_ifount_get(VALUE self)
{
  return INT2NUM(gcpara_.ifount);
}

static VALUE _wrap_gcpara_ifnpot_set(VALUE self, VALUE arg)
{
  gcpara_.ifnpot = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gcpara_ifnpot_get(VALUE self)
{
  return INT2NUM(gcpara_.ifnpot);
}

static VALUE _wrap_gcpara_symphi_set(VALUE self, VALUE arg)
{
  gcpara_.symphi = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcpara_symphi_get(VALUE self)
{
  return rb_float_new(gcpara_.symphi);
}

static VALUE _wrap_gcpara_symteu_set(VALUE self, VALUE arg)
{
  gcpara_.symteu = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcpara_symteu_get(VALUE self)
{
  return rb_float_new(gcpara_.symteu);
}

static VALUE _wrap_gcpara_symted_set(VALUE self, VALUE arg)
{
  gcpara_.symted = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gcpara_symted_get(VALUE self)
{
  return rb_float_new(gcpara_.symted);
}

static VALUE _wrap_gsecti_aiel_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gsecti_.aiel[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gsecti_aiel_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "aiel");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, rb_float_new(gsecti_.aiel[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gsecti_aiel_set, 2);
    rb_iv_set(self, "aiel", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, rb_float_new(gsecti_.aiel[i]));
  }
  return value;
}

static VALUE _wrap_gsecti_aiin_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gsecti_.aiin[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gsecti_aiin_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "aiin");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, rb_float_new(gsecti_.aiin[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gsecti_aiin_set, 2);
    rb_iv_set(self, "aiin", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, rb_float_new(gsecti_.aiin[i]));
  }
  return value;
}

static VALUE _wrap_gsecti_aifi_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gsecti_.aifi[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gsecti_aifi_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "aifi");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, rb_float_new(gsecti_.aifi[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gsecti_aifi_set, 2);
    rb_iv_set(self, "aifi", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, rb_float_new(gsecti_.aifi[i]));
  }
  return value;
}

static VALUE _wrap_gsecti_aica_set(VALUE self, VALUE index, VALUE arg)
{
  int id = NUM2INT(index);
  gsecti_.aica[id] = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gsecti_aica_get(VALUE self)
{
  int i;
  VALUE value = rb_iv_get(self, "aica");
  if (NIL_P(value)) {
    value = rb_ary_new2(20);
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, rb_float_new(gsecti_.aica[i]));
    rb_define_singleton_method(value, "[]=", _wrap_gsecti_aica_set, 2);
    rb_iv_set(self, "aica", value);
  } else {
    for (i = 0; i < 20; i++)
      rb_ary_store(value, i, rb_float_new(gsecti_.aica[i]));
  }
  return value;
}

static VALUE _wrap_gsecti_alam_set(VALUE self, VALUE arg)
{
  gsecti_.alam = NUM2DBL(arg);
  return arg;
}

static VALUE _wrap_gsecti_alam_get(VALUE self)
{
  return rb_float_new(gsecti_.alam);
}

static VALUE _wrap_gsecti_k0flag_set(VALUE self, VALUE arg)
{
  gsecti_.k0flag = NUM2INT(arg);
  return arg;
}

static VALUE _wrap_gsecti_k0flag_get(VALUE self)
{
  return INT2NUM(gsecti_.k0flag);
}


void Init_geant()
{
  VALUE wrap_sGCFLAG, wrap_sGCLIST, wrap_sGCONST, wrap_sGCKINE, wrap_sGCSETS, wrap_sGCTMED, wrap_sGCKING, wrap_sGCKIN2, wrap_sGCKIN3, wrap_sGCTRAK, wrap_sGCVOLU, wrap_sGCCUTS, wrap_sGCDRAW, wrap_sGCMATE, wrap_sGCNUM, wrap_sGCPHYS, wrap_sGCPHLT, wrap_sGCPARM, wrap_sGCPARA, wrap_sGSECTI;

  cern_id_id = rb_intern("id");

  wrap_mCERN = rb_define_module("CERN");
  wrap_mGEANT = rb_define_module_under(wrap_mCERN, "GEANT");

  rb_define_module_function(wrap_mGEANT, "gdaxis", _wrap_gdaxis, 4);
  rb_define_module_function(wrap_mGEANT, "gdclos", _wrap_gdclos, 0);
  rb_define_module_function(wrap_mGEANT, "gdhead", _wrap_gdhead, 3);
  rb_define_module_function(wrap_mGEANT, "gdinit", _wrap_gdinit, 0);
  rb_define_module_function(wrap_mGEANT, "gdman", _wrap_gdman, 2);
  rb_define_module_function(wrap_mGEANT, "gdopen", _wrap_gdopen, 1);
  rb_define_module_function(wrap_mGEANT, "gdopt", _wrap_gdopt, 2);
  rb_define_module_function(wrap_mGEANT, "gdraw", _wrap_gdraw, 8);
  rb_define_module_function(wrap_mGEANT, "gdrawc", _wrap_gdrawc, 7);
  rb_define_module_function(wrap_mGEANT, "gdrawt", _wrap_gdrawt, 7);
  rb_define_module_function(wrap_mGEANT, "gdrawv", _wrap_gdrawv, 2);
  rb_define_module_function(wrap_mGEANT, "gdrawx", _wrap_gdrawx, 10);
  rb_define_module_function(wrap_mGEANT, "gdscal", _wrap_gdscal, 2);
  rb_define_module_function(wrap_mGEANT, "gdshow", _wrap_gdshow, 1);
  rb_define_module_function(wrap_mGEANT, "gdwmn1", _wrap_gdwmn1, 2);
  rb_define_module_function(wrap_mGEANT, "gdwmn2", _wrap_gdwmn2, 2);
  rb_define_module_function(wrap_mGEANT, "gdwmn3", _wrap_gdwmn3, 2);
  rb_define_module_function(wrap_mGEANT, "gffgo", _wrap_gffgo, 0);
  rb_define_module_function(wrap_mGEANT, "ggclos", _wrap_ggclos, 0);
  rb_define_module_function(wrap_mGEANT, "ginit", _wrap_ginit, 0);
  rb_define_module_function(wrap_mGEANT, "gmate", _wrap_gmate, 0);
  rb_define_module_function(wrap_mGEANT, "gpart", _wrap_gpart, 0);
  rb_define_module_function(wrap_mGEANT, "gphysi", _wrap_gphysi, 0);
  rb_define_module_function(wrap_mGEANT, "gprint", _wrap_gprint, 2);
  rb_define_module_function(wrap_mGEANT, "grun", _wrap_grun, 0);
  rb_define_module_function(wrap_mGEANT, "gsatt", _wrap_gsatt, 3);
  rb_define_module_function(wrap_mGEANT, "gsdet", _wrap_gsdet, 8);
  rb_define_module_function(wrap_mGEANT, "gsdvn", _wrap_gsdvn, 4);
  rb_define_module_function(wrap_mGEANT, "gsmixt", _wrap_gsmixt, 7);
  rb_define_module_function(wrap_mGEANT, "gspos", _wrap_gspos, 8);
  rb_define_module_function(wrap_mGEANT, "gsrotm", _wrap_gsrotm, 7);
  rb_define_module_function(wrap_mGEANT, "gstmed", _wrap_gstmed, 12);
  rb_define_module_function(wrap_mGEANT, "gsvolu", _wrap_gsvolu, 4);
  rb_define_module_function(wrap_mGEANT, "gzebra", _wrap_gzebra, 1);
  rb_define_module_function(wrap_mGEANT, "gzinit", _wrap_gzinit, 0);
  rb_define_module_function(wrap_mGEANT, "ffset", _wrap_ffset, 2);
  rb_define_module_function(wrap_mGEANT, "gdfr3d", _wrap_gdfr3d, 1);


  wrap_sGCFLAG = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCFLAG, "idebug", _wrap_gcflag_idebug_get, 0);
  rb_define_singleton_method(wrap_sGCFLAG, "idebug=", _wrap_gcflag_idebug_set, 1);
  rb_define_singleton_method(wrap_sGCFLAG, "idemin", _wrap_gcflag_idemin_get, 0);
  rb_define_singleton_method(wrap_sGCFLAG, "idemin=", _wrap_gcflag_idemin_set, 1);
  rb_define_singleton_method(wrap_sGCFLAG, "idemax", _wrap_gcflag_idemax_get, 0);
  rb_define_singleton_method(wrap_sGCFLAG, "idemax=", _wrap_gcflag_idemax_set, 1);
  rb_define_singleton_method(wrap_sGCFLAG, "itest", _wrap_gcflag_itest_get, 0);
  rb_define_singleton_method(wrap_sGCFLAG, "itest=", _wrap_gcflag_itest_set, 1);
  rb_define_singleton_method(wrap_sGCFLAG, "idrun", _wrap_gcflag_idrun_get, 0);
  rb_define_singleton_method(wrap_sGCFLAG, "idrun=", _wrap_gcflag_idrun_set, 1);
  rb_define_singleton_method(wrap_sGCFLAG, "idevt", _wrap_gcflag_idevt_get, 0);
  rb_define_singleton_method(wrap_sGCFLAG, "idevt=", _wrap_gcflag_idevt_set, 1);
  rb_define_singleton_method(wrap_sGCFLAG, "ieorun", _wrap_gcflag_ieorun_get, 0);
  rb_define_singleton_method(wrap_sGCFLAG, "ieorun=", _wrap_gcflag_ieorun_set, 1);
  rb_define_singleton_method(wrap_sGCFLAG, "ieotri", _wrap_gcflag_ieotri_get, 0);
  rb_define_singleton_method(wrap_sGCFLAG, "ieotri=", _wrap_gcflag_ieotri_set, 1);
  rb_define_singleton_method(wrap_sGCFLAG, "ievent", _wrap_gcflag_ievent_get, 0);
  rb_define_singleton_method(wrap_sGCFLAG, "ievent=", _wrap_gcflag_ievent_set, 1);
  rb_define_singleton_method(wrap_sGCFLAG, "iswit", _wrap_gcflag_iswit_get, 0);
  rb_define_singleton_method(wrap_sGCFLAG, "ifinit", _wrap_gcflag_ifinit_get, 0);
  rb_define_singleton_method(wrap_sGCFLAG, "nevent", _wrap_gcflag_nevent_get, 0);
  rb_define_singleton_method(wrap_sGCFLAG, "nevent=", _wrap_gcflag_nevent_set, 1);
  rb_define_singleton_method(wrap_sGCFLAG, "nrndm", _wrap_gcflag_nrndm_get, 0);
  rb_define_const(wrap_mGEANT, "GCFLAG", wrap_sGCFLAG);

  wrap_sGCLIST = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCLIST, "nhsta", _wrap_gclist_nhsta_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "nhsta=", _wrap_gclist_nhsta_set, 1);
  rb_define_singleton_method(wrap_sGCLIST, "nget", _wrap_gclist_nget_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "nget=", _wrap_gclist_nget_set, 1);
  rb_define_singleton_method(wrap_sGCLIST, "nsave", _wrap_gclist_nsave_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "nsave=", _wrap_gclist_nsave_set, 1);
  rb_define_singleton_method(wrap_sGCLIST, "nsets", _wrap_gclist_nsets_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "nsets=", _wrap_gclist_nsets_set, 1);
  rb_define_singleton_method(wrap_sGCLIST, "nprin", _wrap_gclist_nprin_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "nprin=", _wrap_gclist_nprin_set, 1);
  rb_define_singleton_method(wrap_sGCLIST, "ngeom", _wrap_gclist_ngeom_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "ngeom=", _wrap_gclist_ngeom_set, 1);
  rb_define_singleton_method(wrap_sGCLIST, "nview", _wrap_gclist_nview_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "nview=", _wrap_gclist_nview_set, 1);
  rb_define_singleton_method(wrap_sGCLIST, "nplot", _wrap_gclist_nplot_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "nplot=", _wrap_gclist_nplot_set, 1);
  rb_define_singleton_method(wrap_sGCLIST, "nstat", _wrap_gclist_nstat_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "nstat=", _wrap_gclist_nstat_set, 1);
  rb_define_singleton_method(wrap_sGCLIST, "lhsta", _wrap_gclist_lhsta_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "lget", _wrap_gclist_lget_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "lsave", _wrap_gclist_lsave_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "lsets", _wrap_gclist_lsets_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "lprin", _wrap_gclist_lprin_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "lgeom", _wrap_gclist_lgeom_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "lview", _wrap_gclist_lview_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "lplot", _wrap_gclist_lplot_get, 0);
  rb_define_singleton_method(wrap_sGCLIST, "lstat", _wrap_gclist_lstat_get, 0);
  rb_define_const(wrap_mGEANT, "GCLIST", wrap_sGCLIST);

  wrap_sGCONST = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCONST, "pi", _wrap_gconst_pi_get, 0);
  rb_define_singleton_method(wrap_sGCONST, "pi=", _wrap_gconst_pi_set, 1);
  rb_define_singleton_method(wrap_sGCONST, "twopi", _wrap_gconst_twopi_get, 0);
  rb_define_singleton_method(wrap_sGCONST, "twopi=", _wrap_gconst_twopi_set, 1);
  rb_define_singleton_method(wrap_sGCONST, "piby2", _wrap_gconst_piby2_get, 0);
  rb_define_singleton_method(wrap_sGCONST, "piby2=", _wrap_gconst_piby2_set, 1);
  rb_define_singleton_method(wrap_sGCONST, "degrad", _wrap_gconst_degrad_get, 0);
  rb_define_singleton_method(wrap_sGCONST, "degrad=", _wrap_gconst_degrad_set, 1);
  rb_define_singleton_method(wrap_sGCONST, "raddeg", _wrap_gconst_raddeg_get, 0);
  rb_define_singleton_method(wrap_sGCONST, "raddeg=", _wrap_gconst_raddeg_set, 1);
  rb_define_singleton_method(wrap_sGCONST, "clight", _wrap_gconst_clight_get, 0);
  rb_define_singleton_method(wrap_sGCONST, "clight=", _wrap_gconst_clight_set, 1);
  rb_define_singleton_method(wrap_sGCONST, "big", _wrap_gconst_big_get, 0);
  rb_define_singleton_method(wrap_sGCONST, "big=", _wrap_gconst_big_set, 1);
  rb_define_singleton_method(wrap_sGCONST, "emass", _wrap_gconst_emass_get, 0);
  rb_define_singleton_method(wrap_sGCONST, "emass=", _wrap_gconst_emass_set, 1);
  rb_define_const(wrap_mGEANT, "GCONST", wrap_sGCONST);

  wrap_sGCKINE = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCKINE, "ikine", _wrap_gckine_ikine_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "ikine=", _wrap_gckine_ikine_set, 1);
  rb_define_singleton_method(wrap_sGCKINE, "pkine", _wrap_gckine_pkine_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "itra", _wrap_gckine_itra_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "itra=", _wrap_gckine_itra_set, 1);
  rb_define_singleton_method(wrap_sGCKINE, "istak", _wrap_gckine_istak_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "istak=", _wrap_gckine_istak_set, 1);
  rb_define_singleton_method(wrap_sGCKINE, "ivert", _wrap_gckine_ivert_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "ivert=", _wrap_gckine_ivert_set, 1);
  rb_define_singleton_method(wrap_sGCKINE, "ipart", _wrap_gckine_ipart_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "ipart=", _wrap_gckine_ipart_set, 1);
  rb_define_singleton_method(wrap_sGCKINE, "itrtyp", _wrap_gckine_itrtyp_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "itrtyp=", _wrap_gckine_itrtyp_set, 1);
  rb_define_singleton_method(wrap_sGCKINE, "napart", _wrap_gckine_napart_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "amass", _wrap_gckine_amass_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "amass=", _wrap_gckine_amass_set, 1);
  rb_define_singleton_method(wrap_sGCKINE, "charge", _wrap_gckine_charge_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "charge=", _wrap_gckine_charge_set, 1);
  rb_define_singleton_method(wrap_sGCKINE, "tlife", _wrap_gckine_tlife_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "tlife=", _wrap_gckine_tlife_set, 1);
  rb_define_singleton_method(wrap_sGCKINE, "vert", _wrap_gckine_vert_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "pvert", _wrap_gckine_pvert_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "ipaold", _wrap_gckine_ipaold_get, 0);
  rb_define_singleton_method(wrap_sGCKINE, "ipaold=", _wrap_gckine_ipaold_set, 1);
  rb_define_const(wrap_mGEANT, "GCKINE", wrap_sGCKINE);

  wrap_sGCSETS = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCSETS, "ihset", _wrap_gcsets_ihset_get, 0);
  rb_define_singleton_method(wrap_sGCSETS, "ihset=", _wrap_gcsets_ihset_set, 1);
  rb_define_singleton_method(wrap_sGCSETS, "ihdet", _wrap_gcsets_ihdet_get, 0);
  rb_define_singleton_method(wrap_sGCSETS, "ihdet=", _wrap_gcsets_ihdet_set, 1);
  rb_define_singleton_method(wrap_sGCSETS, "iset", _wrap_gcsets_iset_get, 0);
  rb_define_singleton_method(wrap_sGCSETS, "iset=", _wrap_gcsets_iset_set, 1);
  rb_define_singleton_method(wrap_sGCSETS, "idet", _wrap_gcsets_idet_get, 0);
  rb_define_singleton_method(wrap_sGCSETS, "idet=", _wrap_gcsets_idet_set, 1);
  rb_define_singleton_method(wrap_sGCSETS, "idtype", _wrap_gcsets_idtype_get, 0);
  rb_define_singleton_method(wrap_sGCSETS, "idtype=", _wrap_gcsets_idtype_set, 1);
  rb_define_singleton_method(wrap_sGCSETS, "nvname", _wrap_gcsets_nvname_get, 0);
  rb_define_singleton_method(wrap_sGCSETS, "nvname=", _wrap_gcsets_nvname_set, 1);
  rb_define_singleton_method(wrap_sGCSETS, "numbv", _wrap_gcsets_numbv_get, 0);
  rb_define_const(wrap_mGEANT, "GCSETS", wrap_sGCSETS);

  wrap_sGCTMED = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCTMED, "numed", _wrap_gctmed_numed_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "numed=", _wrap_gctmed_numed_set, 1);
  rb_define_singleton_method(wrap_sGCTMED, "natmed", _wrap_gctmed_natmed_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "isvol", _wrap_gctmed_isvol_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "isvol=", _wrap_gctmed_isvol_set, 1);
  rb_define_singleton_method(wrap_sGCTMED, "ifield", _wrap_gctmed_ifield_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "ifield=", _wrap_gctmed_ifield_set, 1);
  rb_define_singleton_method(wrap_sGCTMED, "fieldm", _wrap_gctmed_fieldm_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "fieldm=", _wrap_gctmed_fieldm_set, 1);
  rb_define_singleton_method(wrap_sGCTMED, "tmaxfd", _wrap_gctmed_tmaxfd_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "tmaxfd=", _wrap_gctmed_tmaxfd_set, 1);
  rb_define_singleton_method(wrap_sGCTMED, "dmaxms", _wrap_gctmed_dmaxms_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "dmaxms=", _wrap_gctmed_dmaxms_set, 1);
  rb_define_singleton_method(wrap_sGCTMED, "deemax", _wrap_gctmed_deemax_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "deemax=", _wrap_gctmed_deemax_set, 1);
  rb_define_singleton_method(wrap_sGCTMED, "epsil", _wrap_gctmed_epsil_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "epsil=", _wrap_gctmed_epsil_set, 1);
  rb_define_singleton_method(wrap_sGCTMED, "stmin", _wrap_gctmed_stmin_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "stmin=", _wrap_gctmed_stmin_set, 1);
  rb_define_singleton_method(wrap_sGCTMED, "cfield", _wrap_gctmed_cfield_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "cfield=", _wrap_gctmed_cfield_set, 1);
  rb_define_singleton_method(wrap_sGCTMED, "prec", _wrap_gctmed_prec_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "prec=", _wrap_gctmed_prec_set, 1);
  rb_define_singleton_method(wrap_sGCTMED, "iupd", _wrap_gctmed_iupd_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "iupd=", _wrap_gctmed_iupd_set, 1);
  rb_define_singleton_method(wrap_sGCTMED, "istpar", _wrap_gctmed_istpar_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "istpar=", _wrap_gctmed_istpar_set, 1);
  rb_define_singleton_method(wrap_sGCTMED, "numold", _wrap_gctmed_numold_get, 0);
  rb_define_singleton_method(wrap_sGCTMED, "numold=", _wrap_gctmed_numold_set, 1);
  rb_define_const(wrap_mGEANT, "GCTMED", wrap_sGCTMED);

  wrap_sGCKING = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCKING, "kcase", _wrap_gcking_kcase_get, 0);
  rb_define_singleton_method(wrap_sGCKING, "kcase=", _wrap_gcking_kcase_set, 1);
  rb_define_singleton_method(wrap_sGCKING, "ngkine", _wrap_gcking_ngkine_get, 0);
  rb_define_singleton_method(wrap_sGCKING, "ngkine=", _wrap_gcking_ngkine_set, 1);
  rb_define_singleton_method(wrap_sGCKING, "gkin", _wrap_gcking_gkin_get, 0);
  rb_define_singleton_method(wrap_sGCKING, "tofd", _wrap_gcking_tofd_get, 0);
  rb_define_singleton_method(wrap_sGCKING, "iflgk", _wrap_gcking_iflgk_get, 0);
  rb_define_const(wrap_mGEANT, "GCKING", wrap_sGCKING);

  wrap_sGCKIN2 = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCKIN2, "ngphoto", _wrap_gckin2_ngphoto_get, 0);
  rb_define_singleton_method(wrap_sGCKIN2, "ngphoto=", _wrap_gckin2_ngphoto_set, 1);
  rb_define_singleton_method(wrap_sGCKIN2, "xphoto", _wrap_gckin2_xphoto_get, 0);
  rb_define_const(wrap_mGEANT, "GCKIN2", wrap_sGCKIN2);

  wrap_sGCKIN3 = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCKIN3, "gpos", _wrap_gckin3_gpos_get, 0);
  rb_define_const(wrap_mGEANT, "GCKIN3", wrap_sGCKIN3);

  wrap_sGCTRAK = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCTRAK, "vect", _wrap_gctrak_vect_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "getot", _wrap_gctrak_getot_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "getot=", _wrap_gctrak_getot_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "gekin", _wrap_gctrak_gekin_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "gekin=", _wrap_gctrak_gekin_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "vout", _wrap_gctrak_vout_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "nmec", _wrap_gctrak_nmec_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "nmec=", _wrap_gctrak_nmec_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "lmec", _wrap_gctrak_lmec_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "namec", _wrap_gctrak_namec_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "nstep", _wrap_gctrak_nstep_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "nstep=", _wrap_gctrak_nstep_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "maxnst", _wrap_gctrak_maxnst_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "maxnst=", _wrap_gctrak_maxnst_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "destep", _wrap_gctrak_destep_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "destep=", _wrap_gctrak_destep_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "destel", _wrap_gctrak_destel_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "destel=", _wrap_gctrak_destel_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "safety", _wrap_gctrak_safety_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "safety=", _wrap_gctrak_safety_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "sleng", _wrap_gctrak_sleng_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "sleng=", _wrap_gctrak_sleng_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "step", _wrap_gctrak_step_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "step=", _wrap_gctrak_step_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "snext", _wrap_gctrak_snext_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "snext=", _wrap_gctrak_snext_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "sfield", _wrap_gctrak_sfield_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "sfield=", _wrap_gctrak_sfield_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "tofg", _wrap_gctrak_tofg_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "tofg=", _wrap_gctrak_tofg_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "gekrat", _wrap_gctrak_gekrat_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "gekrat=", _wrap_gctrak_gekrat_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "upwght", _wrap_gctrak_upwght_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "upwght=", _wrap_gctrak_upwght_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "ignext", _wrap_gctrak_ignext_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "ignext=", _wrap_gctrak_ignext_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "inwvol", _wrap_gctrak_inwvol_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "inwvol=", _wrap_gctrak_inwvol_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "istop", _wrap_gctrak_istop_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "istop=", _wrap_gctrak_istop_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "igauto", _wrap_gctrak_igauto_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "igauto=", _wrap_gctrak_igauto_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "iekbin", _wrap_gctrak_iekbin_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "iekbin=", _wrap_gctrak_iekbin_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "ilosl", _wrap_gctrak_ilosl_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "ilosl=", _wrap_gctrak_ilosl_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "imull", _wrap_gctrak_imull_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "imull=", _wrap_gctrak_imull_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "ingoto", _wrap_gctrak_ingoto_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "ingoto=", _wrap_gctrak_ingoto_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "nldown", _wrap_gctrak_nldown_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "nldown=", _wrap_gctrak_nldown_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "nlevin", _wrap_gctrak_nlevin_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "nlevin=", _wrap_gctrak_nlevin_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "nlvsav", _wrap_gctrak_nlvsav_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "nlvsav=", _wrap_gctrak_nlvsav_set, 1);
  rb_define_singleton_method(wrap_sGCTRAK, "istory", _wrap_gctrak_istory_get, 0);
  rb_define_singleton_method(wrap_sGCTRAK, "istory=", _wrap_gctrak_istory_set, 1);
  rb_define_const(wrap_mGEANT, "GCTRAK", wrap_sGCTRAK);

  wrap_sGCVOLU = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCVOLU, "nlevel", _wrap_gcvolu_nlevel_get, 0);
  rb_define_singleton_method(wrap_sGCVOLU, "nlevel=", _wrap_gcvolu_nlevel_set, 1);
  rb_define_singleton_method(wrap_sGCVOLU, "names", _wrap_gcvolu_names_get, 0);
  rb_define_singleton_method(wrap_sGCVOLU, "number", _wrap_gcvolu_number_get, 0);
  rb_define_singleton_method(wrap_sGCVOLU, "lvolum", _wrap_gcvolu_lvolum_get, 0);
  rb_define_singleton_method(wrap_sGCVOLU, "lindex", _wrap_gcvolu_lindex_get, 0);
  rb_define_singleton_method(wrap_sGCVOLU, "infrom", _wrap_gcvolu_infrom_get, 0);
  rb_define_singleton_method(wrap_sGCVOLU, "infrom=", _wrap_gcvolu_infrom_set, 1);
  rb_define_singleton_method(wrap_sGCVOLU, "nlevmx", _wrap_gcvolu_nlevmx_get, 0);
  rb_define_singleton_method(wrap_sGCVOLU, "nlevmx=", _wrap_gcvolu_nlevmx_set, 1);
  rb_define_singleton_method(wrap_sGCVOLU, "nldev", _wrap_gcvolu_nldev_get, 0);
  rb_define_singleton_method(wrap_sGCVOLU, "linmx", _wrap_gcvolu_linmx_get, 0);
  rb_define_singleton_method(wrap_sGCVOLU, "gtran", _wrap_gcvolu_gtran_get, 0);
  rb_define_singleton_method(wrap_sGCVOLU, "grmat", _wrap_gcvolu_grmat_get, 0);
  rb_define_singleton_method(wrap_sGCVOLU, "gonly", _wrap_gcvolu_gonly_get, 0);
  rb_define_singleton_method(wrap_sGCVOLU, "glx", _wrap_gcvolu_glx_get, 0);
  rb_define_const(wrap_mGEANT, "GCVOLU", wrap_sGCVOLU);

  wrap_sGCCUTS = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCCUTS, "cutgam", _wrap_gccuts_cutgam_get, 0);
  rb_define_singleton_method(wrap_sGCCUTS, "cutgam=", _wrap_gccuts_cutgam_set, 1);
  rb_define_singleton_method(wrap_sGCCUTS, "cutele", _wrap_gccuts_cutele_get, 0);
  rb_define_singleton_method(wrap_sGCCUTS, "cutele=", _wrap_gccuts_cutele_set, 1);
  rb_define_singleton_method(wrap_sGCCUTS, "cutneu", _wrap_gccuts_cutneu_get, 0);
  rb_define_singleton_method(wrap_sGCCUTS, "cutneu=", _wrap_gccuts_cutneu_set, 1);
  rb_define_singleton_method(wrap_sGCCUTS, "cuthad", _wrap_gccuts_cuthad_get, 0);
  rb_define_singleton_method(wrap_sGCCUTS, "cuthad=", _wrap_gccuts_cuthad_set, 1);
  rb_define_singleton_method(wrap_sGCCUTS, "cutmuo", _wrap_gccuts_cutmuo_get, 0);
  rb_define_singleton_method(wrap_sGCCUTS, "cutmuo=", _wrap_gccuts_cutmuo_set, 1);
  rb_define_singleton_method(wrap_sGCCUTS, "bcute", _wrap_gccuts_bcute_get, 0);
  rb_define_singleton_method(wrap_sGCCUTS, "bcute=", _wrap_gccuts_bcute_set, 1);
  rb_define_singleton_method(wrap_sGCCUTS, "bcutm", _wrap_gccuts_bcutm_get, 0);
  rb_define_singleton_method(wrap_sGCCUTS, "bcutm=", _wrap_gccuts_bcutm_set, 1);
  rb_define_singleton_method(wrap_sGCCUTS, "dcute", _wrap_gccuts_dcute_get, 0);
  rb_define_singleton_method(wrap_sGCCUTS, "dcute=", _wrap_gccuts_dcute_set, 1);
  rb_define_singleton_method(wrap_sGCCUTS, "dcutm", _wrap_gccuts_dcutm_get, 0);
  rb_define_singleton_method(wrap_sGCCUTS, "dcutm=", _wrap_gccuts_dcutm_set, 1);
  rb_define_singleton_method(wrap_sGCCUTS, "ppcutm", _wrap_gccuts_ppcutm_get, 0);
  rb_define_singleton_method(wrap_sGCCUTS, "ppcutm=", _wrap_gccuts_ppcutm_set, 1);
  rb_define_singleton_method(wrap_sGCCUTS, "tofmax", _wrap_gccuts_tofmax_get, 0);
  rb_define_singleton_method(wrap_sGCCUTS, "tofmax=", _wrap_gccuts_tofmax_set, 1);
  rb_define_singleton_method(wrap_sGCCUTS, "gcuts", _wrap_gccuts_gcuts_get, 0);
  rb_define_const(wrap_mGEANT, "GCCUTS", wrap_sGCCUTS);

  wrap_sGCDRAW = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCDRAW, "numnod", _wrap_gcdraw_numnod_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "numnod=", _wrap_gcdraw_numnod_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "maxnod", _wrap_gcdraw_maxnod_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "maxnod=", _wrap_gcdraw_maxnod_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "numnd1", _wrap_gcdraw_numnd1_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "numnd1=", _wrap_gcdraw_numnd1_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "levver", _wrap_gcdraw_levver_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "levver=", _wrap_gcdraw_levver_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "levhor", _wrap_gcdraw_levhor_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "levhor=", _wrap_gcdraw_levhor_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "maxv", _wrap_gcdraw_maxv_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "maxv=", _wrap_gcdraw_maxv_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "ipick", _wrap_gcdraw_ipick_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "ipick=", _wrap_gcdraw_ipick_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "mlevv", _wrap_gcdraw_mlevv_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "mlevv=", _wrap_gcdraw_mlevv_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "mlevh", _wrap_gcdraw_mlevh_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "mlevh=", _wrap_gcdraw_mlevh_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "nwcut", _wrap_gcdraw_nwcut_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "nwcut=", _wrap_gcdraw_nwcut_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jnam", _wrap_gcdraw_jnam_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jnam=", _wrap_gcdraw_jnam_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jmot", _wrap_gcdraw_jmot_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jmot=", _wrap_gcdraw_jmot_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jxon", _wrap_gcdraw_jxon_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jxon=", _wrap_gcdraw_jxon_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jbro", _wrap_gcdraw_jbro_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jbro=", _wrap_gcdraw_jbro_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jdup", _wrap_gcdraw_jdup_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jdup=", _wrap_gcdraw_jdup_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jsca", _wrap_gcdraw_jsca_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jsca=", _wrap_gcdraw_jsca_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jdvm", _wrap_gcdraw_jdvm_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jdvm=", _wrap_gcdraw_jdvm_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jpsm", _wrap_gcdraw_jpsm_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jpsm=", _wrap_gcdraw_jpsm_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jnam1", _wrap_gcdraw_jnam1_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jnam1=", _wrap_gcdraw_jnam1_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jmot1", _wrap_gcdraw_jmot1_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jmot1=", _wrap_gcdraw_jmot1_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jxon1", _wrap_gcdraw_jxon1_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jxon1=", _wrap_gcdraw_jxon1_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jbro1", _wrap_gcdraw_jbro1_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jbro1=", _wrap_gcdraw_jbro1_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jdup1", _wrap_gcdraw_jdup1_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jdup1=", _wrap_gcdraw_jdup1_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jsca1", _wrap_gcdraw_jsca1_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jsca1=", _wrap_gcdraw_jsca1_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "julev", _wrap_gcdraw_julev_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "julev=", _wrap_gcdraw_julev_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "jvlev", _wrap_gcdraw_jvlev_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "jvlev=", _wrap_gcdraw_jvlev_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "looktb", _wrap_gcdraw_looktb_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "grmat0", _wrap_gcdraw_grmat0_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gtran0", _wrap_gcdraw_gtran0_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "idrnum", _wrap_gcdraw_idrnum_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "idrnum=", _wrap_gcdraw_idrnum_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gsin", _wrap_gcdraw_gsin_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gcos", _wrap_gcdraw_gcos_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "sinpsi", _wrap_gcdraw_sinpsi_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "sinpsi=", _wrap_gcdraw_sinpsi_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "cospsi", _wrap_gcdraw_cospsi_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "cospsi=", _wrap_gcdraw_cospsi_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gtheta", _wrap_gcdraw_gtheta_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gtheta=", _wrap_gcdraw_gtheta_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gphi", _wrap_gcdraw_gphi_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gphi=", _wrap_gcdraw_gphi_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gpsi", _wrap_gcdraw_gpsi_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gpsi=", _wrap_gcdraw_gpsi_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gu0", _wrap_gcdraw_gu0_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gu0=", _wrap_gcdraw_gu0_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gv0", _wrap_gcdraw_gv0_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gv0=", _wrap_gcdraw_gv0_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gscu", _wrap_gcdraw_gscu_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gscu=", _wrap_gcdraw_gscu_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gscv", _wrap_gcdraw_gscv_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gscv=", _wrap_gcdraw_gscv_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "ngview", _wrap_gcdraw_ngview_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "ngview=", _wrap_gcdraw_ngview_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "icutfl", _wrap_gcdraw_icutfl_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "icutfl=", _wrap_gcdraw_icutfl_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "icut", _wrap_gcdraw_icut_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "icut=", _wrap_gcdraw_icut_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "ctheta", _wrap_gcdraw_ctheta_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "ctheta=", _wrap_gcdraw_ctheta_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "cphi", _wrap_gcdraw_cphi_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "cphi=", _wrap_gcdraw_cphi_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "dcut", _wrap_gcdraw_dcut_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "dcut=", _wrap_gcdraw_dcut_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "nsurf", _wrap_gcdraw_nsurf_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "nsurf=", _wrap_gcdraw_nsurf_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "isurf", _wrap_gcdraw_isurf_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "isurf=", _wrap_gcdraw_isurf_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gzua", _wrap_gcdraw_gzua_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gzua=", _wrap_gcdraw_gzua_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gzva", _wrap_gcdraw_gzva_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gzva=", _wrap_gcdraw_gzva_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gzub", _wrap_gcdraw_gzub_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gzub=", _wrap_gcdraw_gzub_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gzvb", _wrap_gcdraw_gzvb_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gzvb=", _wrap_gcdraw_gzvb_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gzuc", _wrap_gcdraw_gzuc_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gzuc=", _wrap_gcdraw_gzuc_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "gzvc", _wrap_gcdraw_gzvc_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "gzvc=", _wrap_gcdraw_gzvc_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "pltrnx", _wrap_gcdraw_pltrnx_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "pltrnx=", _wrap_gcdraw_pltrnx_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "pltrny", _wrap_gcdraw_pltrny_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "pltrny=", _wrap_gcdraw_pltrny_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "linatt", _wrap_gcdraw_linatt_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "linatt=", _wrap_gcdraw_linatt_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "linatp", _wrap_gcdraw_linatp_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "linatp=", _wrap_gcdraw_linatp_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "itxatt", _wrap_gcdraw_itxatt_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "itxatt=", _wrap_gcdraw_itxatt_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "ithrz", _wrap_gcdraw_ithrz_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "ithrz=", _wrap_gcdraw_ithrz_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "iprj", _wrap_gcdraw_iprj_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "iprj=", _wrap_gcdraw_iprj_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "dpers", _wrap_gcdraw_dpers_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "dpers=", _wrap_gcdraw_dpers_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "itr3d", _wrap_gcdraw_itr3d_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "itr3d=", _wrap_gcdraw_itr3d_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "ipkhit", _wrap_gcdraw_ipkhit_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "ipkhit=", _wrap_gcdraw_ipkhit_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "iobj", _wrap_gcdraw_iobj_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "iobj=", _wrap_gcdraw_iobj_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "linbumaxgu", _wrap_gcdraw_linbumaxgu_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "linbumaxgu=", _wrap_gcdraw_linbumaxgu_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "morgu", _wrap_gcdraw_morgu_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "morgu=", _wrap_gcdraw_morgu_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "maxgs", _wrap_gcdraw_maxgs_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "maxgs=", _wrap_gcdraw_maxgs_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "morgs", _wrap_gcdraw_morgs_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "morgs=", _wrap_gcdraw_morgs_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "maxtu", _wrap_gcdraw_maxtu_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "maxtu=", _wrap_gcdraw_maxtu_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "mortu", _wrap_gcdraw_mortu_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "mortu=", _wrap_gcdraw_mortu_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "maxts", _wrap_gcdraw_maxts_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "maxts=", _wrap_gcdraw_maxts_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "morts", _wrap_gcdraw_morts_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "morts=", _wrap_gcdraw_morts_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "igu", _wrap_gcdraw_igu_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "igu=", _wrap_gcdraw_igu_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "igs", _wrap_gcdraw_igs_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "igs=", _wrap_gcdraw_igs_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "itu", _wrap_gcdraw_itu_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "itu=", _wrap_gcdraw_itu_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "its", _wrap_gcdraw_its_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "its=", _wrap_gcdraw_its_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "nkview", _wrap_gcdraw_nkview_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "nkview=", _wrap_gcdraw_nkview_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "idview", _wrap_gcdraw_idview_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "idview=", _wrap_gcdraw_idview_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "nopen", _wrap_gcdraw_nopen_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "nopen=", _wrap_gcdraw_nopen_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "igmr", _wrap_gcdraw_igmr_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "igmr=", _wrap_gcdraw_igmr_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "ipions", _wrap_gcdraw_ipions_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "ipions=", _wrap_gcdraw_ipions_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "itrkop", _wrap_gcdraw_itrkop_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "itrkop=", _wrap_gcdraw_itrkop_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "ihiden", _wrap_gcdraw_ihiden_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "ihiden=", _wrap_gcdraw_ihiden_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "zzfu", _wrap_gcdraw_zzfu_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "zzfu=", _wrap_gcdraw_zzfu_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "zzfv", _wrap_gcdraw_zzfv_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "zzfv=", _wrap_gcdraw_zzfv_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "myisel", _wrap_gcdraw_myisel_get, 0);
  rb_define_singleton_method(wrap_sGCDRAW, "myisel=", _wrap_gcdraw_myisel_set, 1);
  rb_define_singleton_method(wrap_sGCDRAW, "ddummy", _wrap_gcdraw_ddummy_get, 0);
  rb_define_const(wrap_mGEANT, "GCDRAW", wrap_sGCDRAW);

  wrap_sGCMATE = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCMATE, "nmat", _wrap_gcmate_nmat_get, 0);
  rb_define_singleton_method(wrap_sGCMATE, "nmat=", _wrap_gcmate_nmat_set, 1);
  rb_define_singleton_method(wrap_sGCMATE, "namate", _wrap_gcmate_namate_get, 0);
  rb_define_singleton_method(wrap_sGCMATE, "a", _wrap_gcmate_a_get, 0);
  rb_define_singleton_method(wrap_sGCMATE, "a=", _wrap_gcmate_a_set, 1);
  rb_define_singleton_method(wrap_sGCMATE, "z", _wrap_gcmate_z_get, 0);
  rb_define_singleton_method(wrap_sGCMATE, "z=", _wrap_gcmate_z_set, 1);
  rb_define_singleton_method(wrap_sGCMATE, "dens", _wrap_gcmate_dens_get, 0);
  rb_define_singleton_method(wrap_sGCMATE, "dens=", _wrap_gcmate_dens_set, 1);
  rb_define_singleton_method(wrap_sGCMATE, "radl", _wrap_gcmate_radl_get, 0);
  rb_define_singleton_method(wrap_sGCMATE, "radl=", _wrap_gcmate_radl_set, 1);
  rb_define_singleton_method(wrap_sGCMATE, "absl", _wrap_gcmate_absl_get, 0);
  rb_define_singleton_method(wrap_sGCMATE, "absl=", _wrap_gcmate_absl_set, 1);
  rb_define_const(wrap_mGEANT, "GCMATE", wrap_sGCMATE);

  wrap_sGCNUM = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCNUM, "nmate", _wrap_gcnum_nmate_get, 0);
  rb_define_singleton_method(wrap_sGCNUM, "nmate=", _wrap_gcnum_nmate_set, 1);
  rb_define_singleton_method(wrap_sGCNUM, "nvolum", _wrap_gcnum_nvolum_get, 0);
  rb_define_singleton_method(wrap_sGCNUM, "nvolum=", _wrap_gcnum_nvolum_set, 1);
  rb_define_singleton_method(wrap_sGCNUM, "nrotm", _wrap_gcnum_nrotm_get, 0);
  rb_define_singleton_method(wrap_sGCNUM, "nrotm=", _wrap_gcnum_nrotm_set, 1);
  rb_define_singleton_method(wrap_sGCNUM, "ntmed", _wrap_gcnum_ntmed_get, 0);
  rb_define_singleton_method(wrap_sGCNUM, "ntmed=", _wrap_gcnum_ntmed_set, 1);
  rb_define_singleton_method(wrap_sGCNUM, "ntmult", _wrap_gcnum_ntmult_get, 0);
  rb_define_singleton_method(wrap_sGCNUM, "ntmult=", _wrap_gcnum_ntmult_set, 1);
  rb_define_singleton_method(wrap_sGCNUM, "ntrack", _wrap_gcnum_ntrack_get, 0);
  rb_define_singleton_method(wrap_sGCNUM, "ntrack=", _wrap_gcnum_ntrack_set, 1);
  rb_define_singleton_method(wrap_sGCNUM, "npart", _wrap_gcnum_npart_get, 0);
  rb_define_singleton_method(wrap_sGCNUM, "npart=", _wrap_gcnum_npart_set, 1);
  rb_define_singleton_method(wrap_sGCNUM, "nstmax", _wrap_gcnum_nstmax_get, 0);
  rb_define_singleton_method(wrap_sGCNUM, "nstmax=", _wrap_gcnum_nstmax_set, 1);
  rb_define_singleton_method(wrap_sGCNUM, "nvertx", _wrap_gcnum_nvertx_get, 0);
  rb_define_singleton_method(wrap_sGCNUM, "nvertx=", _wrap_gcnum_nvertx_set, 1);
  rb_define_singleton_method(wrap_sGCNUM, "nhead", _wrap_gcnum_nhead_get, 0);
  rb_define_singleton_method(wrap_sGCNUM, "nhead=", _wrap_gcnum_nhead_set, 1);
  rb_define_singleton_method(wrap_sGCNUM, "nbit", _wrap_gcnum_nbit_get, 0);
  rb_define_singleton_method(wrap_sGCNUM, "nbit=", _wrap_gcnum_nbit_set, 1);
  rb_define_const(wrap_mGEANT, "GCNUM", wrap_sGCNUM);

  wrap_sGCPHYS = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCPHYS, "ipair", _wrap_gcphys_ipair_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "ipair=", _wrap_gcphys_ipair_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "spair", _wrap_gcphys_spair_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "spair=", _wrap_gcphys_spair_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "slpair", _wrap_gcphys_slpair_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "slpair=", _wrap_gcphys_slpair_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "zintpa", _wrap_gcphys_zintpa_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "zintpa=", _wrap_gcphys_zintpa_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "steppa", _wrap_gcphys_steppa_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "steppa=", _wrap_gcphys_steppa_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "icomp", _wrap_gcphys_icomp_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "icomp=", _wrap_gcphys_icomp_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "scomp", _wrap_gcphys_scomp_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "scomp=", _wrap_gcphys_scomp_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "slcomp", _wrap_gcphys_slcomp_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "slcomp=", _wrap_gcphys_slcomp_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "zintco", _wrap_gcphys_zintco_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "zintco=", _wrap_gcphys_zintco_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "stepco", _wrap_gcphys_stepco_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "stepco=", _wrap_gcphys_stepco_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "iphot", _wrap_gcphys_iphot_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "iphot=", _wrap_gcphys_iphot_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "sphot", _wrap_gcphys_sphot_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "sphot=", _wrap_gcphys_sphot_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "slphot", _wrap_gcphys_slphot_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "slphot=", _wrap_gcphys_slphot_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "zintph", _wrap_gcphys_zintph_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "zintph=", _wrap_gcphys_zintph_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "stepph", _wrap_gcphys_stepph_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "stepph=", _wrap_gcphys_stepph_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "ipfis", _wrap_gcphys_ipfis_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "ipfis=", _wrap_gcphys_ipfis_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "spfis", _wrap_gcphys_spfis_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "spfis=", _wrap_gcphys_spfis_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "slpfis", _wrap_gcphys_slpfis_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "slpfis=", _wrap_gcphys_slpfis_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "zintpf", _wrap_gcphys_zintpf_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "zintpf=", _wrap_gcphys_zintpf_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "steppf", _wrap_gcphys_steppf_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "steppf=", _wrap_gcphys_steppf_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "idray", _wrap_gcphys_idray_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "idray=", _wrap_gcphys_idray_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "sdray", _wrap_gcphys_sdray_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "sdray=", _wrap_gcphys_sdray_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "sldray", _wrap_gcphys_sldray_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "sldray=", _wrap_gcphys_sldray_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "zintdr", _wrap_gcphys_zintdr_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "zintdr=", _wrap_gcphys_zintdr_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "stepdr", _wrap_gcphys_stepdr_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "stepdr=", _wrap_gcphys_stepdr_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "ianni", _wrap_gcphys_ianni_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "ianni=", _wrap_gcphys_ianni_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "sanni", _wrap_gcphys_sanni_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "sanni=", _wrap_gcphys_sanni_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "slanni", _wrap_gcphys_slanni_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "slanni=", _wrap_gcphys_slanni_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "zintan", _wrap_gcphys_zintan_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "zintan=", _wrap_gcphys_zintan_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "stepan", _wrap_gcphys_stepan_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "stepan=", _wrap_gcphys_stepan_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "ibrem", _wrap_gcphys_ibrem_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "ibrem=", _wrap_gcphys_ibrem_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "sbrem", _wrap_gcphys_sbrem_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "sbrem=", _wrap_gcphys_sbrem_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "slbrem", _wrap_gcphys_slbrem_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "slbrem=", _wrap_gcphys_slbrem_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "zintbr", _wrap_gcphys_zintbr_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "zintbr=", _wrap_gcphys_zintbr_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "stepbr", _wrap_gcphys_stepbr_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "stepbr=", _wrap_gcphys_stepbr_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "ihadr", _wrap_gcphys_ihadr_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "ihadr=", _wrap_gcphys_ihadr_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "shadr", _wrap_gcphys_shadr_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "shadr=", _wrap_gcphys_shadr_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "slhadr", _wrap_gcphys_slhadr_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "slhadr=", _wrap_gcphys_slhadr_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "zintha", _wrap_gcphys_zintha_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "zintha=", _wrap_gcphys_zintha_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "stepha", _wrap_gcphys_stepha_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "stepha=", _wrap_gcphys_stepha_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "imunu", _wrap_gcphys_imunu_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "imunu=", _wrap_gcphys_imunu_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "smunu", _wrap_gcphys_smunu_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "smunu=", _wrap_gcphys_smunu_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "slmunu", _wrap_gcphys_slmunu_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "slmunu=", _wrap_gcphys_slmunu_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "zintmu", _wrap_gcphys_zintmu_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "zintmu=", _wrap_gcphys_zintmu_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "stepmu", _wrap_gcphys_stepmu_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "stepmu=", _wrap_gcphys_stepmu_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "idcay", _wrap_gcphys_idcay_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "idcay=", _wrap_gcphys_idcay_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "sdcay", _wrap_gcphys_sdcay_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "sdcay=", _wrap_gcphys_sdcay_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "slife", _wrap_gcphys_slife_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "slife=", _wrap_gcphys_slife_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "sumlif", _wrap_gcphys_sumlif_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "sumlif=", _wrap_gcphys_sumlif_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "dphys1", _wrap_gcphys_dphys1_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "dphys1=", _wrap_gcphys_dphys1_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "iloss", _wrap_gcphys_iloss_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "iloss=", _wrap_gcphys_iloss_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "sloss", _wrap_gcphys_sloss_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "sloss=", _wrap_gcphys_sloss_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "soloss", _wrap_gcphys_soloss_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "soloss=", _wrap_gcphys_soloss_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "stloss", _wrap_gcphys_stloss_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "stloss=", _wrap_gcphys_stloss_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "dphys2", _wrap_gcphys_dphys2_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "dphys2=", _wrap_gcphys_dphys2_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "imuls", _wrap_gcphys_imuls_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "imuls=", _wrap_gcphys_imuls_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "smuls", _wrap_gcphys_smuls_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "smuls=", _wrap_gcphys_smuls_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "somuls", _wrap_gcphys_somuls_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "somuls=", _wrap_gcphys_somuls_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "stmuls", _wrap_gcphys_stmuls_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "stmuls=", _wrap_gcphys_stmuls_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "dphys3", _wrap_gcphys_dphys3_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "dphys3=", _wrap_gcphys_dphys3_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "irayl", _wrap_gcphys_irayl_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "irayl=", _wrap_gcphys_irayl_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "srayl", _wrap_gcphys_srayl_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "srayl=", _wrap_gcphys_srayl_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "slrayl", _wrap_gcphys_slrayl_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "slrayl=", _wrap_gcphys_slrayl_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "zintra", _wrap_gcphys_zintra_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "zintra=", _wrap_gcphys_zintra_set, 1);
  rb_define_singleton_method(wrap_sGCPHYS, "stepra", _wrap_gcphys_stepra_get, 0);
  rb_define_singleton_method(wrap_sGCPHYS, "stepra=", _wrap_gcphys_stepra_set, 1);
  rb_define_const(wrap_mGEANT, "GCPHYS", wrap_sGCPHYS);

  wrap_sGCPHLT = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCPHLT, "ilabs", _wrap_gcphlt_ilabs_get, 0);
  rb_define_singleton_method(wrap_sGCPHLT, "ilabs=", _wrap_gcphlt_ilabs_set, 1);
  rb_define_singleton_method(wrap_sGCPHLT, "slabs", _wrap_gcphlt_slabs_get, 0);
  rb_define_singleton_method(wrap_sGCPHLT, "slabs=", _wrap_gcphlt_slabs_set, 1);
  rb_define_singleton_method(wrap_sGCPHLT, "sllabs", _wrap_gcphlt_sllabs_get, 0);
  rb_define_singleton_method(wrap_sGCPHLT, "sllabs=", _wrap_gcphlt_sllabs_set, 1);
  rb_define_singleton_method(wrap_sGCPHLT, "zintla", _wrap_gcphlt_zintla_get, 0);
  rb_define_singleton_method(wrap_sGCPHLT, "zintla=", _wrap_gcphlt_zintla_set, 1);
  rb_define_singleton_method(wrap_sGCPHLT, "stepla", _wrap_gcphlt_stepla_get, 0);
  rb_define_singleton_method(wrap_sGCPHLT, "stepla=", _wrap_gcphlt_stepla_set, 1);
  rb_define_singleton_method(wrap_sGCPHLT, "isync", _wrap_gcphlt_isync_get, 0);
  rb_define_singleton_method(wrap_sGCPHLT, "isync=", _wrap_gcphlt_isync_set, 1);
  rb_define_singleton_method(wrap_sGCPHLT, "istra", _wrap_gcphlt_istra_get, 0);
  rb_define_singleton_method(wrap_sGCPHLT, "istra=", _wrap_gcphlt_istra_set, 1);
  rb_define_const(wrap_mGEANT, "GCPHLT", wrap_sGCPHLT);

  wrap_sGCPARM = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCPARM, "iparam", _wrap_gcparm_iparam_get, 0);
  rb_define_singleton_method(wrap_sGCPARM, "iparam=", _wrap_gcparm_iparam_set, 1);
  rb_define_singleton_method(wrap_sGCPARM, "pcutga", _wrap_gcparm_pcutga_get, 0);
  rb_define_singleton_method(wrap_sGCPARM, "pcutga=", _wrap_gcparm_pcutga_set, 1);
  rb_define_singleton_method(wrap_sGCPARM, "pcutel", _wrap_gcparm_pcutel_get, 0);
  rb_define_singleton_method(wrap_sGCPARM, "pcutel=", _wrap_gcparm_pcutel_set, 1);
  rb_define_singleton_method(wrap_sGCPARM, "pcutne", _wrap_gcparm_pcutne_get, 0);
  rb_define_singleton_method(wrap_sGCPARM, "pcutne=", _wrap_gcparm_pcutne_set, 1);
  rb_define_singleton_method(wrap_sGCPARM, "pcutha", _wrap_gcparm_pcutha_get, 0);
  rb_define_singleton_method(wrap_sGCPARM, "pcutha=", _wrap_gcparm_pcutha_set, 1);
  rb_define_singleton_method(wrap_sGCPARM, "pcutmu", _wrap_gcparm_pcutmu_get, 0);
  rb_define_singleton_method(wrap_sGCPARM, "pcutmu=", _wrap_gcparm_pcutmu_set, 1);
  rb_define_singleton_method(wrap_sGCPARM, "nspara", _wrap_gcparm_nspara_get, 0);
  rb_define_singleton_method(wrap_sGCPARM, "nspara=", _wrap_gcparm_nspara_set, 1);
  rb_define_singleton_method(wrap_sGCPARM, "mpstak", _wrap_gcparm_mpstak_get, 0);
  rb_define_singleton_method(wrap_sGCPARM, "mpstak=", _wrap_gcparm_mpstak_set, 1);
  rb_define_singleton_method(wrap_sGCPARM, "npgene", _wrap_gcparm_npgene_get, 0);
  rb_define_singleton_method(wrap_sGCPARM, "npgene=", _wrap_gcparm_npgene_set, 1);
  rb_define_const(wrap_mGEANT, "GCPARM", wrap_sGCPARM);

  wrap_sGCPARA = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGCPARA, "epsix0", _wrap_gcpara_epsix0_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "idrphi", _wrap_gcpara_idrphi_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "idrtet", _wrap_gcpara_idrtet_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "idrout", _wrap_gcpara_idrout_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "jplost", _wrap_gcpara_jplost_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "iphtmp", _wrap_gcpara_iphtmp_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "bitphi", _wrap_gcpara_bitphi_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "bittet", _wrap_gcpara_bittet_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "bitpot", _wrap_gcpara_bitpot_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "jjlost", _wrap_gcpara_jjlost_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "jjlost=", _wrap_gcpara_jjlost_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "jjfill", _wrap_gcpara_jjfill_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "jjfill=", _wrap_gcpara_jjfill_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "jentry", _wrap_gcpara_jentry_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "jentry=", _wrap_gcpara_jentry_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "jempty", _wrap_gcpara_jempty_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "jempty=", _wrap_gcpara_jempty_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "epsmax", _wrap_gcpara_epsmax_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "epsmax=", _wrap_gcpara_epsmax_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "jjtemp", _wrap_gcpara_jjtemp_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "jjtemp=", _wrap_gcpara_jjtemp_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "jjwork", _wrap_gcpara_jjwork_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "jjwork=", _wrap_gcpara_jjwork_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "jjstk1", _wrap_gcpara_jjstk1_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "jjstk1=", _wrap_gcpara_jjstk1_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "j1temp", _wrap_gcpara_j1temp_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "j1temp=", _wrap_gcpara_j1temp_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "j1stk1", _wrap_gcpara_j1stk1_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "j1stk1=", _wrap_gcpara_j1stk1_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "ifounp", _wrap_gcpara_ifounp_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "ifounp=", _wrap_gcpara_ifounp_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "ifount", _wrap_gcpara_ifount_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "ifount=", _wrap_gcpara_ifount_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "ifnpot", _wrap_gcpara_ifnpot_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "ifnpot=", _wrap_gcpara_ifnpot_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "symphi", _wrap_gcpara_symphi_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "symphi=", _wrap_gcpara_symphi_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "symteu", _wrap_gcpara_symteu_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "symteu=", _wrap_gcpara_symteu_set, 1);
  rb_define_singleton_method(wrap_sGCPARA, "symted", _wrap_gcpara_symted_get, 0);
  rb_define_singleton_method(wrap_sGCPARA, "symted=", _wrap_gcpara_symted_set, 1);
  rb_define_const(wrap_mGEANT, "GCPARA", wrap_sGCPARA);

  wrap_sGSECTI = rb_obj_alloc(rb_cObject);
  rb_define_singleton_method(wrap_sGSECTI, "aiel", _wrap_gsecti_aiel_get, 0);
  rb_define_singleton_method(wrap_sGSECTI, "aiin", _wrap_gsecti_aiin_get, 0);
  rb_define_singleton_method(wrap_sGSECTI, "aifi", _wrap_gsecti_aifi_get, 0);
  rb_define_singleton_method(wrap_sGSECTI, "aica", _wrap_gsecti_aica_get, 0);
  rb_define_singleton_method(wrap_sGSECTI, "alam", _wrap_gsecti_alam_get, 0);
  rb_define_singleton_method(wrap_sGSECTI, "alam=", _wrap_gsecti_alam_set, 1);
  rb_define_singleton_method(wrap_sGSECTI, "k0flag", _wrap_gsecti_k0flag_get, 0);
  rb_define_singleton_method(wrap_sGSECTI, "k0flag=", _wrap_gsecti_k0flag_set, 1);
  rb_define_const(wrap_mGEANT, "GSECTI", wrap_sGSECTI);

  rb_define_const(wrap_mGEANT, "NWPAWC", INT2NUM(NWPAWC));
  rb_define_const(wrap_mGEANT, "NGCBANK", INT2NUM(NGCBANK));
}
