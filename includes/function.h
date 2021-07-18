/*
** EPITECH PROJECT, 2021
** func
** File description:
** func
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_
#include "struct.h"
#include "define.h"

//          [PARTICULES]        //

void draw_life_and_manas(rpg_t *rpg);
void move_ending(rpg_t *rpg);
void init_ending(rpg_t *rpg);
void drawing_menu_sprite(rpg_t *rpg);
void rain(rpg_t *rpg);
int gen_particles(void);
float get_random_float(float const min, float const max);
sfColor get_random_color(unsigned char opacity);
frame_t *frame_create(unsigned int width, unsigned int height);
void frame_clear(frame_t *frame, sfColor color);
void frame_destroy(frame_t *frame);
void my_put_pixel(frame_t *frame, unsigned int x,
                unsigned int y, sfColor color);
void draw_line(frame_t *frame, sfVector2f point_a,
                sfVector2f point_b, sfColor color);
int map_int(int x, int const in_min, int const in_max,
            int const out_min, int const out_max);
float map_float(float x, float const in_min, float const in_max,
                float const out_min, float const out_max);
void swap_int(int *array, int index_1, int index_2);
sfColor hsb_to_rgb(float hue, float saturation, float brightness,
                    unsigned char opacity);
rpg_t *window_create(unsigned int width, unsigned int height,
                    char const *title);
void window_refresh(rpg_t *window, sfColor *color);
void window_destroy(rpg_t *window);
void poll_events(rpg_t *rpg);
void rainbow_rain(rpg_t *window);

//          [DESTROY]       //

void destroy_pause_back_paral(rpg_t *rpg);
void destroy_every(rpg_t *rpg);

//          [PARALLAX]  //

void anime_chidori(rpg_t *rpg);
void init_chidori(rpg_t *rpg);
void parallax_loop(rpg_t *rpg);
void init_parallax(rpg_t *rpg);
void init_paral_object(rpg_t *rpg);
void moving_parallax(rpg_t *rpg);
void enter_to_last_fight(rpg_t *rpg);
void init_player(rpg_t *rpg);
void using_clock_parallax(rpg_t *rpg);
void using_clock_parallax_bis(rpg_t *rpg);
void move_character_right_lefts(rpg_t *rpg, int speed);
void move_rects(sfIntRect *rect, int offset, int max_value);
void move_shuriken_para(rpg_t *rpg);
void press_shuriken_mouse(rpg_t *rpg);
void touch_naruto(rpg_t *rpg);
//          [MAP]       //

char *parse_map(rpg_t *rpg, char *map);

//          [OTHER]     //

char **my_str_to_word_array(char *str, const char *limit);
char **fs_open_file(char const *filepath);
unsigned int array_len(char **array);
char *my_str_to_null(char *s, int c);
void init_player2(rpg_t *rpg);

//        [Menu]        //

void init_window(rpg_t *rpg);
void background_sprt(rpg_t *rpg);
void animation_back(rpg_t *rpg);
void animation_back(rpg_t *rpg);
int menu_loop(rpg_t *rpg);
int main_loop(rpg_t *rpg);
void button_set(rpg_t *rpg);
void button_quit_handler(rpg_t *rpg);
void button_play_handler(rpg_t *rpg, sfEvent event);
void music_menu(rpg_t *rpg);
void button_effect(rpg_t *rpg);
void button_option_handler(rpg_t *rpg, sfEvent event);
void button_htp_handler(rpg_t *rpg, sfEvent event);
void button_effect2(rpg_t *rpg);
int htp_loop(rpg_t *rpg);
void play_realeased_and_htp(rpg_t *rpg);
struct object *create_sprite(const char *pathfile,
                            sfVector2f vector, sfIntRect rect);
struct button_s *init_butt(sfVector2f pos, sfVector2f size);
void light_play_and_htp(rpg_t *rpg);
void light_option(rpg_t *rpg);
int option_loop(rpg_t *rpg);
void back_htp(rpg_t *rpg);
void htp_button(rpg_t *rpg);
void back_htp_bis(rpg_t *rpg);

//          [GAME]       //

int game_loop(rpg_t *rpg);
void init_team7(rpg_t *rpg);
void background_game(rpg_t *rpg);
void move_character_up_down(rpg_t *rpg, int speed);
void key_released(rpg_t *rpg, sfEvent event);
void init_view(rpg_t *rpg);
void update_view(rpg_t *rpg);
void using_clock_game(rpg_t *rpg);
void press_left_mouse(rpg_t *rpg);
void move_shuriken(rpg_t *rpg);
void init_red_life(rpg_t *rpg);
void init_life(rpg_t *rpg);
void init_shuriken(rpg_t *rpg);
void inventory_cases(rpg_t *rpg);
void use_items(rpg_t *rpg);
void init_mana(rpg_t *rpg);
void draw_life_and_mana(rpg_t *rpg);
void init_special_attack(rpg_t *rpg);
void draw_special_and_shuriken(rpg_t *rpg);
void press_right_mouse(rpg_t *rpg);
void move_special(rpg_t *rpg);
void move_rect(sfIntRect *rect, int offset, int max_value);
void music_in_game(rpg_t *rpg);
void game_object(rpg_t *rpg);
void game_object2(rpg_t *rpg);
void game_object3(rpg_t *rpg);
void game_object4(rpg_t *rpg);
void game_object5(rpg_t *rpg);
void init_tree(rpg_t *rpg);
void init_tree2(rpg_t *rpg);
void check_collision_house_up(rpg_t *rpg, int speed);
void move_sprite(rpg_t *rpg);
void check_collision_house_right(rpg_t *rpg, int speed);
void check_collision_house_left(rpg_t *rpg, int speed);
void check_collision_house_down(rpg_t *rpg, int speed);
int general_collision_up_down(rpg_t *rpg, int x, int w, int y);
int general_collision_left_right(rpg_t *rpg, int x, int w, int y);
void naruto_bars(rpg_t *rpg);

//          [FIGHT]        //

void fight_loop(rpg_t *rpg);
void init_clone(rpg_t *rpg);
sfVector2f move_shuriken_clone(rpg_t *rpg, sfVector2f weapon,
                            sfVector2f clone, sfSprite *sprite);
void clone_shuriken(rpg_t *rpg);
void life_clones(rpg_t *rpg);
void init_pos_weapon(rpg_t *rpg);
void check_character_fight(rpg_t *rpg);
void check_enemy_fight(rpg_t *rpg);
void draw_clones(rpg_t *rpg);

//          [TUTORIAL]     //

void ask_for_tutorial_loop(rpg_t *rpg);
sfText *yes_tutorial(sfRenderWindow *window, char *buffer, int i);
sfText *no_tutorial(sfRenderWindow *window, char *buffer, int i);
sfText *text_tutorial(sfRenderWindow *window, char *buffer);
void init_enemy(rpg_t *rpg);
int tutorial_loop(rpg_t *rpg);
void print_enemy(rpg_t *rpg);
void using_clock_tutorial(rpg_t *rpg);
void check_touch(rpg_t *rpg);
void move_shuriken_enemy(rpg_t *rpg);
void move_special_enemy(rpg_t *rpg);
void init_kakashi(rpg_t *rpg);
void talk_hitbox(rpg_t *rpg);
void move_kakashi(rpg_t *rpg);
void print_kakashi_rec(rpg_t *rpg);
void reset_tutorial(rpg_t *rpg);

//          [DIALOGUE]      //

void dialogue_tutorial(rpg_t *rpg);
void init_dialogue(rpg_t *rpg);
void text_dialogue(rpg_t *rpg, const char *buffer);
void text_speaking(rpg_t *rpg, const char *buffer);
void print_characters(rpg_t *rpg);
void print_characters_shop(rpg_t *rpg);
void print_characters_ramen(rpg_t *rpg);
int shop_loop(rpg_t *rpg);
void dialogue_shop(rpg_t *rpg);
void activate_shop(rpg_t *rpg);
int ramen_loop(rpg_t *rpg);
void dialogue_ramen(rpg_t *rpg);
void activate_ramen(rpg_t *rpg);
void draw_dialogue_kakashi(rpg_t *rpg);
void dialogue_kakashi(rpg_t *rpg);

//          [PAUSE]        //

void init_pause_sprt(rpg_t *rpg);
void init_drk_pause_sprt(rpg_t *rpg);
void pause_loop(rpg_t *rpg);
void pause_quit_handler(rpg_t *rpg);
void pause_menu_handler(rpg_t *rpg, sfEvent event);
void init_real_sprt(rpg_t *rpg);
void light_button(rpg_t *rpg);
void launch_pause(rpg_t *rpg);
void music_pause(rpg_t *rpg);

//          [OPTION]        //

void seetings_sprt(rpg_t *rpg);
void settings_retur(rpg_t *rpg);
void return_settings_sprite(rpg_t *rpg);
void init_volume_buttons(rpg_t *rpg);
void init_framerate_buttons(rpg_t *rpg);
sfText *init_txt_color(int size, sfVector2f vect, char *str, sfColor color);
char *my_itoa(int nbr);
size_t my_strlen(const char *str);
char *my_strcat(char *dest, char *src);
int change_volume(int idx, rpg_t *rpg);
int change_framerate(unsigned int idx, rpg_t *rpg);
void init_volume(rpg_t *rpg, sfVector2f vector, sfText *text, int idx);

//          [QUEST]         //

void launch_quest(rpg_t *rpg);
void init_quest(rpg_t *rpg);
void text_main_quest(rpg_t *rpg, const char *buffer);
void text_side_quest(rpg_t *rpg, const char *buffer);
void print_quest_rec(rpg_t *rpg);
void check_quest(rpg_t *rpg);
void quest_game(rpg_t *rpg);

//          [CURSOR]        //

sfSprite *init_cursor(sfRenderWindow *window, char *filepath, int x, int y);

//          [LOSE]          //

void check_lose(rpg_t *rpg);
void change_pos_text(rpg_t *rpg, sfSprite *menu, sfSprite *quit);
void lose_menu_handler(rpg_t *rpg, sfEvent event, sfSprite *menu);
void lose_quit_handler(rpg_t *rpg, sfSprite *quit);
sfSprite *create_lose(char *pathfile);
void ending_song(rpg_t *rpg);
void destroy_music(rpg_t *rpg);

#endif /* !FUNCTION_H_ */