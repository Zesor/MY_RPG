/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create_quest
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void launch_quest(rpg_t *rpg)
{
    print_quest_rec(rpg);
    text_main_quest(rpg, number_quest[rpg->quest.nb_quest][0]);
    text_side_quest(rpg, number_quest[rpg->quest.nb_quest]
                        [rpg->quest.side_quest]);
}

void init_quest(rpg_t *rpg)
{
    rpg->quest.font = sfFont_createFromFile("asset/font/pixel.ttf");
    rpg->quest.title = sfText_create();
    rpg->quest.quest = sfText_create();
    rpg->quest.nb_quest = 0;
    rpg->quest.side_quest = 1;
    rpg->quest.shape = sfRectangleShape_create();
    rpg->quest.size.x = 320;
    rpg->quest.size.y = 50;

    sfRectangleShape_setSize(rpg->quest.shape, rpg->quest.size);
    sfRectangleShape_setFillColor(rpg->quest.shape, sfWhite);
    sfRectangleShape_setOutlineColor(rpg->quest.shape, sfBlack);
    sfRectangleShape_setOutlineThickness(rpg->quest.shape, 3);
}