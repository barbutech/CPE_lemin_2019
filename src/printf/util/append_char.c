/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** append_char.c
*/

#include <stdlib.h>
#include "printf/util.h"

char *append_char(char *str, int size, char c)
{
    char *temp = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++) {
        temp[i] = str[i];
    }
    temp[size] = c;
    free(str);
    return (temp);
}
