/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** print.h
*/

#include <stdarg.h>

int print_big_str(va_list args, int format, int space, int zspace);
int print_binary(va_list args, int format, int space, int zspace);
int print_char(va_list args, int format, int space, int zspace);
int print_escapement(va_list args, int format, int space, int zspace);
int print_hex_low(va_list args, int format, int space, int zspace);
int print_hex_up(va_list args, int format, int space, int zspace);
int print_int(va_list args, int format, int space, int zspace);
int print_octal(va_list args, int format, int space, int zspace);
int print_ptr(va_list args, int format, int space, int zspace);
int print_str(va_list args, int format, int space, int zspace);
int print_unsigned(va_list args, int format, int space, int zspace);
