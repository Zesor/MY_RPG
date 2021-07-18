/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init_life_clone
*/

#include "struct.h"
#include "define.h"
#include "function.h"

sfVector2f init_life_clone(sfRectangleShape *sp, sfVector2f sz, sfVector2f pos)
{
    sz.x = 50;
    sz.y = 10;
    sfVector2f pos_bis;
    pos_bis.x = pos.x - 5;
    pos_bis.y = pos.y + 50;

    sfRectangleShape_setSize(sp, sz);
    sfRectangleShape_setPosition(sp, pos_bis);
    sfRectangleShape_setFillColor(sp, sfGreen);
    return sz;
}

void life_clones(rpg_t *rpg)
{
    rpg->enemy.rect_first = sfRectangleShape_create();
    rpg->enemy.rect_second = sfRectangleShape_create();
    rpg->enemy.rect_third = sfRectangleShape_create();
    rpg->enemy.rect_fourth = sfRectangleShape_create();
    rpg->enemy.rect_fifth = sfRectangleShape_create();
    rpg->enemy.size_first = init_life_clone(rpg->enemy.rect_first,
                            rpg->enemy.size_first, rpg->enemy.clone_first_pos);
    rpg->enemy.size_second = init_life_clone(rpg->enemy.rect_second,
                            rpg->enemy.size_second,
                                rpg->enemy.clone_second_pos);
    rpg->enemy.size_third = init_life_clone(rpg->enemy.rect_third,
                            rpg->enemy.size_third,
                                rpg->enemy.clone_third_pos);
    rpg->enemy.size_fourth = init_life_clone(rpg->enemy.rect_fourth,
                            rpg->enemy.size_fourth,
                                rpg->enemy.clone_fourth_pos);
    rpg->enemy.size_fifth = init_life_clone(rpg->enemy.rect_fifth,
                            rpg->enemy.size_fifth, rpg->enemy.clone_fifth_pos);
}

void init_pos_weapon(rpg_t *rpg)
{
    rpg->enemy.weapon_first_pos = rpg->enemy.clone_first_pos;
    rpg->enemy.weapon_second_pos = rpg->enemy.clone_second_pos;
    rpg->enemy.weapon_third_pos = rpg->enemy.clone_third_pos;
    rpg->enemy.weapon_fourth_pos = rpg->enemy.clone_fourth_pos;
    rpg->enemy.weapon_fifth_pos = rpg->enemy.clone_fifth_pos;
    life_clones(rpg);
}