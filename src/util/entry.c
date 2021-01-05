/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** The entry class.
*/

#include "entry.h"
#include "object.h"
#include "node.h"
#include "room.h"
#include "type.h"
#include "base.h"

entry *entry_construct(type *object_type)
{
    entry *self = (entry *) node_construct(object_type);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    ((object *) self)->finalize = &entry_finalize;

    return (self);
}

entry *entry_new(uint hash, object *value)
{
    entry *self = entry_construct(TYPE_ENTRY);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    object_ref((object *) value);

    self->hash = hash;
    self->value = value;

    return (self);
}

object *entry_get_value(entry *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    object_ref((object *) self->value);
    return (self->value);
}

type *entry_get_type(void)
{
    return (type_register(
        "util.entry",
        sizeof(entry),
        TYPE_NODE
    ));
}

void entry_finalize(object *parent)
{
    RETURN_IF_FAIL(parent != NULL);
    entry *self = (entry *) parent;

    object_unref((object *) self->value);

    node_finalize(parent);
}
