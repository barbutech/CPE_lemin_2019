/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The string class.
*/

#include <stdlib.h>
#include "string.h"
#include "object.h"
#include "type.h"
#include "base.h"

string *string_substring(string *self, int start, int end)
{
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    if (start > end)
        return (NULL);

    return (string_new_with_range(self->value, start, end));
}

bool string_contains(string *self, char needle)
{
    RETURN_VAL_IF_FAIL(self != NULL, FALSE);

    for (int i = 0; i < self->length; i++) {
        if (self->value[i] == needle)
            return (TRUE);
    }

    return (FALSE);
}

bool string_has_prefix(string *self, string *prefix)
{
    RETURN_VAL_IF_FAIL(self != NULL, FALSE);

    if (self->length < prefix->length)
        return (FALSE);
    if (self->length == prefix->length)
        return (string_equals(self, prefix));

    for (int i = 0; i < prefix->length; i++) {
        if (self->value[i] == prefix->value[i])
            continue;
        return (FALSE);
    }

    return (TRUE);
}

bool string_equals(string *self, string *another)
{
    RETURN_VAL_IF_FAIL(self != NULL, FALSE);

    if (self->length != another->length)
        return (FALSE);

    for (int i = 0; i < self->length; i++) {
        if (self->value[i] == another->value[i])
            continue;
        return (FALSE);
    }

    return (TRUE);
}
