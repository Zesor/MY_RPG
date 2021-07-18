/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** button_lose
*/

#include "define.h"
#include "function.h"
#include "struct.h"

sfSprite *create_lose(char *pathfile)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(pathfile, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

static void destroy_m(rpg_t *rpg)
{
    sfMusic_destroy(rpg->music.ending_music);
    sfMusic_destroy(rpg->music.menu_mus);
    sfMusic_destroy(rpg->music.peace_music);
    sfMusic_destroy(rpg->music.pause_music);
}

void light_button_lose(rpg_t *rpg)
{
    sfVector2f mouse = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect menu_drk_pos = BOUNDS(rpg->pause.menu_drk_sprt);
    sfFloatRect *menu_drk_rect = &menu_drk_pos;

    if (sfFloatRect_contains(menu_drk_rect, mouse.x, mouse.y))
        sfRenderWindow_drawSprite(rpg->win.window, rpg->pause.menu_drk_sprt,
        NULL);
}

void lose_quit_handler(rpg_t *rpg, sfSprite *quit)
{
    sfVector2f mouse = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect quit_drk_pos = BOUNDS(quit);
    sfFloatRect *quit_drk_rect = &quit_drk_pos;
    sfTexture *red = sfTexture_createFromFile("asset/image/quit_drk.png", NULL);
    sfTexture *light = sfTexture_createFromFile("asset/image/quit_real.png",
                        NULL);
    sfTexture *normal = sfTexture_createFromFile("asset/image/quit.png",
                        NULL);

    if (sfFloatRect_contains(quit_drk_rect, mouse.x, mouse.y))
        sfSprite_setTexture(quit, red, sfTrue);
    else
        sfSprite_setTexture(quit, normal, sfTrue);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(quit_drk_rect, mouse.x, mouse.y)) {
        sfSprite_setTexture(quit, light, sfTrue);
        destroy_m(rpg);
        sfRenderWindow_close(rpg->win.window);
    }
}

void lose_menu_handler(rpg_t *rpg, sfEvent event, sfSprite *menu)
{
    sfVector2f mouse = COORDS(rpg->win.window, GETPOS(rpg->win.window), NULL);
    sfFloatRect menu_drk_pos = BOUNDS(menu);
    sfFloatRect *menu_drk_rect = &menu_drk_pos;
    sfTexture *red = sfTexture_createFromFile("asset/image/menu_drk.png", NULL);
    sfTexture *light = sfTexture_createFromFile("asset/image/menu_real.png",
        NULL);
    sfTexture *normal = sfTexture_createFromFile("asset/image/menu.png", NULL);

    if (sfFloatRect_contains(menu_drk_rect, mouse.x, mouse.y))
        sfSprite_setTexture(menu, red, sfTrue);
    else
        sfSprite_setTexture(menu, normal, sfTrue);
    if (event.mouseButton.button == sfMouseLeft
        && sfFloatRect_contains(menu_drk_rect, mouse.x, mouse.y)) {
        sfSprite_setTexture(menu, light, sfTrue);
        sfMusic_pause(rpg->music.pause_music);
        sfMusic_destroy(rpg->music.ending_music);
        sfSprite_setColor(rpg->game.fond_sprt, sfWhite);
        menu_loop(rpg);
    }
}