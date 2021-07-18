/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** shuriken_clone
*/

#include "define.h"
#include "struct.h"
#include "function.h"

sfVector2f move_shuriken_bis_clone(rpg_t *rpg, sfVector2f weapon,
sfVector2f clone)
{
    if (weapon.y <= rpg->game.team_7_pos.y && weapon.y <= clone.y + 200)
        weapon.y += 5;
    if (weapon.x == rpg->game.team_7_pos.x &&
        weapon.y == rpg->game.team_7_pos.y ||
        weapon.x <= clone.x - 200 || weapon.x >= clone.x + 200 ||
        weapon.y <= clone.y - 200 || weapon.y >= clone.y + 200) {
        weapon = clone;
    }
    return weapon;
}

sfVector2f move_shuriken_clone(rpg_t *rpg, sfVector2f weapon, sfVector2f clone, sfSprite *sprite)
{
    if (weapon.x <= rpg->game.team_7_pos.x && weapon.x <= clone.x + 200)
        weapon.x += 5;
    if (weapon.y >= rpg->game.team_7_pos.y && weapon.y >= clone.y - 200)
        weapon.y -= 5;
    if (weapon.x >= rpg->game.team_7_pos.x && weapon.x >= clone.x - 200)
        weapon.x -= 5;
    weapon = move_shuriken_bis_clone(rpg, weapon, clone);
    sfSprite_setPosition(sprite, weapon);
    return weapon;
}

void clone_shuriken(rpg_t *rpg)
{
    if (rpg->general_seconds < 0.1) {
        rpg->enemy.weapon_first_pos = move_shuriken_clone(rpg,
                    rpg->enemy.weapon_first_pos, rpg->enemy.clone_first_pos,
                    rpg->enemy.weapon_first);
        rpg->enemy.weapon_second_pos = move_shuriken_clone(rpg,
                    rpg->enemy.weapon_second_pos, rpg->enemy.clone_second_pos,
                    rpg->enemy.weapon_second);
        rpg->enemy.weapon_third_pos = move_shuriken_clone(rpg,
                    rpg->enemy.weapon_third_pos, rpg->enemy.clone_third_pos,
                    rpg->enemy.weapon_third);
        rpg->enemy.weapon_fourth_pos = move_shuriken_clone(rpg,
                    rpg->enemy.weapon_fourth_pos, rpg->enemy.clone_fourth_pos,
                    rpg->enemy.weapon_fourth);
        rpg->enemy.weapon_fifth_pos = move_shuriken_clone(rpg,
                    rpg->enemy.weapon_fifth_pos, rpg->enemy.clone_fifth_pos,
                    rpg->enemy.weapon_fifth);
        sfClock_restart(rpg->general_clock);
        }
}