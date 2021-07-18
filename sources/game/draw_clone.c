/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw_clone
*/

#include "struct.h"
#include "define.h"
#include "function.h"

static void draw_clone_last(rpg_t *rpg)
{
    if (rpg->enemy.size_fifth.x > 0) {
        sfRenderWindow_drawSprite(rpg->win.window,
                        rpg->enemy.fifth_clone, NULL);
        sfRenderWindow_drawSprite(rpg->win.window,
                        rpg->enemy.weapon_fifth, NULL);
        sfRenderWindow_drawRectangleShape(rpg->win.window,
                        rpg->enemy.rect_fifth, NULL);
    }
}

static void draw_clone_third(rpg_t *rpg)
{
    if (rpg->enemy.size_third.x > 0) {
        sfRenderWindow_drawSprite(rpg->win.window,
                        rpg->enemy.third_clone, NULL);
        sfRenderWindow_drawSprite(rpg->win.window, rpg->enemy.weapon_third,
            NULL);
        sfRenderWindow_drawRectangleShape(rpg->win.window,
                        rpg->enemy.rect_third, NULL);
    }
    if (rpg->enemy.size_fourth.x > 0) {
        sfRenderWindow_drawSprite(rpg->win.window,
                        rpg->enemy.fourth_clone, NULL);
        sfRenderWindow_drawSprite(rpg->win.window,
                        rpg->enemy.weapon_fourth, NULL);
        sfRenderWindow_drawRectangleShape(rpg->win.window,
                        rpg->enemy.rect_fourth, NULL);
    }
}

static void draw_clone_first(rpg_t *rpg)
{
    if (rpg->enemy.size_first.x > 0) {
        sfRenderWindow_drawSprite(rpg->win.window,
                        rpg->enemy.first_clone, NULL);
        sfRenderWindow_drawSprite(rpg->win.window,
                        rpg->enemy.weapon_first, NULL);
        sfRenderWindow_drawRectangleShape(rpg->win.window,
                        rpg->enemy.rect_first, NULL);
    }
    if (rpg->enemy.size_second.x > 0) {
        sfRenderWindow_drawSprite(rpg->win.window,
                        rpg->enemy.second_clone, NULL);
        sfRenderWindow_drawSprite(rpg->win.window,
                        rpg->enemy.weapon_second, NULL);
        sfRenderWindow_drawRectangleShape(rpg->win.window,
                        rpg->enemy.rect_second, NULL);
    }
}

void draw_clones(rpg_t *rpg)
{
    draw_clone_first(rpg);
    draw_clone_third(rpg);
    draw_clone_last(rpg);
}