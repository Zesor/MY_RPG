/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** change_volume
*/

#include "define.h"
#include "struct.h"
#include "function.h"

int change_volume(int idx, rpg_t *rpg)
{
    sfVector2f mouse1 = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect return_pos1 = BOUNDS(rpg->opt.vol_incr_s);
    sfFloatRect *return_rect1 = &return_pos1;
    sfVector2f mouse2 = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect return_pos2 = BOUNDS(rpg->opt.vol_decr_s);
    sfFloatRect *return_rect2 = &return_pos2;

    if (sfFloatRect_contains(return_rect1, mouse1.x, mouse1.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && idx < 100)
            idx += 1;
    }
    if (sfFloatRect_contains(return_rect2, mouse2.x, mouse2.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && idx > 5)
            idx -= 1;
    }
    return idx;
}