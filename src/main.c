/*
** EPITECH PROJECT, 2025
** duo_stumpeur4
** File description:
** main
*/

#include <stdio.h>
#include "my.h"
#include "struct.h"

int main(int argc, char const *argv[])
{
    global_t *all = NULL;

    all = init_struct(argc, argv, all);
    if (!all)
        return FAILURE;
    if (print_grid(all) == FAILURE)
        return FAILURE;
    while (1) {
        if (next_move(all) == FAILURE)
            return FAILURE;
        if (print_grid(all) == FAILURE)
            return FAILURE;
        all->nb_turn += 1;
        if (is_winner(all) == 0 || all->nb_turn == all->size * all->size)
            break;
    }
    return SUCCESS;
}
