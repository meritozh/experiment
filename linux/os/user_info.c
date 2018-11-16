#include <unistd.h>
#include <stdio.h>
#include <pwd.h>

int main() {
  uid_t uid = getuid();
  fprintf(stdout, "Current uid is: %d\n", uid);

  struct passwd *pw = getpwnam("gaoge");
  if (pw != NULL) {
    fprintf(stdout, "%s\'s password is: %s\n", pw->pw_name, pw->pw_passwd);
  }

  return 0;
}
