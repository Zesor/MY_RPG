/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdio.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <stdlib.h>
#include <time.h>

typedef struct parallax_s
{
    sfTexture *f_back_text;
    sfSprite *f_back_sprt;

    sfTexture *mount_text;
    sfSprite *mount_sprt;

    sfTexture *w_mount_text;
    sfSprite *w_mount_sprt;

    sfTexture *cloud_text;
    sfSprite *cloud_sprt;

    sfTexture *floor_text;
    sfSprite *floor_sprt;

    sfTexture *naruto_text;
    sfSprite *naruto_sprt;

    sfVector2f naruto_pos;
    sfIntRect naruto_rect;

    sfVector2f sasuke_pos;
    sfIntRect sasuke_rect;

    sfTexture *sasuke_text;
    sfSprite *sasuke_sprt;

    sfTexture *chidori_text;
    sfSprite *chidori_sprt;
    sfVector2f chidori_pos;
    sfIntRect chidori_rect;

    sfVector2f w_pos_mount;
    sfVector2f mount_pos;
    sfVector2f cloud_pos;
} parllax_t;

typedef struct music_s {
    sfMusic *menu_mus;
    sfMusic *pause_music;
    sfMusic *peace_music;
    sfMusic *ending_music;
} music_t;

typedef struct volume_s
{
    int idx;
    sfText *text;
    sfVector2f vector;
} volume_t;

typedef struct framerate_s
{
    unsigned int idx;
    sfText *text;
    sfVector2f vector;
} framerate_t;

typedef struct background_sprites {
    sfTexture *back_texture;
    sfSprite *back_sprite;

    sfTexture *play_text;
    sfSprite *play_sprt;

    sfTexture *htp_text;
    sfSprite *htp_sprite;

    sfTexture *quit_text;
    sfSprite *quit_sprt;

    sfTexture *option_text;
    sfSprite *option_sprt;

    sfTexture *play_drk;
    sfSprite *play_drk_sprt;

    sfTexture *quit_drk;
    sfSprite *quit_drk_sprt;

    sfTexture *htp_drk;
    sfSprite *htp_drk_sprt;

    sfTexture *opt_drk;
    sfSprite *opt_drk_sprt;

    sfTexture *play_real;
    sfSprite *play_real_sprt;

    sfTexture *htp_real;
    sfSprite *htp_real_sprt;

    sfTexture *opt_real;
    sfSprite *opt_real_sprt;

    sfTexture *back_htp_xt;
    sfSprite *back_htp_sprt;

    sfTexture *htp_key_tx;
    sfSprite *htp_key_sprt;

    sfTexture *return_text;
    sfSprite *return_sprt;

    sfTexture *return_drk_txt;
    sfSprite *return_drk_sprt;
} background_t;

typedef struct mana_s {
    sfRectangleShape *shape;
    sfVector2f position;
    sfVector2f size;
    int remaining_mana;

    sfRectangleShape *black_shape;
} mana_t;

typedef struct game_s
{
    sfTexture *fond_text;
    sfSprite *fond_sprt;

    sfTexture *team7_text;
    sfSprite *team7_sprt;
    sfVector2f team_7_pos;
    sfIntRect team7_rect;
    sfView *view;

    sfTexture *f_home_text;
    sfSprite *f_home_sprt;

    sfTexture *f_home_text2;
    sfSprite *f_home_sprt2;

    sfTexture *f_home_text3;
    sfSprite *f_home_sprt3;

    sfTexture *ichiraku_text;
    sfSprite *ichiraku_sprt;

    sfTexture *tower_text;
    sfSprite *tower_sprt;

    sfTexture *shop_text;
    sfSprite *shop_sprt;

    sfTexture *route_text;
    sfSprite *route_sprt;

    sfTexture *route_text2;
    sfSprite *route_sprt2;

    sfTexture *door_text;
    sfSprite *door_sprt;
    sfTexture *tree_text;
    sfSprite *tree_sprt;
    sfTexture *tree_text2;
    sfSprite *tree_sprt2;
    sfTexture *tree_text3;
    sfSprite *tree_sprt3;
    sfTexture *tree_text4;
    sfSprite *tree_sprt4;
} game_t;

typedef struct pause_s {
    sfTexture *menu_text;
    sfSprite *menu_sprt;

    sfTexture *menu_but_text;
    sfSprite *menu_but_sprt;

    sfTexture *quit_text;
    sfSprite *quit_sprt;

    sfTexture *menu_drk_t;
    sfSprite *menu_drk_sprt;

    sfTexture *quit_drk_t;
    sfSprite *quit_drk_sprt;

    sfTexture *menu_real;
    sfSprite *menu_real_spt;
} pause_t;

typedef struct quest_s {
    sfVector2f title_pos;
    sfFont *font;
    sfText *title;
    sfVector2f quest_pos;
    sfText *quest;
    int nb_quest;
    int side_quest;

    sfRectangleShape *shape;
    sfVector2f shape_pos;
    sfVector2f size;
} quest_t;

