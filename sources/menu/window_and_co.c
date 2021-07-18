/*
** EPITECH PROJECT, 2021
** init_window
** File description:
** init_window
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

#include "struct.h"
#include "define.h"
#include "function.h"

void init_window(rpg_t *rpg)
{
    rpg->win.mode.width = 1920;
    rpg->win.mode.height = 1080;
    rpg->win.mode.bitsPerPixel = 32;
    rpg->win.window = sfRenderWindow_create(rpg->win.mode, "My_RPG",
    sfResize | sfClose, NULL);
    if (!rpg->win.window)
        return;
    sfRenderWindow_setFramerateLimit(rpg->win.window, 30);
    sfRenderWindow_setVerticalSyncEnabled(rpg->win.window, sfTrue);
}

void background_sprt(rpg_t *rpg)
{
    sfVector2f play_pos = {30, 400};
    sfVector2f htp_pos = {30, 550};

    rpg->back.back_texture = sfTexture_createFromFile("asset/image/menu.jpg",
    NULL);
    rpg->back.back_sprite = sfSprite_create();
    sfSprite_setTexture(rpg->back.back_sprite, rpg->back.back_texture, sfTrue);

    rpg->back.play_text = sfTexture_createFromFile("asset/image/play_but.png",
    NULL);
    rpg->back.play_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->back.play_sprt, play_pos);
    sfSprite_setTexture(rpg->back.play_sprt, rpg->back.play_text, sfTrue);

    rpg->back.htp_text = sfTexture_createFromFile("asset/image/htp.png",
    NULL);
    rpg->back.htp_sprite = sfSprite_create();
    sfSprite_setPosition(rpg->back.htp_sprite, htp_pos);
    sfSprite_setTexture(rpg->back.htp_sprite, rpg->back.htp_text, sfTrue);
}

void button_set(rpg_t *rpg)
{
    sfVector2f option_pos = {30, 700};
    sfVector2f quit_pos = {30, 850};

    rpg->back.option_text = sfTexture_createFromFile("asset/image/option.png",
    NULL);
    rpg->back.option_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->back.option_sprt, option_pos);
    sfSprite_setTexture(rpg->back.option_sprt, rpg->back.option_text, sfTrue);

    rpg->back.quit_text = sfTexture_createFromFile("asset/image/quit.png",
    NULL);
    rpg->back.quit_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->back.quit_sprt, quit_pos);
    sfSprite_setTexture(rpg->back.quit_sprt, rpg->back.quit_text, sfTrue);
}

void button_effect(rpg_t *rpg)
{
    sfVector2f play_pos = {30, 400};
    sfVector2f htp_pos = {30, 550};
    sfVector2f opt_pos = {30, 700};

    rpg->back.play_drk = sfTexture_createFromFile("asset/image/playdrk.png",
    NULL);
    rpg->back.play_drk_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->back.play_drk_sprt, play_pos);
    sfSprite_setTexture(rpg->back.play_drk_sprt, rpg->back.play_drk, sfTrue);
    rpg->back.htp_drk = sfTexture_createFromFile("asset/image/htpdrk.png",
    NULL);
    rpg->back.htp_drk_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->back.htp_drk_sprt, htp_pos);
    sfSprite_setTexture(rpg->back.htp_drk_sprt, rpg->back.htp_drk, sfTrue);

    rpg->back.opt_drk = sfTexture_createFromFile("asset/image/option_drk.png",
    NULL);
    rpg->back.opt_drk_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->back.opt_drk_sprt, opt_pos);
    sfSprite_setTexture(rpg->back.opt_drk_sprt, rpg->back.opt_drk, sfTrue);
}

void button_effect2(rpg_t *rpg)
{
    sfVector2f quit_drk_pos = {30, 850};
    sfVector2f team7_pos = {0, 0};
    sfIntRect rect = {0, 0, 120, 120};

    rpg->back.quit_drk = sfTexture_createFromFile("asset/image/quit_drk.png",
    NULL);
    rpg->back.quit_drk_sprt = sfSprite_create();
    sfSprite_setPosition(rpg->back.quit_drk_sprt, quit_drk_pos);
    sfSprite_setTexture(rpg->back.quit_drk_sprt, rpg->back.quit_drk, sfTrue);
}