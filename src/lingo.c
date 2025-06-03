/*
** EPITECH PROJECT, 2025
** duo_stumpeur
** File description:
** Lingo core implementation
*/

#include "../include/lingo.h"

void play_lingo(const char *secret)
{
    int length = strlen(secret);
    char guess[MAX_WORD_LENGTH];
    int count = 1;
    int flag_round = 0;

    printf("The secret word starts with '%c' and has %d letters.\n",
        secret[0], length);
    while (1) {
        if ( flag_round == 0) 
            printf("Round %d\n", count);
        printf(">");
        scanf("%s", guess);
        if (strlen(guess) < length) {
            printf("Word too short. Retry.\n");
            flag_round = 1;
            continue;
        }
        if (strlen(guess) > length) {
            printf("Word too long. Retry.\n");
            flag_round = 1;
            continue;
        }
        if (strcmp(guess, secret) == 0) {
            printf("Congratulations! You've guessed the word: %s\n", secret);
            break;
        } else {
            print_result(guess, secret);
            count++;
            flag_round = 0;
        }
    }
}
