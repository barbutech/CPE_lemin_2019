/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** parser.h
*/

#ifndef PARSER_H
#define PARSER_H

#define PLUS_FORMAT_MASK 1
#define BLANK_FORMAT_MASK 2
#define ALTERNATE_FORMAT_MASK 4
#define MINUS_FORMAT_MASK 8
#define PADDED_FORMAT_MASK 16
#define ZPADDED_FORMAT_MASK 32

#endif

char parse_flag(char **message, int *format, int *space, int *zspace);
