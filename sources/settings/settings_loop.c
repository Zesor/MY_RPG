/*
** EPITECH PROJECT, 2021
** loop
** File description:
** loo
*/

#include "function.h"
#include "define.h"
#include "struct.h"

#define CAT_VOLUME my_strcat(my_itoa(vol_value), "%")
#define CAT_FRAMERATE my_strcat(my_itoa(fmt_value), "FPS")

void event_option_loop(rpg_t *rpg, sfEvent event)
{
    while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ)) {
            sfMusic_destroy(rpg->music.menu_mus);
            sfMusic_destroy(rpg->music.pause_music);
            sfMusic_destroy(rpg->music.peace_music);
            sfRenderWindow_close(rpg->win.window);
        }
    }
}

static void draw_sprite_option_loop(rpg_t *rpg, sfText *vol_text,
                                    int vol_value, unsigned int fmt_value)
{
    sfRenderWindow_clear(rpg->win.window, sfBlack);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->opt.fond_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->opt.vol_spr, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->opt.frmt_spr, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->opt.ret_spr, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->opt.vol_incr_s, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->opt.vol_decr_s, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->opt.fmt_incr_s, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->opt.fmt_decr_s, NULL);
    sfRenderWindow_drawText(rpg->win.window, vol_text, NULL);
    sfMusic_setVolume(rpg->music.menu_mus, vol_value);
    sfRenderWindow_setFramerateLimit(rpg->win.window, fmt_value);
    settings_retur(rpg);
    DRAW_CURSOR;
}

int option_loop(rpg_t *rpg)
{
    sfEvent event;
    sfVector2f fmt_vector = {1355, 550};
    sfText *fmt_text;
    unsigned int fmt_value = 30;
    sfVector2f vol_vector = {500, 550};
    sfText *vol_text;
    int vol_value = 20;

    while (sfRenderWindow_isOpen(rpg->win.window)) {
        event_option_loop(rpg, event);
        vol_text = init_txt_color(40, vol_vector, CAT_VOLUME, sfBlack);
        vol_value = change_volume(vol_value, rpg);
        fmt_text = init_txt_color(40, fmt_vector, CAT_FRAMERATE, sfBlack);
        fmt_value = change_framerate(fmt_value, rpg);
        draw_sprite_option_loop(rpg, vol_text, vol_value, fmt_value);
        sfRenderWindow_drawText(rpg->win.window, fmt_text, NULL);
        sfRenderWindow_display(rpg->win.window);
    }
    return 0;
}