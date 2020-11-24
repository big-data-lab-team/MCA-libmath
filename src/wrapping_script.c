#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
//#include <math.h>

//////////////  Algebraic functions 
static double (*real_sqrt)(double dbl);
static float (*real_sqrtf)(float dbl);
static double (*real_cbrt)(double dbl);
static float (*real_cbrtf)(float dbl);
static double (*real_hypot)(double dbl1, double dbl2);
static float (*real_hypotf)(float dbl1, float dbl2);


///////////// Elementary transcendental functions 
static double (*real_log)(double dbl);
static float (*real_logf)(float dbl);
static double (*real_log10)(double dbl);
static float (*real_log10f)(float dbl);
static double (*real_log1p)(double dbl);
static float (*real_log1pf)(float dbl);
static double (*real_log2)(double dbl);
static float (*real_log2f)(float dbl);

static double (*real_sin)(double dbl);
static float (*real_sinf)(float dbl);
static double (*real_asin)(double dbl);
static float (*real_asinf)(float dbl);
static double (*real_asinh)(double dbl);
static float (*real_asinhf)(float dbl);
// double __sin(double x, double y, int iy)
// float __sindf(double x)

////////////// Higher transcendental functions 
static double (*real_cos)(double dbl);
static float (*real_cosf)(float dbl);
static double (*real_acos)(double dbl);
static float (*real_acosf)(float dbl);
static double (*real_acosh)(double dbl);
static float (*real_acoshf)(float dbl);
// double __cos(double x, double y)
// float __cosdf(double x)

static double (*real_atan)(double dbl);
static float (*real_atanf)(float dbl);
static double (*real_atan2)(double dbl1, double dbl2);
static float (*real_atan2f)(float dbl1, float dbl2);
static double (*real_atanh)(double dbl);
static float (*real_atanhf)(float dbl);
// double __tan(double x, double y, int odd)
// float __tandf(double x, int odd)

static double (*real_exp)(double dbl);
static float (*real_expf)(float dbl);
static double (*real_exp10)(double dbl);
static float (*real_exp10f)(float dbl);
static double (*real_exp2)(double dbl);
static float (*real_exp2f)(float dbl);
static double (*real_expm1)(double dbl);
static float (*real_expm1f)(float dbl);
// double __expo2(double x, double sign)
// float __expo2f(float x, float sign)

static double (*real_pow)(double dbl1, double dbl2);
static float (*real_powf)(float dbl1, float dbl2);

////////////// Higher transcendental functions 

static double (*real_j0)(double dbl);
static float (*real_j0f)(float dbl);
static double (*real_j1)(double dbl);
static float (*real_j1f)(float dbl);
static double (*real_jn)(double dbl);
static float (*real_jnf)(float dbl);
static double (*real_y0)(double dbl);
static float (*real_y0f)(float dbl);
static double (*real_y1)(double dbl);
static float (*real_y1f)(float dbl);
static double (*real_yn)(double dbl);
static float (*real_ynf)(float dbl);
static double (*real_erf)(double dbl);
static float (*real_erff)(float dbl);
static double (*real_erfc)(double dbl);
static float (*real_erfcf)(float dbl);
static double (*real_lgamma)(double dbl);
static float (*real_lgammaf)(float dbl);
static double (*real_tgamma)(double dbl);

static double (*real___lgamma_r)(double dbl, int *signgamp);
static float (*real___lgammaf_r)(float dbl, int *signgamp);

static void (*real_sincos)(double dbl, double *sin, double *cos);
static void (*real_sincosf)(float dbl, float *sin, float *cos);

//////////////////////////////////Override////////

double sqrt(double dbl)
{
    real_sqrt = dlsym(RTLD_NEXT, "sqrt");
    return real_sqrt(dbl) + 0.0;
}

float sqrtf(float dbl)
{
    real_sqrtf = dlsym(RTLD_NEXT, "sqrtf");
    return real_sqrtf(dbl) + 0.0;
}

double cbrt(double dbl)
{
    real_cbrt = dlsym(RTLD_NEXT, "cbrt");
    return real_cbrt(dbl) + 0.0;
}

float cbrtf(float dbl)
{
    real_cbrtf = dlsym(RTLD_NEXT, "cbrtf");
    return real_cbrtf(dbl) + 0.0;
}

double hypot(double dbl1, double dbl2)
{
    real_hypot = dlsym(RTLD_NEXT, "hypot");
    return real_hypot(dbl1, dbl2) + 0.0;
}

float hypotf(float dbl1, float dbl2)
{
    real_hypotf = dlsym(RTLD_NEXT, "hypotf");
    return real_hypotf(dbl1, dbl2) + 0.0;
}

