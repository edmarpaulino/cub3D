# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 19:16:14 by edpaulin          #+#    #+#              #
#    Updated: 2023/03/26 10:19:57 by edpaulin         ###   ########.fr        #
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
						load_textures.c \
						get_matrix_map.c \
						check_empty.c \
						define_map_sizes.c \
						check_map_edges.c \
						check_map_outside.c \
						is_in_set.c \
						format_map.c \
						load_map.c \
						check_player.c \
						free_data.c \
						init_player.c \
						deg_to_rad.c \
						setup.c \
						key_hook.c \
						normalize_angle.c \
						distance_between_points.c \
						draw_pixel.c \
						get_pixel.c \
						has_wall_at.c \
						is_ray_facing.c \
						is_inside_map.c \
						cast_all_rays.c \
						update.c \
						game.c

OBJ_DIR				=	obj
OBJ_FILES			=	$(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

LIBFT_DIR			=	libft
LIBFT_LIB			=	-L$(LIBFT_DIR) -lft
LIBFT_INC			=	-I $(LIBFT_DIR)/includes

LIBS				=	-lmlx -lbsd -lXext -lX11 -lm $(LIBFT_LIB)

CC					=	cc
CFLAGS				=	-g -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) $(LIBFT_INC) -o $(NAME)

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
