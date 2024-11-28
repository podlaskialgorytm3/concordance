#ifndef _LIST_H
#define _LIST_H

typedef struct concordance {
    char word[100];
    int quantity;
    int *lines;
    struct concordance *next;
}concordance, *concordancePointer;

concordancePointer insert(concordancePointer list, char *word, int quantity, int *lines);

void printStruct(concordancePointer wordList);

#endif 