typedef struct dialogue_s {
    sfSprite *naruto_sprt;
    sfTexture *naruto_txt;

    sfSprite *kakashi_sprt;
    sfTexture *kakashi_txt;

    sfSprite *tenten_sprt;
    sfTexture *tenten_txt;

    sfSprite *key_sprt;
    sfTexture *key_txt;

    sfRectangleShape *shape;

    sfText *text;
    sfText *speaking_txt;
    sfFont *font;
    int nb_dialogue;
    int speaking;
    int real_dialogue;
} dialogue_t;


typedef struct special_s {
    sfTexture *special_txt;
    sfSprite *special_sprt;
    sfVector2f special_pos;
    sfIntRect special_rect;
    sfVector2f pos_mouse;
    int ready_to_move;
} special_t;

typedef struct weapon_s {
    sfTexture *shuriken_txt;
    sfSprite *shuriken_sprt;
    sfVector2f shuriken_pos;
    sfIntRect shuriken_rect;
    sfVector2f pos_mouse;
    int ready_to_move;
} weapon_t;

typedef struct life_s {
    sfRectangleShape *shape;
    sfVector2f position;
    sfVector2f size;
    int remaining_life;
    sfVector2f lose;

    sfRectangleShape *red_shape;
} life_t;

typedef struct kakashi_s {
    sfTexture *kakashi_txt;
    sfSprite *kakashi_sprt;
    sfVector2f kakashi_pos;
    sfIntRect kakashi_rect;
    life_t life;

    sfRectangleShape *shape;

    int quest;
} kakashi_t;

typedef struct enemy_s {
    sfTexture *enemy_text;
    sfSprite *enemy_sprt;
    sfVector2f enemy_pos;
    sfIntRect enemy_rect;
    life_t life;

    sfTexture *weapon_txt;
    sfSprite *weapon_sprt;
    sfVector2f weapon_pos;
    sfIntRect weapon_rect;

    sfTexture *special_txt;
    sfSprite *special_sprt;
    sfVector2f special_pos;
    sfIntRect special_rect;

    sfSprite *first_clone;
    sfSprite *weapon_first;
    sfVector2f weapon_first_pos;
    sfVector2f clone_first_pos;
    sfRectangleShape *rect_first;
    sfVector2f size_first;

    sfSprite *second_clone;
    sfSprite *weapon_second;
    sfVector2f weapon_second_pos;
    sfVector2f clone_second_pos;
    sfRectangleShape *rect_second;
    sfVector2f size_second;

    sfSprite *third_clone;
    sfSprite *weapon_third;
    sfVector2f weapon_third_pos;
    sfVector2f clone_third_pos;
    sfRectangleShape *rect_third;
    sfVector2f size_third;

    sfSprite *fourth_clone;
    sfSprite *weapon_fourth;
    sfVector2f weapon_fourth_pos;
    sfVector2f clone_fourth_pos;
    sfRectangleShape *rect_fourth;
    sfVector2f size_fourth;

    sfSprite *fifth_clone;
    sfSprite *weapon_fifth;
    sfVector2f weapon_fifth_pos;
    sfVector2f clone_fifth_pos;
    sfRectangleShape *rect_fifth;
    sfVector2f size_fifth;
} enemy_t;

typedef struct settings_s {
    sfTexture *fond_text;
    sfSprite *fond_sprt;

    sfTexture *vol_txt;
    sfSprite *vol_spr;

    sfTexture *frmt_txt;
    sfSprite *frmt_spr;

    sfTexture *ret_txt;
    sfSprite *ret_spr;

    sfTexture *vol_incr_t;
    sfSprite *vol_incr_s;

    sfTexture *vol_decr_t;
    sfSprite *vol_decr_s;

    sfTexture *fmt_incr_t;
    sfSprite *fmt_incr_s;

    sfTexture *fmt_decr_t;
    sfSprite *fmt_decr_s;
} settings_t;

typedef struct frame_s
{
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} frame_t;

typedef struct rain_s
{
    sfVector2f beg;
    sfVector2f end;
    float speed;
    float len;
    sfColor color;
} rain_t;

typedef struct ending_s
{
    sfTexture *end_text;
    sfSprite *end_sprt;
    sfVector2f pos;
} ending_t;

typedef struct window_s
{
    sfRenderWindow *window;
    sfVideoMode mode;
    unsigned int width;
    unsigned int height;
    frame_t *frame;
    sfTexture *texture;
    sfSprite *sprite;
} window_t;
typedef struct button_s {
    sfRectangleShape *shape;
    sfVector2f position;
    sfVector2f size;
    sfTexture *texture;
    int reset;
} button_s;

typedef struct inventory_s {
    int shop;
    int scroll;
    int ramen;
    int ramen_shop;
    sfRectangleShape *shape1;
    sfRectangleShape *shape2;
    sfRectangleShape *shape3;

} inventory_t;

typedef struct rpg_s {
    window_t win;
    background_t back;
    music_t music;
    game_t game;
    pause_t pause;
    settings_t opt;
    volume_t vol;
    framerate_t fmt;
    weapon_t weapon;
    special_t special;
    sfClock *general_clock;
    sfTime general_time;
    float general_seconds;
    life_t life;
    quest_t quest;
    mana_t mana;
    enemy_t enemy;
    dialogue_t dialogue;
    kakashi_t kakashi;
    parllax_t paral;
    ending_t end;
    inventory_t invent;
} rpg_t;

#endif /* !STRUCT_H_ */