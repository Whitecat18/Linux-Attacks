/*
WRIIEN BASED FORK BOMB LOGIC IMPLEMENTED IN C
CODED BY SMUKX -> https://github.com/Whitecat18/
*/
#include <stdio.h>
#include <stdlib.h>

void infinite_loop() {
  while (1) {
  }
}

int main() {
 
  pid_t child_pid = fork();

  if (child_pid == 0) {
    infinite_loop();
  }
  waitpid(child_pid, NULL, 0);

  return 0;
}
