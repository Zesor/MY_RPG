/*
** EPITECH PROJECT, 2021
** graphique
** File description:
** move_character
*/

#include "define.h"
#include "struct.h"
#include "function.h"

void move_sprite(rpg_t *rpg)
{
    rpg->game.team7_rect.left += 50;
    if (rpg->game.team7_rect.left > 100)
        rpg->game.team7_rect.left = 0;
}

void key_released(rpg_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyReleased) {
        rpg->game.team7_rect.left = 50;
        sfSprite_setTextureRect(rpg->game.team7_sprt, rpg->game.team7_rect);
    }
}

void move_character_right_left(rpg_t *rpg, int speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        check_collision_house_left(rpg, speed);
        sfSprite_setPosition(rpg->game.team7_sprt, rpg->game.team_7_pos);
        sfSprite_setTextureRect(rpg->game.team7_sprt, rpg->game.team7_rect);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        check_collision_house_right(rpg, speed);
        sfSprite_setPosition(rpg->game.team7_sprt, rpg->game.team_7_pos);
        sfSprite_setTextureRect(rpg->game.team7_sprt, rpg->game.team7_rect);
    }
}

void move_character_up_down(rpg_t *rpg, int speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
            speed += 3;
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        check_collision_house_down(rpg, speed);
        sfSprite_setPosition(rpg->game.team7_sprt, rpg->game.team_7_pos);
        sfSprite_setTextureRect(rpg->game.team7_sprt, rpg->game.team7_rect);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        check_collision_house_up(rpg, speed);
        sfSprite_setPosition(rpg->game.team7_sprt, rpg->game.team_7_pos);
        sfSprite_setTextureRect(rpg->game.team7_sprt, rpg->game.team7_rect);
    }
    move_character_right_left(rpg, speed);
    sfClock_restart(rpg->general_clock);
}