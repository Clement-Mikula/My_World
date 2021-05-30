/*
** EPITECH PROJECT, 2020
** animations
** File description:
** animations
*/

#include "my.h"

void move_vertex_reset(game_t *game)
{
    for (int i = 0; i < MAP_X; i++)
        for (int j = 0; j < MAP_Y; j++)
            game->int_map[i][j] = 0;
    sfClock_restart(game->clock);
}

void move_vertex_raindrop(game_t *game)
{
    for (int i = 0; i < MAP_X; i++)
        for (int j = 0; j < MAP_Y; j++) {
            if (i % 2 == 0)
                game->int_map[i][j] += 1;
            else
                game->int_map[i][j] -= 1;
        }
    sfClock_restart(game->clock);
}

void move_vertex_random(game_t *game)
{
    for (int i = 0; i < MAP_X; i++)
        for (int j = 0; j < MAP_Y; j++) {
            game->int_map[i][j] += rand() % 10;
            game->int_map[i][j] -= rand() % 10;
        }
    sfClock_restart(game->clock);
}