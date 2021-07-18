/*
** EPITECH PROJECT, 2021
** DEFINE
** File description:
** DEFINE
*/

#ifndef DEFINE_H_
#define DEFINE_H_

#include "struct.h"

#define COORDS sfRenderWindow_mapPixelToCoords
#define GETPOS sfMouse_getPositionRenderWindow
#define BOUNDS sfSprite_getGlobalBounds

//          [PARTICULES]     //

static const int EXIT_ERROR = 84;
static const int EXIT_SUCCES = 0;

static const unsigned int NB_DROPLETS = 800;
static const int ACCELERATION = 0.125;

static const int W_WIDTH = 1920;
static const int W_HEIGHT = 1080;
static const int W_BPP = 32;
static const int W_MAX_FPS = 60;
static const char *W_TITLE = "ENDING";

//          [QUEST]         //

static const char *tutorial_quest[10] = {
    "Tutorial :",
    "Move your character (Q/Z/S/D).",
    "Press shift to go faster",
    "Talk to kakashi",
    "Shoot a shuriken (left click).",
    "Fight sakura using shuriken.",
    "Talk to kakashi",
    "Use your special (right click).",
    "Fight sasuke using the special.",
    "Talk to kakashi"
};

static const char *game_quest[8] = {
    "Game :",
    "Find kakashi and talk to him",
    "Go into the shop",
    "Find a place to eat",
    "Talk to kakashi",
    "Fight every kakashi clones",
    "Talk to kakashi",
    "Go into the big tower"
};

static const char **number_quest[2] = {
    tutorial_quest,
    game_quest
};

//          [DIALOGUE]      //

static const char *tutorial_dialogue[18] = {
    "- Naruto :",
    "- Kakashi :",
    "Hey Sensei !",
    "Ready for your training ?",
    "Always !",
    "Then let's start by moving.",
    "I already know how to move but ok...",
    "Talk to me when you're done",
    "Now you have to throw a shuriken.",
    "I already know how to throw a shuriken.",
    "Ok then throw it to sakura, \ndon't worry about her she'll be fine.",
    "That training is getting weirder\nminute by minute",
    "Show me your special technique\nyou've been working on.",
    "I hope you're ready for it !!!",
    "Nicely done",
    "Thanks Sensei !",
    "The training is finished,\nyou're ready for the adventure",
    "The adventure ?! Which adventure?\nWhat are you talking about ?"
};

static const char *shop_dialogue[11] = {
    "- Naruto :",
    "- Tenten :",
    "Hey Tenten !",
    "I heard that you're doing a\n lot of missions lately",
    "Yep that's right, that's what i have to do !",
    "Why ?",
    "Well to become the Hokage\nof course !",
    "Not sure about that but\nbelieve in your dreams huh !",
    "I'll show y'all that i have all\nthe qualities for it !",
    "I'll help you then !\n Here's a scroll for you.",
    "Thank you Tenten, \ni'll make good use of it !",
};

static const char *ramen_dialogue[10] = {
    "- Naruto :",
    "- Teuchi :",
    "I'm soooooo hungry",
    "Hey Naruto !\n Are you hungry ?",
    "As always !\n I'll take one bowl please",
    "No problem for you Naruto !\n Where are you going ?",
    "I'm going for a brief mission\n Not a big deal",
    "Sounds great, be careful !\n Here's another bowl for you !",
    "Thank you !\nI'll pay it back when i'll be the hokage !",
    "Ahah, of course !\n I trust you Naruto !"
};

static const char *kakashi_dialogue[14] = {
    "- Naruto :",
    "- Kakashi :",
    "Hey sensei !",
    "Hey you...",
    "So what do we do today ?",
    "for the moment nothing,\ncomeback later i may have\nsomething for you",
    "Do you have anything for me sensei ?",
    "Oh, you're here",
    "Yes you told me to comeback later so\n here i am",
    "GENJUTSU ! (USE YOUR ITEM STUPID)",
    "WHAT THE HELL WAS THAT ?!!!!",
    "I wanted to try that on someone",
    "You're insane !",
    "Well you should move, i heard someone \nis waiting for you in the tower",
};

static const char **nb_dialogue[4] = {
    tutorial_dialogue,
    shop_dialogue,
    ramen_dialogue,
    kakashi_dialogue
};

#define DRAW_SPRITE sfRenderWindow_drawSprite

#define ASSET_CURS_MENU "asset/cursor/cursor.png"
#define CURSOR_MENU init_cursor(rpg->win.window, ASSET_CURS_MENU, 50, 50)
#define DRAW_CURSOR DRAW_SPRITE(rpg->win.window, CURSOR_MENU, NULL);

#define ASSET_CURS_GAME "asset/cursor/game_curs.png"
#define CURSOR_GAME init_cursor(rpg->win.window, ASSET_CURS_GAME, 50, 50)
#define DRAW_GAME_CURSOR DRAW_SPRITE(rpg->win.window, CURSOR_GAME, NULL);

#endif /* !DEFINE_H_ */
