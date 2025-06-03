/*
** EPITECH PROJECT, 2025
** duo_stumpeur
** File description:
** main
*/

#include "../include/lingo.h"

int main(int argc, char *argv[])
{
    char words[100][MAX_WORD_LENGTH];
    int word_count;
    char *secret_word;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <word_file>\n", argv[0]);
        return 84;
    }
    word_count = 0;
    load_words(argv[1], words, &word_count);
    secret_word = choose_secret_word(words, word_count);
    play_lingo(secret_word);
    return 0;
}
