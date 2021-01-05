/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The object abstract class header.
*/

#ifndef OBJECT_H
#define OBJECT_H

#include "type.h"
#include "base.h"

typedef struct object object;

struct object {
    uint ref_count;
    type *object_type;
    void (*finalize)(object *self);
    uint (*hash)(object *self);
};

#define TYPE_OBJECT (object_get_type())

object *object_construct(type *object_type);
uint object_hash(object *self);
void object_ref(object *self);
void object_unref(object *self);
type *object_get_type(void);
void object_finalize(object *self);

#endif
