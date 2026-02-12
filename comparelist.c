#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "apc.h"
int compare_lists(Dlist *head1,Dlist *head2)
{
    //take length variables for 2 lists
    int length1 = 0;
    int length2 = 0;
    Dlist *tail1 = head1;
    Dlist *tail2 = head2;

    //find length of first node
    while (tail1 != NULL) 
    { 
        length1++; 
        tail1 = tail1->next; 
    }
    //find length of second node
    while (tail2 != NULL) 
    { 
        length2++; 
        tail2 = tail2->next; 
    }
    //check which number is greater
    if (length1 > length2) 
        return 1;
    if (length1 < length2) 
        return -1;

    //lengths equal → compare digit by digit 
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data > head2->data) 
            return 1;
        if (head1->data < head2->data) 
            return -1;

        head1 = head1->next;
        head2 = head2->next;
    }
    //if numbers are exactly equal
    return 0;
}
