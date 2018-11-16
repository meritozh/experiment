#include <getopt.h>
#include <stdio.h>

int main(int argc, char * const argv[]) {
  int ch;

  struct option opts[] = {
    { "mode", required_argument, NULL, 'm' },
    { "help", no_argument, NULL, 'h' },
    { "version", no_argument, NULL, 'v' }
  };

  while ((ch = getopt_long(argc, argv, "m:hv", opts, NULL)) != -1) {
    switch (ch) {
      case 'm':
        fprintf(stdout, "You enter \"%s\"\n", optarg);
        break;
      case 'h':
        fprintf(stdout, "Help: blabla\n");
        break;
      case 'v':
        fprintf(stdout, "Version: 1.0.0\n");
        break;
      default:
        fprintf(stdout, "Something wrong!\n");
        break;
    }
  }

  return 0;
}
