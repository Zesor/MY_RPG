/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init_enemy
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void move_special_enemy(rpg_t *rpg)
{
    rpg->enemy.special_pos.y += 5;
    if (rpg->enemy.special_pos.y == 500)
        rpg->enemy.special_pos.y = 200;
    sfSprite_setPosition(rpg->enemy.special_sprt, rpg->enemy.special_pos);
}

void move_shuriken_enemy(rpg_t *rpg)
{
    rpg->enemy.weapon_pos.y += 10;
    if (rpg->enemy.weapon_pos.y == 500)
        rpg->enemy.weapon_pos.y = 200;
    sfSprite_setPosition(rpg->enemy.weapon_sprt, rpg->enemy.weapon_pos);
}

void print_enemy(rpg_t *rpg)
{
    if (rpg->quest.side_quest == 5 || rpg->quest.side_quest == 8) {
        sfRenderWindow_drawSprite(rpg->win.window,
                        rpg->enemy.weapon_sprt, NULL);
        sfRenderWindow_drawSprite(rpg->win.window,
                        rpg->enemy.enemy_sprt, NULL);
        sfRenderWindow_drawRectangleShape(rpg->win.window,
                        rpg->enemy.life.red_shape, NULL);
        sfRenderWindow_drawRectangleShape(rpg->win.window,
                        rpg->enemy.life.shape, NULL);
    }
    if (rpg->quest.side_quest == 8)
        sfRenderWindow_drawSprite(rpg->win.window,
                        rpg->enemy.special_sprt, NULL);
}