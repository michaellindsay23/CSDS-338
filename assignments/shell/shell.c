#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

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
    printf("fih ~ ");
    fgets(buffer, 32, stdin);
    clean(buffer);

    char string_tokens = strtok

    int pid = fork();

    if (pid == 0) {
      execve(buffer, &arguments, NULL);
      printf("child");
    }
    else {
      printf("parent");
      waitpid(pid, NULL, 0);
    }
  }

  return 0;
}
