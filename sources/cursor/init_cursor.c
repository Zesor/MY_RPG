/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** init_cursor
*/

#include "define.h"
#include "function.h"
#include "struct.h"

sfSprite *init_cursor(sfRenderWindow *window, char *filepath, int x, int y)
{
    sfSprite *cursor = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfVector2f position;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    position.x = mouse.x;
    position.x -= x;
    position.y = mouse.y;
    position.y -= y;
    sfSprite_setTexture(cursor, texture, sfFalse);
    sfSprite_setPosition(cursor, position);
    return cursor;
}