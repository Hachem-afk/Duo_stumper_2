/*
** EPITECH PROJECT, 2025
** duo_stumpeur
** File description:
** Lingo core implementation
*/

#include "../include/lingo.h"
 
static int check_too_long_short(char guess[MAX_WORD_LENGTH], size_t length)
{
    if (strlen(guess) < length) {
        printf("Word too short. Retry.\n>");
	return 1;
    }
    if (strlen(guess) > length) {
        printf("Word too long. Retry.\n>");
        return 1;
    }
    return 0;
}

static int check_win_lost(char guess[MAX_WORD_LENGTH], const char *secret,
    int length, int count)
{
    if (strcmp(guess, secret) == 0) {
        printf("\nYou won!\n");
        return 0;
    }
    if (count >= length) {
        printf("\nYou lost!\n");
        return 0;
    }
    return 1;
}

void play_lingo(const char *secret)
{
    int length = strlen(secret);
    char guess[MAX_WORD_LENGTH];
    int count = 1;
    int flag_round = 0;

    print_first_round(secret);
    while (1) {
        if (flag_round == 0) 
            printf("\n\nRound %d\n>", count);
        scanf("%s", guess);
        flag_round = check_too_long_short(guess, length);
        if (check_win_lost(guess, secret, length, count) == 0)
            break;
        if (flag_round == 0) {
            print_result(guess, secret);
            count++;
            flag_round = 0;
        }
    }
}
