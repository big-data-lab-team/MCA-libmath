#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
//#include <math.h>

static double (*real_log)(double dbl);
static float (*real_logf)(float dbl);
static double (*real_sin)(double dbl);
static float (*real_sinf)(float dbl);
static double (*real_cos)(double dbl);
static float (*real_cosf)(float dbl);
static double (*real_atan)(double dbl);
static float (*real_atanf)(float dbl);
static double (*real_atan2)(double dbl1, double dbl2);
static float (*real_atan2f)(float dbl1, float dbl2);

//double log(double dbl);

static void (*real_sincos)(double dbl, double *sin, double *cos);
static double (*real_exp)(double dbl);
static double (*real_pow)(double dbl1, double dbl2);

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

void sincos(double dbl, double *sin, double *cos)
{
    real_sincos = dlsym(RTLD_NEXT, "sincos");
    return real_sincos(dbl, sin, cos);
}

double exp(double dbl)
{
    real_exp = dlsym(RTLD_NEXT, "exp");
    return real_exp(dbl) + 0.0;
}

double pow(double dbl1, double dbl2)
{
    real_pow = dlsym(RTLD_NEXT, "pow");
    return real_pow(dbl1, dbl2) + 0.0;
}