double log(double dbl)
{
    real_log = dlsym(RTLD_NEXT, "log");
    return real_log(dbl) + 0.0;
}

float logf(float dbl)
{
    real_logf = dlsym(RTLD_NEXT, "logf");
    return real_logf(dbl) + 0.0;
}

double log10(double dbl)
{
    real_log10 = dlsym(RTLD_NEXT, "log10");
    return real_log10(dbl) + 0.0;
}

float log10f(float dbl)
{
    real_log10f = dlsym(RTLD_NEXT, "log10f");
    return real_log10f(dbl) + 0.0;
}

double log1p(double dbl)
{
    real_log1p = dlsym(RTLD_NEXT, "log1p");
    return real_log1p(dbl) + 0.0;
}

float log1pf(float dbl)
{
    real_log1pf = dlsym(RTLD_NEXT, "log1pf");
    return real_log1pf(dbl) + 0.0;
}

double log2(double dbl)
{
    real_log2 = dlsym(RTLD_NEXT, "log2");
    return real_log2(dbl) + 0.0;
}

float log2f(float dbl)
{
    real_log2f = dlsym(RTLD_NEXT, "log2f");
    return real_log2f(dbl) + 0.0;
}

double sin(double dbl)
{
    real_sin = dlsym(RTLD_NEXT, "sin");
    return real_sin(dbl) + 0.0;
}

float sinf(float dbl)
{
    real_sinf = dlsym(RTLD_NEXT, "sinf");
    return real_sinf(dbl) + 0.0;
}

double asin(double dbl)
{
    real_asin = dlsym(RTLD_NEXT, "asin");
    return real_asin(dbl) + 0.0;
}

float asinf(float dbl)
{
    real_asinf = dlsym(RTLD_NEXT, "asinf");
    return real_asinf(dbl) + 0.0;
}

double asinh(double dbl)
{
    real_asinh = dlsym(RTLD_NEXT, "asinh");
    return real_asinh(dbl) + 0.0;
}

float asinhf(float dbl)
{
    real_asinhf = dlsym(RTLD_NEXT, "asinhf");
    return real_asinhf(dbl) + 0.0;
}


double cos(double dbl)
{
    real_cos = dlsym(RTLD_NEXT, "cos");
    return real_cos(dbl) + 0.0;
}     

float cosf(float dbl)
{   
    real_cosf = dlsym(RTLD_NEXT, "cosf");
    return real_cosf(dbl) + 0.0;
}

double acos(double dbl)
{
    real_acos = dlsym(RTLD_NEXT, "acos");
    return real_acos(dbl) + 0.0;
}     

float acosf(float dbl)
{   
    real_acosf = dlsym(RTLD_NEXT, "acosf");
    return real_acosf(dbl) + 0.0;
}

double acosh(double dbl)
{
    real_acosh = dlsym(RTLD_NEXT, "acosh");
    return real_acosh(dbl) + 0.0;
}     

float acoshf(float dbl)
{   
    real_acoshf = dlsym(RTLD_NEXT, "acoshf");
    return real_acoshf(dbl) + 0.0;
}

double atan(double dbl)
{
    real_atan = dlsym(RTLD_NEXT, "atan");
    return real_atan(dbl) + 0.0;
}

float atanf(float dbl)
{   
    real_atanf = dlsym(RTLD_NEXT, "atanf");
    return real_atanf(dbl) + 0.0;
}

double atanh(double dbl)
{
    real_atanh = dlsym(RTLD_NEXT, "atanh");
    return real_atanh(dbl) + 0.0;
}

float atanhf(float dbl)
{   
    real_atanhf = dlsym(RTLD_NEXT, "atanhf");
    return real_atanhf(dbl) + 0.0;
}


double atan2(double dbl1, double dbl2)
{
    real_atan2 = dlsym(RTLD_NEXT, "atan2");
    return real_atan2(dbl1, dbl2) + 0.0;
}

float atan2f(float dbl1, float dbl2)
{
    real_atan2f = dlsym(RTLD_NEXT, "atan2f");
    return real_atan2f(dbl1, dbl2) + 0.0;
}


double exp(double dbl)
{
    real_exp = dlsym(RTLD_NEXT, "exp");
    return real_exp(dbl) + 0.0;
}

float expf(float dbl)
{
    real_expf = dlsym(RTLD_NEXT, "expf");
    return real_expf(dbl) + 0.0;
}

double pow(double dbl1, double dbl2)
{
    real_pow = dlsym(RTLD_NEXT, "pow");
    return real_pow(dbl1, dbl2) + 0.0;
}

float powf(float dbl1, float dbl2)
{
    real_powf = dlsym(RTLD_NEXT, "powf");
    return real_powf(dbl1, dbl2) + 0.0;
}

