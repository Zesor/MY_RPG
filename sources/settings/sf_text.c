/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** sf_text
*/

#include "define.h"
#include "struct.h"
#include "function.h"

sfText *init_txt_color(int size, sfVector2f vect, char *str, sfColor color)
{
    sfText *init = sfText_create();
    sfFont *font = sfFont_createFromFile("asset/font/njnaruto.ttf");

    sfText_setFont(init, font);
    sfText_setCharacterSize(init, size);
    sfText_setColor(init, color);
    sfText_setPosition(init, vect);
    sfText_setString(init, str);
    return init;
}