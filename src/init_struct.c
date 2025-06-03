/*
** EPITECH PROJECT, 2025
** init_struct.c
** File description:
** init struct
*/

#include "struct.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static char **put_in(char **grid, global_t *all)
{
    if (!grid || !all)
        return NULL;
    for (size_t i = 0; i < all->size; i++){
        for (size_t j = 0; j < all->size; j++)
            grid[i][j] = ' ';
    }
    return grid;
}

static char **create_grid(global_t *all)
{
    char **grid = NULL;

    if (!all)
        return NULL;
    grid = malloc(sizeof(char *) * (all->size + 1));
    if (!grid)
        return NULL;
    for (size_t i = 0; i < all->size; i++){
        grid[i] = malloc(sizeof(char) * (all->size + 1));
        if (!grid[i])
            return NULL;
        grid[i][all->size] = '\0';
    }
    grid[all->size] = NULL;
    grid = put_in(grid, all);
    if (!grid)
        return NULL;
    return grid;
}

static global_t *check_flag(const char *argv[], size_t i, global_t *all)
{
    if (!argv || !all)
        return NULL;
    if (strcmp(argv[i], "-p1") == 0 && strlen(argv[i + 1]) == 1
        && argv[i + 1][0] != all->p2 && i == 1)
        all->p1 = argv[i + 1][0];
    if (strcmp(argv[i], "-p2") == 0 && strlen(argv[i + 1]) == 1
        && argv[i + 1][0] != all->p1)
        all->p2 = argv[i + 1][0];
    else if (strcmp(argv[i], "-p2") == 0 && atoi(argv[i + 1]) != 0
        && argv[i + 2] == NULL)
        all->size = atoi(argv[i + 1]);
    else
        return NULL;
    return all;
}

global_t *init_struct(int argc, const char *argv[], global_t *all)
{
    all = malloc(sizeof(global_t));
    if (!all || !argv || (argc % 2) == 0 || argc > 7)
        return NULL;
    all->player = 1;
    all->p1 = 'X';
    all->p2 = 'O';
    all->size = 3;
    all->grid = NULL;
    all->nb_turn = 0;
    for (size_t i = 1; argv[i] != NULL; i += 2) {
        if (argc == 1)
            break;
        all = check_flag(argv, i, all);
        if (!all || all->size == 0)
            return NULL;
    }
    all->grid = create_grid(all);
    if (!all->grid)
        return NULL;
    return all;
}
