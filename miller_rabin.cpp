#include "miller_rabin.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <stack>

using namespace std;

const int ACCURACY = 20;

void initMillerRabin() {
  srand(time(NULL));
}

/*
 * Return a random number in the range [low, high] inclusive
 */
num randomInRange(num low, num high) {
  return rand() % (high - low + 1) + low;
}

num powmod(num base, num exponent, num mod) {
  stack<bool> s;

  if (base == 0 && exponent == 0) {
    return 1;
  }
  if (base == 0) {
    return 0;
  }

  while (exponent) {
    s.push(exponent & 1);
    exponent >>= 1;
  }

  num res = 1;

  while (!s.empty()) {
    bool bit = s.top();
    s.pop();

    res *= res;
    res %= mod;
    if (bit) {
      res *= base;
    }
    res %= mod;
  }

  return res;
}

bool isComposite(num candidate) {
  num d, s;

  if (candidate <= 3) {
    return false;
  }

  s = 0;
  for (d = candidate - 1; d % 2 == 0; d /= 2) {
    ++s;
  }
  // printf("s = %i, d = %i\n", s, d);

  for (int test = 0; test < ACCURACY; ++test) {
    num a = randomInRange(2, candidate - 2);
    num x = powmod(a, d, candidate);
    // printf("x = %i\n", x);
    if (x == 1 || x == candidate - 1) {
      continue;
    }
    bool probablyPrime = false;
    for (int t = 0; t < s; ++t) {
      x = (x * x) % candidate;
      // printf("%i, ", x);
      if (x == candidate - 1) {
        probablyPrime = true;
        break;
      }
      if (x == 1) {
        // printf("Found a non-trivial root of unity.\n");
        return true;
      }
    }
    if (!probablyPrime) {
      // printf("Fermat's little theorem failed for base a = %i\n", a);
      return true;
    }
  }
  return false;
}

num randomPrime(num low, num high) {
  int candidate;

  do {
    candidate = randomInRange(low, high);
  } while (isComposite(candidate));

  return candidate;
}
