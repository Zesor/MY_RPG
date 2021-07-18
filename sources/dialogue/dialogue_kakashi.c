/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** dialogue_kakashi
*/

#include "struct.h"
#include "define.h"
#include "function.h"

static int check_dialogue(rpg_t *rpg)
{
    if (rpg->dialogue.real_dialogue == 6 && rpg->quest.side_quest == 1 ||
        rpg->dialogue.real_dialogue == 10 && rpg->quest.side_quest == 4 ||
        rpg->dialogue.real_dialogue == 14 && rpg->quest.side_quest == 6)
        return (1);
    return (0);
}

void key_move(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) ||
        sfKeyboard_isKeyPressed(sfKeyRight) ||
        sfKeyboard_isKeyPressed(sfKeyDown) ||
        sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (rpg->dialogue.speaking == 0)
            rpg->dialogue.speaking = 1;
        else
            rpg->dialogue.speaking = 0;
        if (rpg->dialogue.real_dialogue <= 13)
            rpg->dialogue.real_dialogue++;
    }
}

static void event_dialogue_kakashi(rpg_t *rpg, sfEvent event)
{
    while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyN)) {
            sfMusic_destroy(rpg->music.menu_mus);
            sfMusic_destroy(rpg->music.pause_music);
            sfMusic_destroy(rpg->music.peace_music);
            sfRenderWindow_close(rpg->win.window);
        }
        key_move(rpg);
    }
}

void dialogue_kakashi(rpg_t *rpg)
{
    sfEvent event;


    sfSprite_setPosition(rpg->dialogue.kakashi_sprt, (sfVector2f) {1400, 200});
    sfRenderWindow_setView(rpg->win.window,
        sfRenderWindow_getDefaultView(rpg->win.window));
    while (sfRenderWindow_isOpen(rpg->win.window)) {
        event_dialogue_kakashi(rpg, event);
        if (check_dialogue(rpg) == 1)
            break;
        draw_dialogue_kakashi(rpg);
    }
}