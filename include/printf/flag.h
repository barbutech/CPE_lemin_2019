/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** flag.h
*/

#include <stdarg.h>

int flag_managment(char flag, int (*print)(va_list a, int f, int s, int z),
va_list args, int *ints);
int call_flag(char **message, va_list args);
