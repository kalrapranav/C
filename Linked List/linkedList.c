/*
**   Assignment:  Laboratory Assignment 12 "Linked List"
**
**     Filename:  linkedList.c
**
**       Author:  Pranav Kalra
**        REDID:  821916362
**
**  Lab Section:  CompE160 laboratory section number (1, 2, or 3)
**       Lab TA:  Name of your designated Teaching Assistant (Saipriyati Singh or Atieh Kashani)
**     Due Date:  Date and time this assignment is due for submission to your teaching assistant
**
**  Description:  The program creates a linked list with 100 nodes, sets the value of each node
**                equal to its index and prints the list's index number and value
**
**        Input:  No from the user .
**
**       Output:  List's index and corresponding value
**
**    Algorithm:  Iterative structure to create and assign values to the list
**
**      Caveats:  Describe any known program bugs or limitations.
**      Version:  1.0.0
**
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next;
} node;


int main (void) {

    node *head = NULL;

    for (int i = 0; i < 100; i++) {
        node *newnode = malloc (sizeof *newnode);
        if (!newnode) {
            fprintf (stderr, "error: memory exhausted node '%d'.\n", i);
            break;
        }

        newnode->data = i;
        newnode->next = NULL;

        if (!head)
            head = newnode;
        else {
            node *iter = head;
            for (; iter->next; iter = iter->next) {}
            iter->next = newnode;
        }
    }
//Printing List
    int j = 0;
    for (node *iter = head; iter; iter = iter->next)
        printf ("node[%3d] : %3d      \n",
               j++, iter->data);


    /* free list memory */
    node *victim = NULL;    /* node to delete */
    for (node *iter = head; iter; iter = iter->next) {
        if (victim)     /* cannot delete until after loop increment */
            free (victim);
        victim = iter;  /* so save node as victim, delete next iteration */
    }
    if (victim)         /* free last node */
        free (victim);

    return 0;
}

