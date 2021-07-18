/*
** EPITECH PROJECT, 2021
** pause_loop
** File description:
** pause_loop
*/

#include "function.h"
#include "struct.h"
#include "define.h"

#define NO_CURSOR sfRenderWindow_setMouseCursorVisible(rpg->win.window, sfFalse)

void launch_pause(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        NO_CURSOR;
        sfRenderWindow_setView(rpg->win.window,
        sfRenderWindow_getDefaultView(rpg->win.window));
        sfMusic_pause(rpg->music.peace_music);
        sfMusic_play(rpg->music.pause_music);
        pause_loop(rpg);
    }
}

static void drawing_pause_sprite(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win.window, rpg->pause.menu_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->pause.menu_but_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->pause.quit_sprt, NULL);
    pause_quit_handler(rpg);
    light_button(rpg);
}

static void destroy_m(rpg_t *rpg)
{
    sfMusic_destroy(rpg->music.menu_mus);
    sfMusic_destroy(rpg->music.pause_music);
    sfMusic_destroy(rpg->music.peace_music);
}

void pause_loop(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(rpg->win.window)) {
        sfRenderWindow_display(rpg->win.window);
        while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ)) {
                destroy_m(rpg);
                sfRenderWindow_close(rpg->win.window);
            }
            if (sfKeyboard_isKeyPressed(sfKeyW)) {
                sfMusic_pause(rpg->music.pause_music);
                sfMusic_play(rpg->music.peace_music);
                game_loop(rpg);
            }
            pause_menu_handler(rpg, event);
        }
        sfRenderWindow_clear(rpg->win.window, sfBlack);
        drawing_pause_sprite(rpg);
        DRAW_CURSOR;
    }
}