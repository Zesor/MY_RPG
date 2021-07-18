/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** init_sprite_next
*/

#include "define.h"
#include "struct.h"
#include "function.h"

void game_object4(rpg_t *rpg)
{
    sfVector2f pos = {260, 600};
    sfVector2f pos1 = {260, 780};

    rpg->game.f_home_text3 = sfTexture_createFromFile("asset/image/3darr.png",
    NULL);
    rpg->game.f_home_sprt3 = sfSprite_create();
    sfSprite_setPosition(rpg->game.f_home_sprt3, pos);
    sfSprite_setTexture(rpg->game.f_home_sprt3, rpg->game.f_home_text3, sfTrue);

    rpg->game.shop_text =
        sfTexture_createFromFile("asset/image/shop.png", NULL);
    rpg->game.shop_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->game.shop_sprt, pos1);
    sfSprite_setTexture(rpg->game.shop_sprt, rpg->game.shop_text, sfTrue);
}

void game_object5(rpg_t *rpg)
{

    sfVector2f pos = {688, -65};

    rpg->game.door_text = sfTexture_createFromFile("asset/image/porte.png",
    NULL);
    rpg->game.door_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->game.door_sprt, pos);
    sfSprite_setTexture(rpg->game.door_sprt, rpg->game.door_text, sfTrue);
}