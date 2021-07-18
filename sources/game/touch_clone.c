/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** touch_clone
*/

#include "struct.h"
#include "define.h"
#include "function.h"

sfVector2f clone_character_sp(rpg_t *rpg, sfSprite *clone,
                            sfVector2f size_life, sfRectangleShape *sp)
{
    sfFloatRect weapon = sfSprite_getGlobalBounds(clone);
    sfFloatRect character = sfSprite_getGlobalBounds(rpg->special.special_sprt);
    const sfFloatRect *weapons = &weapon;
    const sfFloatRect *characters = &character;

    if (sfFloatRect_intersects(weapons, characters, NULL)) {
        rpg->weapon.ready_to_move = 0;
        size_life.x = 0;
        sfRectangleShape_setSize(sp, size_life);
        sfSprite_setPosition(rpg->weapon.shuriken_sprt, rpg->game.team_7_pos);
    }
    return size_life;
}

sfVector2f clone_character(rpg_t *rpg, sfSprite *clone,
                            sfVector2f size_life, sfRectangleShape *sp)
{
    sfFloatRect weapon = sfSprite_getGlobalBounds(clone);
    sfFloatRect character = sfSprite_getGlobalBounds(rpg->weapon.shuriken_sprt);
    const sfFloatRect *weapons = &weapon;
    const sfFloatRect *characters = &character;

    if (sfFloatRect_intersects(weapons, characters, NULL)) {
        rpg->weapon.ready_to_move = 0;
        size_life.x -= 25;
        sfRectangleShape_setSize(sp, size_life);
        sfSprite_setPosition(rpg->weapon.shuriken_sprt, rpg->game.team_7_pos);
    }
    return size_life;
}

void check_enemy_fight(rpg_t *rpg)
{
    rpg->enemy.size_first = clone_character(rpg, rpg->enemy.first_clone,
                    rpg->enemy.size_first, rpg->enemy.rect_first);
    rpg->enemy.size_second = clone_character(rpg, rpg->enemy.second_clone,
                    rpg->enemy.size_second, rpg->enemy.rect_second);
    rpg->enemy.size_third = clone_character(rpg, rpg->enemy.third_clone,
                    rpg->enemy.size_third, rpg->enemy.rect_third);
    rpg->enemy.size_fourth = clone_character(rpg, rpg->enemy.fourth_clone,
                    rpg->enemy.size_fourth, rpg->enemy.rect_fourth);
    rpg->enemy.size_fifth = clone_character(rpg, rpg->enemy.fifth_clone,
                    rpg->enemy.size_fifth, rpg->enemy.rect_fifth);
    rpg->enemy.size_first = clone_character_sp(rpg, rpg->enemy.first_clone,
                    rpg->enemy.size_first, rpg->enemy.rect_first);
    rpg->enemy.size_second = clone_character_sp(rpg, rpg->enemy.second_clone,
                    rpg->enemy.size_second, rpg->enemy.rect_second);
    rpg->enemy.size_third = clone_character_sp(rpg, rpg->enemy.third_clone,
                    rpg->enemy.size_third, rpg->enemy.rect_third);
    rpg->enemy.size_fourth = clone_character_sp(rpg, rpg->enemy.fourth_clone,
                    rpg->enemy.size_fourth, rpg->enemy.rect_fourth);
    rpg->enemy.size_fifth = clone_character_sp(rpg, rpg->enemy.fifth_clone,
                    rpg->enemy.size_fifth, rpg->enemy.rect_fifth);
}