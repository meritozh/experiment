#include <stdio.h>
#include <string.h>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  long online_nums = sysconf(_SC_NPROCESSORS_ONLN);
  printf("You have %ld CPU cores online currently.\n", online_nums);

  long conf_nums = sysconf(_SC_NPROCESSORS_CONF);
  printf("You have %ld CPU cores configurable currently.\n", conf_nums);

#if defined(CTL_HW) && defined(HW_AVAILCPU)
  int names[] = {CTL_HW, HW_AVAILCPU};
  int ncpu = 0;
  size_t ncpu_sz = sizeof(ncpu);

  if (sysctl(names, sizeof(names) / sizeof(names[0]), &ncpu, &ncpu_sz, NULL,
             0) != 0) {
    fprintf(stderr,
            "[ERROR] failed to obtain number of CPU cores, assuming as one\n");
    ncpu = 1;
  }

  fprintf(stdout, "You have %d CPU cores.\n", ncpu);

  int maxproc = 0;
  size_t len = sizeof(maxproc);
  sysctlbyname("kern.maxproc", &maxproc, &len, NULL, 0);

  fprintf(stdout, "You can have %d CPU cores maximum.\n", maxproc);
#endif

  return 0;
}
