#include <unistd.h>
#include <stdio.h>

int main(int argc, char *const argv[]) {
  printf("Current OS page size is: %d", getpagesize());
  return 0;
}
