#include "test.h"
#include <cassert>
#include <cstdio>

void assertTrue(bool condition, char message[]) {
  if (!condition) {
    printf("Test failed: %s\n", message);
  }
}

void assertFalse(bool condition, char message[]) {
  assertTrue(!condition, message);
}

void assertEqual(num a, num b, char message[]) {
  if (a != b) {
    printf("Test failed: %i != %i. %s\n", a, b, message);
  }
}
