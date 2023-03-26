/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:51:55 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 16:25:21 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void		init_empty(t_data *data);
static t_img	*get_canvas(void *mlx);
static t_img	*get_texture_img(void *mlx, char *filename);
static void		init_textures(t_data *data, t_map_file *map_file);

void	setup(t_data **data, t_map_file *map_file)
{
	(*data) = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		free_map_file(map_file);
		exit_error("Failed to allocate memory to data");
	}
	init_empty(*data);
	(*data)->mlx = mlx_init();
	(*data)->window = mlx_new_window(
			(*data)->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			TITLE);
	(*data)->canvas = get_canvas((*data)->mlx);
	init_textures(*data, map_file);
	init_player(&(*data)->player, map_file->player_direction,
		map_file->player_y, map_file->player_x);
	(*data)->grid = map_file->matrix;
	map_file->matrix = NULL;
	(*data)->width = map_file->width;
	(*data)->height = map_file->height;
	free_map_file(map_file);
	(*data)->fov_angle = deg_to_rad(FOV_ANGLE_DEGREE);
	(*data)->dist_proj_plane = ((WINDOW_WIDTH / 2)
			/ tan((*data)->fov_angle / 2));
}

static void	init_empty(t_data *data)
{
	data->mlx = NULL;
	data->window = NULL;
	data->canvas = NULL;
	data->grid = NULL;
	data->textures[T_NO] = NULL;
	data->textures[T_SO] = NULL;
	data->textures[T_EA] = NULL;
	data->textures[T_WE] = NULL;
}

static t_img	*get_canvas(void *mlx)
{
	t_img	*canvas;

	canvas = (t_img *)malloc(sizeof(t_img));
	if (!canvas)
		return (NULL);
	canvas->buffer = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	canvas->addr = mlx_get_data_addr(canvas->buffer, &canvas->bpp,
			&canvas->size_line, &canvas->endian);
	canvas->width = WINDOW_WIDTH;
	canvas->height = WINDOW_HEIGHT;
	return (canvas);
}

static t_img	*get_texture_img(void *mlx, char *filename)
{
	t_img	*texture;

	texture = (t_img *)malloc(sizeof(t_img));
	if (!texture)
		return (NULL);
	texture->buffer = mlx_xpm_file_to_image(mlx, filename, &texture->width,
			&texture->height);
	texture->addr = mlx_get_data_addr(texture->buffer, &texture->bpp,
			&texture->size_line, &texture->endian);
	return (texture);
}

static void	init_textures(t_data *data, t_map_file *map_file)
{
	data->textures[T_NO] = get_texture_img(data->mlx, map_file->texture_no);
	data->textures[T_SO] = get_texture_img(data->mlx, map_file->texture_so);
	data->textures[T_EA] = get_texture_img(data->mlx, map_file->texture_ea);
	data->textures[T_WE] = get_texture_img(data->mlx, map_file->texture_we);
	data->ceil_color = map_file->ceil_color;
	data->floor_color = map_file->floor_color;
}
