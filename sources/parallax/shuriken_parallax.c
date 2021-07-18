/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** shuriken_parallax
*/

#include "function.h"
#include "struct.h"
#include "define.h"

void press_shuriken_mouse(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
        && rpg->weapon.ready_to_move == 0) {
        rpg->weapon.ready_to_move = 1;
    }
}

void move_shuriken_para(rpg_t *rpg)
{
    if (rpg->weapon.shuriken_pos.x <= rpg->paral.sasuke_pos.x)
        rpg->weapon.shuriken_pos.x += 10;
    if (rpg->weapon.shuriken_pos.x >= rpg->paral.sasuke_pos.x) {
        rpg->weapon.ready_to_move = 0;
        rpg->weapon.shuriken_pos = rpg->paral.naruto_pos;
        sfSprite_setPosition(rpg->weapon.shuriken_sprt,
                        rpg->weapon.shuriken_pos);
    }
}