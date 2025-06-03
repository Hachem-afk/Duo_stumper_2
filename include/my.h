/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** all prototypes
*/

#ifndef PROTOTYPE
    #define PROTOTYPE

    #define FAILURE 84
    #define SUCCESS 0
    #include "struct.h"

global_t *init_struct(int argc, const char *argv[], global_t *all);
int intlen(int nb);
int next_move(global_t *all);
int print_grid(global_t *all);
int is_winner(global_t *all);

#endif /* PROTOTYPE */
