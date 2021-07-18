/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "define.h"
#include "struct.h"
#include "function.h"

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

#include "struct.h"
#include "define.h"
#include "function.h"

int main_loop(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(rpg->win.window)) {
        sfRenderWindow_display(rpg->win.window);
        while (sfRenderWindow_pollEvent(rpg->win.window, &event)) {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ)) {
                sfRenderWindow_close(rpg->win.window);
            }
        }
        sfRenderWindow_clear(rpg->win.window, sfBlack);
        menu_loop(rpg);
    }
}