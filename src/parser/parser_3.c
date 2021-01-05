/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The parser class.
*/

#include "parser.h"
#include "object.h"
#include "lexer.h"
#include "list.h"
#include "node.h"
#include "entry.h"
#include "abstract_node.h"
#include "room.h"
#include "type.h"
#include "base.h"

bool parser_parse_room(parser *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, FALSE);

    if (self->tokens->size < 3)
        return (FALSE);
    token *name = (token *) list_pop_first(self->tokens);
    token *x = (token *) list_pop_first(self->tokens);
    token *y = (token *) list_pop_first(self->tokens);
    if (
        name->type != TOKEN_TEXT || !string_can_be_int(x->content) ||
        !string_can_be_int(y->content)
    ) {
        return (FALSE);
    }
    PARSER_PARSE_ROOM;
    object_unref((object *) room_);
    object_unref((object *) node_);
    object_unref((object *) name);
    object_unref((object *) x);
    object_unref((object *) y);
    return (TRUE);
}

bool parser_parse_link(parser *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, FALSE);

    if (self->tokens->size < 3) {
        return (FALSE);
    }
    PARSER_PARSE_LINK;
    object_unref((object *) first_);
    object_unref((object *) second_);
    object_unref((object *) node_11);
    object_unref((object *) node_12);
    object_unref((object *) node_21);
    object_unref((object *) node_22);
    object_unref((object *) first);
    object_unref((object *) link);
    object_unref((object *) second);
    return (TRUE);
}
