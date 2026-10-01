#include <stdio.h>
#include <stdlib.h>
#include "transact.h"
#include <pthread.h>

void * process(void * arg) {

}

int main(int argc, char * argv[]) {
  int threadCount = atoi(argv[1]);
  int useFile = atoi(argv[2]);
  int transaction;

  for(int i = 0; i < 100000000/threadCount; i++) {
    if (useFile) {
      transaction = getTransactionFromFile(i);
    }
    else {
      transaction = getTransaction(i);
    }
    printf("%d : %d\n", i, transaction);
  }
}
