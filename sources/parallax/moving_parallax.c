/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** moving_parallax
*/

#include "function.h"
#include "struct.h"

void moving_parallax(rpg_t *rpg)
{
    rpg->general_clock = sfClock_create();

    if (rpg->general_clock)
        rpg->paral.w_pos_mount.x -= 0.4;
    if (rpg->paral.w_pos_mount.x < -1920)
        rpg->paral.w_pos_mount.x = 0;
    sfSprite_setPosition(rpg->paral.w_mount_sprt, rpg->paral.w_pos_mount);

    if (rpg->general_clock)
        rpg->paral.mount_pos.x -= 0.2;
    if (rpg->paral.mount_pos.x < -1920)
        rpg->paral.mount_pos.x = 0;
    sfSprite_setPosition(rpg->paral.mount_sprt, rpg->paral.mount_pos);

    if (rpg->general_clock)
        rpg->paral.cloud_pos.x -= 0.3;
    if (rpg->paral.cloud_pos.x < -1920)
        rpg->paral.cloud_pos.x = 0;
    sfSprite_setPosition(rpg->paral.cloud_sprt, rpg->paral.cloud_pos);
}