/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The string class.
*/

#ifndef STRING_H
#define STRING_H

#include "object.h"
#include "type.h"
#include "base.h"

typedef struct string string;

struct string {
    object parent;
    char *value;
    int length;
};

#define TYPE_STRING (string_get_type())

string *string_construct(type *object_type);
string *string_new(char *value);
string *string_new_with_length(char *value, int length);
string *string_new_with_range(char *value, int start, int end);
string *string_substring(string *self, int start, int end);
bool string_contains(string *self, char needle);
bool string_has_prefix(string *self, string *prefix);
bool string_equals(string *self, string *another);
bool string_can_be_int(string *self);
int string_to_int(string *self);
uint string_hash(object *parent);
type *string_get_type(void);
void string_finalize(object *parent);

#endif
