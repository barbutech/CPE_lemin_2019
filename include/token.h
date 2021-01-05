/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The token class header.
*/

#ifndef TOKEN_H
#define TOKEN_H

#include "node.h"
#include "object.h"
#include "string.h"
#include "type.h"
#include "base.h"

typedef struct token token;
typedef enum token_type token_type;

enum token_type {
    TOKEN_TEXT,
    TOKEN_COMMENT,
    TOKEN_COMMAND,
    TOKEN_LINK,
    TOKEN_EOL,
    TOKEN_UNKNOWN
};

struct token {
    node parent;
    string *content;
    token_type type;
};

#define TYPE_TOKEN (token_get_type())

token *token_construct(type *object_type);
token *token_new(string *content, token_type type);
type *token_get_type(void);
void token_finalize(object *parent);

#endif
