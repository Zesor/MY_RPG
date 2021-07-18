/*
** EPITECH PROJECT, 2021
** other
** File description:
** text
*/

#include "struct.h"
#include "define.h"
#include "function.h"

sfText *yes_tutorial(sfRenderWindow *window, char *buffer, int i)
{
    sfVector2f position = {650, 450};
    sfFont *font = sfFont_createFromFile("asset/font/pixel.ttf");
    sfText *text2 = sfText_create();

    sfText_setFont(text2, font);
    sfText_setString(text2, buffer);
    sfText_setCharacterSize(text2, 50);
    if (i == 0) {
        sfText_setStyle(text2, sfTextBold);
        sfText_setStyle(text2, sfTextUnderlined);
    }
    sfText_setPosition(text2, position);
    return (text2);
}

sfText *no_tutorial(sfRenderWindow *window, char *buffer, int i)
{
    sfVector2f position = {1100, 450};
    sfFont *font = sfFont_createFromFile("asset/font/pixel.ttf");
    sfText *text2 = sfText_create();

    sfText_setFont(text2, font);
    sfText_setString(text2, buffer);
    sfText_setCharacterSize(text2, 50);
    if (i == 1) {
        sfText_setStyle(text2, sfTextBold);
        sfText_setStyle(text2, sfTextUnderlined);
    }
    sfText_setPosition(text2, position);
    return (text2);
}

sfText *text_tutorial(sfRenderWindow *window, char *buffer)
{
    sfVector2f position = {620, 350};
    sfFont *font = sfFont_createFromFile("asset/font/pixel.ttf");
    sfText *text2 = sfText_create();

    sfText_setFont(text2, font);
    sfText_setString(text2, buffer);
    sfText_setCharacterSize(text2, 40);
    sfText_setStyle(text2, sfTextBold);
    sfText_setPosition(text2, position);
    return (text2);
}