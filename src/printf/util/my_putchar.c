/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_putchar.c
*/

#include <unistd.h>
#include "printf/util.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
