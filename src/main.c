/*
** EPITECH PROJECT, 2019
** lem-in
** File description:
** The main file.
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

int main(void)
{
    lexer *lexer_ = lexer_new(stdin);
    if (!lexer_lexe(lexer_))
        return (84);
    parser *parser_ = parser_new(lexer_);
    if (!parser_parse(parser_))
        return (84);
    abstract_node *head_node = (abstract_node *) list_get_head(parser_->rooms);
    if (head_node == NULL || parser_->start == NULL || parser_->end == NULL) {
        return (84);
    }
    print_solution(parser_);
    room *head = (room *) parser_->start;
    step *path = find_shortest_path(head);
    if (path != NULL)
        ants_move(1, parser_->ants, path);
    object_unref((object *) head_node);
    object_unref((object *) lexer_);
    object_unref((object *) parser_);
    return ((path != NULL && parser_->ants != 0) ? 0 : 84);
}
