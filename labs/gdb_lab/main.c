#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
void showPointerProperties(void *somePointer) {
  printf("\tSomePointer's Address: %p\n", somePointer);
  printf("\tSomePointer's Int Value: %d\n", *(int *)somePointer);
}

int main (int argc, char * argv[]) {
  // Below is an example of passing arguments
  printf("Number of arguments passed %d\n", argc);
  if (argc > 1) {
    printf("You actually passed arguments:\n");
    for(int i = 1; i < argc; i++) {
      printf("\tArg %d:%s\n", i, argv[i]);
    }
  }

  int x = 0, y = 1;
  int *intPointer;
  // What happens if you call this, why?
  //showPointerProperties(intPointer);
  //return 1;
  intPointer = &x;
  showPointerProperties(intPointer);
  // Can we do the same for x? Is it different than intPointer, why or why not?
  showPointerProperties(&x);
  showPointerProperties(&y);
  // Let's get wild!
  while(1) {
    showPointerProperties(++intPointer);
    sleep(1);
  }
  // Eventually what happens?
}
