/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The lexer class.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "object.h"
#include "string.h"
#include "list.h"
#include "node.h"
#include "token.h"
#include "type.h"
#include "type.h"

lexer *lexer_construct(type *object_type)
{
    lexer *self = (lexer *) object_construct(object_type);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    ((object *) self)->finalize = &lexer_finalize;

    return (self);
}

lexer *lexer_new(FILE *stream)
{
    lexer *self = lexer_construct(TYPE_LEXER);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    self->stream = stream;
    self->tokens = list_new();

    return (self);
}

type *lexer_get_type(void)
{
    return (type_register(
        "lexer.lexer",
        sizeof(lexer),
        TYPE_OBJECT
    ));
}

void lexer_finalize(object *parent)
{
    RETURN_IF_FAIL(parent != NULL);
    lexer *self = (lexer *) parent;

    object_unref((object *) self->tokens);

    object_finalize(parent);
}
