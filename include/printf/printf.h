/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my.h
*/

#include <stdarg.h>

int my_printf(char const *fmt, ...);
void register_flag(char flag, int (*print)(va_list a, int f, int s, int z));
