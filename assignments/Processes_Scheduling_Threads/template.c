#include <stdio.h>
#include <stdlib.h>
#include "transact.h"
#include <pthread.h>

struct execution_information {
  int starting_index;
  int ending_index;
  int useFile;
};

void * process(void * arg) {
  struct execution_information* args = (struct execution_information*)arg;
  int transaction;

  for(int i = args->starting_index; i < args->ending_index; i++) {
    if (args->useFile) {
      transaction = getTransactionFromFile(i);
    }
    else {
      transaction = getTransaction(i);
    }
    //printf("%d : %d\n", i, transaction);
  }
}

int main(int argc, char * argv[]) {
  int threadCount = atoi(argv[1]);
  int useFile = atoi(argv[2]);
  pthread_t thread[threadCount];

  for (int i = 0; i < threadCount; i++) {
    struct execution_information args = { 
      .starting_index = (100000000/threadCount)*i, 
      .ending_index = (100000000/threadCount)*(i+1), 
      .useFile = useFile 
    };

    pthread_create(&(thread[i]), NULL, process, (void*)&args);
  }
  
  for (int i = 0; i < threadCount; i++) {
    pthread_join(thread[i], NULL);
  }
}
