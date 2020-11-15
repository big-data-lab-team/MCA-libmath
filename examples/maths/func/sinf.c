#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {

  if (argc != 2) {
    fprintf(stderr, "usage: ./sinf <x>\n");
    exit(1);
  }
  
  float x = atof(argv[1]);
  float res = sinf(x);
  printf("%.13a\n", res);
  
  return 0;
}

