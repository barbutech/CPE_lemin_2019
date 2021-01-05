/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The history_node class.
*/

#include "history_node.h"
#include "node.h"
#include "object.h"
#include "room.h"
#include "type.h"
#include "base.h"

history_node *history_node_construct(type *object_type)
{
    history_node *self = (history_node *) node_construct(object_type);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    ((object *) self)->finalize = &history_node_finalize;

    return (self);
}

history_node *history_node_new(room *current, history_node *superior)
{
    history_node *self = history_node_construct(TYPE_HISTORY_NODE);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    self->current = current;
    self->superior = superior;

    object_ref((object *) current);
    object_ref((object *) superior);

    return (self);
}

type *history_node_get_type(void)
{
    return (type_register(
        "util.history_node",
        sizeof(history_node),
        TYPE_NODE
    ));
}

void history_node_finalize(object *parent)
{
    RETURN_IF_FAIL(parent != NULL);
    history_node *self = (history_node *) parent;

    object_unref((object *) self->current);
    object_unref((object *) self->superior);

    node_finalize(parent);
}
