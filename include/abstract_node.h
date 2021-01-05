/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The abstract_node class header.
*/

#ifndef ABSTRACT_NODE
#define ABSTRACT_NODE

#include "node.h"
#include "object.h"
#include "type.h"
#include "base.h"

typedef struct abstract_node abstract_node;

struct abstract_node {
    node parent;
    object *value;
};

#define TYPE_ABSTRACT_NODE (abstract_node_get_type())

abstract_node *abstract_node_construct(type *object_type);
abstract_node *abstract_node_new(object *value);
type *abstract_node_get_type(void);
void abstract_node_finalize(object *parent);

#endif
