/*
** EPITECH PROJECT, 2021
** init
** File description:
** init
*/

#include "define.h"
#include "struct.h"
#include "function.h"

void init_team7(rpg_t *rpg)
{
    rpg->invent.shop = 0;
    rpg->invent.scroll = 0;
    rpg->invent.ramen = 0;
    rpg->invent.ramen_shop = 0;
    rpg->game.team7_text = sfTexture_createFromFile("asset/image/naruto.png",
    NULL);
    rpg->game.team7_sprt = sfSprite_create();
    rpg->game.team_7_pos.x = 700;
    rpg->game.team_7_pos.y = 400;
    rpg->game.team7_rect = (sfIntRect) {50, 0, 50, 48};
    sfSprite_setPosition(rpg->game.team7_sprt, rpg->game.team_7_pos);
    sfSprite_setTexture(rpg->game.team7_sprt, rpg->game.team7_text, sfTrue);
    sfSprite_setTextureRect(rpg->game.team7_sprt, rpg->game.team7_rect);
}

void background_game(rpg_t *rpg)
{
    sfVector2f scale = {1.5, 1.5};
    sfVector2f pos = {200, 20};

    rpg->game.fond_text = sfTexture_createFromFile("asset/image/fond.jpg",
    NULL);
    rpg->game.fond_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->game.fond_sprt, pos);
    sfSprite_setScale(rpg->game.fond_sprt, scale);
    sfSprite_setTexture(rpg->game.fond_sprt, rpg->game.fond_text, sfTrue);
}

void game_object(rpg_t *rpg)
{
    sfVector2f pos = {260, 200};
    sfVector2f pos1 = {260, 400};

    rpg->game.f_home_text = sfTexture_createFromFile("asset/image/3darr.png",
    NULL);
    rpg->game.f_home_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->game.f_home_sprt, pos);
    sfSprite_setTexture(rpg->game.f_home_sprt, rpg->game.f_home_text, sfTrue);

    rpg->game.f_home_text2 = sfTexture_createFromFile("asset/image/home5.png",
    NULL);
    rpg->game.f_home_sprt2 = sfSprite_create();
    sfSprite_setPosition(rpg->game.f_home_sprt2, pos1);
    sfSprite_setTexture(rpg->game.f_home_sprt2, rpg->game.f_home_text2, sfTrue);
}

void game_object2(rpg_t *rpg)
{
    sfVector2f pos = {950, 750};
    sfVector2f pos1 = {950, 100};

    rpg->game.ichiraku_text =
        sfTexture_createFromFile("asset/image/ichiraku.png", NULL);
    rpg->game.ichiraku_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->game.ichiraku_sprt, pos);
    sfSprite_setTexture(rpg->game.ichiraku_sprt,
                        rpg->game.ichiraku_text, sfTrue);

    rpg->game.tower_text = sfTexture_createFromFile("asset/image/home4.png",
    NULL);
    rpg->game.tower_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->game.tower_sprt, pos1);
    sfSprite_setTexture(rpg->game.tower_sprt, rpg->game.tower_text, sfTrue);
}

void game_object3(rpg_t *rpg)
{
    sfVector2f pos = {700, 20};
    sfVector2f pos1 = {700, 490};

    rpg->game.route_text = sfTexture_createFromFile("asset/image/rotue.png",
    NULL);
    rpg->game.route_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->game.route_sprt, pos);
    sfSprite_setTexture(rpg->game.route_sprt, rpg->game.route_text, sfTrue);

    rpg->game.route_text2 = sfTexture_createFromFile("asset/image/rotue.png",
    NULL);
    rpg->game.route_sprt2 = sfSprite_create();
    sfSprite_setPosition(rpg->game.route_sprt2, pos1);
    sfSprite_setTexture(rpg->game.route_sprt2, rpg->game.route_text2, sfTrue);
}