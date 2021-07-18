/*
** EPITECH PROJECT, 2021
** other
** File description:
** tutorial
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void draw_ask_tutorial(rpg_t *rpg, int choice, sfRectangleShape *rec)
{
    sfRenderWindow_clear(rpg->win.window, sfBlack);
    sfRenderWindow_drawRectangleShape(rpg->win.window, rec, NULL);
    sfRenderWindow_drawText(rpg->win.window,
    text_tutorial(rpg->win.window, "Do you want to play tutorial ?"), NULL);
    sfRenderWindow_drawText(rpg->win.window,
    no_tutorial(rpg->win.window, "No.", choice), NULL);
    sfRenderWindow_drawText(rpg->win.window,
    yes_tutorial(rpg->win.window, "Yes.", choice), NULL);
    sfRenderWindow_display(rpg->win.window);
}

int events_ask_tutorial(rpg_t *rpg, int choice, sfEvent event)
{
    while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyN)) {
            sfMusic_destroy(rpg->music.menu_mus);
            sfRenderWindow_close(rpg->win.window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight) ||
            sfKeyboard_isKeyPressed(sfKeyLeft)) {
            choice--;
            if (choice < 0)
                choice = 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            if (choice == 0)
                tutorial_loop(rpg);
            if (choice == 1) {
                rpg->quest.side_quest = 1;
                rpg->quest.nb_quest = 1;
                game_loop(rpg);
            }
        }
    }
    return (choice);
}

sfRectangleShape *create_rectangle(void)
{
    sfRectangleShape *rec = sfRectangleShape_create();

    sfRectangleShape_setPosition(rec, (sfVector2f) {550, 300});
    sfRectangleShape_setSize(rec, (sfVector2f) {800, 400});
    sfRectangleShape_setFillColor(rec, sfTransparent);
    sfRectangleShape_setOutlineColor(rec, sfWhite);
    sfRectangleShape_setOutlineThickness(rec, 1);
    return (rec);
}

void ask_for_tutorial_loop(rpg_t *rpg)
{
    sfEvent event;
    sfRectangleShape *rec = create_rectangle();
    int choice = 0;

    while (sfRenderWindow_isOpen(rpg->win.window)) {
        choice = events_ask_tutorial(rpg, choice, event);
        draw_ask_tutorial(rpg, choice, rec);
    }
}