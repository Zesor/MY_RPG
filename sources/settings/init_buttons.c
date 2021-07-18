/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** init_buttons
*/

#include "define.h"
#include "function.h"
#include "struct.h"

static const char *increase_volume = "asset/option/vol_increase.png";
static const char *increase_framerate = "asset/option/fmt_increase.png";
static const char *decrease_volume = "asset/option/vol_decrease.png";
static const char *decrease_framerate = "asset/option/fmt_decrease.png";

void init_volume_buttons(rpg_t *rpg)
{
    sfVector2f increase = {400, 450};
    sfVector2f decrease = {600, 480};

    rpg->opt.vol_incr_t = sfTexture_createFromFile(increase_volume, NULL);
    rpg->opt.vol_incr_s = sfSprite_create();
    sfSprite_setPosition(rpg->opt.vol_incr_s, increase);
    sfSprite_setTexture(rpg->opt.vol_incr_s, rpg->opt.vol_incr_t, sfTrue);

    rpg->opt.vol_decr_t = sfTexture_createFromFile(decrease_volume, NULL);
    rpg->opt.vol_decr_s = sfSprite_create();
    sfSprite_setPosition(rpg->opt.vol_decr_s, decrease);
    sfSprite_setTexture(rpg->opt.vol_decr_s, rpg->opt.vol_decr_t, sfTrue);
}

void init_framerate_buttons(rpg_t *rpg)
{
    sfVector2f increase = {1300, 450};
    sfVector2f decrease = {1500, 480};

    rpg->opt.fmt_incr_t = sfTexture_createFromFile(increase_framerate, NULL);
    rpg->opt.fmt_incr_s = sfSprite_create();
    sfSprite_setPosition(rpg->opt.fmt_incr_s, increase);
    sfSprite_setTexture(rpg->opt.fmt_incr_s, rpg->opt.fmt_incr_t, sfTrue);

    rpg->opt.fmt_decr_t = sfTexture_createFromFile(decrease_framerate, NULL);
    rpg->opt.fmt_decr_s = sfSprite_create();
    sfSprite_setPosition(rpg->opt.fmt_decr_s, decrease);
    sfSprite_setTexture(rpg->opt.fmt_decr_s, rpg->opt.fmt_decr_t, sfTrue);
}