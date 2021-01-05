/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The solution header.
*/

#ifndef SOL_H
#define SOL_H

void print_solution(parser *parser_);
step *find_shortest_path(room *head);
void ants_move(int current, int max, step *path);

#define FIND_SHORTEST \
while (queue->size != 0) { \
    history_node *node_ = (history_node *) list_pop_first(queue); \
    room *room_ = node_->current; \
    if (room_->is_end) { \
        end = node_; \
        break; \
    } \
    node *tmp = room_->children->head; \
    while (tmp != NULL) { \
        room *child = (room *) ((abstract_node *) tmp)->value; \
        if (!child->visited) { \
            history_node *child_node = history_node_new(child, node_); \
            list_push(queue, (node *) child_node); \
            child->visited = TRUE; \
            object_unref((object *) child_node); \
        } \
        tmp = tmp->next; \
    } \
    object_unref((object *) node_); \
} \
step *result = NULL; \
step *step_ = NULL; \
int size = 0; \
while (end != NULL) { \
    step *_step = step_new(end->current->name); \
    if (result == NULL) \
        result = _step; \
    if (step_ != NULL) \
        step_->next = _step; \
    step_ = _step; \
    size++; \
    end = end->superior; \
} \
if (result == NULL) \
    return (NULL);

#define ANTS_MOVE if (tmp->next != NULL && !tmp->next->is_empty) { \
    tmp->is_empty = FALSE; \
    tmp->next->is_empty = TRUE; \
    tmp->index = tmp->next->index; \
    tmp->next->index = -1; \
    my_printf("P%i-%s%s", tmp->index, tmp->name->value, \
    (tmp->index == max ? "" : " ")); \
} \
if (tmp->next != NULL) \
    first = tmp; \
tmp = tmp->next;

#endif
