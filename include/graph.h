/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The graph file header.
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "room.h"
#include "base.h"
#include <stddef.h>
#include <stdarg.h>

struct room_set {
    char *name;
    int pos_x;
    int pos_y;
    struct room_set *next;
    struct room_set *head;
};
typedef struct room_set room_set_t;

struct output {
    int ant_nbr;
    room_set_t *start;
    bool start_found;
    room_set_t *end;
    bool end_found;
    room_set_t *room_set;
    room_set_t *tunnel;
};
typedef struct output output_t;

room *create_graph(void);
int is_tunnel(char *str);
int check(char *str, output_t **output, size_t n);
char *my_strncpy(char *dest, int value, int location);
char *my_strcpy(char *str);
void stack_push(room_set_t **room, char *str, int x, int y);
int my_modified_strcmp(char *s1, char *s2);
void my_putchar(char c);
int my_put_nbr(int nbr);
int my_putstr(char *str);
int my_printf(char *format , ...);
int flag_char(va_list listpointer);
void fill_tunnel(room_set_t **tunnel, int enter, int exit);
int check_tunnels(char *str, output_t **output);
int check_beginning(output_t **output);

#endif
