/*This file contains the structure definition and function declarations for the APC project.
It uses a doubly linked list to store large numbers digit by digit.
The file declares list operations and arithmetic functions such as addition, subtraction, multiplication, and division.*/

#ifndef APC_H
#define APC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Doubly Linked List Node //
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

//List operations 
int insert_at_last(Dlist **,Dlist **,int);

int insert_at_first(Dlist **,Dlist **,int);

void print_list(Dlist *);

void remove_leading_zeroes(Dlist**,Dlist**);

//Arithmatic operations 
int addition(Dlist *, Dlist*,Dlist **, Dlist **);

int compare_lists(Dlist *,Dlist *);

int subtraction(Dlist *,Dlist*,Dlist **,Dlist **);

int multiplication(Dlist *,Dlist *,Dlist **,Dlist **);

int division(Dlist**,Dlist **,Dlist *,Dlist  *,char *, char *,Dlist **,Dlist **);

#endif
