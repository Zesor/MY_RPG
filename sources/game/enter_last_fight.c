/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** enter_last_fight
*/

#include "struct.h"
#include "function.h"

void enter_to_last_fight(rpg_t *rpg)
{
    if (rpg->game.team_7_pos.x >= 968 && rpg->game.team_7_pos.x <= 1013
            && rpg->game.team_7_pos.y >= 200 && rpg->game.team_7_pos.y <= 210
        && rpg->quest.side_quest == 7) {
        sfMusic_pause(rpg->music.peace_music);
        parallax_loop(rpg);
    }
}