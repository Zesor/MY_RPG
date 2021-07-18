/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** init_player
*/

#include "define.h"
#include "function.h"
#include "struct.h"

void init_player(rpg_t *rpg)
{
    sfVector2f pos = {0, 863};
    sfVector2f scale = {2, 2};

    rpg->paral.floor_text = sfTexture_createFromFile("asset/image/floor.png",
    NULL);
    rpg->paral.floor_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->paral.floor_sprt, pos);
    sfSprite_setTexture(rpg->paral.floor_sprt, rpg->paral.floor_text, sfTrue);
    rpg->paral.naruto_text = sfTexture_createFromFile("asset/image/naruto.png",
    NULL);
    rpg->paral.naruto_sprt = sfSprite_create();
    rpg->paral.naruto_pos.x = 400;
    rpg->paral.naruto_pos.y = 770;
    rpg->paral.naruto_rect = (sfIntRect) {50, 96, 50, 48};
    sfSprite_setPosition(rpg->paral.naruto_sprt, rpg->paral.naruto_pos);
    sfSprite_setScale(rpg->paral.naruto_sprt, scale);
    sfSprite_setTexture(rpg->paral.naruto_sprt, rpg->paral.naruto_text, sfTrue);
    sfSprite_setTextureRect(rpg->paral.naruto_sprt, rpg->paral.naruto_rect);
}

void init_player2(rpg_t *rpg)
{
    sfVector2f scale = {2, 2};

    rpg->paral.sasuke_text = sfTexture_createFromFile("asset/image/sasuke.png",
    NULL);
    rpg->paral.sasuke_sprt = sfSprite_create();
    rpg->paral.sasuke_pos.x = 1600;
    rpg->paral.sasuke_pos.y = 770;
    rpg->paral.sasuke_rect = (sfIntRect) {50, 48, 50, 48};
    rpg->weapon.shuriken_pos = rpg->paral.naruto_pos;

    sfSprite_setPosition(rpg->weapon.shuriken_sprt, rpg->weapon.shuriken_pos);
    sfSprite_setPosition(rpg->paral.sasuke_sprt, rpg->paral.sasuke_pos);
    sfSprite_setScale(rpg->paral.sasuke_sprt, scale);
    sfSprite_setTexture(rpg->paral.sasuke_sprt, rpg->paral.sasuke_text, sfTrue);
    sfSprite_setTextureRect(rpg->paral.sasuke_sprt, rpg->paral.sasuke_rect);
}

void using_clock_parallax(rpg_t *rpg)
{
    rpg->general_time = sfClock_getElapsedTime(rpg->general_clock);
    rpg->general_seconds = rpg->general_time.microseconds / 1000000.0;
    if (rpg->general_seconds < 0.1)
        move_character_right_lefts(rpg, 5);
    if (rpg->weapon.ready_to_move == 1 && rpg->general_seconds > 0.001) {
        move_shuriken_para(rpg);
        move_rects(&rpg->weapon.shuriken_rect, 37, 120);
        sfSprite_setPosition(rpg->weapon.shuriken_sprt,
                rpg->weapon.shuriken_pos);
        sfClock_restart(rpg->general_clock);
        sfSprite_setTextureRect(rpg->weapon.shuriken_sprt,
                rpg->weapon.shuriken_rect);
    }
    using_clock_parallax_bis(rpg);
}

void touch_naruto(rpg_t *rpg)
{
    sfFloatRect weapon = sfSprite_getGlobalBounds(rpg->paral.chidori_sprt);
    sfFloatRect character = sfSprite_getGlobalBounds(rpg->paral.naruto_sprt);
    const sfFloatRect *weapons = &weapon;
    const sfFloatRect *characters = &character;

    if (sfFloatRect_intersects(weapons, characters, NULL)) {
        rpg->paral.chidori_pos.y = 200;
        rpg->life.remaining_life--;
        rpg->life.size.x -= 15;
        sfRectangleShape_setSize(rpg->life.shape, rpg->life.size);
        sfSprite_setPosition(rpg->paral.chidori_sprt, rpg->paral.chidori_pos);
    }
}