.PHONY: all clean install uninstall

FLAGS = -Wall -Wextra -Werror -I./libft/include/libft.h -I./include/

FILES = convert.c \
      ft_printf.c \
      ft_fprintf.c \
      ft_printf_puts.c \
      read_flags.c \
      print_xob.c \
      print_di.c \
      print_tyr.c \
      print_u.c \
      print_s.c \
      print_c.c \
      print_fff.c \
      infin_mult.c \
      print_ff.c \
      handle_decoded.c \
      print_f.c

SRC_PATH = ./src/

SRC = $(addprefix $(SRC_PATH), $(FILES))

LIBFT = ../libft/libft.a

NAME = ../libftprintf.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)

$(OBJ): %.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
