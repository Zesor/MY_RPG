/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** print_dialogue
*/

#include "struct.h"
#include "define.h"
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

void draw_dialogue_kakashi(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->win.window, sfTransparent);
    draw_build(rpg);
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