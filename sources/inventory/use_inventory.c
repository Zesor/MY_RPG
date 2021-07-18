/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** use_inventory
*/

#include "define.h"
#include "struct.h"
#include "function.h"

static void give_back_life(rpg_t *rpg)
{
    int a = 150 - rpg->life.size.x;

    if (a >= 0) {
        rpg->life.size.x += a;
        sfRectangleShape_setSize(rpg->life.shape, rpg->life.size);
    }
}

static void give_back_chakra(rpg_t *rpg)
{
    int a = 100 - rpg->mana.size.x;

    if (a >= 0) {
        rpg->mana.size.x += a;
        sfRectangleShape_setSize(rpg->mana.shape, rpg->mana.size);
    }
}

static void click_item_2(rpg_t *rpg, sfVector2f mouse)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(rpg->invent.shape2);
    const sfFloatRect *bibou = &hello;

    if (sfFloatRect_contains(bibou, mouse.x, mouse.y) &&
        rpg->invent.ramen == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        rpg->weapon.ready_to_move = 0;
        give_back_life(rpg);
        rpg->invent.ramen = 0;
    }
}

static void click_item_1(rpg_t *rpg, sfVector2f mouse)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(rpg->invent.shape1);
    const sfFloatRect *bibou = &hello;

    if (sfFloatRect_contains(bibou, mouse.x, mouse.y) &&
        rpg->invent.scroll == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        give_back_chakra(rpg);
        rpg->weapon.ready_to_move = 0;
        rpg->invent.scroll = 0;
    }
}

void use_items(rpg_t *rpg)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win.window);
    sfVector2f worldpos = sfRenderWindow_mapPixelToCoords(rpg->win.window,
                        mouse, rpg->game.view);

    click_item_1(rpg, worldpos);
    click_item_2(rpg, worldpos);
}