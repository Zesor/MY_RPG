/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** special_attack
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void press_right_mouse(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseRight)
        && rpg->special.ready_to_move == 0
        && rpg->mana.size.x >= 50) {
        rpg->special.pos_mouse = sfRenderWindow_mapPixelToCoords(
            rpg->win.window, sfMouse_getPositionRenderWindow(
            rpg->win.window), NULL);
        rpg->special.pos_mouse.x -= 15;
        rpg->special.pos_mouse.y -= 20;
        rpg->special.ready_to_move = 1;
        rpg->mana.size.x -= 50;
        sfRectangleShape_setSize(rpg->mana.shape, rpg->mana.size);
    }
}

void move_special_bis(rpg_t *rpg)
{
    if (rpg->special.special_pos.y <= rpg->special.pos_mouse.y)
        rpg->special.special_pos.y += 5;
    if (rpg->special.special_pos.x >= rpg->special.pos_mouse.x - 10
        && rpg->special.special_pos.x <= rpg->special.pos_mouse.x + 10
        && rpg->special.special_pos.y >= rpg->special.pos_mouse.y - 10
        && rpg->special.special_pos.y <= rpg->special.pos_mouse.y + 10) {
        rpg->special.special_pos = rpg->game.team_7_pos;
        rpg->special.ready_to_move = 0;
    }
}

void move_special(rpg_t *rpg)
{
    if (rpg->special.special_pos.x <= rpg->special.pos_mouse.x)
        rpg->special.special_pos.x += 5;
    if (rpg->special.special_pos.y >= rpg->special.pos_mouse.y)
        rpg->special.special_pos.y -= 5;
    if (rpg->special.special_pos.x >= rpg->special.pos_mouse.x)
        rpg->special.special_pos.x -= 5;
    move_special_bis(rpg);
}

void init_special_attack(rpg_t *rpg)
{
    rpg->special.special_txt =
    sfTexture_createFromFile("asset/image/rasengan.png", NULL);
    rpg->special.special_sprt = sfSprite_create();
    rpg->special.special_pos = rpg->game.team_7_pos;
    rpg->special.special_rect = (sfIntRect) {0, 0, 65, 75};
    rpg->special.ready_to_move = 0;

    sfSprite_setPosition(rpg->special.special_sprt, rpg->special.special_pos);
    sfSprite_setTexture(rpg->special.special_sprt, rpg->special.special_txt,
                        sfTrue);
    sfSprite_setTextureRect(rpg->special.special_sprt,
                            rpg->special.special_rect);
}