#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long long fastPow(int, int, int);

int main(int argc, char **argv) {
  int modulo = 1, base = 1, exponent = 1;
  int bFlag = 0, eFlag = 0, mFlag = 0;
  int c;


  while ((c = getopt(argc, argv, "b:e:m:")) != -1) {
    switch(c) {
      case 'b':
        bFlag = 1;
        base = strtol(optarg, NULL, 10);
        break;
      case 'e':
        eFlag = 1;
        exponent = strtol(optarg, NULL, 10);
        break;
      case 'm':
        mFlag = 1;
        modulo = strtol(optarg, NULL, 10);
        break;
      default:
        break;
    }
  }

  if (!bFlag) {
    printf("What is the base? ");
    scanf("\n %d", &base);
  }
  if (!eFlag) {
    printf("What is the exponent? ");
    scanf("\n %d", &exponent);
  }
  if (!mFlag) {
    printf("What is the modulus? ");
    scanf("\n %d", &modulo);
  }

  printf("The answer is %lld\n", fastPow(base, exponent, modulo));

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
