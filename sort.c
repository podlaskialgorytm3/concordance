#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

void swapNodes(concordancePointer a, concordancePointer b)
{
    char tempWord[100];
    int tempQuantity;
    int *tempLines;

    strcpy(tempWord, a->word);
    strcpy(a->word, b->word);
    strcpy(b->word, tempWord);

    tempQuantity = a->quantity;
    a->quantity = b->quantity;
    b->quantity = tempQuantity;

    tempLines = a->lines;
    a->lines = b->lines;
    b->lines = tempLines;
}

void bubbleSortByQuantity(concordancePointer head)
{
    if (!head)
        return;

    int swapped;
    concordancePointer ptr;
    concordancePointer lptr = NULL;

    do
    {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr)
        {
            if (ptr->quantity > ptr->next->quantity)
            {
                swapNodes(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

void bubbleSortByWord(concordancePointer head)
{
    if (!head)
        return;

    int swapped;
    concordancePointer ptr;
    concordancePointer lptr = NULL;

    do
    {
        swapped = 0;
        ptr = head;
        while (ptr->next != lptr)
        {
            if (strcmp(ptr->word, ptr->next->word) > 0)
            {
                swapNodes(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}