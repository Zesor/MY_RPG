/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** clock
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void move_objects(rpg_t *rpg)
{
    if (rpg->general_seconds < 0.1 && rpg->quest.side_quest == 8) {
        move_rect(&rpg->enemy.special_rect, 75, 226);
        move_special_enemy(rpg);
        sfClock_restart(rpg->general_clock);
        sfSprite_setTextureRect(rpg->enemy.special_sprt,
                rpg->enemy.special_rect);
    }
}

void using_clock_bis_tuto(rpg_t *rpg)
{
    if (rpg->special.ready_to_move == 1 && rpg->general_seconds < 0.1) {
        move_rect(&rpg->special.special_rect, 70, 421);
        move_special(rpg);
        sfClock_restart(rpg->general_clock);
        sfSprite_setTextureRect(rpg->special.special_sprt,
                rpg->special.special_rect);
    }
    if (rpg->general_seconds < 0.1 && rpg->quest.side_quest == 5) {
        move_rect(&rpg->enemy.weapon_rect, 37, 120);
        move_shuriken_enemy(rpg);
        sfClock_restart(rpg->general_clock);
        sfSprite_setTextureRect(rpg->enemy.weapon_sprt,
                rpg->enemy.weapon_rect);
    }
    move_objects(rpg);
}

void using_clock_tutorial(rpg_t *rpg)
{
    rpg->general_time = sfClock_getElapsedTime(rpg->general_clock);
    rpg->general_seconds = rpg->general_time.microseconds / 1000000.0;
    if (rpg->general_seconds > 0.1)
        sfClock_restart(rpg->general_clock);
    if (rpg->general_seconds < 0.1)
        move_character_up_down(rpg, 5);
    if (rpg->weapon.ready_to_move == 1 && rpg->general_seconds < 0.1) {
        move_rect(&rpg->weapon.shuriken_rect, 37, 120);
        move_shuriken(rpg);
        sfClock_restart(rpg->general_clock);
        sfSprite_setTextureRect(rpg->weapon.shuriken_sprt,
                    rpg->weapon.shuriken_rect);
    }
    using_clock_bis_tuto(rpg);
}