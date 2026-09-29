#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  if (atoi(argv[1]) == 0) {
    printf("You gave me zero!");
    return 0;
  }
}
