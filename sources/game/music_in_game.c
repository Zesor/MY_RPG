/*
** EPITECH PROJECT, 2021
** music
** File description:
** music_in_game
*/

#include "function.h"
#include "struct.h"

void music_in_game(rpg_t *rpg)
{
    rpg->music.peace_music = sfMusic_createFromFile("asset/music/peace.ogg");
    if (!rpg->music.peace_music)
        return;
    sfMusic_setVolume(rpg->music.peace_music, 20);
    sfMusic_setLoop(rpg->music.peace_music, sfTrue);
}