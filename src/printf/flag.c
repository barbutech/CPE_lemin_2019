/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** flag.c
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "printf/flag.h"
#include "printf/parser.h"
#include "printf/print.h"
#include "printf/util.h"

int flag_managment(char flag, int (*print)(va_list a, int f, int s, int z),
va_list args, int *ints)
{
    static int (*collection[255])(va_list a, int f, int s, int z) = { NULL };

    if (print != NULL && args == NULL) {
        collection[(int) flag] = print;
    } else if (print == NULL && args != NULL) {
        if (collection[(int) flag] != NULL) {
            return (collection[(int) flag](args, ints[0], ints[1], ints[2]));
        } else {
            print_escapement(NULL, 0, 0, 0);
            write(1, &flag, 1);
            return (2);
        }
    } else {
        return (print_escapement(NULL, 0, 0, 0));
    }
    return (0);
}

void register_flag(char flag, int (*print)(va_list a, int f, int s, int z))
{
    flag_managment(flag, print, NULL, NULL);
}

int call_flag(char **message, va_list args)
{
    int *ints = malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; i++)
        ints[i] = 0;
    (*message)++;

    char flag = parse_flag(message, &ints[0], &ints[1], &ints[2]);

    return (flag_managment(flag, NULL, args, ints));
}
