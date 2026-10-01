#include <stdio.h>
#include "transact.h"
#include <pthread.h>

void * process(void * arg) {
}

int main(int argc, char * argv[]) {
  for(int i = 0; i < 10; i++) {
    //int transaction = getTransaction(i);
    //int transaction = getTransactionFromFile(i);
    printf("%d : %d\n", i, transaction);
  }
}
