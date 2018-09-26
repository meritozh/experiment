#include <time.h>
#include <stdio.h>

int main() {
  time_t curr = time(NULL);
  fprintf(stdout, "Current unix timestamp is: %ld.\n", curr);

  return 0;
}
