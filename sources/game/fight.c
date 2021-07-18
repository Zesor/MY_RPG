/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight
*/

#include "struct.h"
#include "define.h"
#include "function.h"

static void draw_fight_build(rpg_t *rpg)
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

static void draw_fight_sprite(rpg_t *rpg)
{
    char *map = NULL;

    sfRenderWindow_clear(rpg->win.window, sfBlack);
    draw_fight_build(rpg);
    draw_clones(rpg);
    draw_special_and_shuriken(rpg);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->game.team7_sprt, NULL);
    draw_life_and_mana(rpg);
    inventory_cases(rpg);
    launch_quest(rpg);
    sfRenderWindow_display(rpg->win.window);
}

void analyse_event_fight(rpg_t *rpg, sfEvent event)
{
    while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyN)) {
            sfMusic_destroy(rpg->music.menu_mus);
            sfMusic_destroy(rpg->music.peace_music);
            sfRenderWindow_close(rpg->win.window);
        }
        launch_pause(rpg);
        key_released(rpg, event);
        press_left_mouse(rpg);
        press_right_mouse(rpg);
    }
}

void fight_loop(rpg_t *rpg)
{
    sfEvent event;
    init_clone(rpg);

    sfSprite_setColor(rpg->game.fond_sprt, sfRed);
    while (sfRenderWindow_isOpen(rpg->win.window)) {
        rpg->general_time = sfClock_getElapsedTime(rpg->general_clock);
        rpg->general_seconds = rpg->general_time.microseconds / 1000000.0;
        if (sfKeyboard_isKeyPressed(sfKeyX)) {
            sfSprite_setColor(rpg->game.fond_sprt, sfWhite);
            game_loop(rpg);
        }
        check_character_fight(rpg);
        check_enemy_fight(rpg);
        clone_shuriken(rpg);
        update_view(rpg);
        draw_fight_sprite(rpg);
        using_clock_game(rpg);
        analyse_event_fight(rpg, event);
        check_lose(rpg);
    }
}