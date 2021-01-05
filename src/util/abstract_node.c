/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The abstract_node class.
*/

#include "abstract_node.h"
#include "node.h"
#include "object.h"
#include "type.h"
#include "base.h"

abstract_node *abstract_node_construct(type *object_type)
{
    abstract_node *self = (abstract_node *) node_construct(object_type);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    ((object *) self)->finalize = &abstract_node_finalize;

    return (self);
}

abstract_node *abstract_node_new(object *value)
{
    abstract_node *self = abstract_node_construct(TYPE_ABSTRACT_NODE);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    self->value = value;

    object_ref((object *) value);

    return (self);
}

type *abstract_node_get_type(void)
{
    return (type_register(
        "util.abstract_node",
        sizeof(abstract_node),
        TYPE_NODE
    ));
}

void abstract_node_finalize(object *parent)
{
    RETURN_IF_FAIL(parent != NULL);
    abstract_node *self = (abstract_node *) parent;

    object_unref((object *) self->value);

    node_finalize(parent);
}
