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

void move_vertex_perlin(game_t *game);
float perlin2d(float x, float y, float freq, int depth);
float noise2d(float x, float y);
float smooth_inter(float x, float y, float s);
float lin_inter(float x, float y, float s);
int noise2(int x, int y);