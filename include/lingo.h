/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** all prototypes
*/

#ifndef LINGO
    #define LINGO
    #include <stdio.h> 
    #include <stdlib.h>
    #include <string.h>
    #define MAX_WORD_LENGTH 100

void print_result(const char *guess, const char *secret);
void load_words(const char *filename, char words[][MAX_WORD_LENGTH],
    int *word_count);
char *choose_secret_word(char words[][MAX_WORD_LENGTH], int word_count);
void play_lingo(const char *secret);
void print_first_round(const char *secret);

#endif /* LINGO */
