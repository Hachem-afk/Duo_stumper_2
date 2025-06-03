/*
** EPITECH PROJECT, 2024
** nbr_len
** File description:
** Return the len of an int
*/

#include "../include/lingo.h"

void print_first_round(const char *secret)
{
    int length = strlen(secret);
    int i;

    printf("*: invalid letter\n?: incorrectly placed letter\n");
    printf("Will you find the secret word?\n");
    printf("%c", secret[0]);
    for (i = 1; i < length; i++) {
        printf("*");
    }
    printf("\n\n");
}

void print_result_correct(const char *guess, const char *secret, char *result)
{
    int length = strlen(secret);
    int i;

    for (i = 0; i < length; i++) {
        if (guess[i] == secret[i]) {
          result[i] = guess[i];
        } else {
          result[i] = '*';
        }
    }
}

void print_result_m_h(const char *g, const char *secret, char *res, int i)
{
    int j;
    int length = strlen(secret);

    for (j = 0; j < length; j++) {
        if (g[i] == secret[j] && res[j] != secret[j]) {
            res[i] = '?';
            break;
	}
    }
}

void print_result_m(const char *guess, const char *secret, char *result)
{
    int i;
    int length = strlen(secret);

    for (i = 0; i < length; i++) {
        if (result[i] == '*') {
            print_result_m_h(guess, secret, result, i);
        }
    }
}

void print_result(const char *guess, const char *secret)
{
    char result[MAX_WORD_LENGTH];
    int length = strlen(secret);

    memset(result, '*', length);
    result[length] = '\0';
    print_result_correct(guess, secret, result);
    print_result_m(guess, secret, result);
    printf("Result: %s\n", result);
}
