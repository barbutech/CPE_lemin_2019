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

bool parser_parse(parser *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, FALSE);

    while (self->tokens->size != 0) {
        if (!parser_parse_line(self))
            return (FALSE);
    }

    return (TRUE);
}

bool parser_parse_line(parser *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, FALSE);

    token *token_ = (token *) list_get_head(self->tokens);
    PARSER_PARSE_LINE;
    object_unref((object *) token_);
    if (self->tokens->size == 0)
        return (TRUE);
    token_ = (token *) list_get_head(self->tokens);
    if (token_->type != TOKEN_EOL && token_->type != TOKEN_COMMENT) {
        return (FALSE);
    }
    if (token_->type == TOKEN_EOL)
        list_remove_first(self->tokens);
    object_unref((object *) token_);
    return (TRUE);
}

bool parser_parse_command(parser *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, FALSE);

    token *token_ = (token *) list_pop_first(self->tokens);
    if (token_->type != TOKEN_COMMAND)
        return (FALSE);
    object_unref((object *) token_);
    token_ = (token *) list_pop_first(self->tokens);
    string *start_cmd = string_new("start");
    string *end_cmd = string_new("end");
    PARSER_PARSE_COMMAND;
    object_unref((object *) start_cmd);
    object_unref((object *) end_cmd);
    object_unref((object *) token_);
    return (TRUE);
}

bool parser_parse_comment(parser *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, FALSE);

    token *token_ = (token *) list_pop_first(self->tokens);
    if (token_->type != TOKEN_COMMENT) {
        return (FALSE);
    }
    object_unref((object *) token_);
    token_ = (token *) list_get_head(self->tokens);
    if (token_ == NULL)
        return (TRUE);
    while (token_->type != TOKEN_EOL) {
        list_remove_first(self->tokens);
        object_unref((object *) token_);
        token_ = (token *) list_get_head(self->tokens);
        if (token_ == NULL) return (TRUE);
    }
    object_unref((object *) token_);
    return (TRUE);
}

bool parser_parse_header(parser *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, FALSE);

    token *number = (token *) list_pop_first(self->tokens);
    if (!string_can_be_int(number->content)) {
        return (FALSE);
    }
    self->ants = string_to_int(number->content);
    object_unref((object *) number);
    return (TRUE);
}
