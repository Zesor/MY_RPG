/*
** EPITECH PROJECT, 2021
** PARTICULES
** File description:
** main
*/

#include "struct.h"
#include "define.h"
#include "function.h"
#include <time.h>

float get_random_float(float const min, float const max)
{
    return ((float)rand() / (float)(RAND_MAX) * (max - min) + min);
}

sfColor get_random_color(unsigned char opacity)
{
    sfColor color;

    color.r = rand() % 255;
    color.g = rand() % 255;
    color.b = rand() % 255;
    color.a = opacity;
    return color;
}

static void (*display_rainbow_rain(unsigned int id))(rpg_t *)
{
    void (*animation)(rpg_t *) = NULL;
    void (*animations[])(rpg_t *) = {
        &rain
    };
    animation = animations[id - 1];
    return animation;
}

static int launch_animation(unsigned int id)
{
    rpg_t *rpg = NULL;
    void (*play_animation)(rpg_t *) = display_rainbow_rain(id);

    if (!play_animation)
        return EXIT_ERROR;
    rpg = window_create(W_WIDTH, W_HEIGHT, "TITRE");
    if (!rpg)
        return EXIT_ERROR;
    play_animation(rpg);
    window_destroy(rpg);
    return EXIT_SUCCES;
}

int gen_particles(void)
{
    int launch = 0;
    unsigned int id = 1;

    srand(time(NULL));
    launch = launch_animation(id);
    if (launch == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCES;
}