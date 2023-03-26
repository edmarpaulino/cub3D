/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:59:30 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 10:20:24 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# include "../libft/includes/libft.h"
# include "./defs.h"
# include "./queue.h"

void		exit_error(char *err);
t_map_file	*get_map_file(char *filename);
void		free_map_file(t_map_file *map_file);
void		check_file(char *filename);
int			is_file(char *filename);
t_queue		*get_file_content(char *filename);
int			has_content(char *content);
void		check_texture(t_map_file *map_file, char **tex);
void		load_textures(t_map_file *map_file);
int			get_color(char *texture);
char		**get_matrix_map(t_queue *file_content);
void		check_empty(t_map_file *map_file);
void		define_map_sizes(t_map_file *map_file);
void		check_map_edges(t_map_file *map_file);
void		check_map_outside(t_map_file *map_file);
int			is_in_set(char c, char *set);
void		load_map(t_map_file *map_file);
void		check_player(t_map_file *map_file);
void		format_map(t_map_file *map_file);
int			free_data(t_data *data);
void		init_player(t_player *player, char dir, int grid_y, int grid_x);
float		deg_to_rad(float deg);
void		setup(t_data **data, t_map_file *map_file);
void		key_hook(t_data *data);
void		normalize_angle(float *angle);
float		distance_between_points(float x1, float y1, float x2, float y2);
int			get_pixel(t_img *img, int x, int y);
void		draw_pixel(t_img *img, int x, int y, int color);
int			has_wall_at(t_data *data, int x, int y);
int			is_ray_facing_down(float angle);
int			is_ray_facing_up(float angle);
int			is_ray_facing_right(float angle);
int			is_ray_facing_left(float angle);
int			is_inside_map(t_data *data, float x, float y);
void		cast_all_rays(t_data *data);
void		update(t_data *data);
int			game(t_data *data);

#endif
