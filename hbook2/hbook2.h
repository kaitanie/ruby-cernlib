/*
 *  hbook2.h  - header file for HBook2 module
 *    This program is a part of Ruby/CERNLIB package
 *  (c) 1999 - 2003  TAKAHASHI Hitoshi <hitoshi.takahashi@kek.jp>
 */

#ifndef _RUBY_CERN_HBOOK2_H
#define _RUBY_CERN_HBOOK2_H

#define MAX_NUM_VARIABLES 512
#define MAX_VARNAME_LENGTH 8
#define MAX_BLOCKNAME_LENGTH 8
#define MAX_TITLE_LENGTH 100

#define HID_UNTITLED 999999

typedef struct {
  int id;
  char *title;
  int deleted;
  int xbin, ybin;
  float xmin, xmax, ymin, ymax;
} HistData;

typedef struct {
  int id;
  char *title;
  int deleted;
  int nvar;
} NtupleData;

typedef struct {
  int id;
  char *title;
  int deleted;
  int nvar;
  char **variable;
} RWNData;

typedef struct {
  ID name;
  int type, size;
  void *ptr;
} CWNVar;

typedef struct {
  ID name;
  int size, nvar;
  CWNVar *var;
  void *buf;
} CWNBlock;

typedef struct {
  ID id;
  char *name;
  int name_len;
  VALUE klass;
  char *buf;
} CWNStoredBlock;

typedef struct {
  int id;
  char *title;
  int deleted;
  int nvar;
  int num_block;
  CWNStoredBlock *blocks;
} CWNData;

typedef struct {
  char *name;
  int hid, closed;
} RZDir;

typedef struct {
  RZDir dir;
  int lun;
  char *filename, *topname, *option;
} RZFile;

#define CWNVAR_INTEGER ('i')
#define CWNVAR_REAL    ('r')

extern VALUE mHBook2;
extern VALUE cBasicHist;
extern VALUE cHist1;
extern VALUE cHist2;
extern VALUE cProfile;
extern VALUE cNtuple;
extern VALUE cRWNtuple;
extern VALUE cCWNtuple;
extern VALUE cCWNBlock;
extern VALUE cTable;
extern VALUE cRZFile;
extern VALUE cRZDir;


extern VALUE hbook2_make_object_from_data_auto_type(int id);
extern VALUE hbook2_make_histogram(VALUE klass, int id, char *title,
				   int xbin, float xmin, float xmax,
				   int ybin, float ymin, float ymax,
				   char *option);
extern VALUE hbook2_make_histogram_from_data(VALUE klass, int hid);
extern VALUE hbook2_make_ntuple_from_data(int id);
extern VALUE hbook2_make_rwn_from_data(int id);
extern VALUE hbook2_make_cwn_from_data(int id);

extern RZFile *hbook2_get_rz_file(VALUE obj);
extern RZDir *hbook2_get_rz_dir(VALUE obj);
extern HistData *hbook2_get_hist_data(VALUE obj);
extern NtupleData *hbook2_get_ntuple_data(VALUE obj);
extern int hbook2_read_file(int id, char *filename);
extern char *hbook2_current_dir_name();

#define hbook2_get_rwn(obj) ((RWNData*)hbook2_get_ntuple_data(obj))
#define hbook2_get_cwn(obj) ((CWNData*)hbook2_get_ntuple_data(obj))

extern float hi_(int *id, int *i);
extern float hij_(int *id, int *i, int *j);
extern float hmax_(int *id);
extern float hmin_(int *id);
extern float hsum_(int *id);
extern float hstati_(int *id, int *icase, char *choice, int *num, int len);
extern float hrndm1_(int *id);

static int zero = 0;

#endif  /* !defined(_RUBY_CERN_HBOOK2_H) */
