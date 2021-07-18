/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** init_parallax
*/

#include "struct.h"

void init_parallax(rpg_t *rpg)
{
    rpg->paral.f_back_text = sfTexture_createFromFile("asset/image/blue.jpg",
    NULL);
    rpg->paral.f_back_sprt = sfSprite_create();
    sfSprite_setTexture(rpg->paral.f_back_sprt, rpg->paral.f_back_text, sfTrue);

    rpg->paral.mount_text = sfTexture_createFromFile("asset/image/mount.png",
    NULL);
    rpg->paral.mount_sprt = sfSprite_create();
    rpg->paral.mount_pos.x = 0;
    rpg->paral.mount_pos.y = 640;
    sfSprite_setTexture(rpg->paral.mount_sprt, rpg->paral.mount_text, sfTrue);

    rpg->paral.w_mount_text =
        sfTexture_createFromFile("asset/image/w_mount.png", NULL);
    rpg->paral.w_mount_sprt = sfSprite_create();
    rpg->paral.w_pos_mount.x = 0;
    rpg->paral.w_pos_mount.y = 640;
    sfSprite_setTexture(rpg->paral.w_mount_sprt,
        rpg->paral.w_mount_text, sfTrue);
}

void init_paral_object(rpg_t *rpg)
{
    rpg->paral.cloud_text = sfTexture_createFromFile("asset/image/cloud.png",
    NULL);
    rpg->paral.cloud_sprt = sfSprite_create();
    rpg->paral.cloud_pos.x = 0;
    rpg->paral.cloud_pos.y = 130;
    sfSprite_setTexture(rpg->paral.cloud_sprt, rpg->paral.cloud_text, sfTrue);
}