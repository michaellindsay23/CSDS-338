#include <stdio.h>
#include <stdlib.h>

struct ListItem {
  int data;
  struct ListItem *next;
};

int main() {
  struct ListItem* current_tail;

  int numItems = 0;
  while (numItems < 3) {
    char input[3];

    printf("Enter a to add, d to delete, or p to print: ");
    fgets(input, 3, stdin);
    
    if (input[0] == 'a') {
      struct ListItem* item = malloc(sizeof(struct ListItem)); 
      printf("What number do you want to add? ");

      char new_data[32];
      fgets(new_data, 32, stdin);
      item->data = atoi(new_data);

      if (current_tail == NULL) {
        item->next = NULL;
      } else {
        current_tail->next = item;
      }

      current_tail = item;

      numItems++;
    }
    if (input[0] == 'p') {
      
    }
  }

  printf("%i\n", current_tail->data);

  return 0;
}
