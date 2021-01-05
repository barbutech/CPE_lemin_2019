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

string *string_new(char *value)
{
    int length = 0;
    for (; value[length] != '\0'; length++);

    return (string_new_with_length(value, length));
}

string *string_new_with_length(char *value, int length)
{
    return (string_new_with_range(value, 0, length));
}

string *string_new_with_range(char *value, int start, int end)
{
    string *self = string_construct(TYPE_STRING);
    RETURN_VAL_IF_FAIL(self != NULL, NULL);

    self->length = end - start;
    self->value = malloc(sizeof(char) * (self->length + 1));

    for (int i = 0; i < self->length; i++) {
        self->value[i] = value[start + i];
    }
    self->value[self->length] = '\0';

    return (self);
}

static int my_pow(int nb, int pow)
{
    int max = 2147483647;
    int nb2 = max;
    for (int i = 0; i < pow; i++) {
        nb2 /= nb;
        if (nb2 == 0) {
            return (0);
        }
    }
    if (pow < 0) {
        return (0);
    }
    if (pow == 0) {
        return (1);
    }
    int power = nb;
    while (pow-- > 1) {
        power *= nb;
    }
    return power;
}

uint string_hash(object *parent)
{
    RETURN_VAL_IF_FAIL(parent != NULL, 0);
    string *self = (string *) parent;

    uint hash = 0;

    for (int i = 0; i < self->length; i++)
        hash += self->value[i] * my_pow(31, self->length - 1 - i);

    return (hash);
}
