#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LENGTH 100

void print_result(const char *guess, const char *secret)
{
    int length = strlen(secret);

    for (int i = 0; i < length; i++) {
        if (guess[i] == secret[i])
            printf("%c ", guess[i]);
        if (strchr(secret, guess[i])) {
            printf("%c? ", guess[i]);
        } else {
            printf("%c  ", guess[i]);
        }
    }
    printf("\n");
}

void play_lingo(const char *secret)
{
    int length = strlen(secret);
    char guess[MAX_WORD_LENGTH];

    printf("The secret word starts with '%c' and has %d letters.\n",
        secret[0], length);
    while (1) {
        printf("Enter your guess: ");
        scanf("%s", guess);
        if (strlen(guess) != length) {
            printf("Your guess must be %d letters long. Try again.\n", length);
            continue;
        }
        if (strcmp(guess, secret) == 0) {
            printf("Congratulations! You've guessed the word: %s\n", secret);
            break;
        } else {
            print_result(guess, secret);
        }
    }
}

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
