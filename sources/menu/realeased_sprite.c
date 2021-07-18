/*
** EPITECH PROJECT, 2021
** realsed
** File description:
** realses
*/

#include "struct.h"
#include "function.h"
#include "define.h"

void play_realeased_and_htp(rpg_t *rpg)
{
    sfVector2f play_real_pos = {30, 400};
    sfVector2f htp_real_pos = {30, 550};
    sfVector2f option_real_pos = {30, 700};

    rpg->back.play_real = sfTexture_createFromFile("asset/image/play_real.png",
    NULL);
    rpg->back.play_real_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->back.play_real_sprt, play_real_pos);
    sfSprite_setTexture(rpg->back.play_real_sprt, rpg->back.play_real, sfTrue);
    rpg->back.htp_real = sfTexture_createFromFile("asset/image/htp_real.png",
        NULL);
    rpg->back.htp_real_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->back.htp_real_sprt, htp_real_pos);
    sfSprite_setTexture(rpg->back.htp_real_sprt, rpg->back.htp_real, sfTrue);

    rpg->back.opt_real = sfTexture_createFromFile("asset/image/option_real.png",
        NULL);
    rpg->back.opt_real_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->back.opt_real_sprt, option_real_pos);
    sfSprite_setTexture(rpg->back.opt_real_sprt, rpg->back.opt_real, sfTrue);
}

void back_htp(rpg_t *rpg)
{
    sfVector2f back_pos = {30, 950};

    rpg->back.back_htp_xt = sfTexture_createFromFile("asset/image/back_htp.jpg",
    NULL);
    rpg->back.back_htp_sprt = sfSprite_create();
    sfSprite_setTexture(rpg->back.back_htp_sprt, rpg->back.back_htp_xt, sfTrue);

    rpg->back.return_text = sfTexture_createFromFile("asset/image/return.png",
    NULL);
    rpg->back.return_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->back.return_sprt, back_pos);
    sfSprite_setTexture(rpg->back.return_sprt, rpg->back.return_text, sfTrue);
}

void back_htp_bis(rpg_t *rpg)
{
    sfVector2f back_drk_pos = {30, 950};
    sfVector2f htp_key = {330, 0};

    rpg->back.htp_key_tx = sfTexture_createFromFile("asset/image/htp_key.png",
    NULL);
    rpg->back.htp_key_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->back.htp_key_sprt, htp_key);
    sfSprite_setTexture(rpg->back.htp_key_sprt, rpg->back.htp_key_tx, sfTrue);

    rpg->back.return_drk_txt = sfTexture_createFromFile("asset/image/fresh.png",
    NULL);
    rpg->back.return_drk_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->back.return_drk_sprt, back_drk_pos);
    sfSprite_setTexture(rpg->back.return_drk_sprt, rpg->back.return_drk_txt,
    sfTrue);
}