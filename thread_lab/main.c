#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void add_integer_pointers(int* i, int* j) {
  *i = *i + *j;
}

void* add_integers(void* integers) {
  struct ints *integerss = integers;
  return  (integerss -> i) + (integerss -> j);
}

struct ints {
  int i;
  int j;
};

int main() {
  char i_in[4];
  printf("first integer: ");
  fgets(i_in, 4, stdin);

  char j_in[4];
  printf("second integer: ");
  fgets(j_in, 4, stdin);

  int i = atoi(i_in);
  int j = atoi(j_in);

  pthread_t thread1;
  pthread_t thread2;
  
  struct ints not_pointers;
  not_pointers.i = i;
  not_pointers.j = j;
  
  pthread_create(&thread1, NULL, add_integers, (void*)&not_pointers);
 // make_thread(thread2, add_integer_pointers, struct ints(&i, &j));

  printf("%i\n", add_integers((void*)&not_pointers));
  add_integer_pointers(&i, &j);

  printf("%i", i);
}
