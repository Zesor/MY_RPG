/*
** EPITECH PROJECT, 2021
** graphique
** File description:
** view
*/

#include "define.h"
#include "struct.h"
#include "function.h"

void update_view(rpg_t *rpg)
{
    sfVector2f pos = {rpg->game.team_7_pos.x + 20, rpg->game.team_7_pos.y + 15};

    sfView_setCenter(rpg->game.view, pos);
    sfRenderWindow_setView(rpg->win.window, rpg->game.view);
}

void init_view(rpg_t *rpg)
{
    sfFloatRect rect = {0, 0, 0, 0};

    rect.height = 500;
    rect.width = 900;
    rpg->game.view = sfView_createFromRect(rect);
}