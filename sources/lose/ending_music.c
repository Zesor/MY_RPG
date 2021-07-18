/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** ending_music
*/

#include "define.h"
#include "function.h"
#include "struct.h"

void ending_song(rpg_t *rpg)
{
    rpg->music.ending_music =
        sfMusic_createFromFile("asset/music/naruto_lost.ogg");
    if (!rpg->music.ending_music)
        return;
    sfMusic_setVolume(rpg->music.ending_music, 20);
    sfMusic_setLoop(rpg->music.ending_music, sfTrue);
    sfMusic_play(rpg->music.ending_music);
}