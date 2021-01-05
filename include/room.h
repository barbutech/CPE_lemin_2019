/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** The room class header.
*/

#ifndef ROOM_H
#define ROOM_H

#include "object.h"
#include "string.h"
#include "list.h"
#include "type.h"
#include "base.h"

typedef struct room room;

struct room {
    object parent;
    string *name;
    list *children;
    int x;
    int y;
    bool is_start;
    bool is_end;
    bool visited;
};

#define TYPE_ROOM (room_get_type())

room *room_construct(type *object_type);
room *room_new(string *name, int x, int y);
uint room_hash(object *parent);
type *room_get_type(void);
void room_finalize(object *parent);

#endif
