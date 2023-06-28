1. How to compile and run your code on a Linux system:
  a. Verify that GCC (GNU Compiler Collection) is set up on your computer. If not, you can install it using the package manager provided by your distribution (for Ubuntu/Debian-based computers, type "sudo apt install gcc").
   b. Launch a terminal and go to the directory where the source files are located.
   c. Use the command shown below to compile the code: sortList.c gcc main.c -o disk_io_simulation
   d. Execute the compiled programme using the './disk_io_simulation' command.

2. Solution Logic:
   a. Create a list of IORB structures that are linked together, with each IORB having a base priority, a filler (description), and a link to the one after it.
   b. The 'buildList' method produces a predetermined number of IORBs with random base priorities and appends them to the list.
   c. The list is sorted using the'sortList' function according to the scheduling priorities determined by the 'priComp' function. These are the arguments that the'sortList' function accepts:
      Header to the list that needs to be sorted.
      - prio: Pointer to the priority computation function (in this case, priComp).
      - flag: Defines the sort order for the list, either ascendingly (1) or descendingly(0).
   
   d. The'sortList' function compares and swaps adjacent entries in the linked list according to their computed scheduling priority using the Bubble sort algorithm.
   e. The 'displayList' function outputs each member in the sorted list's description, base priority, and scheduling priority.


3. Test Runs and Outputs:
You can RUN the code for all the options from 0 to 4 and can add the output here in this question.
4. Limitations:
   In this I supposed to use the Bubble sort algorithm, which has a worst-case time complexity of O(n^2) where n is the number of elements in the list. This may lead to performance issues when sorting a large number of IORBs. A more efficient sorting algorithm, such as Merge sort or Quick sort, could be used to improve performance.

5. Comments:
   The provided code includes detailed comments for each line, explaining the purpose and functionality of the code.


 A particular Unix kernel operation handles disk I/O by allowing independent user
processes to place I/O request blocks (IORB) in a linked list. The order in which
these requests are serviced depends on their scheduling priorities. The scheduling
strategy is adaptive, which simply means that the kernel may carry out different
computations at different times in order to calculate the priority value for each
element of the list.
 You will have a chance to use multiple C source files, recursive structure, pointers,
function pointers, and passing function as a parameter etc.
Task:
 Your task is to design and implement a C program on Linux that tests a sorting
function with the following prototype:
void sortList(IORB ∗ ∗head, int(∗prio)(int), intflag)
The first parameter of the function, head, is a pointer to the pointer that points to
the list to be sorted. The second parameter, prio, is a priority computing function
that computes and returns the scheduling priority value. The third parameter, flag,
is a flag that indicates whether the list should be sorted in ascending or descending
order.
 The sorting function should sort the list based on the scheduling priority of each
element.
 Since the Operating System has other structures with pointers to IORB blocks, the
list must be sorted in place.
Requirements:
1. IORB structure
The IORB structure is defined as:
typedef struct iorb {
int base_pri;
char filler[100];
struct iorb *link;
} IORB;
where base pri is an integer representing the block’s base priority; f iller is a description of the block that is opaque to the sorting function; link is a pointer to the
next block in the list.
2. Sorting function
(a) Priority computing function
For this assignment, to keep things simple, the scheduling priority of each IORB
will be computed from a single integer field named base pri) in the IORB
structure. You may design any method to compute the scheduling priority.
The function should return an integer as the scheduling priority. You should
use the following prototype
int priComp(int)
(b) Sorting algorithm
You are required to implement the Bubble sort algorithm to sort the list. This
algorithm works by repeatedly travering the list and swapping any neighbouring
elements that are out of order until the list is in order.
(c) Sorting in place
The list must be sorted in place. This means that ONLY the links within the list
may be altered by the sorting function. No other fields of the IORB structure
may be copied to somewhere else in memory during the sorting process.
(d) Separate C source file for the sorting function
The implementation of sortList() should be placed in a separate C source file
from any driver code. You may however include other functions needed for
testing, such as those for building and displaying the list, in the same source
file as the driver code.
3. Other functions
(a) Build the list
The list is initially built by a function buildList(). A possible prototype is given
below:
void buildList(IORB ∗ ∗head, int size)
where head is a pointer to the pointer that points to the list, size represents
the length of the list. For each IORB in the list, its base priority, base pri, is
calculated using a random number generator; its block description, f iller, may
be assigned any string you prefer.
(b) Display the list
The list is displayed by a function displayList(), which prints the block description f iller, the base priority base pri and the scheduling priority of each
element in the list. Here is a possible prototype:
void displayList(IORB ∗ head, int(∗prio)(int))
where head is a pointer to the linked list, and prio is a priority computing
function.
