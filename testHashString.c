#include <stdio.h>
#include "wordCounter.h"

int main() {
  printf("%d\n", hashString("A"));
  printf("%d\n", hashString("AA"));
  printf("%d\n", hashString("a"));
  return 0;
}
