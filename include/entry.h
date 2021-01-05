/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** The entry class header.
*/

#ifndef ENTRY_H
#define ENTRY_H

#include "object.h"
#include "node.h"
#include "type.h"
#include "base.h"

typedef struct entry entry;

struct entry {
    node parent;
    uint hash;
    object *value;
};

#define TYPE_ENTRY (entry_get_type())

entry *entry_construct(type *object_type);
entry *entry_new(uint hash, object *value);
object *entry_get_value(entry *self);
type *entry_get_type(void);
void entry_finalize(object *parent);

#endif