double exp10(double dbl)
{
    real_exp10 = dlsym(RTLD_NEXT, "exp10");
    return real_exp10(dbl) + 0.0;
}

float exp10f(float dbl)
{
    real_exp10f = dlsym(RTLD_NEXT, "exp10f");
    return real_exp10f(dbl) + 0.0;
}

double exp2(double dbl)
{
    real_exp2 = dlsym(RTLD_NEXT, "exp2");
    return real_exp2(dbl) + 0.0;
}

float exp2f(float dbl)
{
    real_exp2f = dlsym(RTLD_NEXT, "exp2f");
    return real_exp2f(dbl) + 0.0;
}

double expm1(double dbl)
{
    real_expm1 = dlsym(RTLD_NEXT, "expm1");
    return real_expm1(dbl) + 0.0;
}

float expm1f(float dbl)
{
    real_expm1f = dlsym(RTLD_NEXT, "expm1f");
    return real_expm1f(dbl) + 0.0;
}

double j0(double dbl)
{
    real_j0 = dlsym(RTLD_NEXT, "j0");
    return real_j0(dbl) + 0.0;
}

float j0f(float dbl)
{
    real_j0f = dlsym(RTLD_NEXT, "j0f");
    return real_j0f(dbl) + 0.0;
}

double j1(double dbl)
{
    real_j1 = dlsym(RTLD_NEXT, "j1");
    return real_j1(dbl) + 0.0;
}

float j1f(float dbl)
{
    real_j1f = dlsym(RTLD_NEXT, "j1f");
    return real_j1f(dbl) + 0.0;
}

double jn(double dbl)
{
    real_jn = dlsym(RTLD_NEXT, "jn");
    return real_jn(dbl) + 0.0;
}

float jnf(float dbl)
{
    real_jnf = dlsym(RTLD_NEXT, "jnf");
    return real_jnf(dbl) + 0.0;
}

double y0(double dbl)
{
    real_y0 = dlsym(RTLD_NEXT, "y0");
    return real_y0(dbl) + 0.0;
}

float y0f(float dbl)
{
    real_y0f = dlsym(RTLD_NEXT, "y0f");
    return real_y0f(dbl) + 0.0;
}

double y1(double dbl)
{
    real_y1 = dlsym(RTLD_NEXT, "y1");
    return real_y1(dbl) + 0.0;
}

float y1f(float dbl)
{
    real_y1f = dlsym(RTLD_NEXT, "y1f");
    return real_y1f(dbl) + 0.0;
}

double yn(double dbl)
{
    real_yn = dlsym(RTLD_NEXT, "yn");
    return real_yn(dbl) + 0.0;
}

float ynf(float dbl)
{
    real_ynf = dlsym(RTLD_NEXT, "ynf");
    return real_ynf(dbl) + 0.0;
}

double erf(double dbl)
{
    real_erf = dlsym(RTLD_NEXT, "erf");
    return real_erf(dbl) + 0.0;
}

float erff(float dbl)
{
    real_erff = dlsym(RTLD_NEXT, "erff");
    return real_erff(dbl) + 0.0;
}

double erfc(double dbl)
{
    real_erfc = dlsym(RTLD_NEXT, "erfc");
    return real_erfc(dbl) + 0.0;
}

float erfcf(float dbl)
{
    real_erfcf = dlsym(RTLD_NEXT, "erfcf");
    return real_erfcf(dbl) + 0.0;
}

double lgamma(double dbl)
{
    real_lgamma = dlsym(RTLD_NEXT, "lgamma");
    return real_lgamma(dbl) + 0.0;
}

double tgamma(double dbl)
{
    real_tgamma = dlsym(RTLD_NEXT, "tgamma");
    return real_tgamma(dbl) + 0.0;
}

float lgammaf(float dbl)
{
    real_lgammaf = dlsym(RTLD_NEXT, "lgammaf");
    return real_lgammaf(dbl) + 0.0;
}

double __lgamma_r(double dbl, int *signgamp)
{
    real___lgamma_r = dlsym(RTLD_NEXT, "__lgamma_r");
    return real___lgamma_r(dbl, signgamp);
}

float __lgammaf_r(float dbl, int *signgamp)
{
    real___lgammaf_r = dlsym(RTLD_NEXT, "__lgammaf_r");
    return real___lgammaf_r(dbl, signgamp);
}

void sincos(double dbl, double *sin, double *cos)
{
    real_sincos = dlsym(RTLD_NEXT, "sincos");
    return real_sincos(dbl, sin, cos);
}

void sincosf(float dbl, float *sin, float *cos)
{
    real_sincosf = dlsym(RTLD_NEXT, "sincosf");
    return real_sincosf(dbl, sin, cos);
}

