/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** init_bars
*/

#include "define.h"
#include "function.h"
#include "struct.h"

void naruto_bars_bis(rpg_t *rpg)
{
    rpg->mana.position.x = 10;
    rpg->mana.position.y = 120;
    sfRectangleShape_setPosition(rpg->mana.shape, rpg->mana.position);
    sfRectangleShape_setPosition(rpg->mana.black_shape, rpg->mana.position);
    sfRectangleShape_setSize(rpg->mana.shape, (sfVector2f)
                            {rpg->mana.size.x, rpg->mana.size.y + 50});
    sfRectangleShape_setSize(rpg->mana.black_shape, (sfVector2f)
                            {rpg->mana.size.x + 100, rpg->mana.size.y + 50});
    sfRenderWindow_drawRectangleShape(rpg->win.window,
                                    rpg->mana.black_shape, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win.window, rpg->mana.shape, NULL);
}

void naruto_bars(rpg_t *rpg)
{
    rpg->life.position.x = 10;
    rpg->life.position.y = 30;
    sfRectangleShape_setPosition(rpg->life.shape, rpg->life.position);
    sfRectangleShape_setPosition(rpg->life.red_shape, rpg->life.position);
    sfRectangleShape_setSize(rpg->life.shape, (sfVector2f)
                        {rpg->life.size.x, rpg->life.size.y + 40});
    sfRectangleShape_setSize(rpg->life.red_shape, (sfVector2f)
                        {rpg->life.size.x, rpg->life.size.y + 40});
    sfRenderWindow_drawRectangleShape(rpg->win.window,
                                    rpg->life.red_shape, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win.window, rpg->life.shape, NULL);
    naruto_bars_bis(rpg);
}