/*
** EPITECH PROJECT, 2020
** game_help
** File description:
** game_help
*/

#include "my.h"

void game_help(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        write(1, "HOW TO PLAY\n", 13);
}