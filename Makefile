# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pparalax <pparalax@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 00:14:47 by pparalax          #+#    #+#              #
#    Updated: 2020/11/06 00:14:49 by pparalax         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lem-in

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc

HEADERS		= lem_in b_tree list

SRC			= \
			after_bf_path_processing \
			after_bf_path_processing_2 \
			b_tree \
			b_tree_special \
			bf \
			exit \
			free \
			helpers \
			list \
			list_2 \
			lem_in \
			main_validation \
			mode \
			mode_set \
			parse \
			print_pathes_with_ants \
			print_tmp

SRC_PATH	= src/
OBJ_PATH	= .obj/

OBJ			= $(addprefix $(OBJ_PATH), $(addsuffix .o, $(SRC)))

OBJ_ALL		= $(OBJ)

LIBFT		= ./libft

LIBFTA		= libft/libft.a

LIBFT_FLAGS	= -L $(LIBFT) -I $(LIBFT)/include -lft

HEADER = ./include/

HEADERS_ALL = $(addprefix $(HEADER), $(addsuffix .h, $(HEADERS)))

LIBFT_HEADER = ./libft/include

all: $(NAME)

$(LIBFTA):
	make -C $(LIBFT)

$(NAME): $(LIBFTA) $(OBJ_ALL)
	$(CC) $(CFLAGS) $(OBJ) $(LEM_IN_OBJ) -I$(HEADER) $(LIBFT_FLAGS) -o $(NAME)

$(OBJ_ALL) : $(OBJ_PATH)%.o : $(SRC_PATH)%.c $(HEADERS_ALL)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -I$(LIBFT_HEADER) -I$(HEADER) -o $@ -c $<

clean:
	make fclean -C $(LIBFT)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
