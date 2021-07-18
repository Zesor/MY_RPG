/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** shop
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void activate_shop(rpg_t *rpg)
{
    if (rpg->game.team_7_pos.x >= 320 && rpg->game.team_7_pos.x <= 340 &&
        rpg->game.team_7_pos.y >= 845 && rpg->game.team_7_pos.y <= 855 &&
        sfKeyboard_isKeyPressed(sfKeyEnter) && rpg->invent.shop == 0
        && rpg->quest.side_quest == 2) {
        rpg->quest.side_quest++;
        rpg->invent.shop++;
        rpg->invent.scroll++;
        shop_loop(rpg);
    }
}

void analyse_event_shop(rpg_t *rpg, sfEvent event)
{
    while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyN)) {
            sfMusic_destroy(rpg->music.peace_music);
            sfMusic_destroy(rpg->music.pause_music);
            sfMusic_destroy(rpg->music.menu_mus);
            sfMusic_destroy(rpg->music.ending_music);
            sfRenderWindow_close(rpg->win.window);
        }
        launch_pause(rpg);
    }
}

int shop_loop(rpg_t *rpg)
{
    sfEvent event;
    rpg->general_clock = sfClock_create();

    dialogue_shop(rpg);
    while (sfRenderWindow_isOpen(rpg->win.window)) {
        analyse_event_shop(rpg, event);
        update_view(rpg);
    }
}