 /* Compare list : This function compares two large numbers stored as linked lists.

Division : This function performs division of two large numbers using repeated subtraction.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apc.h"
int division(Dlist **head1,Dlist **tail1,Dlist *head2,Dlist *tail2,char *num1, char *num2,Dlist **reshead,Dlist **restail)
{
    //variable to store quotient count
    int count=0;
    //temporary list to store subtraction result
    Dlist *temphead=NULL;
    Dlist *temptail = NULL;

    //repeated subtraction
    while (compare_lists(*head1, head2)>= 0)
    {
        //subtract divisor from dividend 
        subtraction(*tail1,tail2,&temphead,&temptail);
        //remove leading zeros from subtraction result
        remove_leading_zeroes(&temphead, &temptail);
        //update dividend with new value
        *head1=temphead;
        *tail1=temptail;
        // reset temporary pointers for next iteration
        temphead=NULL;
        temptail=NULL;
        //increment the count
        count++;
    }

    // store quotient 
    if (count==0)
    {
        insert_at_last(reshead,restail,0);
    }
    else
    {
        //store quotient digits into result list
        while (count)
        {
            insert_at_first(reshead,restail,count % 10);
            count=count/10;
        }
    }
    //after division completed
    return 1;
}
