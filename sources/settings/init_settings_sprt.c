/*
** EPITECH PROJECT, 2021
** spr
** File description:
** sprt
*/

#include "define.h"
#include "struct.h"
#include "function.h"

#define ASSET_RET_OPT "asset/image/return_opt.png"

void seetings_sprt(rpg_t *rpg)
{
    sfVector2f volume = {350, 300};
    sfVector2f framerate = {1200, 300};

    rpg->opt.fond_text = sfTexture_createFromFile("asset/image/option_fond.jpg"
    , NULL);
    rpg->opt.fond_sprt = sfSprite_create();
    sfSprite_setTexture(rpg->opt.fond_sprt, rpg->opt.fond_text, sfTrue);

    rpg->opt.vol_txt = sfTexture_createFromFile("asset/option/volume.png",
    NULL);
    rpg->opt.vol_spr = sfSprite_create();
    sfSprite_setPosition(rpg->opt.vol_spr, volume);
    sfSprite_setTexture(rpg->opt.vol_spr, rpg->opt.vol_txt, sfTrue);

    rpg->opt.frmt_txt = sfTexture_createFromFile("asset/option/framerate.png",
    NULL);
    rpg->opt.frmt_spr = sfSprite_create();
    sfSprite_setPosition(rpg->opt.frmt_spr, framerate);
    sfSprite_setTexture(rpg->opt.frmt_spr, rpg->opt.frmt_txt, sfTrue);
}

void return_settings_sprite(rpg_t *rpg)
{
    sfVector2f return_pos = {30, 950};

    rpg->opt.ret_txt = sfTexture_createFromFile(ASSET_RET_OPT, NULL);
    rpg->opt.ret_spr = sfSprite_create();
    sfSprite_setPosition(rpg->opt.ret_spr, return_pos);
    sfSprite_setTexture(rpg->opt.ret_spr, rpg->opt.ret_txt, sfTrue);
}