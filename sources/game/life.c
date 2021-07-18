/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** life
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void draw_life_and_mana(rpg_t *rpg)
{
    rpg->life.position.x = rpg->game.team_7_pos.x - 420;
    rpg->life.position.y = rpg->game.team_7_pos.y - 220;
    sfRectangleShape_setPosition(rpg->life.shape, rpg->life.position);
    sfRectangleShape_setPosition(rpg->life.red_shape, rpg->life.position);
    sfRenderWindow_drawRectangleShape(rpg->win.window,
                                    rpg->life.red_shape, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win.window, rpg->life.shape, NULL);
    rpg->mana.position.x = rpg->game.team_7_pos.x - 420;
    rpg->mana.position.y = rpg->game.team_7_pos.y - 180;
    sfRectangleShape_setPosition(rpg->mana.shape, rpg->mana.position);
    sfRectangleShape_setPosition(rpg->mana.black_shape, rpg->mana.position);
    sfRenderWindow_drawRectangleShape(rpg->win.window,
                                    rpg->mana.black_shape, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win.window, rpg->mana.shape, NULL);
}

void init_red_life(rpg_t *rpg)
{
    rpg->life.red_shape = sfRectangleShape_create();

    sfRectangleShape_setSize(rpg->life.red_shape, (sfVector2f) {150, 30});
    sfRectangleShape_setPosition(rpg->life.red_shape, (sfVector2f) {280, 175});
    sfRectangleShape_setFillColor(rpg->life.red_shape, sfRed);
    sfRectangleShape_setOutlineColor(rpg->life.red_shape, sfWhite);
    sfRectangleShape_setOutlineThickness(rpg->life.red_shape, 5);
}

void init_life(rpg_t *rpg)
{
    rpg->life.shape = sfRectangleShape_create();
    rpg->life.remaining_life = 10;
    rpg->life.size.x = 150;
    rpg->life.size.y = 30;

    sfRectangleShape_setSize(rpg->life.shape, rpg->life.size);
    sfRectangleShape_setPosition(rpg->life.shape, (sfVector2f) {280, 175});
    sfRectangleShape_setFillColor(rpg->life.shape, sfGreen);
}