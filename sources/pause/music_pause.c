/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** music_pause
*/

#include "struct.h"
#include "function.h"

void music_pause(rpg_t *rpg)
{
    rpg->music.pause_music = sfMusic_createFromFile("asset/music/download.ogg");
    if (!rpg->music.pause_music)
        return;
    sfMusic_setVolume(rpg->music.pause_music, 20);
    sfMusic_setLoop(rpg->music.pause_music, sfTrue);
}