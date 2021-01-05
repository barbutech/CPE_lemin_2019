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

parser *parser_construct(type *object_type)
{
    parser *self = (parser *) object_construct(object_type);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    ((object *) self)->finalize = &parser_finalize;

    return (self);
}

parser *parser_new(lexer *lexer)
{
    parser *self = parser_construct(TYPE_PARSER);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    self->mode = PARSER_HEADER_MODE;

    self->tokens = lexer->tokens;
    self->rooms = list_new();
    self->tunnels = list_new();
    self->map = map_new();

    object_ref((object *) self->tokens);

    self->ants = 0;
    self->start = NULL;
    self->end = NULL;
    self->next_is_start = FALSE;
    self->next_is_end = FALSE;
    return (self);
}

type *parser_get_type(void)
{
    return (type_register(
        "parser.parser",
        sizeof(parser),
        TYPE_OBJECT
    ));
}

void parser_finalize(object *parent)
{
    RETURN_IF_FAIL(parent != NULL);
    parser *self = (parser *) parent;

    object_unref((object *) self->tokens);
    object_unref((object *) self->rooms);
    object_unref((object *) self->tunnels);
    object_unref((object *) self->map);

    object_unref((object *) self->start);
    object_unref((object *) self->end);

    object_finalize(parent);
}
