/*
** EPITECH PROJECT, 2024
** File_parsing.c
** File description:
** Check if there is winner
*/

#include "../include/lingo.h"
#include <time.h>

void load_words(const char *filename, char words[][MAX_WORD_LENGTH],
    int *word_count)
{
    FILE *file = fopen(filename, "r");

    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    *word_count = 0;
    while (fgets(words[*word_count], MAX_WORD_LENGTH, file)) {
        words[*word_count][strcspn(words[*word_count], "\n")] = '\0';
        (*word_count)++;
    }
    fclose(file);
}

char *choose_secret_word(char words[][MAX_WORD_LENGTH], int word_count)
{
    int index;

    if (word_count == 0) {
        fprintf(stderr, "No words available to choose from.\n");
        exit(84);
    }
    srand(time(NULL));
    index = rand() % word_count;
    return words[index];
}
