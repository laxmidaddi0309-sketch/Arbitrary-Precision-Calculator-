/*
Name            : Laxmi B Daddi
Project Name    : APC (Arbitrary Precision Calculator)
Submission Date : 03/02/2026
Description     : This project performs arithmetic operations on very large integers using linked lists.It overcomes the limitation of built-in data types by storing each digit in a node.Command-line arguments are used to read operands and operators.
Details         : The project supports addition, subtraction, multiplication, and division operations.It correctly handles positive and negative numbers using sign detection logic.Leading zeros are removed and results are displayed in proper format.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "apc.h"

int main(int argc,char *argv[])
{
    //check is the arguements are correct or not
    if (argc != 4)
    {
        printf("Invalid / Insufficient arguments\n");
        return 0;
    }
    //take 2 node head and tail and update
    Dlist *head1 = NULL; 
    Dlist *tail1 = NULL;
    Dlist *head2 = NULL; 
    Dlist *tail2 = NULL;
    Dlist *reshead = NULL;
    Dlist *restail = NULL;

    int i=0;
    int sign1=0,sign2=0,res_sign=0;
    char buf[2];
    buf[1]='\0';
    // SIGN DETECTION //
    if (argv[1][0]=='-')
    {
        sign1=1;
        argv[1]++;  //skip the sign
    }

    if (argv[3][0]=='-')
    {
        sign2=1;
        argv[3]++;  //skip the sign
    }

    // read first number
    i = 0;
    while (argv[1][i])
    {
        buf[0]=argv[1][i];
        insert_at_last(&head1,&tail1,atoi(buf));
        i++;
    }

    // read second number
    i=0;
    while(argv[3][i])
    {
        buf[0]=argv[3][i];
        insert_at_last(&head2,&tail2,atoi(buf));
        i++;
    }

    switch (argv[2][0])
    {
        //if operator is addition
        case '+':
            if (sign1==sign2)
            {
                addition(tail1,tail2,&reshead,&restail);
                res_sign=sign1;
            }
            else
            {
                if (compare_lists(head1,head2)>=0)
                {
                    subtraction(tail1,tail2,&reshead,&restail);
                    res_sign=sign1;
                }
                else
                {
                    subtraction(tail2,tail1,&reshead,&restail);
                    res_sign=sign2;
                }
            }
            break;

        //if operator is subtraction
        case '-':
            sign2 = !sign2;   
            if (sign1 == sign2)
            {
                addition(tail1,tail2,&reshead,&restail);
                res_sign=sign1;
            }
            else
            {
                if (compare_lists(head1,head2)>=0)
                {
                    subtraction(tail1,tail2,&reshead,&restail);
                    res_sign=sign1;
                }
                else
                {
                    subtraction(tail2,tail1,&reshead,&restail);
                    res_sign=!sign1;
                }
            }
            break;

        // if operator is multiplication
        case 'x':
            multiplication(tail1,tail2,&reshead,&restail);
            res_sign=sign1^sign2;
            break;

        //if operator is division
        case '/':
            if (strcmp(argv[3],"0")==0)
            {
                printf("Division by zero error\n");
                return 0;
            }
            division(&head1, &tail1,head2,tail2,argv[1],argv[3],&reshead,&restail);
            res_sign=sign1^sign2;
            break;

        default:
            printf("Invalid operator\n");
            return 0;
    }
    //for removing extra starting zeros
    remove_leading_zeroes(&reshead,&restail);
    //for printing sign
    if (res_sign && !(reshead->data==0 && reshead->next==NULL))
        printf("-");
    //for printing the result
    print_list(reshead);

    return 0;
}
