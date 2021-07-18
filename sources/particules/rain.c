/*
** EPITECH PROJECT, 2021
** PARTICULES
** File description:
** rainbow_rain
*/

#include "function.h"
#include "struct.h"
#include "define.h"

static void random_rain(rpg_t *rpg, rain_t *rain)
{
    rain->beg.x = get_random_float(0.0, (float)rpg->win.width);
    rain->beg.y = get_random_float(0.0, (float)(-(int)(rpg->win.height)));
    rain->len = get_random_float(5.0, 20.0);
    rain->speed = get_random_float(0.0, 15.0);
    rain->color = get_random_color(rand() % 255);
    rain->end.x = rain->beg.x;
    rain->end.y = rain->beg.y + rain->len;
}

static void fall_rain(rpg_t *rpg, rain_t *rain)
{
    rain->speed += ACCELERATION;
    rain->beg.y += rain->speed;
    rain->end.y += rain->speed;
    if (rain->beg.y >= rpg->win.height)
        random_rain(rpg, rain);
}

static void display_rain(rpg_t *rpg, rain_t **rain)
{
    for (unsigned int i = 0; i < NB_DROPLETS; i++) {
        if (rain[i]->beg.y > 0)
            draw_line(rpg->win.frame, rain[i]->beg, rain[i]->end,
                        rain[i]->color);
        fall_rain(rpg, rain[i]);
    }
}

static rain_t *create_rain(rpg_t *rpg)
{
    rain_t *rain = malloc(sizeof(*rain));

    random_rain(rpg, rain);
    return rain;
}

void rain(rpg_t *rpg)
{
    rain_t **rain = malloc(sizeof(*rain) * NB_DROPLETS);

    for (unsigned int i = 0; i < NB_DROPLETS; i++)
        rain[i] = create_rain(rpg);
    while (sfRenderWindow_isOpen(rpg->win.window)) {
        poll_events(rpg);
        display_rain(rpg, rain);
        window_refresh(rpg, &sfBlack);
    }
    for (unsigned int i = 0; i < NB_DROPLETS; i++)
        free(rain[i]);
    free(rain);
}