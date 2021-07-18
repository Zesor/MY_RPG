/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** lose
*/

#include "struct.h"
#include "define.h"
#include "function.h"

void draw_text_lose(rpg_t *rpg, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("asset/font/naruto.ttf");

    sfText_setFont(text, font);
    sfText_setString(text, "You're Dead");
    sfText_setCharacterSize(text, 100);
    sfText_setColor(text, sfRed);
    sfText_setPosition(text, pos);
    sfText_setOutlineThickness(text, 10);
    sfText_setOutlineColor(text, sfBlack);
    sfRenderWindow_drawText(rpg->win.window, text, NULL);
}

void change_pos_text(rpg_t *rpg, sfSprite *menu, sfSprite *quit)
{
    sfVector2f position;

    position = rpg->life.lose;
    rpg->general_time = sfClock_getElapsedTime(rpg->general_clock);
    rpg->general_seconds = rpg->general_time.microseconds / 1000000.0;
    if (rpg->general_seconds < 0.1 &&
        rpg->life.lose.y < 300) {
        rpg->life.lose.y += 5;
        sfClock_restart(rpg->general_clock);
    } else if (rpg->life.lose.y >= 200) {
        position.x -= 80;
        position.y += 250;
        sfSprite_setPosition(menu, position);
        position.x += 500;
        sfSprite_setPosition(quit, position);
        sfRenderWindow_drawSprite(rpg->win.window, menu, NULL);
        sfRenderWindow_drawSprite(rpg->win.window, quit, NULL);
    }
}

static void draw_lose_sprite(rpg_t *rpg, sfSprite *menu,
                            sfSprite *quit, sfSprite *background)
{
    sfRenderWindow_clear(rpg->win.window, sfBlack);
    sfRenderWindow_drawSprite(rpg->win.window, background, NULL);
    change_pos_text(rpg, menu, quit);
    draw_text_lose(rpg, rpg->life.lose);
    sfRenderWindow_display(rpg->win.window);
}

void lose_screen(rpg_t *rpg)
{
    sfEvent event;
    sfSprite *menu = create_lose("asset/image/menu.png");
    sfSprite *quit = create_lose("asset/image/quit.png");
    sfSprite *background = create_lose("asset/image/naruto_swing.jpg");
    sfVector2f pos = {650, 0};

    rpg->life.lose = pos;
    ending_song(rpg);
    sfRenderWindow_setView(rpg->win.window,
    sfRenderWindow_getDefaultView(rpg->win.window));
    while (sfRenderWindow_isOpen(rpg->win.window)) {
        while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyN)) {
                sfMusic_destroy(rpg->music.ending_music);
                sfMusic_destroy(rpg->music.menu_mus);
                sfMusic_destroy(rpg->music.peace_music);
                sfMusic_destroy(rpg->music.pause_music);
                sfRenderWindow_close(rpg->win.window);
            }
            lose_menu_handler(rpg, event, menu);
        }
        lose_quit_handler(rpg, quit);
        draw_lose_sprite(rpg, menu, quit, background);
    }
}

void check_lose(rpg_t *rpg)
{
    if (rpg->life.size.x <= 0) {
        sfRenderWindow_setMouseCursorVisible(rpg->win.window, sfTrue);
        rpg->life.size.x = 150;
        sfRectangleShape_setSize(rpg->life.shape, rpg->life.size);
        lose_screen(rpg);
    }
}