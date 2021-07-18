/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** change_framerate
*/

#include "struct.h"
#include "define.h"
#include "function.h"

int change_framerate(unsigned int idx, rpg_t *rpg)
{
    sfVector2f mouse1 = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect return_pos1 = BOUNDS(rpg->opt.fmt_incr_s);
    sfFloatRect *return_rect1 = &return_pos1;
    sfVector2f mouse2 = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect return_pos2 = BOUNDS(rpg->opt.fmt_decr_s);
    sfFloatRect *return_rect2 = &return_pos2;

    if (sfFloatRect_contains(return_rect1, mouse1.x, mouse1.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && idx < 240)
            idx += 1;
    }
    if (sfFloatRect_contains(return_rect2, mouse2.x, mouse2.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && idx > 10)
            idx -= 1;
    }
    return idx;
}