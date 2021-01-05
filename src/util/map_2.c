/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The map class.
*/

#include "map.h"
#include "object.h"
#include "string.h"
#include "list.h"
#include "entry.h"
#include "type.h"
#include "base.h"

void map_insert(map *self, string *key, object *elem)
{
    RETURN_IF_FAIL(self != NULL);

    entry *entry_ = entry_new(
        object_hash((object *) key),
        elem
    );

    list_push(self->list, (node *) entry_);

    object_unref((object *) entry_);
}

bool map_contains(map *self, string *key)
{
    RETURN_VAL_IF_FAIL(self != NULL, FALSE);

    node *tmp = self->list->head;
    uint hash = object_hash((object *) key);

    while (tmp != NULL) {

        entry *entry_ = (entry *) tmp;

        if (entry_->hash == hash)
            return (TRUE);

        tmp = tmp->next;
    }

    return (FALSE);
}

object *map_get(map *self, string *key)
{
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    node *tmp = self->list->head;
    uint hash = object_hash((object *) key);

    while (tmp != NULL) {

        entry *entry_ = (entry *) tmp;

        if (entry_->hash == hash)
            return (entry_get_value(entry_));

        tmp = tmp->next;
    }

    return (NULL);
}
