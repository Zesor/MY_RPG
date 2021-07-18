/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init_dialogue
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void init_text_dialogue(rpg_t *rpg)
{
    rpg->dialogue.nb_dialogue = 0;
    rpg->dialogue.speaking = 0;
    rpg->dialogue.real_dialogue = 2;
    rpg->dialogue.text = sfText_create();
    rpg->dialogue.font = sfFont_createFromFile("asset/font/naruto.ttf");
    rpg->dialogue.speaking_txt = sfText_create();
}

void init_rect_dialogue(rpg_t *rpg)
{
    rpg->dialogue.shape = sfRectangleShape_create();
    sfColor orange = sfColor_fromRGB(250, 150, 100);

    sfRectangleShape_setSize(rpg->dialogue.shape, (sfVector2f) {1850, 400});
    sfRectangleShape_setPosition(rpg->dialogue.shape, (sfVector2f) {40, 605});
    sfRectangleShape_setFillColor(rpg->dialogue.shape, sfWhite);
    sfRectangleShape_setOutlineColor(rpg->dialogue.shape, orange);
    sfRectangleShape_setOutlineThickness(rpg->dialogue.shape, 20);
    init_text_dialogue(rpg);
}

void init_dialogue(rpg_t *rpg)
{
    rpg->dialogue.naruto_txt = sfTexture_createFromFile(
            "asset/image/naruto_dial.png", NULL);
    rpg->dialogue.naruto_sprt = sfSprite_create();
    rpg->dialogue.kakashi_txt = sfTexture_createFromFile(
            "asset/image/kakashi_dial.png", NULL);
    rpg->dialogue.kakashi_sprt = sfSprite_create();
    rpg->dialogue.key_sprt = sfSprite_create();
    rpg->dialogue.key_txt = sfTexture_createFromFile(
            "asset/image/key.png", NULL);

    sfSprite_setTexture(rpg->dialogue.key_sprt, rpg->dialogue.key_txt, sfTrue);
    sfSprite_setTexture(rpg->dialogue.naruto_sprt, rpg->dialogue.naruto_txt,
                        sfTrue);
    sfSprite_setTexture(rpg->dialogue.kakashi_sprt, rpg->dialogue.kakashi_txt,
                        sfTrue);
    sfSprite_setPosition(rpg->dialogue.key_sprt, (sfVector2f) {100, 850});
    sfSprite_setPosition(rpg->dialogue.kakashi_sprt, (sfVector2f) {1400, 200});
    sfSprite_setPosition(rpg->dialogue.naruto_sprt, (sfVector2f) {100, 300});
    init_rect_dialogue(rpg);
}