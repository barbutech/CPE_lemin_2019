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

bool string_can_be_int(string *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, FALSE);

    int i = 0;

    i += (self->value[0] == '-');
    i += (self->value[0] == '+');

    for (; i < self->length; i++) {
        if ('0' <= self->value[i] && self->value[i] <= '9')
            continue;
        return (FALSE);
    }

    return (TRUE);
}

int string_to_int(string *self)
{
    RETURN_VAL_IF_FAIL(self != NULL, 0);

    int sign = 1;
    int nb = 0;
    int i = 0;

    if (self->value[0] == '-') {
        sign = -1;
        i++;
    }
    if (self->value[0] == '+') {
        sign = 1;
        i++;
    }
    for (; i < self->length; i++) {
        if ('0' > self->value[i] || self->value[i] > '9')
            return (-1);
        nb = (nb * 10) + (self->value[i] - '0');
    }
    return (nb * sign);
}
