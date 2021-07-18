/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** print_ramen_character
*/

#include "struct.h"
#include "define.h"
#include "function.h"

static void print_characters_ramen_bis(rpg_t *rpg)
{
    rpg->dialogue.kakashi_txt = sfTexture_createFromFile(
                    "asset/image/ichiraku.jpg", NULL);
    rpg->dialogue.naruto_txt = sfTexture_createFromFile(
                    "asset/image/naruto_dial_sbr.png", NULL);
    sfSprite_setTexture(rpg->dialogue.kakashi_sprt,
                    rpg->dialogue.kakashi_txt, sfTrue);
    sfSprite_setTexture(rpg->dialogue.naruto_sprt,
                    rpg->dialogue.naruto_txt, sfTrue);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->dialogue.kakashi_sprt,
                    NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->dialogue.naruto_sprt,
                    NULL);
}

void print_characters_ramen(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->dialogue.kakashi_sprt, (sfVector2f) {0, 0});
    if (rpg->dialogue.speaking == 0) {
        rpg->dialogue.kakashi_txt = sfTexture_createFromFile(
                        "asset/image/ichiraku_drk.jpg", NULL);
        rpg->dialogue.naruto_txt = sfTexture_createFromFile(
                        "asset/image/naruto_dial.png", NULL);
        sfSprite_setTexture(rpg->dialogue.kakashi_sprt,
                        rpg->dialogue.kakashi_txt, sfTrue);
        sfSprite_setTexture(rpg->dialogue.naruto_sprt,
                        rpg->dialogue.naruto_txt, sfTrue);
        sfRenderWindow_drawSprite(rpg->win.window, rpg->dialogue.kakashi_sprt,
                        NULL);
        sfRenderWindow_drawSprite(rpg->win.window, rpg->dialogue.naruto_sprt,
                        NULL);
    } else
        print_characters_ramen_bis(rpg);
}