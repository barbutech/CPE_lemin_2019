/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The step class header.
*/

#ifndef STEP_H
#define STEP_H

#include "object.h"
#include "string.h"
#include "type.h"
#include "base.h"

typedef struct step step;

struct step {
    object parent;
    string *name;
    step *next;
    int index;
    bool is_empty;
    int size;
};

#define TYPE_STEP (step_get_type())

step *step_construct(type *object_type);
step *step_new(string *name);
type *step_get_type(void);
void step_finalize(object *parent);

#endif
