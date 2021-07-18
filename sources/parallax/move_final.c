/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** move_final
*/

#include "struct.h"
#include "function.h"
#include "define.h"

void move_naruto(rpg_t *rpg)
{
    rpg->paral.naruto_rect.left += 50;
    if (rpg->paral.naruto_rect.left > 100)
        rpg->paral.naruto_rect.left = 0;
}

void key_releas(rpg_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyReleased) {
        rpg->paral.naruto_rect.left = 50;
        sfSprite_setTextureRect(rpg->paral.naruto_sprt, rpg->paral.naruto_rect);
    }
}

void move_character_right_lefts(rpg_t *rpg, int speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        sfSprite_setPosition(rpg->paral.naruto_sprt, rpg->paral.naruto_pos);
        sfSprite_setTextureRect(rpg->paral.naruto_sprt, rpg->paral.naruto_rect);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        sfSprite_setPosition(rpg->paral.naruto_sprt, rpg->paral.naruto_pos);
        sfSprite_setTextureRect(rpg->paral.naruto_sprt, rpg->paral.naruto_rect);
    }
    sfClock_restart(rpg->general_clock);
}

void move_rects(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;

    if (rect->left >= max_value)
        rect->left = 0;
}

void using_clock_parallax_bis(rpg_t *rpg)
{
    if (rpg->special.ready_to_move == 1 && rpg->general_seconds < 0.1) {
        move_rects(&rpg->special.special_rect, 70, 421);
        sfClock_restart(rpg->general_clock);
        sfSprite_setTextureRect(rpg->special.special_sprt,
                rpg->special.special_rect);
    }
}