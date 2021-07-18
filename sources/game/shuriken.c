/*
** EPITECH PROJECT, 2021
** other
** File description:
** init_shuriken
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void draw_special_and_shuriken(rpg_t *rpg)
{
    if (rpg->weapon.ready_to_move == 0)
        rpg->weapon.shuriken_pos = rpg->game.team_7_pos;
    sfSprite_setPosition(rpg->weapon.shuriken_sprt, rpg->weapon.shuriken_pos);
    if (rpg->weapon.ready_to_move == 1)
        sfRenderWindow_drawSprite(rpg->win.window, rpg->weapon.shuriken_sprt,
                                    NULL);
    if (rpg->special.ready_to_move == 0)
        rpg->special.special_pos = rpg->game.team_7_pos;
    sfSprite_setPosition(rpg->special.special_sprt, rpg->special.special_pos);
    if (rpg->special.ready_to_move == 1)
        sfRenderWindow_drawSprite(rpg->win.window, rpg->special.special_sprt,
                                    NULL);
}

void press_left_mouse(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
        && rpg->weapon.ready_to_move == 0) {
        rpg->weapon.pos_mouse = sfRenderWindow_mapPixelToCoords(
            rpg->win.window, sfMouse_getPositionRenderWindow(
            rpg->win.window), NULL);
        rpg->weapon.pos_mouse.x -= 15;
        rpg->weapon.pos_mouse.y -= 20;
        rpg->weapon.ready_to_move = 1;
    }
}

void move_shuriken_bis(rpg_t *rpg)
{
    if (rpg->weapon.shuriken_pos.y <= rpg->weapon.pos_mouse.y)
        rpg->weapon.shuriken_pos.y += 10;
    if (rpg->weapon.shuriken_pos.x >= rpg->weapon.pos_mouse.x - 10
        && rpg->weapon.shuriken_pos.x <= rpg->weapon.pos_mouse.x + 10
        && rpg->weapon.shuriken_pos.y >= rpg->weapon.pos_mouse.y - 10
        && rpg->weapon.shuriken_pos.y <= rpg->weapon.pos_mouse.y + 10) {
        rpg->weapon.shuriken_pos = rpg->game.team_7_pos;
        rpg->weapon.ready_to_move = 0;
    }
}

void move_shuriken(rpg_t *rpg)
{
    if (rpg->weapon.shuriken_pos.x <= rpg->weapon.pos_mouse.x)
        rpg->weapon.shuriken_pos.x += 10;
    if (rpg->weapon.shuriken_pos.y >= rpg->weapon.pos_mouse.y)
        rpg->weapon.shuriken_pos.y -= 10;
    if (rpg->weapon.shuriken_pos.x >= rpg->weapon.pos_mouse.x)
        rpg->weapon.shuriken_pos.x -= 10;
    move_shuriken_bis(rpg);
}

void init_shuriken(rpg_t *rpg)
{
    rpg->weapon.shuriken_txt =
        sfTexture_createFromFile("asset/image/weapon.png", NULL);
    rpg->weapon.shuriken_sprt = sfSprite_create();
    rpg->weapon.shuriken_pos.x = rpg->game.team_7_pos.x;
    rpg->weapon.shuriken_pos.y = rpg->game.team_7_pos.y;
    rpg->weapon.shuriken_rect = (sfIntRect) {0, 0, 35, 25};
    rpg->weapon.ready_to_move = 0;

    sfSprite_setPosition(rpg->weapon.shuriken_sprt, rpg->weapon.shuriken_pos);
    sfSprite_setTexture(rpg->weapon.shuriken_sprt,
                        rpg->weapon.shuriken_txt, sfTrue);
    sfSprite_setTextureRect(rpg->weapon.shuriken_sprt,
                            rpg->weapon.shuriken_rect);
}