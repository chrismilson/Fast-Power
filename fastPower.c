#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int int main(int argc, char const *argv[]) {
  int testFlag = 0;
  int modulo, base, exponent;
  int c;
  int *basePowers;

  while ((c = getopt(argc, argv, "t")) != -1) {
    switch(c) {
      case 't':
        testFlag = 1;
        break;
      default:
    }
  }

  if (testFlag) {
    base = 873;
  }

  return 0;
}
