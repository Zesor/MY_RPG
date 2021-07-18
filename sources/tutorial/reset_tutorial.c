/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** reset_tutorial
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void reset_tutorial(rpg_t *rpg)
{
    rpg->quest.nb_quest = 0;
    rpg->quest.side_quest = 1;
    rpg->dialogue.nb_dialogue = 0;
    rpg->dialogue.speaking = 0;
    rpg->dialogue.real_dialogue = 2;
    rpg->enemy.life.remaining_life = 2;
    rpg->enemy.life.size.x = 40;
    rpg->enemy.life.size.y = 10;
    rpg->game.team_7_pos.x = 700;
    rpg->game.team_7_pos.y = 400;
    rpg->mana.size.x = 0;
    rpg->kakashi.kakashi_pos.x = 800;
    rpg->kakashi.kakashi_pos.y = rpg->game.team_7_pos.y;
    sfSprite_setPosition(rpg->kakashi.kakashi_sprt, rpg->kakashi.kakashi_pos);
    sfSprite_setPosition(rpg->game.team7_sprt, rpg->game.team_7_pos);
    sfRectangleShape_setSize(rpg->enemy.life.shape, rpg->enemy.life.size);
}