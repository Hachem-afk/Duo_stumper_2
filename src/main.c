/*
** EPITECH PROJECT, 2025
** duo_stumpeur
** File description:
** main
*/

#include <stdio.h>
#include "my.h"
#include "struct.h"

int main(int argc, char const *argv[])
{
    global_t *all = NULL;

    if (argc != 2)
        return FAILURE;
    all = init_struct(argc, argv, all);
    if (!all)
        return FAILURE;
    if (print_menu(all) == FAILURE)
        return FAILURE;
    for (size_t i = 0; i < all->nb_iteration; i++) {
        if (next_move(all, i) == FAILURE)
            return FAILURE;
        if (print_grid(all) == FAILURE)
            return FAILURE;
        all->nb_turn += 1;
        if (is_winner(all) == 0 || all->nb_turn == all->size * all->size)
            break;
    }
    return SUCCESS;
}
