/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The step class.
*/

#include "step.h"
#include "object.h"
#include "string.h"
#include "type.h"
#include "base.h"

step *step_construct(type *object_type)
{
    step *self = (step *) object_construct(object_type);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    ((object *) self)->finalize = &step_finalize;

    return (self);
}

step *step_new(string *name)
{
    step *self = step_construct(TYPE_STEP);

    self->name = name;
    self->next = NULL;
    self->index = -1;
    self->is_empty = TRUE;
    self->size = 0;

    object_ref((object *) name);

    return (self);
}

type *step_get_type(void)
{
    return (type_register(
        "parser.step",
        sizeof(step),
        TYPE_OBJECT
    ));
}

void step_finalize(object *parent)
{
    RETURN_IF_FAIL(parent != NULL);
    step *self = (step *) parent;

    object_unref((object *) self->name);
    object_unref((object *) self->next);

    object_finalize(parent);
}
