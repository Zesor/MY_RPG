/*
** EPITECH PROJECT, 2021
** menu_loop
** File description:
** menu_loop
*/

#include "function.h"
#include "define.h"
#include "struct.h"

void drawing_menu_sprite(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win.window, rpg->back.back_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->back.play_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->back.htp_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->back.option_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->back.quit_sprt, NULL);
    button_quit_handler(rpg);
    light_play_and_htp(rpg);
    light_option(rpg);
}

static void destroy_m(rpg_t *rpg)
{
    sfMusic_destroy(rpg->music.menu_mus);
    sfMusic_destroy(rpg->music.pause_music);
    sfMusic_destroy(rpg->music.peace_music);
}

int menu_loop(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(rpg->win.window)) {
        sfRenderWindow_display(rpg->win.window);
        while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ)) {
                destroy_m(rpg);
                sfRenderWindow_close(rpg->win.window);
            }
            button_play_handler(rpg, event);
            button_htp_handler(rpg, event);
            button_option_handler(rpg, event);
        }
        sfRenderWindow_clear(rpg->win.window, sfBlack);
        drawing_menu_sprite(rpg);
        DRAW_CURSOR;
    }
    return 0;
}