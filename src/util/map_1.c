/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The map class.
*/

#include "map.h"
#include "object.h"
#include "string.h"
#include "list.h"
#include "entry.h"
#include "type.h"
#include "base.h"

map *map_construct(type *object_type)
{
    map *self = (map *) object_construct(object_type);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    ((object *) self)->finalize = &map_finalize;

    return (self);
}

map *map_new(void)
{
    map *self = map_construct(TYPE_MAP);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    self->list = list_new();

    return (self);
}

type *map_get_type(void)
{
    return (type_register(
        "util.map",
        sizeof(map),
        TYPE_OBJECT
    ));
}

void map_finalize(object *parent)
{
    RETURN_IF_FAIL(parent != NULL);
    map *self = (map *) parent;

    object_unref((object *) self->list);

    object_finalize(parent);
}
