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

bool lexer_lexe(lexer *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, FALSE);

    char *buffer = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&buffer, &len, self->stream)) != -1) {
        self->pos = 0;
        string *line = string_new_with_length(buffer, nread);
        token *token_;
        while ((token_ = lexer_get_next_token(self, line)) != NULL) {
            if (token_->type == TOKEN_UNKNOWN)
                return (FALSE);
            list_push(self->tokens, (node *) token_);
            object_unref((object *) token_);
        }
        object_unref((object *) line);
    }
    free(buffer);
    return (TRUE);
}

static bool is_text(char c) {
    char text_chars[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
        'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
        'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F',
        'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
        'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
        'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
        '4', '5', '6', '7', '8', '9', '_', '.'
    };

    for (int i = 0; i < 64; i++) {
        if (c == text_chars[i])
            return (TRUE);
    }

    return (FALSE);
}

token *lexer_get_next_token(lexer *self, string *line)
{
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    while (line->value[self->pos] == ' ')
        self->pos++;
    if (self->pos >= line->length)
        return (NULL);
    int start = self->pos;
    token_type type;
    LEXER_LEXE;
    string *substr = string_substring(line, start, self->pos);
    token *token_ = token_new(substr, type);
    object_unref((object *) substr);
    return (token_);
}
