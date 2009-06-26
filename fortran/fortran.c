#include <ruby.h>

extern void fortfileopen_(int*, char*, char*, char*, char*, char*, int*,
			  int, int, int, int, int);
extern void fortfileclose_(int*, char*, int);


static VALUE
fortran_file_open(int argc, VALUE *argv, VALUE klass)
{
  VALUE vlun, vfname, vstatus, vform, vacces, vblank, vrecord;
  int lun, record;
  char *fname, *status, *form, *acces, *blank;

  rb_scan_args(argc, argv, "25", &vlun, &vfname, &vstatus,
	       &vform, &vacces, &vblank, &vrecord);

  Check_SafeStr(vfname);
  fname = RSTRING(vfname)->ptr;
  lun = FIX2INT(vlun);
  if (NIL_P(vstatus))
    status = "UNKNOWN";
  else
    status = STR2CSTR(vstatus);
  if (NIL_P(vform))
    form = "FORMATTED";
  else
    form = STR2CSTR(vform);
  if (NIL_P(vacces))
    acces = "SEQUENTIAL";
  else
    acces = STR2CSTR(vacces);
  if (NIL_P(vblank))
    blank = "NULL";
  else
    blank = STR2CSTR(vblank);
  if (NIL_P(vrecord))
    record = 0;
  else
    record = FIX2INT(vrecord);

  fortfileopen_(&lun, fname, status, form, acces, blank, &record,
		strlen(fname), strlen(status), strlen(form),
		strlen(acces), strlen(blank));

  return Qnil;
}

static VALUE
fortran_file_close(int argc, VALUE *argv, VALUE klass)
{
  VALUE vlun, vstatus;
  int lun;
  char *status;

  rb_scan_args(argc, argv, "11", &vlun, &vstatus);

  lun = FIX2INT(vlun);
  if (NIL_P(vstatus))
    status = "KEEP";
  else
    status = STR2CSTR(vstatus);

  fortfileclose_(&lun, status, strlen(status));

  return Qnil;
}

void
Init_fortran()
{
  VALUE mCERN, mFortran;

  mCERN = rb_define_module("CERN");
  mFortran = rb_define_module_under(mCERN, "Fortran");

  rb_define_module_function(mFortran, "open", fortran_file_open, -1);
  rb_define_module_function(mFortran, "close", fortran_file_close, -1);
}
