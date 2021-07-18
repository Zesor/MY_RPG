/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** teuchi_dialogue
*/

#include "struct.h"
#include "define.h"
#include "function.h"

static void draw_dialogue_ramen(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->win.window, sfTransparent);
    print_characters_ramen(rpg);
    sfRenderWindow_drawRectangleShape(rpg->win.window, rpg->dialogue.shape,
                        NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->dialogue.key_sprt, NULL);
    text_speaking(rpg, nb_dialogue[rpg->dialogue.nb_dialogue]
                [rpg->dialogue.speaking]);
    text_dialogue(rpg, nb_dialogue[rpg->dialogue.nb_dialogue]
                [rpg->dialogue.real_dialogue]);
    sfRenderWindow_display(rpg->win.window);
}

int check_dialogue_ramen(rpg_t *rpg)
{
    if (rpg->dialogue.real_dialogue == 9)
        return (1);
    return 0;
}

static void move_talk(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) ||
        sfKeyboard_isKeyPressed(sfKeyRight) ||
        sfKeyboard_isKeyPressed(sfKeyDown) ||
        sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (rpg->dialogue.speaking == 0)
            rpg->dialogue.speaking = 1;
        else
            rpg->dialogue.speaking = 0;
        if (rpg->dialogue.real_dialogue < 9)
            rpg->dialogue.real_dialogue++;
    }
}

static void event_ramen_dialogue(rpg_t *rpg, sfEvent event)
{
    while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyN)) {
            sfMusic_destroy(rpg->music.menu_mus);
            sfMusic_destroy(rpg->music.peace_music);
            sfRenderWindow_close(rpg->win.window);
        }
        move_talk(rpg);
    }
}

void dialogue_ramen(rpg_t *rpg)
{
    sfEvent event;
    rpg->dialogue.speaking = 0;
    rpg->dialogue.real_dialogue = 2;
    rpg->dialogue.nb_dialogue = 2;

    sfRenderWindow_setView(rpg->win.window,
        sfRenderWindow_getDefaultView(rpg->win.window));
    while (sfRenderWindow_isOpen(rpg->win.window)) {
        event_ramen_dialogue(rpg, event);
        if (check_dialogue_ramen(rpg) == 1)
            game_loop(rpg);
        draw_dialogue_ramen(rpg);
    }
}