#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>


int main(int argc, char* argv[]) {
  int source = open(argv[1], O_RDONLY); // Only open it for reading
  int dest = open(argv[2], O_WRONLY, 0644); // Open for writing, create if it doesn't exit, truncate it, give it permisisons of 644

  char buffer[16384];
  int bytesRead = read(source, buffer, 16384);

  while ((bytesRead = read(source, buffer, 16384)) > 0) {
    write(dest, buffer, bytesRead);
  }

  close(source);
  close(dest);

  return 0;
}
