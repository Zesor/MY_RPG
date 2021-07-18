/*
** EPITECH PROJECT, 2021
** handler
** File description:
** handkler
*/

#include "struct.h"
#include "function.h"
#include "define.h"

void button_quit_handler(rpg_t *rpg)
{
    sfVector2f mouse = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect quit_pos = BOUNDS(rpg->back.quit_sprt);
    sfFloatRect *quit_rect = &quit_pos;

    if (sfFloatRect_contains(quit_rect, mouse.x, mouse.y))
        sfRenderWindow_drawSprite(rpg->win.window, rpg->back.quit_drk_sprt,
        NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(quit_rect, mouse.x, mouse.y)) {
            sfMusic_destroy(rpg->music.menu_mus);
            sfMusic_destroy(rpg->music.pause_music);
            sfMusic_destroy(rpg->music.peace_music);
            sfRenderWindow_close(rpg->win.window);
        }
}

void button_play_handler(rpg_t *rpg, sfEvent event)
{
    sfVector2f mouse = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect play_pos = BOUNDS(rpg->back.play_drk_sprt);
    sfFloatRect *play_rect = &play_pos;

    switch (event.type) {
    case sfEvtMouseButtonReleased:
        if (event.mouseButton.button == sfMouseLeft &&
                sfFloatRect_contains(play_rect, mouse.x, mouse.y)) {
            sfRenderWindow_drawSprite(rpg->win.window, rpg->back.play_real_sprt,
                    NULL);
            sfMusic_pause(rpg->music.menu_mus);
            ask_for_tutorial_loop(rpg);
        }
        break;
    default:
        break;
    }
}

void button_htp_handler(rpg_t *rpg, sfEvent event)
{
    sfVector2f mous1 = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect htp_pos = BOUNDS(rpg->back.htp_sprite);
    sfFloatRect *htp_rect = &htp_pos;

    switch (event.type) {
    case sfEvtMouseButtonReleased:
        if (event.mouseButton.button == sfMouseLeft &&
                sfFloatRect_contains(htp_rect, mous1.x, mous1.y)) {
            sfRenderWindow_drawSprite(rpg->win.window, rpg->back.htp_real_sprt,
                NULL);
            sfMusic_pause(rpg->music.peace_music);
            htp_loop(rpg);
        }
        break;
    default:
        break;
    }
}

void button_option_handler(rpg_t *rpg, sfEvent event)
{
    sfVector2f mous1 = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect option_pos = BOUNDS(rpg->back.option_sprt);
    sfFloatRect *option_rect = &option_pos;

    switch (event.type) {
    case sfEvtMouseButtonReleased:
        if (event.mouseButton.button == sfMouseLeft &&
                sfFloatRect_contains(option_rect, mous1.x, mous1.y)) {
            sfRenderWindow_drawSprite(rpg->win.window, rpg->back.opt_real_sprt,
                NULL);
            option_loop(rpg);
        }
        break;
    default:
        break;
    }
}