/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The token class.
*/

#include "token.h"
#include "node.h"
#include "object.h"
#include "string.h"
#include "type.h"
#include "base.h"

token *token_construct(type *object_type)
{
    token *self = (token *) node_construct(object_type);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    ((object *) self)->finalize = &token_finalize;

    return (self);
}

token *token_new(string *content, token_type type)
{
    token *self = token_construct(TYPE_TOKEN);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    self->content = content;
    self->type = type;

    object_ref((object *) content);

    return (self);
}

type *token_get_type(void)
{
    return (type_register(
        "lexer.token",
        sizeof(token),
        TYPE_NODE
    ));
}

void token_finalize(object *parent)
{
    RETURN_IF_FAIL(parent != NULL);
    token *self = (token *) parent;

    object_unref((object *) self->content);

    node_finalize(parent);
}
