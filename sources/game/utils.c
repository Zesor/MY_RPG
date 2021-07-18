/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include <stdlib.h>
#include <unistd.h>
#include "define.h"
#include "function.h"
#include "struct.h"

char *my_str_to_null(char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s) {
        if (*s == c)
            break;
        s++;
    }
    return (s);
}

unsigned int array_len(char **array)
{
    char **ptr = NULL;

    ptr = array;
    while (*ptr)
        ptr++;
    return (ptr - array);
}