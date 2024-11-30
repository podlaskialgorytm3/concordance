#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1024

int word_search_in_line(char *line, char *target_word)
{
    int count = 0;
    char *pos = line;

    while ((pos = strstr(pos, target_word)) != NULL)
    {
        if ((pos == line || *(pos - 1) == ' ' || *(pos - 1) == '\t') &&
            (*(pos + strlen(target_word)) == '\0' || *(pos + strlen(target_word)) == ' ' || *(pos + strlen(target_word)) == '\n' || *(pos + strlen(target_word)) == '\t'))
        {
            count++;
        }
        pos += strlen(target_word);
    }

    return count;
}

int *get_lines(char *file_name, char *target_word)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        perror("Error with file.");
        return NULL;
    }

    char line[MAX];
    int line_number = 0;
    int *lines = malloc(MAX * sizeof(int));
    int index = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;
        line[strcspn(line, "\n")] = '\0';

        int count = word_search_in_line(line, target_word);
        for (int i = 0; i < count; i++)
        {
            lines[index++] = line_number;

            if (index >= MAX)
            {
                lines = realloc(lines, (index + MAX) * sizeof(int));
                if (lines == NULL)
                {
                    perror("Memory allocation failed.");
                    fclose(file);
                    return NULL;
                }
            }
        }
    }

    fclose(file);
    return lines;
}

int count_word_in_file(char *file_name, char *target_word)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        perror("Error with file.");
        return -1;
    }

    char line[MAX];
    int total_count = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';
        total_count += word_search_in_line(line, target_word);
    }

    fclose(file);
    return total_count;
}