/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** inventory
*/

#include "define.h"
#include "struct.h"
#include "function.h"

void add_object(rpg_t *rpg)
{
    sfTexture *scroll = sfTexture_createFromFile("asset/image/scroll.png",
                                                NULL);
    sfTexture *ramen = sfTexture_createFromFile("asset/image/ramen.png",
                                                NULL);
    if (rpg->invent.scroll == 1)
        sfRectangleShape_setTexture(rpg->invent.shape1, scroll, sfTrue);
    if (rpg->invent.ramen == 1)
        sfRectangleShape_setTexture(rpg->invent.shape2, ramen, sfTrue);
}

static void inventory_item(rpg_t *rpg)
{
    rpg->invent.shape1 = sfRectangleShape_create();
    rpg->invent.shape2 = sfRectangleShape_create();
    rpg->invent.shape3 = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->invent.shape1, (sfVector2f){40, 40});
    sfRectangleShape_setSize(rpg->invent.shape2, (sfVector2f){40, 40});
    sfRectangleShape_setSize(rpg->invent.shape3, (sfVector2f){40, 40});
    sfRectangleShape_setPosition(rpg->invent.shape1, (sfVector2f)
            {rpg->game.team_7_pos.x + 395, rpg->game.team_7_pos.y - 90});
    sfRectangleShape_setPosition(rpg->invent.shape2, (sfVector2f)
            {rpg->game.team_7_pos.x + 395, rpg->game.team_7_pos.y + 15});
    sfRectangleShape_setPosition(rpg->invent.shape3, (sfVector2f)
            {rpg->game.team_7_pos.x + 395, rpg->game.team_7_pos.y + 120});
}

static void chose_inventory(button_s *inventory, sfVector2f mouse, rpg_t *rpg)
{
    sfFloatRect hello = sfRectangleShape_getGlobalBounds(inventory->shape);
    const sfFloatRect *bibou = &hello;

    if (sfFloatRect_contains(bibou, mouse.x, mouse.y)) {
        rpg->weapon.ready_to_move = 0;
        sfRectangleShape_setOutlineThickness(inventory->shape, 5);
        sfRectangleShape_setFillColor(inventory->shape, sfWhite);
        sfRectangleShape_setOutlineColor(inventory->shape, sfYellow);
    } else
        sfRectangleShape_setFillColor(inventory->shape, sfWhite);
}

button_s **create_inventory(button_s **inventory, rpg_t *rpg)
{

    inventory = malloc(sizeof(button_s **) * 3);
    inventory[0] = init_butt((sfVector2f){rpg->game.team_7_pos.x + 365,
                    rpg->game.team_7_pos.y - 120}, (sfVector2f){100, 100});
    inventory[1] = init_butt((sfVector2f){rpg->game.team_7_pos.x + 365,
                    rpg->game.team_7_pos.y - 15}, (sfVector2f){100, 100});
    inventory[2] = init_butt((sfVector2f){rpg->game.team_7_pos.x + 365,
                    rpg->game.team_7_pos.y + 90}, (sfVector2f){100, 100});
    return inventory;
}

void inventory_cases(rpg_t *rpg)
{
    sfTexture *slot = sfTexture_createFromFile("asset/image/slot.png", NULL);
    button_s **cases = create_inventory(cases, rpg);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win.window);
    sfVector2f worldpos = sfRenderWindow_mapPixelToCoords(rpg->win.window,
                        mouse, rpg->game.view);

    for (int i = 0; i <= 2; i++) {
        if (cases[i]->shape != NULL) {
            chose_inventory(cases[i], worldpos, rpg);
            sfRectangleShape_setTexture(cases[i]->shape, slot, sfTrue);
            sfRenderWindow_drawRectangleShape(rpg->win.window,
                                            cases[i]->shape, NULL);
        }
    }
    inventory_item(rpg);
    add_object(rpg);
    sfRenderWindow_drawRectangleShape(rpg->win.window,
                                rpg->invent.shape1, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win.window,
                                rpg->invent.shape2, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win.window,
                                rpg->invent.shape3, NULL);
    use_items(rpg);
}