/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** create_buttons
*/

#include "my.h"

struct button_s *init_butt(sfVector2f pos, sfVector2f size)
{
    button_s *butt = malloc(sizeof(button_s));

    if (butt == NULL)
        return NULL;
    butt->shape = sfRectangleShape_create();
    butt->position = pos;
    butt->size = size;
    sfRectangleShape_setSize(butt->shape, butt->size);
    sfRectangleShape_setPosition(butt->shape, butt->position);
    sfRectangleShape_setFillColor(butt->shape, sfTransparent);
    return butt;
}