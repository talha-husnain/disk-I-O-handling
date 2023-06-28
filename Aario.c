// Include the standard input-output library for I/O operations like printf and scanf
#include <stdio.h>
// Include the standard library for memory allocation and random number generation
#include <stdlib.h>
// Include the time library for seeding the random number generator
#include <time.h>

// Define a struct for I/O request blocks (IORB)
typedef struct iorb {
    int base_pri;          // The base priority of the I/O request
    char filler[100];      // A string description of the I/O request
    struct iorb *link;     // A pointer to the next I/O request block in the list
} IORB;

// A function to compute the scheduling priority from the base priority
int priComp(int base_pri) {
    // Return the scheduling priority computed as (base_pri * 3) % 100
    return (base_pri * 3) % 100;
}

// A function to build a linked list of I/O request blocks of a given size
void buildList(IORB **head, int size) {
    // Seed the random number generator with the current time
    srand(time(NULL));
    // Loop through the number of I/O request blocks specified by the size
    for (int i = 0; i < size; i++) {
        // Allocate memory for a new I/O request block
        IORB *new_node = (IORB *) malloc(sizeof(IORB));
        // Assign a random base priority between 0 and 99
        new_node->base_pri = rand() % 100;
        // Fill the description with the I/O request number
        snprintf(new_node->filler, sizeof(new_node->filler), "this is i/o request %d", i);
        // Link the new I/O request block to the current head of the list
        new_node->link = *head;
        // Update the head of the list to the new I/O request block
        *head = new_node;
    }
}

// A function to display the linked list of I/O request blocks
void displayList(IORB *head, int (*prio)(int)) {
    // Loop through the I/O request blocks in the list
    while (head != NULL) {
        // Print the description, base priority, and scheduling priority of each I/O request block
        printf("Description: %s, Base Priority: %d Priority: %d\n", head->filler, head->base_pri, prio(head->base_pri));
        // Move to the next I/O request block in the list
        head = head->link;
    }
}

// A function to sort the linked list of I/O request blocks based on scheduling priority and flag (ascending or descending)
void sortList(IORB **head, int (*prio)(int), int flag) {
    // Return if the list is empty or contains only one I/O request block
    if (*head == NULL || (*head)->link == NULL) {
        return;
    }

    // Initialize variables for sorting
    int swapped;
    IORB *ptr1;
    IORB *lptr = NULL;

    // Loop until no swaps are performed in the last pass
    do {
        // Reset the swapped flag
        swapped = 0;
        // Initialize ptr1 to the head of the list
        ptr1 = *head;

        // Loop through the I/O request blocks until the last unsorted block
        while (ptr1->link != lptr) {
                        // Determine the sorting order based on the flag (ascending or descending)
            int order = (flag == 1) ? (prio(ptr1->base_pri) > prio(ptr1->link->base_pri)) : (prio(ptr1->base_pri) < prio(ptr1->link->base_pri));

            // If the current pair of I/O request blocks need to be swapped, swap their base priorities
            if (order) {
                int temp_base_pri = ptr1->base_pri;
                ptr1->base_pri = ptr1->link->base_pri;
                ptr1->link->base_pri = temp_base_pri;

                // Set the swapped flag to true
                swapped = 1;
            }
            // Move to the next I/O request block in the list
            ptr1 = ptr1->link;
        }
        // Update the last unsorted block in the list
        lptr = ptr1;
    } while (swapped); // Repeat the process until no swaps are needed
}

// The main function of the program
int main() {
    int choice, size; // Declare variables for user input and list size
    IORB *head = NULL; // Initialize the head of the I/O request block list to NULL

    // Loop until the user chooses to exit
    do {
        // Display the menu options
        printf("Please enter your choice:\n");
        printf("0) Exit\n");
        printf("1) Build List\n");
        printf("2) Sort List (ascending)\n");
        printf("3) Sort List (descending)\n");
        printf("4) Display List\n");
        printf("Your choice: ");
        // Read the user's choice
        scanf("%d", &choice);

        // Perform the corresponding action based on the user's choice
        switch (choice) {
            case 0: // Exit
                printf("Terminating...\n");
                break;
            case 1: // Build List
                printf("Enter the size of the list: ");
                scanf("%d", &size);
                buildList(&head, size);
                break;
            case 2: // Sort List (ascending)
                sortList(&head, priComp, 1);
                break;
            case 3: // Sort List (descending)
                sortList(&head, priComp, 0);
                break;
            case 4: // Display List
                displayList(head, priComp);
                break;
            default: // Invalid choice
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0); // Continue until the user chooses to exit

    // Return success status
    return 0;
}

