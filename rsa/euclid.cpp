#include "euclid.h"
#include <cstdio>
#include <cassert>
#include <utility>

num gcd(num a, num b, num& x, num& y) {
  num ap, bp, xp, yp, gcdp;

  if (a > b) {
    return gcd(b, a, y, x);
  }
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  ap = b % a;
  bp = a;
  gcdp = gcd(ap, bp, xp, yp);

  x = -xp * (b / a) + yp;
  y = xp;

  return gcdp;
}

num gcd(num a, num b) {
  num x, y;

  return gcd(a, b, x, y);
}

num invert(num a, num mod) {
  num x, y, divisor;

  divisor = gcd(a, mod, x, y);

  assert(divisor == 1);

  if (x < 0) {
    x += mod * (x / mod + 1);
  }
  return x % mod;
}
