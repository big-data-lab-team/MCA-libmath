#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {

  if (argc != 2) {
    fprintf(stderr, "usage: ./cos <x>\n");
    exit(1);
  }
  
  double x = atof(argv[1]);
  double res = cos(x);
  printf("%.13a\n", res);
  
  return 0;
}

