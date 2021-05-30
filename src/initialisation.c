/*
** EPITECH PROJECT, 2020
** initialisation
** File description:
** initialisation
*/

#include "my.h"

void initialisation(game_t *game)
{
    game->clock = sfClock_create();
    create_button(&game->blue_buttons, "assets/blue_button06.png",
     1600, 500);
    create_button(&game->green_buttons, "assets/green_button06.png",
     1600, 625);
    create_button(&game->yellow_buttons, "assets/yellow_button06.png",
     1600, 750);
    game->window = create_window("my world");
    game->int_map = create_2d_map();
}

sfRenderWindow *create_window(char *windowname)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, windowname,
     sfResize | sfClose, NULL);

    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    return window;
}

void draw_sprite(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->blue_buttons.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->green_buttons.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->yellow_buttons.sprite, NULL);
}