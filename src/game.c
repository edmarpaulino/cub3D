/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:48:51 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 09:57:29 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	render(t_data *data);
static void	render_wall_projection(t_data *data);

int	game(t_data *data)
{
	update(data);
	render(data);
	return (1);
}

static void	render(t_data *data)
{
	render_wall_projection(data);
	mlx_put_image_to_window(data->mlx, data->window, data->canvas->buffer, 0, 0);
}

static void	render_wall_projection(t_data *data)
{
	int		x;
	int		y;
	int		c;
	int		f;
	float	perpendicular_distance;
	float	wall_height;
	int		wall_top_y;
	int		wall_bottom_y;
	int		texture_offset_x;
	int		texture_offset_y;
	t_img	*texture;
	int		distance_from_top;
	int		texel_color;

	x = 0;
	while (x < NUM_RAYS)
	{
		perpendicular_distance = data->rays[x].distance * cos(data->rays[x].angle - data->player.rotation_angle);
		wall_height = (TILE_SIZE / perpendicular_distance) * data->dist_proj_plane;
		wall_top_y = (WINDOW_HEIGHT / 2) - (wall_height / 2);
		if (wall_top_y < 0)
			wall_top_y = 0;
		wall_bottom_y = (WINDOW_HEIGHT / 2) + (wall_height / 2);
		if (wall_bottom_y > WINDOW_HEIGHT || wall_bottom_y < 0)
			wall_bottom_y = WINDOW_HEIGHT;
		c = 0;
		while (c < wall_top_y)
		{
			draw_pixel(data->canvas, x, c, data->ceil_color);
			c++;
		}
		if (data->rays[x].was_hit_vertical)
			texture_offset_x = (int)data->rays[x].wall_hit_y % TILE_SIZE;
		else
			texture_offset_x = (int)data->rays[x].wall_hit_x % TILE_SIZE;
		if (data->rays[x].texture == 0)
			texture = data->north;
		else if (data->rays[x].texture == 1)
			texture = data->south;
		else if (data->rays[x].texture == 2)
			texture = data->east;
		else
			texture = data->west;
		y = wall_top_y;
		while (y < wall_bottom_y)
		{
			distance_from_top = y + (wall_height / 2) - (WINDOW_HEIGHT / 2);
			texture_offset_y = distance_from_top * ((float)texture->height / wall_height);
			texel_color = get_pixel(texture, texture_offset_x, texture_offset_y);
			draw_pixel(data->canvas, x, y, texel_color);
			y++;
		}
		f = wall_bottom_y;
		while (f < WINDOW_HEIGHT)
		{
			draw_pixel(data->canvas, x, f, data->floor_color);
			f++;
		}
		x++;
	}
}
