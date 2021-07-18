/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init_fight
*/

#include "struct.h"
#include "define.h"
#include "function.h"

sfSprite *init_sprt(rpg_t *rpg, sfSprite *srt, sfTexture *txt, sfIntRect rt)
{
    srt = sfSprite_create();

    sfSprite_setTexture(srt, txt, sfTrue);
    sfSprite_setTextureRect(srt, rt);
    return (srt);
}

sfVector2f make_pos_clone(sfVector2f pos, sfSprite *sprite, int x, int y)
{
    pos.x = x;
    pos.y = y;

    sfSprite_setPosition(sprite, pos);
    return pos;
}

void init_pos_clone(rpg_t *rpg)
{
    sfTexture *texture = sfTexture_createFromFile("asset/image/sand.png", NULL);
    srand(time(NULL));
    rpg->enemy.clone_first_pos = make_pos_clone(rpg->enemy.clone_first_pos,
                rpg->enemy.first_clone, random()%(1096 - 194 +1) + 194,
                random()%((886 - (-6) + (-6))));
    rpg->enemy.clone_second_pos = make_pos_clone(rpg->enemy.clone_second_pos,
                rpg->enemy.second_clone, random()%(1096 - 194 +1) + 194,
                random()%((886 - (-6) + (-6))));
    rpg->enemy.clone_third_pos = make_pos_clone(rpg->enemy.clone_third_pos,
                rpg->enemy.third_clone, random()%(1096 - 194 +1) + 194,
                random()%((886 - (-6) + (-6))));
    rpg->enemy.clone_fourth_pos = make_pos_clone(rpg->enemy.clone_fourth_pos,
                rpg->enemy.fourth_clone, random()%(1096 - 194 +1) + 194,
                random()%((886 - (-6) + (-6))));
    rpg->enemy.clone_fifth_pos = make_pos_clone(rpg->enemy.clone_fifth_pos,
                rpg->enemy.fifth_clone, random()%(1096 - 194 +1) + 194,
                random()%((886 - (-6) + (-6))));
    init_pos_weapon(rpg);
}

void init_clone(rpg_t *rpg)
{
    rpg->enemy.first_clone = init_sprt(rpg, rpg->enemy.first_clone,
                        rpg->kakashi.kakashi_txt, rpg->kakashi.kakashi_rect);
    rpg->enemy.weapon_first = init_sprt(rpg, rpg->enemy.weapon_first,
                        rpg->weapon.shuriken_txt, rpg->weapon.shuriken_rect);
    rpg->enemy.second_clone = init_sprt(rpg, rpg->enemy.second_clone,
                        rpg->kakashi.kakashi_txt, rpg->kakashi.kakashi_rect);
    rpg->enemy.weapon_second = init_sprt(rpg, rpg->enemy.weapon_second,
                        rpg->weapon.shuriken_txt, rpg->weapon.shuriken_rect);
    rpg->enemy.third_clone = init_sprt(rpg, rpg->enemy.third_clone,
                        rpg->kakashi.kakashi_txt, rpg->kakashi.kakashi_rect);
    rpg->enemy.weapon_third = init_sprt(rpg, rpg->enemy.weapon_third,
                        rpg->weapon.shuriken_txt, rpg->weapon.shuriken_rect);
    rpg->enemy.fourth_clone = init_sprt(rpg, rpg->enemy.fourth_clone,
                        rpg->kakashi.kakashi_txt, rpg->kakashi.kakashi_rect);
    rpg->enemy.weapon_fourth = init_sprt(rpg, rpg->enemy.weapon_fourth,
                        rpg->weapon.shuriken_txt, rpg->weapon.shuriken_rect);
    rpg->enemy.fifth_clone = init_sprt(rpg, rpg->enemy.fifth_clone,
                        rpg->kakashi.kakashi_txt, rpg->kakashi.kakashi_rect);
    rpg->enemy.weapon_fifth = init_sprt(rpg, rpg->enemy.weapon_fifth,
                        rpg->weapon.shuriken_txt, rpg->weapon.shuriken_rect);
    init_pos_clone(rpg);
}