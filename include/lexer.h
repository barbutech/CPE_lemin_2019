/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The lexer class header.
*/

#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include "object.h"
#include "string.h"
#include "list.h"
#include "token.h"
#include "type.h"
#include "type.h"

typedef struct lexer lexer;

struct lexer {
    object parent;
    FILE *stream;
    list *tokens;
    int pos;
};

#define LEXER_LEXE_COMMENT if (line->value[self->pos + 1] == '#') { \
    type = TOKEN_COMMAND; \
    self->pos++; \
} else { \
    type = TOKEN_COMMENT; \
}

#define LEXER_LEXE if (is_text(line->value[self->pos])) { \
    while (is_text(line->value[self->pos])) \
        self->pos++; \
    type = TOKEN_TEXT; \
} \
else { \
    switch (line->value[self->pos]) { \
        case '#': \
            LEXER_LEXE_COMMENT; \
            break; \
        case '-': \
            type = TOKEN_LINK; \
            break; \
        case '\n': \
            type = TOKEN_EOL; \
            break; \
        default: \
            type = TOKEN_UNKNOWN; \
    } \
    self->pos++; \
}

#define TYPE_LEXER (lexer_get_type())

lexer *lexer_construct(type *object_type);
lexer *lexer_new(FILE *stream);
bool lexer_lexe(lexer *self);
token *lexer_get_next_token(lexer *self, string *line);
type *lexer_get_type(void);
void lexer_finalize(object *parent);

#endif
