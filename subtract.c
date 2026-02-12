/*This function performs subtraction of two large numbers stored as doubly linked lists.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apc.h"
int subtraction(Dlist *tail1,Dlist *tail2,Dlist **res_head,Dlist **res_tail)
{
    //variable to store digit difference
    int diff,borrow = 0;
    //loop through all digits of first number from LSB to MSB
    while (tail1 != NULL)
    {
        //subtract previous borrow from current digit
        diff=tail1->data - borrow;
        //if second number still has digits, subtract it
        if (tail2)
        {
            diff=diff - tail2->data;
            tail2=tail2->prev;
        }
        //if subtraction becomes negative, handle borrow
        if (diff < 0)
        {
            diff = diff + 10;
            borrow = 1;
        }
        else
            borrow = 0;
        //call insert at first function
        insert_at_first(res_head,res_tail,diff);
        //update the tail1
        tail1=tail1->prev;
    }
    return 1;
}