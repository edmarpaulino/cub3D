# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 19:16:14 by edpaulin          #+#    #+#              #
#    Updated: 2023/03/23 07:38:19 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL		=	all

NAME				=	cub3D

SRC_DIR				=	src
SRC_FILES			=	main.c \
						queue.c \
						exit_error.c \
						get_map_file.c \
						free_map_file.c \
						check_file.c \
						get_file_content.c \
						has_content.c \
						check_texture.c \
						get_color.c \
						load_textures.c

OBJ_DIR				=	obj
OBJ_FILES			=	$(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

LIBFT_DIR			=	libft
LIBFT_LIB			=	-L$(LIBFT_DIR) -lft
LIBFT_INC			=	-I $(LIBFT_DIR)/includes

CC					=	cc
CFLAGS				=	-g -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_LIB) $(LIBFT_INC) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make $@ -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make $@ -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
