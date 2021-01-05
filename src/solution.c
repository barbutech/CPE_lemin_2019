/*
** EPITECH PROJECT, 2019
** lem-in
** File description:
** The solution file.
*/

#include "printf/printf.h"
#include "lexer.h"
#include "parser.h"
#include "node.h"
#include "abstract_node.h"
#include "history_node.h"
#include "token.h"
#include "step.h"
#include "solution.h"
#include "type.h"
#include "base.h"

void print_solution(parser *parser_)
{
    my_printf("#number_of_ants\n%i\n", parser_->ants);
    my_printf("#rooms\n");
    node *tmp = parser_->rooms->head;
    while (tmp != NULL) {
        room *room_ = (room *) ((abstract_node *) tmp)->value;
        if (room_->is_start)
            my_printf("##start\n");
        else if (room_->is_end)
            my_printf("##end\n");
        my_printf("%s %i %i\n", room_->name->value, room_->x, room_->y);
        tmp = tmp->next;
    }
    my_printf("#tunnels\n");
    tmp = parser_->tunnels->head;
    while (tmp != NULL) {
        room *room_1 = (room *) ((abstract_node *) tmp)->value;
        room *room_2 = (room *) ((abstract_node *) tmp->next)->value;
        my_printf("%s-%s\n", room_1->name->value, room_2->name->value);
        tmp = tmp->next->next;
    }
}

step *find_shortest_path(room *head)
{
    list *queue = list_new();
    history_node *node_ = history_node_new(head, NULL);
    list_push(queue, (node *) node_);
    object_unref((object *) node_);
    history_node *end = NULL;
    FIND_SHORTEST;
    result->size = size;
    object_unref((object *) queue);
    return (result);
}

void ants_move(int current, int max, step *path)
{
    my_printf("#moves\n");
    int max_it = path->size + max - 2;
    for (int i = 0; i < max_it; i++) {
        step *tmp = path;
        step *first;
        while (tmp != NULL) {
            ANTS_MOVE;
        }
        if (current <= max) {
            first->is_empty = FALSE;
            first->index = current;
            my_printf("P%i-%s", current, first->name->value);
            current++;
        }
        my_printf("\n");
    }
}
