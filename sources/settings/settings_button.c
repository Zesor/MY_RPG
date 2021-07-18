/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** settings_button
*/

#include "function.h"
#include "define.h"
#include "struct.h"

void settings_retur(rpg_t *rpg)
{
    sfVector2f mous1 = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect return_pos = BOUNDS(rpg->back.return_sprt);
    sfFloatRect *return_rect = &return_pos;

    if (sfFloatRect_contains(return_rect, mous1.x, mous1.y)) {
        sfRenderWindow_drawSprite(rpg->win.window, rpg->back.return_drk_sprt,
            NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            menu_loop(rpg);
    }
}