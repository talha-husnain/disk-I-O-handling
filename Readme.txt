Name: [Your Name]
Student ID: [Your Student ID]

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
