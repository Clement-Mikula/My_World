/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#include "my.h"

#define MAP_X 13
#define MAP_Y 13
#define ANGLE_X 45
#define ANGLE_Y 35

#define TRANS_X 960
#define TRANS_Y 50

void create_button(object_t *button, char *filepath, int x, int y);
void move_vertex_random(game_t *game);

void create_sprite(object_t *object, char *filepath, sfVector2f scale)
{
    object->sprite = sfSprite_create();
    object->texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setScale(object->sprite, scale);
}

void click_blue_button(sfEvent event, game_t *game)
{
    if (event.type == sfEvtMouseButtonPressed)
    {
        sfVector2f spritepos = sfSprite_getPosition(game->blue_buttons.sprite);
        sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
        if (mouse.x >= spritepos.x && mouse.x <= spritepos.x + 100 &&
            mouse.y >= spritepos.y && mouse.y <= spritepos.y + 100)
        {
            move_vertex_perlin(game);
        }
    }
    sfClock_restart(game->clock);
}

void move_vertex_random(game_t *game)
{
    for (int i = 0; i < MAP_X; i++)
    {
        for (int j = 0; j < MAP_Y; j++)
        {
            game->int_map[i][j] = rand() % 100;
        }
    }
    sfClock_restart(game->clock);
}

void move_vertex_up(game_t *game)
{
    for (int i = 0; i < MAP_X; i++)
    {
        for (int j = 0; j < MAP_Y; j++)
        {
            if (sfMouse_getPositionRenderWindow(game->window).x < (game->map[i][j].x + TRANS_X + 20) && sfMouse_getPositionRenderWindow(game->window).x > (game->map[i][j].x + TRANS_X - 20) && sfMouse_getPositionRenderWindow(game->window).y < (game->map[i][j].y + TRANS_Y + 20) && sfMouse_getPositionRenderWindow(game->window).y > (game->map[i][j].y + TRANS_Y - 20))
            {
                game->int_map[i][j] += 10;
                sfClock_restart(game->clock);
            }
        }
    }
}

void move_tiles_up(game_t *game)
{
    for (int i = 0; i < MAP_X - 1; i++)
    {
        for (int j = 0; j < MAP_Y - 1; j++)
        {
            if (sfMouse_getPositionRenderWindow(game->window).x < (game->map[i][j].x + TRANS_X + 20) && sfMouse_getPositionRenderWindow(game->window).x > (game->map[i][j].x + TRANS_X - 20) && sfMouse_getPositionRenderWindow(game->window).y < (game->map[i][j].y + TRANS_Y + 20) && sfMouse_getPositionRenderWindow(game->window).y > (game->map[i][j].y + TRANS_Y - 20))
            {
                game->int_map[i][j] += 10;
                game->int_map[i + 1][j] += 10;
                game->int_map[i][j + 1] += 10;
                game->int_map[i + 1][j + 1] += 10;
                sfClock_restart(game->clock);
            }
        }
    }
}

void move_vertex_down(game_t *game)
{
    for (int i = 0; i < MAP_X; i++)
    {
        for (int j = 0; j < MAP_Y; j++)
        {
            if (sfMouse_getPositionRenderWindow(game->window).x < (game->map[i][j].x + TRANS_X + 100) && sfMouse_getPositionRenderWindow(game->window).x > (game->map[i][j].x + TRANS_X - 100) && sfMouse_getPositionRenderWindow(game->window).y < (game->map[i][j].y + TRANS_Y + 100) && sfMouse_getPositionRenderWindow(game->window).y > (game->map[i][j].y + TRANS_Y - 100))
            {
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
}


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
    for (int y = 0; y < MAP_Y - 1; y++)
    {
        for (int x = 0; x < MAP_X - 1; x++)
        {
            sfRenderWindow_drawVertexArray(window, create_line(map[y][x], map[y][x + 1]), NULL);
            sfRenderWindow_drawVertexArray(window, create_line(map[y][x], map[y + 1][x]), NULL);
            sfRenderWindow_drawVertexArray(window, create_line(map[MAP_Y - 1][x], map[MAP_Y - 1][x + 1]), NULL);
        }
        sfRenderWindow_drawVertexArray(window, create_line(map[y][MAP_X - 1], map[y + 1][MAP_X - 1]), NULL);
    }
}



int **create_2d_map(void)
{
    int **base_map = malloc(MAP_Y * sizeof(int *));

    for (int i = 0; i < MAP_Y; i++)
        base_map[i] = calloc(MAP_X, sizeof(int));
    return base_map;
}


sfRenderWindow *create_window(char *windowname)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, windowname, sfResize | sfClose, NULL);

    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    return window;
}


sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f d_point;

    d_point.x = cos(ANGLE_X * M_PI / 180) * x - cos(ANGLE_X * M_PI / 180) * y;
    d_point.y = sin(ANGLE_Y * M_PI / 180) * y + sin(ANGLE_Y * M_PI / 180) * x - z;
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

void create_button(object_t *button, char *filepath, int x, int y)
{
    button->rect = (sfIntRect){0, 0, 49, 49};
    create_sprite(button, filepath, (sfVector2f){2, 2});
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_move(button->sprite, (sfVector2f){x, y});
}

void game_loop(game_t *game)
{
    game->clock = sfClock_create();
    sfTime time;
    float seconds = 0;

    create_button(&game->blue_buttons, "../assets/blue_button06.png", 1600, 500);

    game->window = create_window("my world");
    game->int_map = create_2d_map();

    while (sfRenderWindow_isOpen(game->window))
    {
        sfRenderWindow_clear(game->window, sfBlack);

        game->map = create_map(game->int_map);
        draw_map(game->window, game->map);

        sfRenderWindow_drawSprite(game->window, game->blue_buttons.sprite, NULL);


        while (sfRenderWindow_pollEvent(game->window, &game->event))
            if (game->event.type == sfEvtClosed)
                sfRenderWindow_close(game->window);

        if (seconds > 0.01)
        {
            click_blue_button(game->event, game);
        }

        if (seconds > 0.016)
        {
            if (sfMouse_isButtonPressed(sfMouseRight))
                move_vertex_down(game);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                move_vertex_up(game);
            if (sfKeyboard_isKeyPressed(sfKeyT))
                move_tiles_up(game);
        }
        time = sfClock_getElapsedTime(game->clock);
        seconds = time.microseconds / 1000000.0;

        sfRenderWindow_display(game->window);
        for (int i = 0; i < MAP_Y; i++)
            free(game->map[i]);
        free(game->map);
    }
}

void game_help(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        write(1, "HOW TO PLAY\n", 13);
}

int main(int argc, char **argv)
{
    game_help(argc, argv);
    game_t game;
    game_loop(&game);

    return 0;
}
