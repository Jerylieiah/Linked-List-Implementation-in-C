#ifndef ASS2_ASS2_SORT_LIST_H
#define ASS2_ASS2_SORT_LIST_H
#include <stdio.h>
#include "linked_list.h"


IORB sort_list(IORB *head)
{
    int numberOfSwaps; //Records number of swaps that happen to know when the list has been sorted

    //Iterators to go through the list
    IORB *iterator1 = head;
    IORB *iterator2 = head->link;
    IORB *iterator3 = head->link->link;

    //Pointer to temporarily store an element of the list
    IORB *temp = NULL;

    do {
        numberOfSwaps = 0;
        //Checks if left element is bigger than right element and if so, swaps them
        if ( iterator1->base_pri > iterator2->base_pri )
        {
            numberOfSwaps++; //Increments number of swaps
            iterator1->link = iterator2->link; //The pointer of the first element now points to the location of the third element
            iterator2->link = iterator1; //Second element now points to the first element

            temp = iterator2; //Saves the second element temporarily
            iterator2 = iterator1; //Sets the second element to become the first element
            iterator1 = temp; //Sets the first element to become the second element
            head = iterator1; //Sets the new head to the new first element of the list
        }

        //Checks if left element is bigger than right element and if so, swaps them
        if ( iterator2->base_pri > iterator3->base_pri )
        {
            numberOfSwaps++; //Increments number of swaps
            iterator1->link = iterator2->link; //The pointer of the first element now points to the location of the third element
            iterator2->link = iterator3->link; //The pointer of the second element now points to the location of the fourth element
            iterator3->link = iterator2; //The pointer of the third element now points to the location of the second element

            temp = iterator3; //Saves the third element temporarily
            iterator3 = iterator2; //Sets the third element to become the second element
            iterator2 = temp; //Sets the second element to become the third element
        }
        iterator1 = iterator1->link; //Increments the first iterator
        iterator2 = iterator2->link; //Increments the second iterator
        iterator3 = iterator3->link; //Increments the third iterator


        while (iterator3->link != NULL) //Exits when the iterators have reached the end of the list
        {
            //Checks if left element is bigger than right element and if so, swaps them
            if ( iterator2->base_pri > iterator3->base_pri )
            {
                numberOfSwaps++; //Increments number of swaps
                iterator1->link = iterator2->link; //The pointer of the first element now points to the location of the third element
                iterator2->link = iterator3->link; //The pointer of the second element now points to the location of the fourth element
                iterator3->link = iterator2; //The pointer of the third element now points to the location of the second element

                temp = iterator3; //Saves the third element temporarily
                iterator3 = iterator2; //Sets the third element to become the second element
                iterator2 = temp; //Sets the second element to become the third element
            }
            iterator1 = iterator1->link; //Increments the first iterator
            if (iterator2->link != NULL) //Checks whether the second iterator points to NULL
                iterator2 = iterator2->link; //Increments the second iterator
            if (iterator3->link != NULL) //Checks whether the third iterator points to NULL
                iterator3 = iterator3->link; //Increments the third iterator
        }

        //Checks if left element is bigger than right element and if so, swaps them
        if ( iterator2->base_pri > iterator3->base_pri )
        {
            numberOfSwaps++; //Increments number of swaps
            iterator1->link = iterator2->link; //The pointer of the first element now points to the location of the third element
            iterator2->link = iterator3->link; //The pointer of the second element now points to the location of the fourth element
            iterator3->link = iterator2; //The pointer of the third element now points to the location of the second element
        }

        iterator1 = head; //Sets the first iterator to be the head of the linked list, starting the iteration again
        iterator2 = head->link; //Sets the second iterator to be the second element of the list
        iterator3 = head->link->link; //Sets the third iterator to be the third element of the list
    } while ( numberOfSwaps != 0 ); //Exits when the list has been fully sorted
    return *head; //Returns the fully sorted list
}

#endif //ASS2_ASS2_SORT_LIST_H
