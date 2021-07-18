/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** text_dialogue
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void text_speaking(rpg_t *rpg, const char *buffer)
{
    sfColor grey = sfColor_fromRGB(120, 120, 120);
    sfColor orange = sfColor_fromRGB(250, 150, 100);

    sfText_setFont(rpg->dialogue.speaking_txt, rpg->dialogue.font);
    sfText_setString(rpg->dialogue.speaking_txt, buffer);
    sfText_setCharacterSize(rpg->dialogue.speaking_txt, 30);
    sfText_setStyle(rpg->dialogue.speaking_txt, sfTextItalic);
    sfText_setStyle(rpg->dialogue.speaking_txt, sfTextUnderlined);
    if (rpg->dialogue.speaking == 0)
        sfText_setColor(rpg->dialogue.speaking_txt, orange);
    else
        sfText_setColor(rpg->dialogue.speaking_txt, grey);
    sfText_setPosition(rpg->dialogue.speaking_txt, (sfVector2f) {900, 700});
    sfRenderWindow_drawText(rpg->win.window, rpg->dialogue.speaking_txt, NULL);
}

void text_dialogue(rpg_t *rpg, const char *buffer)
{
    sfText_setFont(rpg->dialogue.text, rpg->dialogue.font);
    sfText_setString(rpg->dialogue.text, buffer);
    sfText_setCharacterSize(rpg->dialogue.text, 50);
    sfText_setStyle(rpg->dialogue.text, sfTextBold);
    sfText_setColor(rpg->dialogue.text, sfBlack);
    sfText_setPosition(rpg->dialogue.text, (sfVector2f) {700, 800});
    sfRenderWindow_drawText(rpg->win.window, rpg->dialogue.text, NULL);
}

void print_kakashi_text(rpg_t *rpg)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("asset/font/pixel.ttf");
    sfVector2f pos = rpg->kakashi.kakashi_pos;
    pos.x -= 70;
    pos.y -= 30;

    sfText_setFont(text, font);
    sfText_setString(text, "You are not done yet.");
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfBlack);
    sfText_setStyle(text, sfTextBold);
    sfText_setCharacterSize(text, 15);
    sfRenderWindow_drawText(rpg->win.window, text, NULL);
}

void print_kakashi_rec(rpg_t *rpg)
{
    sfVector2f pos = rpg->kakashi.kakashi_pos;
    pos.x -= 75;
    pos.y -= 30;

    sfRectangleShape_setPosition(rpg->kakashi.shape, pos);
    sfRenderWindow_drawRectangleShape(rpg->win.window,
                            rpg->kakashi.shape, NULL);
    print_kakashi_text(rpg);
}