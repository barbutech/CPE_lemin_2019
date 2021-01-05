/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** parser.c
*/

#include "printf/parser.h"
#include "printf/util.h"

static char parse_flag3(char **message, int *format, int *space, int *zspace)
{
    if ('1' <= **message && **message <= '9') {
        while ('0' <= **message && **message <= '9') {
            *space = (*space * 10) + (**message - '0');
            (*message)++;
            *format |= PADDED_FORMAT_MASK;
        }
    }
    if (**message == '.' || **message == '0') {
        while (**message == '.' || **message == '0') {
            (*message)++;
        }
        while ('0' <= **message && **message <= '9') {
            *zspace = (*zspace * 10) + (**message - '0');
            (*message)++;
            *format |= ZPADDED_FORMAT_MASK;
        }
    }
    return (**message);
}

static char parse_flag2(char **message, int *format, int *space, int *zspace)
{
    while (**message == '#') {
        (*message)++;
        *format |= ALTERNATE_FORMAT_MASK;
    }
    while (**message == '-') {
        (*message)++;
        *format |= MINUS_FORMAT_MASK;
    }
    return (parse_flag3(message, format, space, zspace));
}

char parse_flag(char **message, int *format, int *space, int *zspace)
{
    while (**message == '-') {
        (*message)++;
        *format |= MINUS_FORMAT_MASK;
    }
    while (**message == '+') {
        (*message)++;
        *format |= PLUS_FORMAT_MASK;
    }
    while (**message == ' ') {
        (*message)++;
        *format |= BLANK_FORMAT_MASK;
    }
    return (parse_flag2(message, format, space, zspace));
}
