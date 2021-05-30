/*
** EPITECH PROJECT, 2020
** line
** File description:
** line
*/

#include "my.h"

sfVertexArray *create_line(sfVector2f pos1, sfVector2f pos2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex start = {.position = pos1, .color = sfWhite};
    sfVertex end = {.position = pos2, .color = sfWhite};

    start.position.x += TRANS_X;
    start.position.y += TRANS_Y;
    end.position.x += TRANS_X;
    end.position.y += TRANS_Y;
    sfVertexArray_append(vertex_array, start);
    sfVertexArray_append(vertex_array, end);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

void draw_map(sfRenderWindow *window, sfVector2f **map)
{
    for (int y = 0; y < MAP_Y - 1; y++) {
        for (int x = 0; x < MAP_X - 1; x++) {
            sfRenderWindow_drawVertexArray(window, create_line
            (map[y][x], map[y][x + 1]), NULL);
            sfRenderWindow_drawVertexArray(window, create_line
            (map[y][x], map[y + 1][x]), NULL);
            sfRenderWindow_drawVertexArray(window, create_line
            (map[MAP_Y - 1][x], map[MAP_Y - 1][x + 1]), NULL);
        }
        sfRenderWindow_drawVertexArray(window, create_line
        (map[y][MAP_X - 1], map[y + 1][MAP_X - 1]), NULL);
    }
}