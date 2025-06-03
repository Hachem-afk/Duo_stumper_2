/*
** EPITECH PROJECT, 2024
** next_move.c
** File description:
** Check the next move and modify the grid in consequencies
*/

#include "my.h"
#include "struct.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int print_line(global_t *all)
{
    if (!all)
        return FAILURE;
    if (printf("Player %i> ", all->player) < 0)
        return FAILURE;
    fflush(stdout);
    return SUCCESS;
}

int next_move(global_t *all)
{
    size_t x = 0;
    size_t y = 0;
    char input[1024];

    if (!all || print_line(all) == FAILURE)
        return FAILURE;
    if (read(STDIN_FILENO, input, 1024) < 0)
        return FAILURE;
    x = atoi(input);
    y = atoi(input + intlen(x) + 1);
    if (x > all->size || y > all->size || all->grid[y][x] != ' ')
        return FAILURE;
    if (all->player == 1) {
        all->grid[y][x] = all->p1;
        all->player = 2;
    } else {
        all->grid[y][x] = all->p2;
        all->player = 1;
    }
    return SUCCESS;
}
