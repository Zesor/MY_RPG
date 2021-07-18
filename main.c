/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

#include "struct.h"
#include "define.h"
#include "function.h"

#define NO_CURS sfRenderWindow_setMouseCursorVisible(rpg->win.window, sfFalse)

static void object_game(rpg_t *rpg)
{
    init_team7(rpg);
    init_view(rpg);
    init_shuriken(rpg);
    init_life(rpg);
    init_kakashi(rpg);
    init_red_life(rpg);
    init_quest(rpg);
    init_dialogue(rpg);
    init_mana(rpg);
    init_enemy(rpg);
    init_tree(rpg);
    init_tree2(rpg);
    game_object(rpg);
    game_object2(rpg);
    game_object3(rpg);
    game_object4(rpg);
    game_object5(rpg);
    init_player(rpg);
    init_player2(rpg);
    init_chidori(rpg);
}

static void object_game1(rpg_t *rpg)
{
    init_special_attack(rpg);
    background_game(rpg);
    init_pause_sprt(rpg);
    init_drk_pause_sprt(rpg);
    init_real_sprt(rpg);
    seetings_sprt(rpg);
}

static void object_menu(rpg_t *rpg)
{
    init_window(rpg);
    music_pause(rpg);
    music_in_game(rpg);
    init_paral_object(rpg);
    init_parallax(rpg);
    background_sprt(rpg);
    back_htp(rpg);
    back_htp_bis(rpg);
    return_settings_sprite(rpg);
    init_volume_buttons(rpg);
    init_framerate_buttons(rpg);
    play_realeased_and_htp(rpg);
    button_set(rpg);
    button_effect(rpg);
    button_effect2(rpg);
    music_menu(rpg);
    NO_CURS;
    main_loop(rpg);
}

int my_rpg(rpg_t *rpg)
{
    object_game(rpg);
    object_game1(rpg);
    object_menu(rpg);
}

int main(int ac, char const *av[], char const *env[])
{
    rpg_t rpg;

    if (!*env)
        return 84;
    return (my_rpg(&rpg));
}