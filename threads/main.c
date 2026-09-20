#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int balance = 20;

void* updateBalance(void* purchase) {
  int* purchaseAmount = (int*)purchase;
  int actualAmount = *purchaseAmount;
  balance -= actualAmount;
  return purchase;
}

int main(int argc, char* argv[]) {
  pthread_t thread1;
  int purchase = 10;

  pthread_create(&thread1, NULL, updateBalance, (void*)&purchase);
  pthread_join(thread1, NULL);

  printf("Balance is %d\n", balance);
}
