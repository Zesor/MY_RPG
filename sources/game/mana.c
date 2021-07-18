/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** mana
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void init_black_mana(rpg_t *rpg)
{
    rpg->mana.black_shape = sfRectangleShape_create();

    sfRectangleShape_setSize(rpg->mana.black_shape, (sfVector2f) {100, 10});
    sfRectangleShape_setFillColor(rpg->mana.black_shape, sfTransparent);
    sfRectangleShape_setOutlineColor(rpg->mana.black_shape, sfWhite);
    sfRectangleShape_setOutlineThickness(rpg->mana.black_shape, 4);
}

void init_mana(rpg_t *rpg)
{
    rpg->mana.shape = sfRectangleShape_create();
    rpg->mana.size.x = 0;
    rpg->mana.size.y = 10;

    sfRectangleShape_setSize(rpg->mana.shape, rpg->mana.size);
    sfRectangleShape_setFillColor(rpg->mana.shape, sfBlue);
    init_black_mana(rpg);
}