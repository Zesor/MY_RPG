/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** my_strlen
*/

#include <stddef.h>

size_t my_strlen(const char *str)
{
    size_t i = 0;

    while (str[i])
        i++;
    return i;
}