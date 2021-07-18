/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** dialog
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void draw_dialogue(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->win.window, sfTransparent);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.fond_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.team7_sprt, NULL);
    move_kakashi(rpg);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->kakashi.kakashi_sprt,
                        NULL);
    print_characters(rpg);
    sfRenderWindow_drawRectangleShape(rpg->win.window, rpg->dialogue.shape,
                        NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->dialogue.key_sprt, NULL);
    text_speaking(rpg, nb_dialogue[rpg->dialogue.nb_dialogue]
                [rpg->dialogue.speaking]);
    text_dialogue(rpg, nb_dialogue[rpg->dialogue.nb_dialogue]
                [rpg->dialogue.real_dialogue]);
    sfRenderWindow_display(rpg->win.window);
}

int check_dialogue(rpg_t *rpg)
{
    if (rpg->dialogue.real_dialogue == 8 && rpg->quest.side_quest == 1 ||
        rpg->dialogue.real_dialogue == 12 && rpg->quest.side_quest == 3 ||
        rpg->dialogue.real_dialogue == 14 && rpg->quest.side_quest == 6)
        return (1);
    if (rpg->dialogue.real_dialogue == 18) {
        rpg->life.remaining_life = 10;
        rpg->life.size.x = 150;
        rpg->mana.size.x = 0;
        sfRectangleShape_setSize(rpg->life.shape, rpg->life.size);
        sfRectangleShape_setSize(rpg->mana.shape, rpg->mana.size);
        sfMusic_play(rpg->music.peace_music);
        rpg->quest.side_quest = 1;
        rpg->quest.nb_quest = 1;
        rpg->dialogue.nb_dialogue = 3;
        rpg->dialogue.real_dialogue = 2;
        rpg->dialogue.speaking = 0;
        game_loop(rpg);
    }
    return (0);
}

void mouse_left(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) ||
        sfKeyboard_isKeyPressed(sfKeyRight) ||
        sfKeyboard_isKeyPressed(sfKeyDown) ||
        sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (rpg->dialogue.speaking == 0 || rpg->dialogue.real_dialogue == 7)
            rpg->dialogue.speaking = 1;
        else
            rpg->dialogue.speaking = 0;
        if (rpg->dialogue.real_dialogue <= 17)
            rpg->dialogue.real_dialogue++;
    }
}

void event_dialogue(rpg_t *rpg, sfEvent event)
{
    while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyN)) {
            sfMusic_destroy(rpg->music.menu_mus);
            sfMusic_destroy(rpg->music.pause_music);
            sfMusic_destroy(rpg->music.peace_music);
            sfRenderWindow_close(rpg->win.window);
        }
        mouse_left(rpg);
    }
}

void dialogue_tutorial(rpg_t *rpg)
{
    sfEvent event;

    sfRenderWindow_setView(rpg->win.window,
        sfRenderWindow_getDefaultView(rpg->win.window));
    while (sfRenderWindow_isOpen(rpg->win.window)) {
        event_dialogue(rpg, event);
        if (check_dialogue(rpg) == 1)
            break;
        draw_dialogue(rpg);
    }
}