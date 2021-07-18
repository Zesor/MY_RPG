/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** my_itoa
*/

#include "define.h"
#include "struct.h"
#include "function.h"

char *my_itoa(int nbr)
{
    char *string = NULL;
    int lenght = 0;
    int tmp = nbr;

    for (; tmp > 0; lenght++) {
        tmp /= 10;
    }
    string = malloc(sizeof(char) * (lenght + 1));
    if (!string)
        return NULL;
    string[lenght] = '\0';
    while (lenght--) {
        string[lenght] = nbr % 10 + 48;
        nbr /= 10;
    }
    return string;
}