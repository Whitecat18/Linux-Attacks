#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  
  int n = 10; // n denotes child process
  pid_t pid;

  for (int i = 0; i < n; i++) {
    pid = fork();
    if (pid < 0) {
      perror("fork");
      exit(1);
    } else if (pid == 0) {
      printf("Child process %d started\n", (int)getpid());
      exit(0);
    }
  }
    for (int i = 0; i < n; i++) {
    pid = wait(&status);
    printf("Child process %d finished with status %d\n", (int)pid, status);
  }

  return 0;
}

// Coded By Smukx . For More info visit https://github.com/Linux-Attacks
