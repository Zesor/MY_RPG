/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** enemy_hit
*/

#include "define.h"
#include "function.h"
#include "struct.h"

void init_chidori(rpg_t *rpg)
{
    rpg->paral.chidori_text = sfTexture_createFromFile(
                "asset/image/chidori.png", NULL);
    rpg->paral.chidori_sprt = sfSprite_create();
    rpg->paral.chidori_pos = rpg->paral.sasuke_pos;
    rpg->paral.chidori_rect = (sfIntRect) {0, 0, 50, 30};

    sfSprite_setPosition(rpg->paral.chidori_sprt, rpg->paral.chidori_pos);
    sfSprite_setTexture(rpg->paral.chidori_sprt, rpg->paral.chidori_text,
                sfTrue);
    sfSprite_setTextureRect(rpg->paral.chidori_sprt, rpg->paral.chidori_rect);
}

void anime_chidori(rpg_t *rpg)
{
    rpg->paral.chidori_pos.x -= 10;
    if (rpg->paral.chidori_pos.x == rpg->paral.naruto_pos.x)
        rpg->paral.chidori_pos.x = 1600;
    sfSprite_setPosition(rpg->paral.chidori_sprt, rpg->paral.chidori_pos);
}