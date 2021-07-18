/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** destroy_quest_and_co
*/

#include "struct.h"
#include "function.h"

static void destroy_quest_and_dialogue(rpg_t *rpg)
{
    sfFont_destroy(rpg->quest.font);
    sfText_destroy(rpg->quest.title);
    sfText_destroy(rpg->quest.quest);
    sfRectangleShape_destroy(rpg->quest.shape);
    sfSprite_destroy(rpg->dialogue.naruto_sprt);
    sfTexture_destroy(rpg->dialogue.naruto_txt);
    sfSprite_destroy(rpg->dialogue.kakashi_sprt);
    sfTexture_destroy(rpg->dialogue.kakashi_txt);
    sfSprite_destroy(rpg->dialogue.key_sprt);
    sfTexture_destroy(rpg->dialogue.key_txt);
    sfRectangleShape_destroy(rpg->dialogue.shape);
    sfText_destroy(rpg->dialogue.text);
    sfText_destroy(rpg->dialogue.speaking_txt);
    sfFont_destroy(rpg->dialogue.font);
    sfTexture_destroy(rpg->special.special_txt);
    sfSprite_destroy(rpg->special.special_sprt);
    sfTexture_destroy(rpg->weapon.shuriken_txt);
    sfSprite_destroy(rpg->weapon.shuriken_sprt);
    sfRectangleShape_destroy(rpg->life.shape);
    sfRectangleShape_destroy(rpg->life.red_shape);
}

static void destroy_enemy(rpg_t *rpg)
{
    sfTexture_destroy(rpg->kakashi.kakashi_txt);
    sfSprite_destroy(rpg->kakashi.kakashi_sprt);
    sfRectangleShape_destroy(rpg->kakashi.shape);
    sfTexture_destroy(rpg->enemy.enemy_text);
    sfSprite_destroy(rpg->enemy.enemy_sprt);
    sfTexture_destroy(rpg->enemy.weapon_txt);
    sfSprite_destroy(rpg->enemy.weapon_sprt);
    sfTexture_destroy(rpg->enemy.special_txt);
    sfSprite_destroy(rpg->enemy.special_sprt);
    sfRectangleShape_destroy(rpg->mana.shape);
    sfRectangleShape_destroy(rpg->mana.black_shape);
    sfTexture_destroy(rpg->game.route_text2);
    sfSprite_destroy(rpg->game.route_sprt2);
    sfTexture_destroy(rpg->game.tree_text);
    sfSprite_destroy(rpg->game.tree_sprt);
    sfTexture_destroy(rpg->game.tree_text2);
    sfSprite_destroy(rpg->game.tree_sprt2);
    sfTexture_destroy(rpg->game.tree_text3);
    sfSprite_destroy(rpg->game.tree_sprt3);
    sfTexture_destroy(rpg->game.tree_text4);
}

static void destroy_settings(rpg_t *rpg)
{
    sfTexture_destroy(rpg->opt.fond_text);
    sfSprite_destroy(rpg->opt.fond_sprt);
    sfTexture_destroy(rpg->opt.vol_txt);
    sfSprite_destroy(rpg->opt.vol_spr);
    sfTexture_destroy(rpg->opt.ret_txt);
    sfSprite_destroy(rpg->opt.ret_spr);
    sfTexture_destroy(rpg->opt.vol_incr_t);
    sfSprite_destroy(rpg->opt.vol_incr_s);
    sfTexture_destroy(rpg->opt.vol_decr_t);
    sfSprite_destroy(rpg->opt.vol_incr_s);
    sfTexture_destroy(rpg->opt.fmt_incr_t);
    sfSprite_destroy(rpg->opt.fmt_incr_s);
    sfTexture_destroy(rpg->opt.fmt_decr_t);
    sfSprite_destroy(rpg->opt.fmt_decr_s);
    sfSprite_destroy(rpg->game.route_sprt);
    sfSprite_destroy(rpg->game.tree_sprt4);
}

void destroy_every(rpg_t *rpg)
{
    destroy_quest_and_dialogue(rpg);
    destroy_enemy(rpg);
    destroy_settings(rpg);
    sfTexture_destroy(rpg->game.fond_text);
    sfSprite_destroy(rpg->game.fond_sprt);
    sfTexture_destroy(rpg->game.team7_text);
    sfSprite_destroy(rpg->game.team7_sprt);
    sfTexture_destroy(rpg->game.f_home_text);
    sfSprite_destroy(rpg->game.f_home_sprt);
    sfTexture_destroy(rpg->game.f_home_text2);
    sfSprite_destroy(rpg->game.f_home_sprt2);
    sfTexture_destroy(rpg->game.f_home_text3);
    sfSprite_destroy(rpg->game.f_home_sprt3);
    sfTexture_destroy(rpg->game.ichiraku_text);
    sfSprite_destroy(rpg->game.ichiraku_sprt);
    sfTexture_destroy(rpg->game.tower_text);
    sfSprite_destroy(rpg->game.tower_sprt);
    sfTexture_destroy(rpg->game.shop_text);
    sfSprite_destroy(rpg->game.shop_sprt);
    sfTexture_destroy(rpg->game.route_text);
}