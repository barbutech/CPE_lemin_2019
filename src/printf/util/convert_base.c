/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** convert_base.c
*/

#include "printf/util.h"

int convert_base(unsigned int nb, char const *base, int length, char **result)
{
    int size = 0;

    if (nb >= length) {
        size += convert_base(nb / length, base, length, result);
    }
    *result = append_char(*result, size, base[nb % length]);
    return (size + 1);
}
