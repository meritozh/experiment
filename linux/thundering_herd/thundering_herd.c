#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int fd = socket(PF_INET, SOCK_STREAM, 0);
  int connfd;
  char sendbuff[1024];

  struct sockaddr_in serveraddr;
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons(1234);

  bind(fd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
  listen(fd, 1024);

  for (int i = 0; i < 10; ++i) {
    int pid = fork();
    if (pid == 0) {
      while (true) {
        connfd = accept(fd, (struct sockaddr *)NULL, NULL);
        snprintf(sendbuff, sizeof(sendbuff), "accept PID is %d\n", getpid());

        send(connfd, sendbuff, strlen(sendbuff) + 1, 0);
        printf("process %d accept success!\n", getpid());
        close(connfd);
      }
    }
  }

  int status;
  wait(&status);
  return 0;
}
