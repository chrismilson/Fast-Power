#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long long fastPow(int, int, int);

int main(int argc, char **argv) {
  int modulo = 1, base = 1, exponent = 1;
  int c;


  while ((c = getopt(argc, argv, "b:e:m:")) != -1) {
    switch(c) {
      case 'b':
        base = strtol(optarg, NULL, 10);
        break;
      case 'e':
        exponent = strtol(optarg, NULL, 10);
        break;
      case 'm':
        modulo = strtol(optarg, NULL, 10);
        break;
      default:
        break;
    }
  }

  printf("answer is %lld\n", fastPow(base, exponent, modulo));

  return 0;
}

long long fastPow(int a, int n, int m) {
  long long answer = 1;
  long long expo = n;
  long long base = a;
  while(expo > 0) {
      if (expo & 1) {
        answer *= base;
        answer %= m;
      }
      base *= base;
      base %= m;
      expo >>= 1;
  }
  return answer;
}
