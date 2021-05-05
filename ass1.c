#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ass1-sort_list.h"

int randArray[10];

void insert(IORB *head, int priority, char *fill)
{
    //Create iterator to find last block, set to head of list
    IORB *currentElement = head;

    //Iterate through until the last block of list
    while ( currentElement->link != NULL)
    {
        //Iterator is equal to next block
        currentElement = currentElement->link;
    }

    //Allocates a new element of the linked list after the last element
    currentElement->link = malloc(sizeof(IORB));

    //Sets the priority of the element to the function argument
    currentElement->link->base_pri = priority;

    //Sets the pointer of the element to null
    currentElement->link->link = NULL;
    //return *currentElement;
}


IORB build_list(IORB head)
{
    //Initialise random number generator
    time_t t;
    srand((unsigned) time(&t));

    //Initialise all elements of array
    for ( int i = 0; i < 10; i++ )
        randArray[i] = i;

    //Swap elements to randomise them
    int temp, firstNum, secondNum;
    for ( int i = 0; i < 10; i++ )
    {
        firstNum = randArray[i];
        secondNum = rand() % 10;

        temp = randArray[firstNum];
        randArray[firstNum] = randArray[secondNum];
        randArray[secondNum] = temp;
    }

    //Set head of list to first element of array
    head.base_pri = randArray[0];

    //Create linked list with 10 blocks
    char fill[] = "string";
    //IORB iterator = head;
    for ( int i = 1; i < 10; i++ )
    {
        //iterator = insert(&iterator, randArray[i], fill);
        insert(&head, randArray[i], fill);
    }
    return head;
}

void print_list(IORB *head)
{
    //Create iterator to traverse through and print every element
    IORB *iterator = head;

    //Prints an element of the list and increments until there is no next element
    while ( iterator->link != NULL )
    {
        printf("%d, ", iterator->base_pri);
        iterator = iterator->link;
    }
    //Print the last element
    printf("%d, ", iterator->base_pri);
    //Start new line with a space in between
    printf("\n\n");
}

int main()
{
    //Initialise head of linked list
    IORB head;
    head.link = NULL;

    //Build the linked list
    head = build_list(head);
    //Print the unordered linked list
    printf("Unsorted list: ");
    print_list(&head);

    //Make the head of the sorted list
    IORB sorted_list;
    //Run the sort list function and store as the sorted list
    sorted_list = sort_list(&head);
    //Print the sorted list
    printf("Sorted list: ");
    print_list(&sorted_list);
    return 0;
}