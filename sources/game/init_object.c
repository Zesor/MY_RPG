/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** init_object
*/

#include "struct.h"
#include "function.h"

void init_tree(rpg_t *rpg)
{
    sfVector2f pos = {857, 25};
    sfVector2f pos1 = {857, 640};

    rpg->game.tree_text = sfTexture_createFromFile("asset/image/long_tree.png",
    NULL);
    rpg->game.tree_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->game.tree_sprt, pos);
    sfSprite_setTexture(rpg->game.tree_sprt, rpg->game.tree_text, sfTrue);

    rpg->game.tree_text2 = sfTexture_createFromFile("asset/image/long_tree.png",
    NULL);
    rpg->game.tree_sprt2 = sfSprite_create();
    sfSprite_setPosition(rpg->game.tree_sprt2, pos1);
    sfSprite_setTexture(rpg->game.tree_sprt2, rpg->game.tree_text2, sfTrue);
}

void init_tree2(rpg_t *rpg)
{
    sfVector2f pos = {658, 25};
    sfVector2f pos1 = {658, 640};

    rpg->game.tree_text3 = sfTexture_createFromFile("asset/image/long_tree.png",
    NULL);
    rpg->game.tree_sprt3 = sfSprite_create();
    sfSprite_setPosition(rpg->game.tree_sprt3, pos);
    sfSprite_setTexture(rpg->game.tree_sprt3, rpg->game.tree_text3, sfTrue);

    rpg->game.tree_text4 = sfTexture_createFromFile("asset/image/long_tree.png",
    NULL);
    rpg->game.tree_sprt4 = sfSprite_create();
    sfSprite_setPosition(rpg->game.tree_sprt4, pos1);
    sfSprite_setTexture(rpg->game.tree_sprt4, rpg->game.tree_text4, sfTrue);
}