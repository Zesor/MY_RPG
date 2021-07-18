/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-thomas.willson
** File description:
** my_strcat
*/

#include "function.h"

char *my_strcat(char *dest, char *src)
{
    int	i;
    int	destlen;

    destlen = my_strlen(dest);
    i = 0;
    while (src[i] != '\0') {
        dest[destlen + i] = src[i];
        i++;
    }
    dest[destlen + i] = '\0';
    return (dest);
}