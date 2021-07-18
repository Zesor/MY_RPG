/*
** EPITECH PROJECT, 2021
** other
** File description:
** tutorial
*/

#include "struct.h"
#include "define.h"
#include "function.h"

static void draw_tutorial_sprite(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->win.window, sfBlack);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.fond_sprt, NULL);
    draw_special_and_shuriken(rpg);
    move_kakashi(rpg);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.team7_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->kakashi.kakashi_sprt,
                                NULL);
    print_enemy(rpg);
    talk_hitbox(rpg);
    draw_life_and_mana(rpg);
    launch_quest(rpg);
    sfRenderWindow_display(rpg->win.window);
}

void analyse_event_tutorial(rpg_t *rpg, sfEvent event)
{
    while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyN)) {
            sfMusic_destroy(rpg->music.menu_mus);
            sfMusic_destroy(rpg->music.pause_music);
            sfMusic_destroy(rpg->music.peace_music);
            sfRenderWindow_close(rpg->win.window);
        }
        launch_pause(rpg);
        key_released(rpg, event);
        press_left_mouse(rpg);
        press_right_mouse(rpg);
    }
}

int tutorial_loop(rpg_t *rpg)
{
    sfEvent event;
    rpg->general_clock = sfClock_create();

    sfRenderWindow_setMouseCursorVisible(rpg->win.window, sfTrue);
    reset_tutorial(rpg);
    dialogue_tutorial(rpg);
    while (sfRenderWindow_isOpen(rpg->win.window)) {
        analyse_event_tutorial(rpg, event);
        update_view(rpg);
        check_lose(rpg);
        draw_tutorial_sprite(rpg);
        using_clock_tutorial(rpg);
        check_touch(rpg);
        check_quest(rpg);
    }
}