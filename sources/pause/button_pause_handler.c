/*
** EPITECH PROJECT, 2021
** button
** File description:
** button
*/

#include "define.h"
#include "function.h"
#include "struct.h"

void light_button(rpg_t *rpg)
{
    sfVector2f mouse = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect menu_drk_pos = BOUNDS(rpg->pause.menu_drk_sprt);
    sfFloatRect *menu_drk_rect = &menu_drk_pos;

    if (sfFloatRect_contains(menu_drk_rect, mouse.x, mouse.y))
        sfRenderWindow_drawSprite(rpg->win.window, rpg->pause.menu_drk_sprt,
        NULL);
}

void pause_quit_handler(rpg_t *rpg)
{
    sfVector2f mouse = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect quit_drk_pos = BOUNDS(rpg->pause.quit_drk_sprt);
    sfFloatRect *quit_drk_rect = &quit_drk_pos;

    if (sfFloatRect_contains(quit_drk_rect, mouse.x, mouse.y))
        sfRenderWindow_drawSprite(rpg->win.window, rpg->pause.quit_drk_sprt,
        NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(quit_drk_rect, mouse.x, mouse.y)) {
            sfMusic_destroy(rpg->music.menu_mus);
            sfMusic_destroy(rpg->music.pause_music);
            sfMusic_destroy(rpg->music.peace_music);
            sfRenderWindow_close(rpg->win.window);
    }
}

void pause_menu_handler(rpg_t *rpg, sfEvent event)
{
    sfVector2f mouse = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect menu_drk_pos = BOUNDS(rpg->pause.menu_drk_sprt);
    sfFloatRect *menu_drk_rect = &menu_drk_pos;

    switch (event.type) {
    case sfEvtMouseButtonReleased:
        if (event.mouseButton.button == sfMouseLeft
                && sfFloatRect_contains(menu_drk_rect, mouse.x, mouse.y)) {
            sfRenderWindow_drawSprite(rpg->win.window, rpg->pause.menu_real_spt,
                    NULL);
            sfMusic_pause(rpg->music.pause_music);
            menu_loop(rpg);
        }
        break;
    default:
        break;
    }
}