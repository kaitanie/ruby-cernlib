#ifndef _RUBY_CERNLIB_UTIL_H_
#define _RUBY_CERNLIB_UTIL_H_


typedef struct {
  float r;
  float i;
} complex;

typedef struct {
  double r;
  double i;
} dcomplex;


/* translate Fortran-style string to C-style and return its length */
static int
util_str_f2c(char *str, int max_len)
{
  int len = max_len - 1;
  while (*(str + len) == ' ' && len >= 0)
    len--;
  *(str + (++len)) = '\0';
  return len;
}

/* translate Fortran-style string array to Ruby's array */
static VALUE
util_str_ary_f2rb(char *str, int len_str, int len_ary)
{
  int i, j;
  VALUE ary = rb_ary_new2(len_ary);
  for (i = 0; i < len_ary; i++) {
    for (j = len_str - 1; str[j] == ' ' && j >= 0; j--);   
    str[++j] = '\0';
    rb_ary_store(ary, i, rb_str_new(str, j));
    str += len_str;
  }
  return ary;
}

/* translate Ruby's array of string to Fortran-style string */
static char*
util_str_ary_rb2f(VALUE ary, int len_str, char *str)
{
  int i, j;
  int len_ary = RARRAY(ary)->len;
  for (i = 0; i < len_ary; i++) {
    char *ptr = STR2CSTR(RARRAY(ary)->ptr[i]);
    for (j = 0; j < len_str && *ptr; j++)
      *str++ = *ptr++;
    for (; j < len_str; j++)
      *str++ = ' ';
  }
  *str = '\0';
  return str;
}


/* callback function with 1 float argument to return float */
static float
float_callback_float(float *x1)
{
  VALUE val = rb_float_new(*x1);
  return ((float) NUM2DBL(rb_yield(val)));
}

/* callback function with 2 float arguments to return float */
static float
float_callback_float_float(float *x1, float *x2)
{
  VALUE val = rb_assoc_new(rb_float_new(*x1), rb_float_new(*x2));
  return ((float) NUM2DBL(rb_yield(val)));
}

/* callback function with 1 double argument to return double */
static double
double_callback_double(double *x1)
{
  VALUE val = rb_float_new(*x1);
  return (NUM2DBL(rb_yield(val)));
}

/* callback function with 2 double arguments to return double */
static double
double_callback_double_double(double *x1, double *x2)
{
  VALUE val = rb_assoc_new(rb_float_new(*x1), rb_float_new(*x2));
  return (NUM2DBL(rb_yield(val)));
}


#endif /* ! _RUBY_CERNLIB_UTIL_H_ */
