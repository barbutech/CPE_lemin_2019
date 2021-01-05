/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The history_node class.
*/

#ifndef HISTORY_NODE
#define HISTORY_NODE

#include "node.h"
#include "object.h"
#include "room.h"
#include "type.h"
#include "base.h"

typedef struct history_node history_node;

struct history_node {
    node parent;
    room *current;
    history_node *superior;
};

#define TYPE_HISTORY_NODE (history_node_get_type())

history_node *history_node_construct(type *object_type);
history_node *history_node_new(room *current, history_node *superior);
type *history_node_get_type(void);
void history_node_finalize(object *parent);

#endif
