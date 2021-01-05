/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The node abstract class.
*/

#include "node.h"
#include "object.h"
#include "room.h"
#include "type.h"
#include "base.h"

node *node_construct(type *object_type)
{
    node *self = (node *) object_construct(object_type);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    ((object *) self)->finalize = &node_finalize;
    self->next = NULL;

    return (self);
}

type *node_get_type(void)
{
    return (type_register(
        "util.node",
        sizeof(node),
        TYPE_OBJECT
    ));
}

void node_finalize(object *parent)
{
    RETURN_IF_FAIL(parent != NULL);
    node *self = (node *) parent;

    object_unref((object *) self->next);

    object_finalize(parent);
}
