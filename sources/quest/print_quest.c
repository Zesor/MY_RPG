/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** print_quest
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void print_quest_rec(rpg_t *rpg)
{
    rpg->quest.shape_pos.x = rpg->game.team_7_pos.x - 150;
    rpg->quest.shape_pos.y = rpg->game.team_7_pos.y + 230;

    sfRectangleShape_setPosition(rpg->quest.shape, rpg->quest.shape_pos);
    sfRenderWindow_drawRectangleShape(rpg->win.window, rpg->quest.shape, NULL);
}

void text_side_quest(rpg_t *rpg, const char *buffer)
{
    rpg->quest.quest_pos.x = rpg->game.team_7_pos.x - 140;
    rpg->quest.quest_pos.y = rpg->game.team_7_pos.y + 245;

    sfText_setFont(rpg->quest.quest, rpg->quest.font);
    sfText_setString(rpg->quest.quest, buffer);
    sfText_setCharacterSize(rpg->quest.quest, 15);
    sfText_setStyle(rpg->quest.quest, sfTextBold);
    sfText_setColor(rpg->quest.quest, sfBlack);
    sfText_setPosition(rpg->quest.quest, rpg->quest.quest_pos);
    sfRenderWindow_drawText(rpg->win.window, rpg->quest.quest, NULL);
}

void text_main_quest(rpg_t *rpg, const char *buffer)
{
    rpg->quest.title_pos.x = rpg->game.team_7_pos.x - 40;
    rpg->quest.title_pos.y = rpg->game.team_7_pos.y + 224;

    sfText_setFont(rpg->quest.title, rpg->quest.font);
    sfText_setString(rpg->quest.title, buffer);
    sfText_setCharacterSize(rpg->quest.title, 20);
    sfText_setStyle(rpg->quest.title, sfTextItalic);
    sfText_setStyle(rpg->quest.title, sfTextBold);
    sfText_setColor(rpg->quest.title, sfRed);
    sfText_setPosition(rpg->quest.title, rpg->quest.title_pos);
    sfRenderWindow_drawText(rpg->win.window, rpg->quest.title, NULL);
}