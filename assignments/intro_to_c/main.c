#include <stdio.h>
#include <stdlib.h>

int getByteStorage(char* greeting) {
  int size = 0;
  while (greeting[size] != '\0') {
    size++;
  }
  printf("\nGreeting requires %i bytes", size + 1);
}

void happyBirthday(char* name, int* age) {
  char greeting[64];
  sprintf(greeting, "Happy Birthday %s, you are now %i!", name, *age + 1);
  printf("%s\n", greeting);

  getByteStorage(greeting);
}

int main() {
  char name[32];
  char age_string[4];
  
  printf("Enter name: ");
  fgets(name, 32, stdin);

  printf("Enter age: ");
  fgets(age_string, 4, stdin);

  int age = atoi(age_string);

  int newline_location = 0;
  while (name[newline_location] != '\n') {
    newline_location++;
  }
  name[newline_location] = '\0';

  happyBirthday(name, &age);

  return 0;
}
