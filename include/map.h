/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The map class header.
*/

#ifndef MAP_H
#define MAP_H

#include "object.h"
#include "string.h"
#include "list.h"
#include "type.h"
#include "base.h"

typedef struct map map;

struct map {
    object parent;
    list *list;
};

#define TYPE_MAP (map_get_type())

map *map_construct(type *object_type);
map *map_new(void);
void map_insert(map *self, string *key, object *elem);
bool map_contains(map *self, string *key);
object *map_get(map *self, string *key);
type *map_get_type(void);
void map_finalize(object *parent);

#endif
