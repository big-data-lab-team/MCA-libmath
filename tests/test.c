#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef N
#define N 30
#endif

int main(int argc, char *argv[]) {

  if (argc != 2) {
    fprintf(stderr, "usage: ./sin <x>\n");
    exit(1);
  }

  double x = atof(argv[1]);
  for (int i = 0; i < N; i++) {
    double res = sin(x);
    printf("%.13a\n", res);
  }

  return 0;
}
