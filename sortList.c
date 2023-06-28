#include "sortList.h"
#include "iorb.h"
#include <stdlib.h>

// Function to sort the IORB list based on scheduling priorities
void sortList(IORB **head, int (*prio)(int), int flag) {

  // Return if the list is empty or has only one element
  if (*head == NULL || (*head)->link == NULL) {
    return;
  }

  int swapped;
  IORB *ptr1;
  IORB *lptr = NULL;

  // Bubble sort algorithm
  do {
    swapped = 0;
    ptr1 = *head;

    // Traverse the list and compare adjacent nodes
    while (ptr1->link != lptr) {
      // Determine the sorting order based on
      // the flag (1 for ascending, 0 for descending)
      int order = (flag == 1)
                      ? (prio(ptr1->base_pri) > prio(ptr1->link->base_pri))
                      : (prio(ptr1->base_pri) < prio(ptr1->link->base_pri));

      // Swap the base priorities if the nodes are out of order
      if (order) {
        int temp_base_pri = ptr1->base_pri;
        ptr1->base_pri = ptr1->link->base_pri;
        ptr1->link->base_pri = temp_base_pri;

        swapped = 1; // Indicate that a swap has occurred
      }
      ptr1 = ptr1->link; // Move to the next node
    }
    lptr = ptr1;     // Update the last pointer for the next iteration
  } while (swapped); // Repeat until no more swaps occur
}
