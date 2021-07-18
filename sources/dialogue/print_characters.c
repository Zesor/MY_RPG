/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** print_characters
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void print_characters_bis(rpg_t *rpg)
{
    rpg->dialogue.kakashi_txt = sfTexture_createFromFile(
                    "asset/image/kakashi_dial.png", NULL);
    rpg->dialogue.naruto_txt = sfTexture_createFromFile(
                    "asset/image/naruto_dial_sbr.png", NULL);
    sfSprite_setTexture(rpg->dialogue.kakashi_sprt,
                    rpg->dialogue.kakashi_txt, sfTrue);
    sfSprite_setTexture(rpg->dialogue.naruto_sprt,
                    rpg->dialogue.naruto_txt, sfTrue);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->dialogue.naruto_sprt,
                    NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->dialogue.kakashi_sprt,
                    NULL);
}

void print_characters(rpg_t *rpg)
{
    if (rpg->dialogue.speaking == 0) {
        rpg->dialogue.kakashi_txt = sfTexture_createFromFile(
                        "asset/image/kakashi_dial_sbr.png", NULL);
        rpg->dialogue.naruto_txt = sfTexture_createFromFile(
                        "asset/image/naruto_dial.png", NULL);
        sfSprite_setTexture(rpg->dialogue.kakashi_sprt,
                        rpg->dialogue.kakashi_txt, sfTrue);
        sfSprite_setTexture(rpg->dialogue.naruto_sprt,
                        rpg->dialogue.naruto_txt, sfTrue);
        sfRenderWindow_drawSprite(rpg->win.window, rpg->dialogue.naruto_sprt,
                        NULL);
        sfRenderWindow_drawSprite(rpg->win.window, rpg->dialogue.kakashi_sprt,
                        NULL);
    } else
        print_characters_bis(rpg);
}