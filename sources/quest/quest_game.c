/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** quest_game
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void quest_game_bis(rpg_t *rpg)
{
    if (rpg->quest.side_quest == 5) {
        fight_loop(rpg);
        rpg->quest.side_quest++;
    }
    if (rpg->quest.side_quest == 6 && rpg->kakashi.quest == 1) {
        sfSprite_setPosition(rpg->game.team7_sprt, rpg->game.team_7_pos);
        rpg->dialogue.real_dialogue = 10;
        rpg->kakashi.quest = 0;
        dialogue_kakashi(rpg);
        rpg->quest.side_quest++;
    }
}

void quest_game(rpg_t *rpg)
{
    rpg->dialogue.nb_dialogue = 3;
    if (rpg->quest.side_quest == 1 && rpg->kakashi.quest == 1) {
        rpg->kakashi.quest = 0;
        dialogue_kakashi(rpg);
        rpg->quest.side_quest++;
    }
    if (rpg->quest.side_quest == 4 && rpg->kakashi.quest == 1) {
        rpg->dialogue.speaking = 0;
        rpg->dialogue.real_dialogue = 6;
        rpg->kakashi.quest = 0;
        dialogue_kakashi(rpg);
        rpg->quest.side_quest++;
    }
    quest_game_bis(rpg);
}