#include <cstdio>
#include "bignum.h"
#include "euclid.h"
#include "miller_rabin.h"

using namespace std;

num n, p, q, e, d;

const int KEY_SIZE = 6;
const num LOWEST_KEY = 1 << KEY_SIZE;
const num HIGHEST_KEY = (1 << (KEY_SIZE + 1)) - 1;

void generateKey() {
  num p = randomPrime(LOWEST_KEY, HIGHEST_KEY);
  num q = randomPrime(LOWEST_KEY, HIGHEST_KEY);
  num n = p * q;
  num e = 13;
  num d = invert(e, (p - 1) * (q - 1));

  num m = 13;
  num c = powmod(m, e, n);
  num mp = powmod(c, d, n);

  printf("p = %i\nq = %i\nn = %i\ne = %i\nd = %i\n", p, q, n, e, d);
  printf("c = %i\n", c);
  printf("%i =? %i\n", m, mp);
}

int main() {
  generateKey();

  return 0;
}
