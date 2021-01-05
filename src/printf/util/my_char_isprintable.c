/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_char_isprintable.c
*/

#include "printf/util.h"

int my_char_isprintable(char c)
{
    if (' ' <= c && c <= '~') {
        return (1);
    }
    return (0);
}
