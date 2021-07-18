/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** touch
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void touch_character(rpg_t *rpg)
{
    sfFloatRect weapon = sfSprite_getGlobalBounds(rpg->enemy.weapon_sprt);
    sfFloatRect character = sfSprite_getGlobalBounds(rpg->game.team7_sprt);
    const sfFloatRect *weapons = &weapon;
    const sfFloatRect *characters = &character;

    if (sfFloatRect_intersects(weapons, characters, NULL)
        && rpg->quest.side_quest == 5) {
        rpg->enemy.weapon_pos.y = 200;
        rpg->life.remaining_life--;
        rpg->life.size.x -= 15;
        sfRectangleShape_setSize(rpg->life.shape, rpg->life.size);
        sfSprite_setPosition(rpg->enemy.weapon_sprt, rpg->enemy.weapon_pos);
    }
}

void touch_enemy(rpg_t *rpg)
{
    sfFloatRect weapon = sfSprite_getGlobalBounds(rpg->weapon.shuriken_sprt);
    sfFloatRect enemy = sfSprite_getGlobalBounds(rpg->enemy.enemy_sprt);
    const sfFloatRect *weapons = &weapon;
    const sfFloatRect *enemys = &enemy;

    if (sfFloatRect_intersects(weapons, enemys, NULL)
        && rpg->weapon.ready_to_move == 1
        && (rpg->quest.side_quest == 5 || rpg->quest.side_quest == 8)) {
        rpg->weapon.ready_to_move = 0;
        rpg->enemy.life.remaining_life--;
        rpg->enemy.life.size.x -= 20;
        if (rpg->mana.size.x < 100)
            rpg->mana.size.x += 10;
        sfRectangleShape_setSize(rpg->enemy.life.shape, rpg->enemy.life.size);
        sfRectangleShape_setSize(rpg->mana.shape, rpg->mana.size);
    }
}

void touch_enemy_special(rpg_t *rpg)
{
    sfFloatRect special = sfSprite_getGlobalBounds(rpg->special.special_sprt);
    sfFloatRect enemy = sfSprite_getGlobalBounds(rpg->enemy.enemy_sprt);
    const sfFloatRect *specials = &special;
    const sfFloatRect *enemys = &enemy;

    if (sfFloatRect_intersects(specials, enemys, NULL)
        && rpg->special.ready_to_move == 1) {
        rpg->special.ready_to_move = 0;
        rpg->enemy.life.remaining_life = 0;
        rpg->enemy.life.size.x = 0;
        sfRectangleShape_setSize(rpg->enemy.life.shape, rpg->enemy.life.size);
    }
}

void touch_character_special(rpg_t *rpg)
{
    sfFloatRect special = sfSprite_getGlobalBounds(rpg->enemy.special_sprt);
    sfFloatRect character = sfSprite_getGlobalBounds(rpg->game.team7_sprt);
    const sfFloatRect *specials = &special;
    const sfFloatRect *characters = &character;

    if (sfFloatRect_intersects(specials, characters, NULL)
        && rpg->quest.side_quest == 8) {
        rpg->enemy.special_pos.y = 200;
        rpg->life.remaining_life -= 5;
        rpg->life.size.x -= 75;
        sfRectangleShape_setSize(rpg->life.shape, rpg->life.size);
        sfSprite_setPosition(rpg->enemy.special_sprt, rpg->enemy.special_pos);
    }
}

void check_touch(rpg_t *rpg)
{
    touch_enemy(rpg);
    touch_enemy_special(rpg);
    touch_character(rpg);
    touch_character_special(rpg);
}