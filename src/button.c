/*
** EPITECH PROJECT, 2020
** button
** File description:
** button
*/

#include "my.h"

void create_button(object_t *button, char *filepath, int x, int y)
{
    button->rect = (sfIntRect){0, 0, 49, 49};
    create_sprite(button, filepath, (sfVector2f){2, 2});
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_move(button->sprite, (sfVector2f){x, y});
}

void click_blue_button(sfEvent event, game_t *game)
{
    sfVector2f spritepos = sfSprite_getPosition(game->blue_buttons.sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    if (mouse.x >= spritepos.x && mouse.x <= spritepos.x + 100 &&
        mouse.y >= spritepos.y && mouse.y <= spritepos.y + 100) {
        sfSprite_setTexture(game->blue_buttons.sprite, 
        sfTexture_createFromFile("assets/blue_button07.png", NULL), 0);
        if (event.type == sfEvtMouseButtonPressed)
            move_vertex_raindrop(game);
    }
    else
        sfSprite_setTexture(game->blue_buttons.sprite, 
        sfTexture_createFromFile("assets/blue_button06.png", NULL), 0);
    sfClock_restart(game->clock);
}

void click_green_button(sfEvent event, game_t *game)
{
    sfVector2f spritepos = sfSprite_getPosition
    (game->green_buttons.sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    if (mouse.x >= spritepos.x && mouse.x <= spritepos.x + 100 &&
            mouse.y >= spritepos.y && mouse.y <= spritepos.y + 100) {
        sfSprite_setTexture(game->green_buttons.sprite, 
        sfTexture_createFromFile("assets/green_button07.png", NULL), 0);
        if (event.type == sfEvtMouseButtonPressed)
            move_vertex_random(game);
    }
    else
        sfSprite_setTexture(game->green_buttons.sprite, 
        sfTexture_createFromFile("assets/green_button06.png", NULL), 0);
    sfClock_restart(game->clock);
}

void click_yellow_button(sfEvent event, game_t *game)
{
    sfVector2f spritepos = sfSprite_getPosition
    (game->yellow_buttons.sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    if (mouse.x >= spritepos.x && mouse.x <= spritepos.x + 100 &&
        mouse.y >= spritepos.y && mouse.y <= spritepos.y + 100) {
        sfSprite_setTexture(game->yellow_buttons.sprite, 
        sfTexture_createFromFile("assets/yellow_button07.png", NULL), 0);
        if (event.type == sfEvtMouseButtonPressed)
            move_vertex_reset(game);
    }
    else
        sfSprite_setTexture(game->yellow_buttons.sprite, 
        sfTexture_createFromFile("assets/yellow_button06.png", NULL), 0);
    sfClock_restart(game->clock);
}

void create_sprite(object_t *object, char *filepath, sfVector2f scale)
{
    object->sprite = sfSprite_create();
    object->texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setScale(object->sprite, scale);
}