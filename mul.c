/*This function performs multiplication of two large numbers stored as doubly linked lists.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apc.h"
int multiplication(Dlist *tail1,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    //take 2 temp pointers
    Dlist *temp1=NULL;
    Dlist *temp2 = NULL;

    //take 2 lists update with NULL
    Dlist *res1_head = NULL;
    Dlist *res1_tail = NULL;
    Dlist *res2_head = NULL;
    Dlist *res2_tail = NULL;

    //take 2 variables to store product and carry
    int mul,carry;
    int count = 0;

    temp2=tail2;

    //traverse upto temp2 reaches NULL
    while (temp2!=NULL)
    {
        //reset temp1 with tail1
        temp1=tail1;
        carry=0;

        while(temp1 != NULL)
        {
            mul=(temp1->data * temp2->data) + carry;
            carry = mul/10;   //calculate carry
            mul = mul%10; //take 1 digit

            //store the result into node
            if (count == 0)
                insert_at_first(&res1_head,&res1_tail,mul);
            else
                insert_at_first(&res2_head,&res2_tail,mul);

            //update the temp1 
            temp1=temp1->prev;
        }

        //for last digit update
        if (carry)
        {
            if (count == 0)
                insert_at_first(&res1_head,&res1_tail,carry);
            else
                insert_at_first(&res2_head,&res2_tail,carry);
        }

        /* From second partial product onwards */
        if (count > 0)
        {
            /* shift res2 */
            for(int i=0;i<count;i++)
                insert_at_last(&res2_head, &res2_tail,0);

            // addition(res1, res2) 
            addition(res1_tail, res2_tail,headR,tailR);

            // free res1 and res2 
            res1_head = NULL;
            res1_tail = NULL;
            res2_head = NULL;
            res2_tail = NULL;

            // update res1 from result 
            res1_head = *headR;
            res1_tail = *tailR;

            //reset headR and tailR 
            *headR = NULL;
            *tailR = NULL;
        }

        count++;
        temp2 = temp2->prev;
    }

    *headR = res1_head;
    *tailR = res1_tail;

    return 1;
}
