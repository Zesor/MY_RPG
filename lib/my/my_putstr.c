/*
** EPITECH PROJECT, 2021
** bsdefender
** File description:
** my_putstr
*/

#include "my.h"

static size_t my_strlen(char const *str)
{
    size_t i = 0;

    while (str[i])
        i++;
    return i;
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}