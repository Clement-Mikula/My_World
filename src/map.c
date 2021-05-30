/*
** EPITECH PROJECT, 2020
** line
** File description:
** line
*/

#include "my.h"

int **clear_bytes(int **base_map)
{
    for (int i = 0; i < MAP_Y; i++)
        for (int j = 0; j < MAP_X; j++)
            base_map[i][j] = 0;
    return base_map;
}

int **create_2d_map(void)
{
    int **base_map = malloc(MAP_Y * sizeof(int *));

    for (int i = 0; i < MAP_Y; i++)
        base_map[i] = malloc(sizeof(int) * MAP_X);
    base_map = clear_bytes(base_map);
    return base_map;
}

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f d_point;

    d_point.x = cos(ANGLE_X * M_PI / 180) * x -
     cos(ANGLE_X * M_PI / 180) * y;
    d_point.y = sin(ANGLE_Y * M_PI / 180) * y +
     sin(ANGLE_Y * M_PI / 180) * x - z;
    return d_point;
}

sfVector2f **create_map(int **map)
{
    sfVector2f **d2_map = malloc((MAP_Y + 1) * sizeof(sfVector2f *));

    for (int i = 0; i < MAP_Y + 1; i++)
        d2_map[i] = malloc(MAP_X * sizeof(sfVector2f));
    for (int y = 0; y < MAP_Y; y++)
        for (int x = 0; x < MAP_X; x++)
            d2_map[y][x] = project_iso_point(x * 64, y * 64, map[y][x]);
    return d2_map;
}
