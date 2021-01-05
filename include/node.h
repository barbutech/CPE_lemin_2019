/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The node abstract class header.
*/

#ifndef NODE_H
#define NODE_H

#include "object.h"
#include "type.h"
#include "base.h"

typedef struct node node;

struct room;

struct node {
    object parent;
    node *next;
};

#define TYPE_NODE (node_get_type())

node *node_construct(type *object_type);
type *node_get_type(void);
void node_finalize(object *parent);

#endif
