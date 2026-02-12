/*This function performs addition of two large numbers stored as doubly linked lists.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apc.h"
int addition(Dlist *tail1,Dlist *tail2,Dlist **res_head,Dlist **res_tail)
{
    int sum,carry=0;
    /*loop upto both lists will reach NULL*/
    while (tail1!= NULL || tail2!= NULL)
    {
        sum = carry;
        //for first node
        if (tail1 != NULL)
        {
            sum=sum+tail1->data;
            tail1=tail1->prev;
        }
        //for second node
        if (tail2 != NULL)
        {
            sum = sum+tail2->data;
            tail2 = tail2->prev;
        }
        //update the carry
        carry = sum / 10;
        //take sum last digit
        sum = sum%10;
        insert_at_first(res_head,res_tail,sum);
    }
    //for last extra digit
    if (carry)
    {
        //call insert at first function
        insert_at_first(res_head,res_tail,carry);
    }
    return 1;
}
