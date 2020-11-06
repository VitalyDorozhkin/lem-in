# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pparalax <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 16:59:28 by pparalax          #+#    #+#              #
#    Updated: 2019/09/06 16:59:33 by pparalax         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc

SRC			= \
		ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memccpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_nbrlen \
		ft_strlen \
		ft_strdup \
		ft_strcpy \
		ft_strncpy \
		ft_strcat \
		ft_strncat \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strrev \
		ft_strstr \
		ft_strnstr \
		ft_strcmp \
		ft_strncmp \
		ft_abs \
		ft_atoi \
		ft_itoa_base \
		ft_uitoa_base \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_memalloc \
		ft_memdel \
		ft_strnew \
		ft_strdel \
		ft_strclr \
		ft_striter \
		ft_striteri \
		ft_strmap \
		ft_strmapi \
		ft_strequ \
		ft_strnequ \
		ft_strsub \
		ft_strjoin \
		ft_strjoinfree \
		ft_strtrim \
		ft_strsplit \
		ft_itoa \
		ft_putchar \
		ft_putchars \
		ft_putnbr \
		ft_putstr \
		ft_putendl \
		ft_putchar_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_lstnew \
		ft_lstdelone \
		ft_lstdel \
		ft_lstadd \
		ft_lstiter \
		ft_lstmap \
		ft_lstlen \
		ft_lstlast \
		ft_strlcpy \
		ft_isupper \
		ft_islower \
		ft_capitalize \
		ft_lst_push_back \
		ft_lst_push_front \
		ft_lst_reverse \
		get_next_line

PRINTF_SRC	= \
		convert \
		ft_printf \
		ft_fprintf \
		ft_printf_puts \
		read_flags \
		print_xob \
		print_di \
		print_tyr \
		print_u \
		print_s \
		print_c \
		print_fff \
		infin_mult \
		print_ff \
		handle_decoded \
		print_f

OBJ			= $(addprefix $(OBJ_PATH), $(addsuffix .o, $(SRC)))

PRINTF_OBJ	= $(addprefix $(PRINTF_OBJ_PATH), $(addsuffix .o, $(PRINTF_SRC)))

HEADER		= include/

PRINTF_HEADER	= ft_printf/include/

SRC_PATH	= src/

OBJ_PATH	= .obj/

PRINTF_SRC_PATH = ft_printf/src/

PRINTF_OBJ_PATH = ft_printf/.obj/

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF_OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ) $(PRINTF_OBJ)
	ranlib $(NAME)

$(OBJ) : $(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -I./$(HEADER) -o $@ -c $<

$(PRINTF_OBJ) : $(PRINTF_OBJ_PATH)%.o : $(PRINTF_SRC_PATH)%.c
	@mkdir -p $(PRINTF_OBJ_PATH)
	$(CC) $(CFLAGS) -I./$(HEADER) -I./$(PRINTF_HEADER) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH) $(PRINTF_OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
