/*This file implements basic doubly linked list operations for the APC project.
insert at last.
insert at first.
print list.
remove leading zeros.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apc.h"

int insert_at_last(Dlist **head,Dlist **tail, int data)
{
    //create a new node
    Dlist *new = malloc(sizeof(Dlist));
    //check if node is creted or not
    if (new == NULL)  
        return 0;
    //update the new node
    new->data = data;
    new->next = NULL;
    new->prev = *tail;
    //if tail != NULL
    if (*tail != NULL)
    {
        (*tail)->next = new;
    }
    else
    {   
        *head = new;
    }
    *tail = new;
    return 1;
}

int insert_at_first(Dlist **head,Dlist **tail, int data)
{
     //create a new node
    Dlist *new = malloc(sizeof(Dlist));
    //check if node is creted or not
    if (new == NULL)
    { 
        return 0;
    }
    //update the new node
    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head != NULL)
        (*head)->prev = new;
    else
        *tail = new;
    //update the head value
    *head = new;
    return 1;
}

void print_list(Dlist *head)
{
    //traverse upto head reches NULL
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

void remove_leading_zeroes(Dlist **head,Dlist **tail)
{
    //if list is empty
    if (*head == NULL)
    {
        return;
    }
    //traverse upto the data will reaches number
    while ((*head)->data == 0 && (*head)->next != NULL)
    {
        Dlist *temp = *head;
        *head = temp->next;
        (*head)->prev = NULL;
        free(temp);
    }
}
