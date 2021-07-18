/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init_enemy
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void init_special_attack_enemy(rpg_t *rpg)
{
    rpg->enemy.special_txt = sfTexture_createFromFile(
                "asset/image/chidori.png", NULL);
    rpg->enemy.special_sprt = sfSprite_create();
    rpg->enemy.special_pos = rpg->enemy.enemy_pos;
    rpg->enemy.special_rect = (sfIntRect) {0, 0, 50, 30};

    sfSprite_setPosition(rpg->enemy.special_sprt, rpg->enemy.special_pos);
    sfSprite_setTexture(rpg->enemy.special_sprt, rpg->enemy.special_txt,
                sfTrue);
    sfSprite_setTextureRect(rpg->enemy.special_sprt, rpg->enemy.special_rect);
}

void init_weapon_enemy(rpg_t *rpg)
{
    rpg->enemy.weapon_txt = sfTexture_createFromFile(
                "asset/image/weapon.png", NULL);
    rpg->enemy.weapon_sprt = sfSprite_create();
    rpg->enemy.weapon_pos = rpg->enemy.enemy_pos;
    rpg->enemy.weapon_rect = (sfIntRect) {0, 0, 35, 25};

    sfSprite_setPosition(rpg->enemy.weapon_sprt, rpg->enemy.weapon_pos);
    sfSprite_setTexture(rpg->enemy.weapon_sprt, rpg->enemy.weapon_txt, sfTrue);
    sfSprite_setTextureRect(rpg->enemy.weapon_sprt, rpg->enemy.weapon_rect);
    init_special_attack_enemy(rpg);
}

void init_red_life_enemy(rpg_t *rpg)
{
    rpg->enemy.life.red_shape = sfRectangleShape_create();

    sfRectangleShape_setSize(rpg->enemy.life.red_shape,
                        (sfVector2f) {40, 10});
    sfRectangleShape_setPosition(rpg->enemy.life.red_shape,
                            rpg->enemy.life.position);
    sfRectangleShape_setFillColor(rpg->enemy.life.red_shape, sfRed);
    sfRectangleShape_setOutlineColor(rpg->enemy.life.red_shape, sfBlack);
    sfRectangleShape_setOutlineThickness(rpg->enemy.life.red_shape, 1);
    init_weapon_enemy(rpg);
}

void init_enemy_life(rpg_t *rpg)
{
    rpg->enemy.life.shape = sfRectangleShape_create();
    rpg->enemy.life.remaining_life = 2;
    rpg->enemy.life.size.x = 40;
    rpg->enemy.life.size.y = 10;
    rpg->enemy.life.position.x = rpg->enemy.enemy_pos.x;
    rpg->enemy.life.position.y = rpg->enemy.enemy_pos.y + 50;

    sfRectangleShape_setSize(rpg->enemy.life.shape, rpg->enemy.life.size);
    sfRectangleShape_setPosition(rpg->enemy.life.shape,
                            rpg->enemy.life.position);
    sfRectangleShape_setFillColor(rpg->enemy.life.shape, sfGreen);
    init_red_life_enemy(rpg);
}

void init_enemy(rpg_t *rpg)
{
    rpg->enemy.enemy_text = sfTexture_createFromFile("asset/image/sakura.png",
    NULL);
    rpg->enemy.enemy_sprt = sfSprite_create();
    rpg->enemy.enemy_pos.x = 700;
    rpg->enemy.enemy_pos.y = 200;
    rpg->enemy.enemy_rect = (sfIntRect) {50, 0, 50, 48};

    sfSprite_setPosition(rpg->enemy.enemy_sprt, rpg->enemy.enemy_pos);
    sfSprite_setTexture(rpg->enemy.enemy_sprt, rpg->enemy.enemy_text, sfTrue);
    sfSprite_setTextureRect(rpg->enemy.enemy_sprt, rpg->enemy.enemy_rect);
    init_enemy_life(rpg);
}