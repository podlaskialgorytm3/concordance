#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "sort.h"
#include "search.h"

#define MAX 1024

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("File name is not written.\n");
        return 1;
    }
    if (argc < 3)
    {
        printf("Sort mode is not written.\n");
        return 1;
    }

    if (argc < 4)
    {
        printf("Any words are not  written.\n");
        return 1;
    }

    char *fileName = argv[1];
    int sortMode = atoi(argv[2]);
    int n = argc - 3;
    char **words = malloc(n * sizeof(char *));

    if (!(sortMode == 1 || sortMode == 0))
    {
        printf("Sort mode is not correct.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        *(words + i) = argv[i + 3];
    }

    concordancePointer wordList = NULL;

    for (int i = 0; i < n; i++)
    {
        int *lines = get_lines(fileName, *(words + i));
        int number_of_lines = count_word_in_file(fileName, *(words + i));
        wordList = insert(wordList, *(words + i), number_of_lines, lines);
    }

    if (sortMode == 0)
    {
        printf("Sorting by word: \n");
        bubbleSortByWord(wordList);
        printStruct(wordList);
    }
    else if (sortMode == 1)
    {
        printf("Sorting by quantity: \n");
        bubbleSortByQuantity(wordList);
        printStruct(wordList);
    }

    return 0;
}