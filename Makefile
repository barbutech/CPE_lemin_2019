
SRC = src/lang/object_1.c \
      src/lang/object_2.c \
	  src/lang/string_1.c \
	  src/lang/string_2.c \
	  src/lang/string_3.c \
      src/lang/string_4.c \
	  src/lexer/lexer_1.c \
      src/lexer/lexer_2.c \
      src/lexer/token.c \
	  src/parser/parser_1.c \
	  src/parser/parser_2.c \
      src/parser/parser_3.c \
      src/parser/room.c \
      src/parser/step.c \
	  src/printf/print/print_big_str.c \
	  src/printf/print/print_binary.c \
	  src/printf/print/print_char.c \
	  src/printf/print/print_escapement.c \
	  src/printf/print/print_hex_low.c \
	  src/printf/print/print_hex_up.c \
	  src/printf/print/print_int_format.c \
	  src/printf/print/print_int.c \
	  src/printf/print/print_octal.c \
	  src/printf/print/print_ptr.c \
	  src/printf/print/print_str.c \
	  src/printf/print/print_unsigned.c \
	  src/printf/util/append_char.c \
	  src/printf/util/append_string.c \
	  src/printf/util/convert_base.c \
	  src/printf/util/my_char_isprintable.c \
	  src/printf/util/my_putchar.c \
	  src/printf/flag.c \
	  src/printf/my_printf.c \
	  src/printf/parser.c \
      src/util/abstract_node.c \
      src/util/entry.c \
      src/util/history_node.c \
	  src/util/list_1.c \
      src/util/list_2.c \
	  src/util/map_1.c \
      src/util/map_2.c \
      src/util/node.c \
	  src/main.c \
      src/solution.c \
      src/type.c

NAME = lem_in

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Iinclude -g
CC = gcc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	$(MAKE) clean
