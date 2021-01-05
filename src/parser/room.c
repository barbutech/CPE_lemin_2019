/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** The room class.
*/

#include "room.h"
#include "object.h"
#include "string.h"
#include "list.h"
#include "type.h"
#include "base.h"

room *room_construct(type *object_type)
{
    room *self = (room *) object_construct(object_type);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    ((object *) self)->finalize = &room_finalize;
    ((object *) self)->hash = &room_hash;

    return (self);
}

room *room_new(string *name, int x, int y)
{
    room *self = room_construct(TYPE_ROOM);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    self->name = name;
    self->children = list_new();

    self->x = x;
    self->y = y;

    self->is_start = FALSE;
    self->is_end = FALSE;

    self->visited = FALSE;

    object_ref((object *) name);

    return (self);
}

uint room_hash(object *parent)
{
    RETURN_VAL_IF_FAIL(parent != NULL, 0);
    room *self = (room *) parent;

    return (object_hash((object *) self->name));
}

type *room_get_type(void)
{
    return (type_register(
        "parser.room",
        sizeof(room),
        TYPE_OBJECT
    ));
}

void room_finalize(object *parent)
{
    RETURN_IF_FAIL(parent != NULL);
    room *self = (room *) parent;

    object_unref((object *) self->name);
    object_unref((object *) self->children);

    object_finalize(parent);
}
