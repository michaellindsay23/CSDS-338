#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wait.h>

void clean(char* buffer) {
  while (*buffer != '\n') {
    buffer++;
  }
  *buffer = '\0';
}

int main() {
  char buffer[32];
  char* arguments = {NULL};
  while (1) {
    printf("Shell> ");
    fgets(buffer, 32, stdin);
    clean(buffer);

    int pid = fork();

    if (pid == 0) {
      execve(buffer, &arguments, NULL);
    } else {
      wait(NULL);
    }
  }

  return 0;
}
