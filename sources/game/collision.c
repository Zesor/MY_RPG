/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** collision
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void check_collision_house_up(rpg_t *rpg, int speed)
{
    if (general_collision_up_down(rpg, 225, 510, 460) == 1 ||
        general_collision_up_down(rpg, 190, 1100, -15) == 1 ||
        general_collision_up_down(rpg, 621, 686, 281) == 1 ||
        general_collision_up_down(rpg, 821, 886, 281) == 1 ||
        general_collision_up_down(rpg, 621, 686, 884) == 1 ||
        general_collision_up_down(rpg, 821, 886, 884) == 1 ||
        general_collision_up_down(rpg, 480, 575, 660) == 1 ||
        general_collision_up_down(rpg, 375, 454, 660) == 1 ||
        general_collision_up_down(rpg, 245, 335, 660) == 1 ||
        general_collision_up_down(rpg, 482, 577, 259) == 1 ||
        general_collision_up_down(rpg, 362, 457, 259) == 1 ||
        general_collision_up_down(rpg, 242, 337, 259) == 1 ||
        general_collision_up_down(rpg, 931, 966, 201) == 1 ||
        general_collision_up_down(rpg, 1018, 1053, 201) == 1 ||
        general_collision_up_down(rpg, 231, 396, 840) == 1 ||
        general_collision_up_down(rpg, 915, 1055, 815) == 1) {
        rpg->game.team7_rect.left = 50;
    } else
        rpg->game.team_7_pos.y -= speed;
        rpg->game.team7_rect.top = 145;
        move_sprite(rpg);
}

void check_collision_house_right(rpg_t *rpg, int speed)
{
    if (general_collision_left_right(rpg, 220, 460, 365) == 1 ||
        general_collision_left_right(rpg, 1090, 890, -8) == 1 ||
        general_collision_left_right(rpg, 621, 281, - 10) == 1 ||
        general_collision_left_right(rpg, 821, 281, - 10) == 1 ||
        general_collision_left_right(rpg, 621, 884, 591) == 1 ||
        general_collision_left_right(rpg, 821, 884, 591) == 1 ||
        general_collision_left_right(rpg, 475, 665, 570) == 1 ||
        general_collision_left_right(rpg, 358, 665, 570) == 1 ||
        general_collision_left_right(rpg, 245, 665, 570) == 1 ||
        general_collision_left_right(rpg, 475, 259, 160) == 1 ||
        general_collision_left_right(rpg, 355, 259, 160) == 1 ||
        general_collision_left_right(rpg, 235, 259, 160) == 1 ||
        general_collision_left_right(rpg, 931, 201, 60) == 1 ||
        general_collision_left_right(rpg, 231, 856, 731) == 1 ||
        general_collision_left_right(rpg, 915, 815, 700) == 1) {
        rpg->game.team7_rect.left = 50;
    } else
        rpg->game.team_7_pos.x += speed;
        rpg->game.team7_rect.top = 97;
        move_sprite(rpg);
}

void check_collision_house_left(rpg_t *rpg, int speed)
{
    if (general_collision_left_right(rpg, 505, 460, 365) == 1 ||
        general_collision_left_right(rpg, 190, 890, -8) == 1 ||
        general_collision_left_right(rpg, 686, 281, - 10) == 1 ||
        general_collision_left_right(rpg, 886, 281, - 10) == 1 ||
        general_collision_left_right(rpg, 686, 884, 591) == 1 ||
        general_collision_left_right(rpg, 886, 884, 591) == 1 ||
        general_collision_left_right(rpg, 575, 665, 570) == 1 ||
        general_collision_left_right(rpg, 335, 665, 570) == 1 ||
        general_collision_left_right(rpg, 454, 665, 570) == 1 ||
        general_collision_left_right(rpg, 340, 259, 160) == 1 ||
        general_collision_left_right(rpg, 460, 259, 160) == 1 ||
        general_collision_left_right(rpg, 580, 259, 160) == 1 ||
        general_collision_left_right(rpg, 1053, 201, 60) == 1 ||
        general_collision_left_right(rpg, 281, 750, 740) == 1 ||
        general_collision_left_right(rpg, 396, 856, 740) == 1 ||
        general_collision_left_right(rpg, 1055, 815, 700) == 1) {
        rpg->game.team7_rect.left = 50;
    } else
        rpg->game.team_7_pos.x -= speed;
        rpg->game.team7_rect.top = 50;
        move_sprite(rpg);
}

void check_collision_house_down(rpg_t *rpg, int speed)
{
    if (general_collision_up_down(rpg, 225, 510, 355) == 1 ||
        general_collision_up_down(rpg, 190, 1096, 885) == 1 ||
        general_collision_up_down(rpg, 621, 686, -10) == 1 ||
        general_collision_up_down(rpg, 821, 886, -10) == 1 ||
        general_collision_up_down(rpg, 621, 686, 591) == 1 ||
        general_collision_up_down(rpg, 821, 886, 591) == 1 ||
        general_collision_up_down(rpg, 480, 575, 560) == 1 ||
        general_collision_up_down(rpg, 245, 335, 560) == 1 ||
        general_collision_up_down(rpg, 375, 454, 560) == 1 ||
        general_collision_up_down(rpg, 482, 577, 160) == 1 ||
        general_collision_up_down(rpg, 362, 457, 160) == 1 ||
        general_collision_up_down(rpg, 242, 340, 160) == 1 ||
        general_collision_up_down(rpg, 931, 1053, 55) == 1 ||
        general_collision_up_down(rpg, 231, 281, 731) == 1 ||
        general_collision_up_down(rpg, 281, 386, 746) == 1 ||
        general_collision_up_down(rpg, 915, 1055, 700) == 1) {
        rpg->game.team7_rect.left = 50;
    } else
        rpg->game.team_7_pos.y += speed;
        rpg->game.team7_rect.top = 0;
        move_sprite(rpg);
}