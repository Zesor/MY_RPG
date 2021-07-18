/*
** EPITECH PROJECT, 2021
** init_pause
** File description:
** init_pause
*/

#include "define.h"
#include "struct.h"
#include "function.h"

void init_pause_sprt(rpg_t *rpg)
{
    sfVector2f menu_pos = {830, 400};
    sfVector2f quit_pos = {830, 700};

    rpg->pause.menu_text = sfTexture_createFromFile("asset/image/back_paus.jpg",
    NULL);
    rpg->pause.menu_sprt = sfSprite_create();
    sfSprite_setTexture(rpg->pause.menu_sprt, rpg->pause.menu_text, sfTrue);
    rpg->pause.menu_but_text = sfTexture_createFromFile("asset/image/menu.png",
    NULL);

    rpg->pause.menu_but_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->pause.menu_but_sprt, menu_pos);
    sfSprite_setTexture(rpg->pause.menu_but_sprt, rpg->pause.menu_but_text,
    sfTrue);

    rpg->pause.quit_text = sfTexture_createFromFile("asset/image/quit.png",
    NULL);
    rpg->pause.quit_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->pause.quit_sprt, quit_pos);
    sfSprite_setTexture(rpg->pause.quit_sprt, rpg->pause.quit_text, sfTrue);
}

void init_drk_pause_sprt(rpg_t *rpg)
{
    sfVector2f menu_drk_pos = {830, 400};
    sfVector2f quit_drk_pos = {830, 700};

    rpg->pause.menu_drk_t = sfTexture_createFromFile("asset/image/menu_drk.png",
    NULL);
    rpg->pause.menu_drk_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->pause.menu_drk_sprt, menu_drk_pos);
    sfSprite_setTexture(rpg->pause.menu_drk_sprt, rpg->pause.menu_drk_t,
    sfTrue);

    rpg->pause.quit_drk_t = sfTexture_createFromFile("asset/image/quit_drk.png",
    NULL);
    rpg->pause.quit_drk_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->pause.quit_drk_sprt, quit_drk_pos);
    sfSprite_setTexture(rpg->pause.quit_drk_sprt, rpg->pause.quit_drk_t,
    sfTrue);
}

void init_real_sprt(rpg_t *rpg)
{
    sfVector2f quit_real_t = {830, 400};

    rpg->pause.menu_real = sfTexture_createFromFile("asset/image/menu_real.png",
    NULL);
    rpg->pause.menu_real_spt = sfSprite_create();
    sfSprite_setPosition(rpg->pause.menu_real_spt, quit_real_t);
    sfSprite_setTexture(rpg->pause.menu_real_spt, rpg->pause.menu_real,
    sfTrue);
}