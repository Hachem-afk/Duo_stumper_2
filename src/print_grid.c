/*
** EPITECH PROJECT, 2024
** print_grid.c
** File description:
** print the grid
*/

#include "my.h"
#include "struct.h"
#include <stdio.h>

static int print_line(int size)
{
    if (printf("+") < 0)
        return FAILURE;
    for (int i = 0; i < size; i++) {
        if (printf("-") < 0)
            return FAILURE;
    }
    if (printf("+\n") < 0)
        return FAILURE;
    return SUCCESS;
}

int print_grid(global_t *all)
{
    if (printf("\n") < 0)
        return FAILURE;
    if (!all)
        return FAILURE;
    if (print_line(all->size) == FAILURE)
        return FAILURE;
    for (size_t i = 0; i < all->size; i++) {
        if (printf("|%s|\n", all->grid[i]) < 0)
            return FAILURE;
    }
    if (print_line(all->size) == FAILURE)
        return FAILURE;
    if (printf("\n") < 0)
        return FAILURE;
    return SUCCESS;
}
