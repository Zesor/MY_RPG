/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** general_collision
*/

#include "struct.h"
#include "define.h"
#include "function.h"

int general_collision_left_right(rpg_t *rpg, int x, int w, int y)
{
    if (rpg->game.team_7_pos.x >= x && rpg->game.team_7_pos.x <= x + 10
        && rpg->game.team_7_pos.y >= y && rpg->game.team_7_pos.y <= w)
        return 1;
    else
        return 0;
}

int general_collision_up_down(rpg_t *rpg, int x, int w, int y)
{
    if (rpg->game.team_7_pos.x >= x && rpg->game.team_7_pos.x <= w
        && rpg->game.team_7_pos.y >= y && rpg->game.team_7_pos.y <= y + 10)
        return 1;
    else
        return 0;
}