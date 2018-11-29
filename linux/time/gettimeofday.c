#include <stdio.h>
#include <sys/time.h>

int main(int argc, char const *argv[]) {
  struct timeval tv;
  time_t nowtime;
  struct tm *nowtm;
  char tmbuf[64], buf[64];

  gettimeofday(&tv, NULL);
  nowtime = tv.tv_sec;
  nowtm = localtime(&nowtime);
  strftime(tmbuf, sizeof(tmbuf), "%Y-%m-%d %H:%M:%S", nowtm);
  snprintf(buf, sizeof(buf), "%s.%06d", tmbuf, tv.tv_usec);

  printf("tmbuf is: %s\n", tmbuf);
  printf("buf is: %s\n", buf);

  return 0;
}
