/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** kakashi
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void move_kakashi(rpg_t *rpg)
{
    if (rpg->game.team_7_pos.y <= rpg->kakashi.kakashi_pos.y)
        sfSprite_setTextureRect(rpg->kakashi.kakashi_sprt, (sfIntRect)
                            {50, 145, 50, 48});
    if (rpg->game.team_7_pos.y >= rpg->kakashi.kakashi_pos.y)
        sfSprite_setTextureRect(rpg->kakashi.kakashi_sprt, (sfIntRect)
                            {50, 0, 50, 48});
    if (rpg->game.team_7_pos.x < rpg->kakashi.kakashi_pos.x &&
        rpg->game.team_7_pos.y + 30 >= rpg->kakashi.kakashi_pos.y &&
        rpg->game.team_7_pos.y - 30 <= rpg->kakashi.kakashi_pos.y)
        sfSprite_setTextureRect(rpg->kakashi.kakashi_sprt, (sfIntRect)
                            {50, 50, 50, 48});
    if (rpg->game.team_7_pos.x > rpg->kakashi.kakashi_pos.x &&
        rpg->game.team_7_pos.y + 30 >= rpg->kakashi.kakashi_pos.y &&
        rpg->game.team_7_pos.y - 30 <= rpg->kakashi.kakashi_pos.y)
        sfSprite_setTextureRect(rpg->kakashi.kakashi_sprt, (sfIntRect)
                            {48, 97, 50, 48});
}

void talk_hitbox(rpg_t *rpg)
{
    sfFloatRect kakashi = sfSprite_getGlobalBounds(rpg->kakashi.kakashi_sprt);
    sfFloatRect player = sfSprite_getGlobalBounds(rpg->game.team7_sprt);
    const sfFloatRect *sensei = &kakashi;
    const sfFloatRect *character = &player;

    if (sfFloatRect_intersects(sensei, character, NULL)
        && sfKeyboard_isKeyPressed(sfKeyEnter))
        if ((rpg->quest.side_quest == 3 || rpg->quest.side_quest == 6
            || rpg->quest.side_quest == 9) && rpg->quest.nb_quest == 0 ||
            (rpg->quest.side_quest == 1 || rpg->quest.side_quest == 4
            || rpg->quest.side_quest == 6) && rpg->quest.nb_quest == 1)
            rpg->kakashi.quest = 1;
        else
            print_kakashi_rec(rpg);
}

void init_kakashi(rpg_t *rpg)
{
    rpg->kakashi.kakashi_txt = sfTexture_createFromFile(
            "asset/image/kakashi.png", NULL);
    rpg->kakashi.kakashi_sprt = sfSprite_create();
    rpg->kakashi.kakashi_pos.x = 800;
    rpg->kakashi.kakashi_pos.y = rpg->game.team_7_pos.y;
    rpg->kakashi.kakashi_rect = (sfIntRect) {50, 0, 50, 48};
    rpg->kakashi.shape = sfRectangleShape_create();

    sfRectangleShape_setSize(rpg->kakashi.shape, (sfVector2f) {210, 20});
    sfRectangleShape_setOutlineColor(rpg->kakashi.shape, sfBlack);
    sfRectangleShape_setOutlineThickness(rpg->kakashi.shape, 2);
    sfSprite_setPosition(rpg->kakashi.kakashi_sprt, rpg->kakashi.kakashi_pos);
    sfSprite_setTexture(rpg->kakashi.kakashi_sprt,
                rpg->kakashi.kakashi_txt, sfTrue);
    sfSprite_setTextureRect(rpg->kakashi.kakashi_sprt,
                rpg->kakashi.kakashi_rect);
}