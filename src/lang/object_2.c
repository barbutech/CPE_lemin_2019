/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** The object abstract class.
*/

#include <stdlib.h>
#include "object.h"
#include "type.h"
#include "base.h"

uint object_hash(object *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, 0);

    if (self->hash == NULL)
        return (0);

    return (self->hash(self));
}

void object_ref(object *self)
{
    RETURN_IF_FAIL(self != NULL);

    self->ref_count++;
}

void object_unref(object *self)
{
    RETURN_IF_FAIL(self != NULL);

    self->ref_count--;

    if (self->ref_count != 0)
        return;

    self->finalize(self);
}
