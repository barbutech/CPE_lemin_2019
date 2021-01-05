/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The list class header.
*/

#ifndef LIST_H
#define LIST_H

#include "object.h"
#include "node.h"
#include "type.h"
#include "base.h"

typedef struct list list;
typedef struct node node;

struct room;
struct node;

struct list {
    object parent;
    node *head;
    node *end;
    int size;
};

#define TYPE_LIST (list_get_type())

list *list_construct(type *object_type);
list *list_new(void);
void list_push(list *self, node *value);
node *list_get_head(list *self);
node *list_pop_first(list *self);
void list_remove_first(list *self);
type *list_get_type(void);
void list_finalize(object *parent);

#endif
