#include <stdio.h>
#include <unistd.h>

void examineInt(int* var) {
  printf("Variable Address: %p\n", var);
  printf("Variable Value: %i\n", *var);
  *var = 0; 
  //The value is changed outside the function, as a pointer to the vaiable was passed to the function, not a copy of the value of the variable
}

void printStringCharacters(char string[]) {
  int pointer = *string;
  int end = pointer + sizeof(string);
  while(pointer < end) {
    printf("%c\n", pointer);
    pointer += 1;
  }
}

void forkFunction() {
  char name[33];

  printf("Enter name: ");
  fgets(name, 33, stdin);

  int pid = fork();

  //if (pid == 0) {
    printf("Hello %s", name);
  //}
}

int main(int argc, char* argv[]) {
  if (argc > 1) {
    printf("%s", argv[1]);
  }
  
  int a = 7;
  examineInt(&a);

  char str[] = "abcdefgh";
  printStringCharacters(str);

  forkFunction();

  return 0;
}
