#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>

int create_server(const char *path) {
  struct sockaddr_un name_sock;
  int fd;

  name_sock.sun_family = AF_UNIX;
  strncpy(name_sock.sun_path, path, sizeof(name_sock.sun_path));

  fd = socket(AF_UNIX, SOCK_DGRAM, 0);
  bind(fd, (struct sockaddr *)&name_sock, sizeof(struct sockaddr_un));
  return fd;
}

int main(int argc, const char *argv[]) {
  int fd = create_server(argv[1]);

  close(fd);
  return 0;
}
