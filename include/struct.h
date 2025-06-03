/*
** EPITECH PROJECT, 2025
** struct.h
** File description:
** structure for textcount project
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include <stddef.h>

typedef struct global_s {
    int player;
    char p1;
    char p2;
    size_t size;
    char **grid;
    size_t nb_turn;
} global_t;

#endif
