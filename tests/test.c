#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef N
#define N 30
#endif

#ifndef REAL
#error "Type is not defined"
#endif

#ifndef FUNCTION
#error "Function to evaluate is not defined"
#endif

#define FMT(x) _Generic(x, float : "%.6a\n", double : "%.13a\n")
#define FMT2(x) _Generic(x, float : "%.6a %.6a\n", double : "%.13a %.13a\n")

#ifdef UNIVAR
void eval(char *argv[]) {
  REAL x = atof(argv[1]);
  for (int i = 0; i < N; i++) {
    REAL res = FUNCTION(x);
    printf(FMT(x), res);
  }
}
#elif BIVAR
void eval(char *argv[]) {
  REAL x = atof(argv[1]);
  REAL y = atof(argv[2]);
  for (int i = 0; i < N; i++) {
    REAL res = FUNCTION(x, y);
    printf(FMT(x), res);
  }
}
#elif LGAMMA_R
void eval(char *argv[]) {
  REAL x = atof(argv[1]);
  int *sign;
  for (int i = 0; i < N; i++) {
    REAL res = FUNCTION(x, sign);
    printf(FMT(x), res);
  }
}
#elif SINCOS
void eval(char *argv[]) {
  REAL x = atof(argv[1]);
  REAL *cos, *sin;
  for (int i = 0; i < N; i++) {
    FUNCTION(x, cos, sin);
    printf(FMT2(x), *cos, *sin);
  }
}
#else
#error "No signature provided"
#endif

int main(int argc, char *argv[]) {

  eval(argv);
  return 0;
}
