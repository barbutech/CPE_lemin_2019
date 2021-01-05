/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The type utility header.
*/

#ifndef TYPE_H
#define TYPE_H

#include "base.h"

typedef struct type type;

struct type {
    char *name;
    uint size;
    type *parent;
};

void *type_instantiate(type *object_type);
uint type_get_size(type *object_type);
void type_free(type *object_type);
type *type_register(char *name, uint size, type *parent);

#endif
