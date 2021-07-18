/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** parallax_loop
*/

#include "function.h"
#include <struct.h>

static void hit_sasuke(rpg_t *rpg)
{
    if (rpg->paral.chidori_pos.x == rpg->paral.naruto_pos.x) {
        sfRenderWindow_close(rpg->win.window);
        gen_particles();
    }
}

static void remove_pos(rpg_t *rpg)
{
    rpg->enemy.life.position.x = 1615;
    rpg->enemy.life.position.y = 755;
    sfRectangleShape_setPosition(rpg->enemy.life.shape,
            rpg->enemy.life.position);
    sfRectangleShape_setPosition(rpg->enemy.life.red_shape,
        rpg->enemy.life.position);
}

static void draw_parallax(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win.window, rpg->paral.f_back_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->paral.cloud_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->paral.mount_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->paral.w_mount_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->paral.floor_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->paral.naruto_sprt, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->paral.sasuke_sprt, NULL);
    naruto_bars(rpg);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->paral.chidori_sprt, NULL);
    remove_pos(rpg);
    sfRenderWindow_drawRectangleShape(rpg->win.window,
        rpg->enemy.life.red_shape, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win.window, rpg->enemy.life.shape,
    NULL);
    anime_chidori(rpg);
    touch_naruto(rpg);
}

void parallax_loop(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(rpg->win.window)) {
        sfRenderWindow_display(rpg->win.window);
        while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyN)) {
                sfMusic_destroy(rpg->music.pause_music);
                sfMusic_destroy(rpg->music.peace_music);
                sfMusic_destroy(rpg->music.menu_mus);
                sfRenderWindow_close(rpg->win.window);
            }
            press_shuriken_mouse(rpg);
        }
        sfRenderWindow_clear(rpg->win.window, sfBlack);
        sfRenderWindow_setView(rpg->win.window,
        sfRenderWindow_getDefaultView(rpg->win.window));
        draw_parallax(rpg);
        moving_parallax(rpg);
        hit_sasuke(rpg);
    }
}