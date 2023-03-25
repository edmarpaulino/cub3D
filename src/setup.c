/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:51:55 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 19:48:51 by edpaulin         ###   ########.fr       */
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
	free_map_file(map_file);
}

static void	init_empty(t_data *data)
{
	data->mlx = NULL;
	data->window = NULL;
	data->canvas = NULL;
	data->grid = NULL;
	data->north = NULL;
	data->south = NULL;
	data->east = NULL;
	data->west = NULL;
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
	return (canvas);
}

static t_img	*get_texture_img(void *mlx, char *filename)
{
	int		width;
	int		height;
	t_img	*texture;

	texture = (t_img *)malloc(sizeof(t_img));
	if (!texture)
		return (NULL);
	texture->buffer = mlx_xpm_file_to_image(mlx, filename, &width, &height);
	texture->addr = mlx_get_data_addr(texture->buffer, &texture->bpp,
			&texture->size_line, &texture->endian);
	return (texture);
}

static void	init_textures(t_data *data, t_map_file *map_file)
{
	data->north = get_texture_img(data->mlx, map_file->texture_no);
	data->south = get_texture_img(data->mlx, map_file->texture_so);
	data->east = get_texture_img(data->mlx, map_file->texture_ea);
	data->west = get_texture_img(data->mlx, map_file->texture_we);
	data->ceil_color = map_file->ceil_color;
	data->floor_color = map_file->floor_color;
}
