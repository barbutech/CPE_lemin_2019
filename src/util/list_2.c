/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The list class.
*/

#include "list.h"
#include "object.h"
#include "node.h"
#include "type.h"
#include "base.h"

void list_push(list *self, node *value)
{
    RETURN_IF_FAIL(self != NULL);

    object_ref((object *) value);

    if (self->size == 0) {

        self->head = value;
        self->end = value;

        self->size++;
        return;
    }

    self->end->next = value;
    self->end = value;

    self->size++;
}

node *list_get_head(list *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    node *tmp = self->head;
    object_ref((object *) tmp);

    return (tmp);
}

node *list_pop_first(list *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    self->size--;

    node *tmp = self->head;
    self->head = tmp->next;

    tmp->next = NULL;

    return (tmp);
}

void list_remove_first(list *self)
{
    RETURN_IF_FAIL(self != NULL);

    self->size--;

    node *tmp = self->head;
    self->head = tmp->next;

    object_ref((object *) tmp->next);
    object_unref((object *) tmp);
}
