#include <cstdio>
#include "test.h"
#include "miller_rabin.h"
#include "euclid.h"

using namespace std;

void testPowMod() {
  assertEqual(powmod(0, 0, 1024), 1, "0^0 should be 1");
  assertEqual(powmod(1, 0, 1024), 1, "Anything raised to 0 should be 1");
  assertEqual(powmod(103, 0, 1024), 1, "Big numbers raised to 0 should be 1");
  assertEqual(powmod(0, 1, 1024), 0, "Base 0 raised to anything should be 0");
  assertEqual(powmod(7, 1, 1024), 7, "Raising to the first power should leave number intact");
  assertEqual(powmod(42, 1, 1024), 42, "Raising to the first power should leave number intact");
  assertEqual(powmod(2, 2, 1024), 4, "Squaring failed");
  assertEqual(powmod(2, 10, 2000), 1024, "Could not calculate powers of 2");
  assertEqual(powmod(10, 3, 2000), 1000, "Small powers of 10 failed");
  assertEqual(powmod(10, 5, 1000000), 100000, "Larger powers of 10 failed");
  assertEqual(powmod(2, 10, 1024), 0, "Modulo at 1024 failed");
  assertEqual(powmod(2, 10, 1023), 1, "Should be able to take odd moduli");
  assertEqual(powmod(103, 106, 1), 0, "Large powers modulo 1 should yield 0");
  assertEqual(powmod(2, 106, 2), 0, "Large powers of 2 are always even");
  assertEqual(powmod(1461, 399, 1597), 610, "Weird large test failed");
  assertEqual(powmod(47224, 25375, 101501), 35984, "Weirder larger test failed");
}

void testRandomInRange() {
  assertEqual(randomInRange(100, 100), 100, "Range of one element should product element in that range");
  assertTrue(randomInRange(1024, 2048) >= 1024, "Lower bound of range must be respected");
  assertTrue(randomInRange(1024, 2048) <= 2048, "Upper bound of range must be respected");
}

void testCompositeness() {
  assertTrue(isComposite(4), "4 is composite");
  assertTrue(isComposite(6), "6 is composite");
  assertTrue(isComposite(9), "9 is composite");
  assertTrue(isComposite(10), "10 is composite");
  assertTrue(isComposite(100), "100 is composite");
  assertTrue(isComposite(12), "12 is composite");
  assertTrue(isComposite(6763567), "6763567 is composite");
}

void testPrimality() {
  assertFalse(isComposite(2), "2 is prime");
  assertFalse(isComposite(3), "3 is prime");
  assertFalse(isComposite(5), "5 is prime");
  assertFalse(isComposite(13), "13 is prime");
  assertFalse(isComposite(101), "101 is prime");
  assertFalse(isComposite(641), "641 is prime");
  assertFalse(isComposite(1597), "1597 is prime");
  assertFalse(isComposite(1699), "1699 is prime");
  assertFalse(isComposite(101501), "101501 is prime");
}

void testEuclid() {
  assertEqual(gcd(2, 3), 1, "Two primes are always co-prime");
  assertEqual(gcd(3, 3), 3, "Same number should have a gcd of itself");
  assertEqual(gcd(300001, 300001), 300001, "Same number should have a gcd of itself");

  num x, y;

  gcd(2, 3, x, y);

  assertEqual(x, -1, "-1 * 2 + 1 * 3 = 1");
  assertEqual(y, 1, "-1 * 2 + 1 * 3 = 1");
  assertEqual(invert(2, 3), 2, "Failed to invert 2 (mod 3)");
  assertEqual(invert(1, 3), 1, "Failed to invert 1 (mod 3)");
  assertEqual(invert(5, 7), 3, "Failed to invert 5 (mod 7)");
  assertEqual(invert(6, 7), 6, "Failed to invert 6 (mod 7)");
  assertEqual(invert(94, 101), 72, "Failed to invert 94 (mod 101)");
}

void testRandomPrime() {
  printf("A random prime: %i\n", randomPrime(100, 200));
}

int main() {
  initMillerRabin();
  testRandomInRange();
  testCompositeness();
  testPrimality();
  testPowMod();
  testEuclid();
  testRandomPrime();

  printf("Test completed.\n");

  return 0;
}
