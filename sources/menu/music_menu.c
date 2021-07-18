/*
** EPITECH PROJECT, 2021
** music
** File description:
** music
*/

#include "function.h"
#include "define.h"
#include "struct.h"

void music_menu(rpg_t *rpg)
{
    rpg->music.menu_mus = sfMusic_createFromFile("asset/music/musicmenu.ogg");
    if (!rpg->music.menu_mus)
        return;
    sfMusic_setVolume(rpg->music.menu_mus, 10);
    sfMusic_setLoop(rpg->music.menu_mus, sfTrue);
    sfMusic_play(rpg->music.menu_mus);
}