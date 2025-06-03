/*
** EPITECH PROJECT, 2024
** is_winner.c
** File description:
** Check if there is winner
*/

#include "my.h"
#include "struct.h"
#include <stddef.h>
#include <stdio.h>

static int check_player(global_t *all, size_t count_p1, size_t count_p2)
{
    if (count_p1 == all->size) {
        all->player = 1;
        return SUCCESS;
    }
    if (count_p2 == all->size) {
        all->player = 2;
        return SUCCESS;
    }
    return FAILURE;
}

static int winner_horizontal(global_t *all)
{
    size_t count_p1 = 0;
    size_t count_p2 = 0;

    for (size_t y = 0; y < all->size; y++) {
        for (size_t x = 0; x < all->size; x++) {
            count_p1 += all->grid[y][x] == all->p1 ? 1 : 0;
            count_p2 += all->grid[y][x] == all->p2 ? 1 : 0;
        }
        if (check_player(all, count_p1, count_p2) == SUCCESS)
            return SUCCESS;
        count_p1 = 0;
        count_p2 = 0;
    }
    return FAILURE;
}

static int winner_vertical(global_t *all)
{
    size_t count_p1 = 0;
    size_t count_p2 = 0;

    for (size_t y = 0; y < all->size; y++) {
        for (size_t x = 0; x < all->size; x++) {
            count_p1 += all->grid[x][y] == all->p1 ? 1 : 0;
            count_p2 += all->grid[x][y] == all->p2 ? 1 : 0;
        }
        if (check_player(all, count_p1, count_p2) == SUCCESS)
            return SUCCESS;
        count_p1 = 0;
        count_p2 = 0;
    }
    return FAILURE;
}

static int winner_diagonales(global_t *all)
{
    size_t count_p1 = 0;
    size_t count_p2 = 0;
    size_t size_copy = all->size;

    for (size_t i = 0; i < all->size; i++) {
        count_p1 += all->grid[i][i] == all->p1 ? 1 : 0;
        count_p2 += all->grid[i][i] == all->p2 ? 1 : 0;
    }
    if (check_player(all, count_p1, count_p2) == SUCCESS)
        return SUCCESS;
    count_p1 = 0;
    count_p2 = 0;
    for (size_t i = 0; i < all->size; i++) {
        size_copy -= 1;
        count_p1 += all->grid[i][size_copy] == all->p1 ? 1 : 0;
        count_p2 += all->grid[i][size_copy] == all->p2 ? 1 : 0;
    }
    return check_player(all, count_p1, count_p2);
}

int is_winner(global_t *all)
{
    int win = 1;

    if (winner_horizontal(all) == SUCCESS)
        win = 0;
    if (win != 0 && winner_vertical(all) == SUCCESS)
        win = 0;
    if (win != 0 && winner_diagonales(all) == SUCCESS)
        win = 0;
    if (win == 0) {
        if (printf("Player %i won!\n", all->player) < 0)
            return FAILURE;
        return SUCCESS;
    }
    return FAILURE;
}
