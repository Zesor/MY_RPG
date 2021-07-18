/*
** EPITECH PROJECT, 2021
** PARTICULES
** File description:
** window
*/

#include "struct.h"
#include "define.h"
#include "function.h"

#define CREATE sfRenderWindow_create

rpg_t *window_create(unsigned int width, unsigned int height,
                        char const *title)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    sfVideoMode mode = {width, height, W_BPP};

    rpg->win.window = CREATE(mode, title, sfClose | sfResize, 0);
    rpg->win.width = 1920;
    rpg->win.height = 1080;
    rpg->win.frame = frame_create(width, height);
    rpg->win.texture = sfTexture_create(width, height);
    rpg->win.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->win.sprite, rpg->win.texture, sfTrue);
    init_ending(rpg);
    sfRenderWindow_setFramerateLimit(rpg->win.window, W_MAX_FPS);
    return rpg;
}

void window_refresh(rpg_t *rpg, sfColor *color)
{
    sfRenderWindow_display(rpg->win.window);
    sfRenderWindow_clear(rpg->win.window, sfBlack);
    sfTexture_updateFromPixels(rpg->win.texture, rpg->win.frame->pixels,
                                rpg->win.width, rpg->win.height, 0, 0);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->win.sprite, NULL);
    sfRenderWindow_drawSprite(rpg->win.window, rpg->end.end_sprt, NULL);
    move_ending(rpg);

    if (color)
        frame_clear(rpg->win.frame, *(color));
}

void window_destroy(rpg_t *rpg)
{
    frame_destroy(rpg->win.frame);
    sfSprite_destroy(rpg->win.sprite);
    sfTexture_destroy(rpg->win.texture);
    sfRenderWindow_destroy(rpg->win.window);
    free(rpg);
}

void poll_events(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape) {
            sfMusic_destroy(rpg->music.menu_mus);
            sfMusic_destroy(rpg->music.pause_music);
            sfMusic_destroy(rpg->music.peace_music);
            sfRenderWindow_close(rpg->win.window);
        }
    }
}