/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:48:15 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 12:52:02 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	draw_ceil(t_data *data, t_wall *wall, int x);
static void	draw_wall(t_data *data, t_wall *wall, int x);
static void	draw_floor(t_data *data, t_wall *wall, int x);
static void	render_wall_projection(t_data *data);

void	render(t_data *data)
{
	render_wall_projection(data);
	mlx_put_image_to_window(data->mlx, data->window,
		data->canvas->buffer, 0, 0);
}

static void	render_wall_projection(t_data *data)
{
	int		x;
	t_wall	wall;

	x = 0;
	while (x < NUM_RAYS)
	{
		wall.perp_distance = (data->rays[x].distance
				* cos(data->rays[x].angle) - data->player.rotation_angle);
		wall.height = (TILE_SIZE / wall.perp_distance) * data->dist_proj_plane;
		wall.top_y = (WINDOW_HEIGHT / 2) - (wall.height / 2);
		if (wall.top_y < 0)
			wall.top_y = 0;
		if (wall.top_y >= WINDOW_HEIGHT)
			wall.top_y = WINDOW_HEIGHT;
		wall.bottom_y = (WINDOW_HEIGHT / 2) + (wall.height / 2);
		if (wall.bottom_y < 0)
			wall.bottom_y = 0;
		if (wall.bottom_y > WINDOW_HEIGHT)
			wall.bottom_y = WINDOW_HEIGHT;
		draw_ceil(data, &wall, x);
		draw_wall(data, &wall, x);
		draw_floor(data, &wall, x);
		x++;
	}
}

static void	draw_ceil(t_data *data, t_wall *wall, int x)
{
	int	y;

	y = 0;
	while (y < wall->top_y)
	{
		draw_pixel(data->canvas, x, y, data->ceil_color);
		y++;
	}
}

static void	draw_wall(t_data *data, t_wall *wall, int x)
{
	int	y;

	if (data->rays[x].was_hit_vertical)
		wall->texture_offset_x = (int)data->rays[x].wall_hit_y % TILE_SIZE;
	else
		wall->texture_offset_x = (int)data->rays[x].wall_hit_x % TILE_SIZE;
	if (data->rays[x].was_hit_vertical
		&& is_ray_facing_down(data->rays[x].angle))
		wall->texture_offset_x = TILE_SIZE - wall->texture_offset_x;
	if (data->rays[x].was_hit_vertical
		&& is_ray_facing_left(data->rays[x].angle))
		wall->texture_offset_x = TILE_SIZE - wall->texture_offset_x;
	if (data->rays[x].wall_texture == 0)
		wall->texture = data->north;
	else if (data->rays[x].wall_texture == 1)
		wall->texture = data->south;
	else if (data->rays[x].wall_texture == 2)
		wall->texture = data->east;
	else
		wall->texture = data->west;
	y = wall->top_y;
	while (y < wall->bottom_y)
	{
		wall->distance_from_top = y + (wall->height / 2) - (WINDOW_HEIGHT / 2);
		wall->texture_offset_y = (wall->distance_from_top
				* ((float)wall->texture->height / wall->height));
		wall->pixel_color = get_pixel(wall->texture, wall->texture_offset_x,
				wall->texture_offset_y);
		draw_pixel(data->canvas, x, y, wall->pixel_color);
		y++;
	}
}

static void	draw_floor(t_data *data, t_wall *wall, int x)
{
	int	y;

	y = wall->bottom_y;
	while (y < WINDOW_HEIGHT)
	{
		draw_pixel(data->canvas, x, y, data->floor_color);
		y++;
	}
}
