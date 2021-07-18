/*
** EPITECH PROJECT, 2021
** game
** File description:
** game
*/

#include "define.h"
#include "struct.h"
#include "function.h"

static void draw_build(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.fond_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.f_home_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.f_home_sprt2, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.f_home_sprt3, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.ichiraku_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.tower_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.shop_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.route_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.route_sprt2, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.door_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.tree_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.tree_sprt2, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.tree_sprt3, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.tree_sprt4, NULL);
}

static void draw_game_sprite(rpg_t *rpg)
{
    char *map = NULL;

    sfRenderWindow_clear(rpg->win.window, sfBlack);
    draw_build(rpg);
    draw_special_and_shuriken(rpg);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.team7_sprt, NULL);
    move_kakashi(rpg);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->kakashi.kakashi_sprt,
                                NULL);
    talk_hitbox(rpg);
    draw_life_and_mana(rpg);
    inventory_cases(rpg);
    launch_quest(rpg);
    sfRenderWindow_display(rpg->win.window);
}

void analyse_event(rpg_t *rpg, sfEvent event)
{
    while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyN)) {
            sfMusic_destroy(rpg->music.menu_mus);
            sfMusic_destroy(rpg->music.peace_music);
            sfMusic_destroy(rpg->music.pause_music);
            sfRenderWindow_close(rpg->win.window);
        }
        launch_pause(rpg);
        key_released(rpg, event);
        press_left_mouse(rpg);
        press_right_mouse(rpg);
    }
}

int game_loop(rpg_t *rpg)
{
    sfEvent event;
    rpg->kakashi.kakashi_pos.x = 200;
    rpg->kakashi.kakashi_pos.y = 15;
    sfSprite_setPosition(rpg->kakashi.kakashi_sprt, rpg->kakashi.kakashi_pos);
    rpg->general_clock = sfClock_create();
    sfMusic_play(rpg->music.peace_music);
    sfRenderWindow_setMouseCursorVisible(rpg->win.window, sfTrue);
    while (sfRenderWindow_isOpen(rpg->win.window)) {
        if (sfKeyboard_isKeyPressed(sfKeyU))
            fight_loop(rpg);
        analyse_event(rpg, event);
        activate_shop(rpg);
        activate_ramen(rpg);
        check_lose(rpg);
        update_view(rpg);
        draw_game_sprite(rpg);
        using_clock_game(rpg);
        enter_to_last_fight(rpg);
        check_quest(rpg);
    }
}