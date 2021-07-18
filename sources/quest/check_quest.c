/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** check_quest
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void quest_kakashi_tutorial(rpg_t *rpg)
{
    if ((rpg->quest.side_quest == 3 || rpg->quest.side_quest == 6
        || rpg->quest.side_quest == 9) && rpg->kakashi.quest == 1) {
        rpg->kakashi.quest = 0;
        dialogue_tutorial(rpg);
        rpg->quest.side_quest++;
    }
    if (rpg->quest.side_quest == 8 && rpg->enemy.life.size.x == 0)
        rpg->quest.side_quest = 9;
}

void quest_tutorial_bis(rpg_t *rpg)
{
    if ((sfKeyboard_isKeyPressed(sfKeyQ)  || sfKeyboard_isKeyPressed(sfKeyZ) ||
        sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyD))
        && rpg->quest.side_quest == 2 && sfKeyboard_isKeyPressed(sfKeyLShift)) {
        rpg->quest.side_quest = 3;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && rpg->quest.side_quest == 4)
        rpg->quest.side_quest = 5;
    if (sfMouse_isButtonPressed(sfMouseRight) && rpg->quest.side_quest == 7) {
        rpg->enemy.enemy_text = sfTexture_createFromFile(
                    "asset/image/sasuke.png", NULL);
        rpg->quest.side_quest = 8;
        rpg->mana.size.x = 100;
        sfRectangleShape_setSize(rpg->mana.shape, rpg->mana.size);
        sfSprite_setTexture(rpg->enemy.enemy_sprt, rpg->enemy.enemy_text,
                            sfTrue);
        sfSprite_setTextureRect(rpg->enemy.enemy_sprt, rpg->enemy.enemy_rect);
    }
    quest_kakashi_tutorial(rpg);
}

void quest_tutorial(rpg_t *rpg)
{
    if ((sfKeyboard_isKeyPressed(sfKeyQ)  || sfKeyboard_isKeyPressed(sfKeyZ) ||
        sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyD))
        && rpg->quest.side_quest == 1)
        rpg->quest.side_quest = 2;
    if (rpg->enemy.life.remaining_life == 0 && rpg->quest.side_quest == 5) {
        rpg->quest.side_quest = 6;
        rpg->enemy.life.remaining_life = 2;
        rpg->enemy.life.size.x = 40;
        rpg->enemy.weapon_pos.y = 200;
        rpg->mana.size.x = 50;
        sfRectangleShape_setSize(rpg->enemy.life.shape, rpg->enemy.life.size);
        sfRectangleShape_setSize(rpg->mana.shape, rpg->mana.size);
        sfSprite_setPosition(rpg->enemy.weapon_sprt, rpg->enemy.weapon_pos);
    }
    quest_tutorial_bis(rpg);
}

void check_quest(rpg_t *rpg)
{
    if (rpg->quest.nb_quest == 0)
        quest_tutorial(rpg);
    if (rpg->quest.nb_quest == 1)
        quest_game(rpg);
}