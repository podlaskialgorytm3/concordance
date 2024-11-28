#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char **argv)
{
    concordancePointer wordList = NULL;

    wordList = insert(wordList, "mozg", 3, (int[]){1, 2, 3});
    wordList = insert(wordList, "nogi", 4, (int[]){1, 2, 3, 9});
    wordList = insert(wordList, "glowa", 5, (int[]){1, 2, 3, 44, 55});
    wordList = insert(wordList, "czolo", 6, (int[]){1, 2, 3, 55, 33, 22});
    wordList = insert(wordList, "reka", 2, (int[]){2, 3});

    printStruct(wordList);

    return 0;
}