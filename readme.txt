Jeremie Brogniez - 19284428------------------------------------------------------------------


How to compile and run the code--------------------------------------------------------------
- Upload ass1.c, ass1-sort_list.h and linked_list.h to linux to use on the terminal
- Compile the code using this command: "cc ass1.c -o ass1 -std=c99"
- Run the code using this command: "./ass1"


Description of the Solution Logic------------------------------------------------------------
- Define the head of the linked list
- Set the pointer to NULL
- Create an array with 10 integers for randomisation
- for ( i from 0 - 10 )
-     array[i] = i
- 
- Define 3 integers for swapping array elements randomly
- for ( i from 0 - 10 )
-     swap elements of array randomly
-
- set head of list to first element of array
- for ( i from 0 - 10 )
-     insert all elements of the array as new blocks in the linked list
- 
- Create iterator to traverse through the linked list
- while ( pointer of iterator != NULL )
-     print element of list
-     increment iterator to the next element of the list
- print last element of list
- print 2 new lines
- 
- Define the head of the sorted list
- 
- Run the sort_list function:
- Define an integer to record the number of swaps per pass, numberOfSwaps
- Define 3 iterators to traverse the linked list, one behind the other
- Define a temporary pointer, pointing to NULL
- do
-     Set numberOfSwaps to 0
-     Checks if first iterator is larger than second, if so, swaps them
-     Sets the head of the list to the first iterator after swapping first and second iterator
-     Checks if second iterator is larger than third, if so, swaps them
-     Increment all iterators to the next element of the linked list
-     while ( third iterator doesn't point to NULL )
-         Checks if second iterator is larger than third, if so, swaps them
-         Increments all iterators unless they point to NULL
-     Checks if second iterator is larger than third, if so, swaps them
-     Set first iterator back to the head of the list
-     Set second iterator to the element that the first iterator points to
-     Set third iterator to the element that the second iterator points to
- while ( numberOfSwaps != 0 )
- 
- 
- Linked list structure:
- linked list node contains:
-     An integer, block priority
-     A pointer to the next node
-     A string, for the description


Test Plan-------------------------------------------------------------------------------------
- Use the random number generator in the code to create a list of ten integers which represent the priorities of the blocks
- Print out the unsorted list
- The sort_list() function will sort the linked list in ascending order of the integers
- Then it will print out the sorted list


Test Run--------------------------------------------------------------------------------------
- Unsorted List: 4, 5, 7, 1, 3, 6, 2, 0, 8, 9,
- Sorted List: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,