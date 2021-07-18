/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** ramen
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void activate_ramen(rpg_t *rpg)
{
    if (rpg->game.team_7_pos.x >= 947 && rpg->game.team_7_pos.x <= 1032 &&
        rpg->game.team_7_pos.y >= 821 && rpg->game.team_7_pos.y <= 836 &&
        sfKeyboard_isKeyPressed(sfKeyEnter) && rpg->invent.ramen_shop == 0
        && rpg->quest.side_quest == 3) {
        rpg->quest.side_quest++;
        rpg->invent.ramen_shop++;
        rpg->invent.ramen++;
        ramen_loop(rpg);
        }
}

void analyse_event_ramen(rpg_t *rpg, sfEvent event)
{
    while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyN)) {
            sfMusic_destroy(rpg->music.menu_mus);
            sfMusic_destroy(rpg->music.peace_music);
            sfMusic_destroy(rpg->music.pause_music);
            sfRenderWindow_close(rpg->win.window);
        }
        launch_pause(rpg);
    }
}

int ramen_loop(rpg_t *rpg)
{
    sfEvent event;
    rpg->general_clock = sfClock_create();

    dialogue_ramen(rpg);
    while (sfRenderWindow_isOpen(rpg->win.window)) {
        analyse_event_ramen(rpg, event);
        update_view(rpg);
    }
}