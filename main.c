#include "iorb.h"
#include "sortList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Priority computing function to calculate the scheduling priority
int priComp(int base_pri) { return (base_pri * 3) % 100; }

// Function to build a list of IORB nodes with given size
void buildList(IORB **head, int size) {
  srand(time(NULL)); // Seed the random number generator
  for (int i = 0; i < size; i++) {
    IORB *new_node =
        (IORB *)malloc(sizeof(IORB));  // Allocate memory for a new IORB node
    new_node->base_pri = rand() % 100; // Assign a random base priority
    snprintf(new_node->filler, sizeof(new_node->filler),
             "this is i/o request %d",
             i);            // Assign a description to the filler field
    new_node->link = *head; // Point the new node's link to the current head
    *head = new_node;       // Update the head to the new node
  }
}

// Function to display the IORB list with their scheduling priorities
void displayList(IORB *head, int (*prio)(int)) {
  while (head != NULL) {
    printf("Description: %s, Base Priority: %d Priority: %d\n", head->filler,
           head->base_pri, prio(head->base_pri));
    head = head->link; // Move to the next node in the list
  }
}

int main() {
  int choice, size;
  IORB *head = NULL;

  do {
    // Display menu
    printf("Please enter your choice:\n");
    printf("0) Exit\n");
    printf("1) Build List\n");
    printf("2) Sort List (ascending)\n");
    printf("3) Sort List (descending)\n");
    printf("4) Display List\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    // Perform action based on user input
    switch (choice) {
    case 0:
      printf("Terminating...\n");
      break;
    case 1:
      printf("Enter the size of the list: ");
      scanf("%d", &size);
      buildList(&head, size);
      break;
    case 2:
      sortList(&head, priComp, 1);
      break;
    case 3:
      sortList(&head, priComp, 0);
      break;
    case 4:
      displayList(head, priComp);
      break;
    default:
      printf("Invalid choice. Try again.\n");
      break;
    }
  } while (choice != 0);

  return 0;
}
