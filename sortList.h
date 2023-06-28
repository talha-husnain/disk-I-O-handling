#ifndef SORT_LIST_H
#define SORT_LIST_H

#include "iorb.h"

// Function prototype for the sortList function
// head: Pointer to the pointer that points to the list to be sorted
// prio: Pointer to the priority computing function
// flag: Indicates whether the list should be sorted in ascending (1) or
// descending (0) order
void sortList(IORB **head, int (*prio)(int), int flag);

#endif
