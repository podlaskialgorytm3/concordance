#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

concordancePointer insert(concordancePointer list, char *word, int quantity, int *lines)
{
    if (list == NULL)
    {
        concordancePointer newConcordance = (concordancePointer)malloc(sizeof(concordance));
        if (newConcordance == NULL)
        {
            exit(1);
        }
        strcpy(newConcordance->word, word);
        newConcordance->quantity = quantity;
        newConcordance->lines = (int *)malloc(sizeof(int) * quantity);
        for (int i = 0; i < quantity; i++)
        {
            newConcordance->lines[i] = lines[i];
        }
        newConcordance->next = NULL;
        return newConcordance;
    }
    else
    {
        list->next = insert(list->next, word, quantity, lines);
        return list;
    }
}

void printStruct(concordancePointer wordList)
{
    while (wordList != NULL)
    {
        printf("Word: %s | Quantity of Lines: %d", wordList->word, wordList->quantity);
        printf(" | No. Lines: [ ");
        for (int i = 0; i < wordList->quantity; i++)
        {
            printf("%d ", wordList->lines[i]);
        }
        printf("]\n");
        wordList = wordList->next;
    }
}