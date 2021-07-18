/*
** EPITECH PROJECT, 2021
** htp
** File description:
** htp
*/

#include "define.h"
#include "struct.h"
#include "function.h"

static void destroy_m(rpg_t *rpg)
{
    sfMusic_destroy(rpg->music.menu_mus);
    sfMusic_destroy(rpg->music.pause_music);
    sfMusic_destroy(rpg->music.peace_music);
}

int htp_loop(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(rpg->win.window)) {
        sfRenderWindow_display(rpg->win.window);
        while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ)) {
                destroy_m(rpg);
                sfRenderWindow_close(rpg->win.window);
            }
        }
        sfRenderWindow_clear(rpg->win.window, sfBlack);
        sfRenderWindow_drawSprite(rpg->win.window, rpg->back.back_htp_sprt,
        NULL);
        sfRenderWindow_drawSprite(rpg->win.window, rpg->back.htp_key_sprt,
        NULL);
        sfRenderWindow_drawSprite(rpg->win.window, rpg->back.return_sprt, NULL);
        htp_button(rpg);
        DRAW_CURSOR;
    }
    return 0;
}