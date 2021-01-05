/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** The parser class header.
*/

#ifndef PARSER_H
#define PARSER_H

#include "object.h"
#include "lexer.h"
#include "list.h"
#include "map.h"
#include "room.h"
#include "type.h"
#include "base.h"

typedef struct parser parser;
typedef enum parser_mode parser_mode;

enum parser_mode {
    PARSER_HEADER_MODE,
    PARSER_ROOM_MODE,
    PARSER_LINK_MODE
};

struct parser {
    object parent;
    list *tokens;
    list *rooms;
    list *tunnels;
    map *map;
    parser_mode mode;
    int ants;
    room *start;
    room *end;
    bool next_is_start;
    bool next_is_end;
};

#define PARSER_PARSE_LINE if (self->mode == PARSER_HEADER_MODE) { \
    if (token_->type == TOKEN_COMMENT) { \
        if (!parser_parse_comment(self)) \
            return (FALSE); \
    } else { \
        if (!parser_parse_header(self)) \
            return (FALSE); \
        self->mode = PARSER_ROOM_MODE; \
    } \
} \
else if (token_->type == TOKEN_COMMAND) { \
    if (!parser_parse_command(self)) \
        return (FALSE); \
} \
else if (token_->type == TOKEN_COMMENT) { \
    if (!parser_parse_comment(self)) \
        return (FALSE); \
} \
else { \
    if ( \
        self->mode == PARSER_ROOM_MODE && \
        ((token *) self->tokens->head->next)->type == TOKEN_LINK \
    ) \
        self->mode = PARSER_LINK_MODE; \
    if (self->mode == PARSER_ROOM_MODE) { \
        if (!parser_parse_room(self)) \
            return (FALSE); \
    } \
    else { \
        if (!parser_parse_link(self)) \
            return (FALSE); \
    } \
}

#define PARSER_PARSE_COMMAND if (string_equals(token_->content, start_cmd)) { \
    if (self->start != NULL) \
        return (FALSE); \
    self->next_is_start = TRUE; \
} \
if (string_equals(token_->content, end_cmd)) { \
    if (self->end != NULL) \
        return (FALSE); \
    self->next_is_end = TRUE; \
}

#define PARSER_PARSE_ROOM int pos_x = string_to_int(x->content); \
int pos_y = string_to_int(y->content); \
room *room_ = room_new( \
    name->content, \
    pos_x, \
    pos_y \
); \
if (self->next_is_start) { \
    self->start = room_; \
    self->next_is_start = FALSE; \
    room_->is_start = TRUE; \
    object_ref((object *) room_); \
} \
if (self->next_is_end) { \
    self->end = room_; \
    self->next_is_end = FALSE; \
    room_->is_end = TRUE; \
    object_ref((object *) room_); \
} \
if (map_contains(self->map, room_->name)) { \
    return (FALSE); \
} \
node *tmp = self->map->list->head; \
while (tmp != NULL) { \
    entry *entry_ = (entry *) tmp; \
    room *room_ = (room *) entry_->value; \
    if (room_->x == pos_x && room_->y == pos_y) { \
        return (FALSE); \
    } \
    tmp = tmp->next; \
} \
abstract_node *node_ = abstract_node_new((object *) room_); \
list_push( \
    self->rooms, \
    (node *) node_ \
); \
map_insert( \
    self->map, \
    room_->name, \
    (object *) room_ \
);

#define PARSER_PARSE_LINK \
token *first = (token *) list_pop_first(self->tokens); \
token *link = (token *) list_pop_first(self->tokens); \
token *second = (token *) list_pop_first(self->tokens); \
if (link->type != TOKEN_LINK || first->type != TOKEN_TEXT || \
    second->type != TOKEN_TEXT) { \
    return (FALSE); \
} \
if (!map_contains(self->map, first->content) || \
!map_contains(self->map, second->content)) { \
    return (FALSE); \
} \
room *first_ = (room *) map_get(self->map, first->content); \
room *second_ = (room *) map_get(self->map, second->content); \
node *node_11 = (node *) abstract_node_new((object *) first_); \
node *node_12 = (node *) abstract_node_new((object *) second_); \
node *node_21 = (node *) abstract_node_new((object *) first_); \
node *node_22 = (node *) abstract_node_new((object *) second_); \
list_push( \
    first_->children, \
    node_12 \
); \
list_push( \
    second_->children, \
    node_11 \
); \
list_push(self->tunnels, node_21); \
list_push(self->tunnels, node_22);

#define TYPE_PARSER (parser_get_type())

parser *parser_construct(type *object_type);
parser *parser_new(lexer *lexer);
bool parser_parse(parser *self);
bool parser_parse_line(parser *self);
bool parser_parse_command(parser *self);
bool parser_parse_comment(parser *self);
bool parser_parse_header(parser *self);
bool parser_parse_room(parser *self);
bool parser_parse_link(parser *self);
type *parser_get_type(void);
void parser_finalize(object *parent);

#endif
