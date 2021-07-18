/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** check_character_fight
*/

#include "struct.h"
#include "define.h"
#include "function.h"

sfVector2f touch_character_clone(rpg_t *rpg, sfSprite *shuriken,
                            sfVector2f enemy_pos, sfVector2f pos)
{
    sfFloatRect weapon = sfSprite_getGlobalBounds(shuriken);
    sfFloatRect character = sfSprite_getGlobalBounds(rpg->game.team7_sprt);
    const sfFloatRect *weapons = &weapon;
    const sfFloatRect *characters = &character;

    if (sfFloatRect_intersects(weapons, characters, NULL)) {
        rpg->life.remaining_life--;
        rpg->life.size.x -= 15;
        pos = enemy_pos;
        sfRectangleShape_setSize(rpg->life.shape, rpg->life.size);
        sfSprite_setPosition(shuriken, enemy_pos);
        return pos;
    }
    return pos;
}

void check_every_clone(rpg_t *rpg)
{

    if (rpg->enemy.size_first.x <= 0 &&
        rpg->enemy.size_second.x <= 0 &&
        rpg->enemy.size_third.x <= 0 &&
        rpg->enemy.size_fourth.x <= 0 &&
        rpg->enemy.size_fifth.x <= 0) {
            rpg->game.team_7_pos.x = 220;
            rpg->game.team_7_pos.y = 20;
            sfSprite_setPosition(rpg->game.team7_sprt, rpg->game.team_7_pos);
            sfSprite_setColor(rpg->game.fond_sprt, sfWhite);
            rpg->quest.side_quest++;
            game_loop(rpg);
        }
}

void check_character_fight(rpg_t *rpg)
{
    if (rpg->enemy.size_first.x > 0)
        rpg->enemy.weapon_first_pos = touch_character_clone(rpg,
                rpg->enemy.weapon_first, rpg->enemy.clone_first_pos,
                rpg->enemy.weapon_first_pos);
    if (rpg->enemy.size_second.x > 0)
        rpg->enemy.weapon_second_pos = touch_character_clone(rpg,
                rpg->enemy.weapon_second, rpg->enemy.clone_second_pos,
                rpg->enemy.weapon_second_pos);
    if (rpg->enemy.size_third.x > 0)
        rpg->enemy.weapon_third_pos = touch_character_clone(rpg,
                rpg->enemy.weapon_third, rpg->enemy.clone_third_pos,
                rpg->enemy.weapon_third_pos);
    if (rpg->enemy.size_fourth.x > 0)
        rpg->enemy.weapon_fourth_pos = touch_character_clone(rpg,
                rpg->enemy.weapon_fourth, rpg->enemy.clone_fourth_pos,
                rpg->enemy.weapon_fourth_pos);
    if (rpg->enemy.size_fifth.x > 0)
        rpg->enemy.weapon_fifth_pos = touch_character_clone(rpg,
                rpg->enemy.weapon_fifth, rpg->enemy.clone_fifth_pos,
                rpg->enemy.weapon_fifth_pos);
    check_every_clone(rpg);
}