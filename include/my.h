/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_X 13
#define MAP_Y 13
#define ANGLE_X 45
#define ANGLE_Y 35
#define TRANS_X 960
#define TRANS_Y 50

typedef struct map_s
{
    sfVector2f **map;
    int x;
    int y;
} map_t;

typedef struct object_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
} object_t;

typedef struct game_s {
    sfRenderWindow *window;
    object_t background;
    object_t character;
    sfClock *clock;
    sfEvent event;
    int **int_map;
    object_t blue_buttons;
    object_t green_buttons;
    object_t yellow_buttons;
    object_t blue_buttons_click;
    object_t green_buttons_click;
    object_t yellow_buttons_click;
    sfVector2f **map;
} game_t;

void create_sprite(object_t *object, char *filepath, sfVector2f scale);
void create_button(object_t *button, char *filepath, int x, int y);
void click_blue_button(sfEvent event, game_t *game);
void click_green_button(sfEvent event, game_t *game);
void click_yellow_button(sfEvent event, game_t *game);
void draw_sprite(game_t *game);

void move_vertex_reset(game_t *game);
void move_vertex_raindrop(game_t *game);
void move_vertex_random(game_t *game);
void move_vertex_up(game_t *game);
void move_vertex_down(game_t *game);
void move_tiles_up(game_t *game);

sfVertexArray *create_line(sfVector2f pos1, sfVector2f pos2);
void draw_map(sfRenderWindow *window, sfVector2f **map);

int **create_2d_map(void);
sfVector2f project_iso_point(int x, int y, int z);
sfVector2f **create_map(int **map);

void initialisation(game_t *game);
sfRenderWindow *create_window(char *windowname);
void events(game_t *game, float seconds);
void game_loop(game_t *game);

void game_help(int argc, char **argv);