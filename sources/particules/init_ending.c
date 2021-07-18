/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** init_ending
*/

#include "function.h"
#include "struct.h"
#include "define.h"

void init_ending(rpg_t *rpg)
{
    rpg->end.end_text = sfTexture_createFromFile("asset/image/end.png", NULL);
    rpg->end.end_sprt = sfSprite_create();
    rpg->end.pos.x = 0;
    rpg->end.pos.y = 1080;
    sfSprite_setPosition(rpg->end.end_sprt, rpg->end.pos);
    sfSprite_setTexture(rpg->end.end_sprt, rpg->end.end_text, sfTrue);
}

void move_ending(rpg_t *rpg)
{
    rpg->general_clock = sfClock_create();

    if (rpg->general_clock)
        rpg->end.pos.y -= 0.4;
    if (rpg->end.pos.y < -1080)
        rpg->end.pos.y = 1080;
    sfSprite_setPosition(rpg->end.end_sprt, rpg->end.pos);
}