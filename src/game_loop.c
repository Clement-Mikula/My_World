/*
** EPITECH PROJECT, 2020
** game_loop
** File description:
** game_loop
*/

#include "my.h"

void game_loop(game_t *game)
{
    sfTime time;
    float seconds = 0;

    initialisation(game);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        events(game, seconds);
        game->map = create_map(game->int_map);
        draw_map(game->window, game->map);
        draw_sprite(game);
        time = sfClock_getElapsedTime(game->clock);
        seconds = time.microseconds / 1000000.0;
        sfRenderWindow_display(game->window);
        for (int i = 0; i < MAP_Y; i++)
            free(game->map[i]);
        free(game->map);
    }
}