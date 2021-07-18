/*
** EPITECH PROJECT, 2021
** infiffnte
** File description:
** infinte
*/

#include "define.h"
#include "function.h"
#include "struct.h"

void light_play_and_htp(rpg_t *rpg)
{
    sfVector2f mouse = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect play_pos = BOUNDS(rpg->back.play_drk_sprt);
    sfFloatRect *play_rect = &play_pos;

    if (sfFloatRect_contains(play_rect, mouse.x, mouse.y))
        sfRenderWindow_drawSprite(rpg->win.window, rpg->back.play_drk_sprt,
            NULL);

    sfVector2f mouse1 = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect htp_pos = BOUNDS(rpg->back.htp_drk_sprt);
    sfFloatRect *htp_rect = &htp_pos;

    if (sfFloatRect_contains(htp_rect, mouse1.x, mouse1.y))
        sfRenderWindow_drawSprite(rpg->win.window, rpg->back.htp_drk_sprt,
            NULL);
}

void light_option(rpg_t *rpg)
{
    sfVector2f mouse1 = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect option_pos = BOUNDS(rpg->back.opt_drk_sprt);
    sfFloatRect *option_rect = &option_pos;

    if (sfFloatRect_contains(option_rect, mouse1.x, mouse1.y))
        sfRenderWindow_drawSprite(rpg->win.window, rpg->back.opt_drk_sprt,
            NULL);
}