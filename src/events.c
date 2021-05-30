/*
** EPITECH PROJECT, 2020
** events
** File description:
** events
*/

#include "my.h"

void move_vertex_up(game_t *game)
{
    for (int i = 0; i < MAP_X; i++)
        for (int j = 0; j < MAP_Y; j++) {
            if (sfMouse_getPositionRenderWindow(game->window).x < (game->map
            [i][j].x + TRANS_X + 20) && sfMouse_getPositionRenderWindow
            (game->window).x > (game->map[i][j].x + TRANS_X - 20) && 
            sfMouse_getPositionRenderWindow(game->window).y < (game->map[i]
            [j].y + TRANS_Y + 20) && sfMouse_getPositionRenderWindow
            (game->window).y > (game->map[i][j].y + TRANS_Y - 20)) {
                game->int_map[i][j] += 10;
                sfClock_restart(game->clock);
            }
        }
}

void move_tiles_up(game_t *game)
{
    for (int i = 0; i < MAP_X - 1; i++)
        for (int j = 0; j < MAP_Y - 1; j++) {
            if (sfMouse_getPositionRenderWindow(game->window).x < (game->map[
                i][j].x + TRANS_X + 20) && sfMouse_getPositionRenderWindow
                (game->window).x > (game->map[i][j].x + TRANS_X - 20) && 
                sfMouse_getPositionRenderWindow(game->window).y < (game->map
                [i][j].y + TRANS_Y + 20) && sfMouse_getPositionRenderWindow
                (game->window).y > (game->map[i][j].y + TRANS_Y - 20)) {
                game->int_map[i][j] += 10;
                game->int_map[i + 1][j] += 10;
                game->int_map[i][j + 1] += 10;
                game->int_map[i + 1][j + 1] += 10;
                sfClock_restart(game->clock);
            }
        }
}

void move_vertex_down(game_t *game)
{
    for (int i = 0; i < MAP_X; i++)
        for (int j = 0; j < MAP_Y; j++) {
            if (sfMouse_getPositionRenderWindow(game->window).x < (game->map
            [i][j].x + TRANS_X + 100) && sfMouse_getPositionRenderWindow(
                game->window).x > (game->map[i][j].x + TRANS_X - 100) && 
                sfMouse_getPositionRenderWindow(game->window).y < (game->map
                [i][j].y + TRANS_Y + 100) && sfMouse_getPositionRenderWindow
                (game->window).y > (game->map[i][j].y + TRANS_Y - 100)) {
                if (game->int_map[i][j] > 10)
                    game->int_map[i][j] -= 5;
                if (game->int_map[i][j] > 0)
                    game->int_map[i][j] -= 1;
                else if (game->int_map[i][j] < -10)
                    game->int_map[i][j] += 5;
                else if (game->int_map[i][j] < 0)
                    game->int_map[i][j] += 1;
                sfClock_restart(game->clock);
            }
        }
}

void events(game_t *game, float seconds)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    if (seconds > 0.01) {
            click_blue_button(game->event, game);
            click_green_button(game->event, game);
            click_yellow_button(game->event, game);
        }
        if (seconds > 0.016) {
            if (sfMouse_isButtonPressed(sfMouseRight))
                move_vertex_down(game);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                move_vertex_up(game);
            if (sfKeyboard_isKeyPressed(sfKeyT))
                move_tiles_up(game);
        }
}