/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:56:53 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 09:06:52 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	cast_ray(t_data *data, float ray_angle, int strip_id);
static int	is_ray_facing_down(float angle);
static int	is_ray_facing_up(float angle);
static int	is_ray_facing_right(float angle);
static int	is_ray_facing_left(float angle);
static int	is_inside_map(t_data *data, float x, float y);

void	cast_all_rays(t_data *data)
{
	int		col;
	float	ray_angle;
	float	ray_angle_step;
	float	angle_adjust;

	col = 0;
	ray_angle_step = data->fov_angle / NUM_RAYS;
	while (col < NUM_RAYS)
	{
		angle_adjust = atan((col - (NUM_RAYS / 2)) / data->dist_proj_plane);
		ray_angle = data->player.rotation_angle + angle_adjust;
		cast_ray(data, ray_angle, col);
		ray_angle += ray_angle_step;
		col++;
	}
}

static void	cast_ray(t_data *data, float ray_angle, int strip_id)
{
	float	x_intercept;
	float	y_intercept;
	float	x_step;
	float	y_step;
	int		found_horz_wall_hit;
	float	horz_wall_hit_x;
	float	horz_wall_hit_y;
	int		horz_wall_texture;
	float	next_horz_touch_x;
	float	next_horz_touch_y;
	float	x_to_check;
	float	y_to_check;
	int		found_vert_wall_hit;
	float	vert_wall_hit_x;
	float	vert_wall_hit_y;
	int		vert_wall_texture;
	float	next_vert_touch_x;
	float	next_vert_touch_y;
	float	horz_hit_distance;
	float	vert_hit_distance;

	normalize_angle(&ray_angle);
	found_horz_wall_hit = 0;
	horz_wall_hit_x = 0;
	horz_wall_hit_y = 0;
	horz_wall_texture = 0;
	y_intercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_down(ray_angle))
		y_intercept += TILE_SIZE;
	x_intercept = data->player.x + (y_intercept - data->player.y) / tan(ray_angle);
	y_step = TILE_SIZE;
	if (is_ray_facing_up(ray_angle))
		y_step = -y_step;
	x_step = TILE_SIZE / tan(ray_angle);
	if (is_ray_facing_left(ray_angle) && x_step > 0)
		x_step = -x_step;
	if (is_ray_facing_right(ray_angle) && x_step < 0)
		x_step = -x_step;
	next_horz_touch_x = x_intercept;
	next_horz_touch_y = y_intercept;
	while (is_inside_map(data, next_horz_touch_x, next_horz_touch_y))
	{
		x_to_check = next_horz_touch_x;
		y_to_check = next_horz_touch_y;
		if (is_ray_facing_up(ray_angle))
			y_to_check -= 1;
		if (has_wall_at(data, x_to_check, y_to_check))
		{
			horz_wall_hit_x = next_horz_touch_x;
			horz_wall_hit_y = next_horz_touch_y;
			if (is_ray_facing_up(ray_angle))
				horz_wall_texture = 0;
			if (is_ray_facing_down(ray_angle))
				horz_wall_texture = 1;
			found_horz_wall_hit = 1;
			break ;
		}
		else
		{
			next_horz_touch_x += x_step;
			next_horz_touch_y += y_step;
		}
	}
	found_vert_wall_hit = 0;
	vert_wall_hit_x = 0;
	vert_wall_hit_y = 0;
	vert_wall_texture = 0;
	x_intercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_right(ray_angle))
		x_intercept += TILE_SIZE;
	y_intercept = data->player.y + (x_intercept / data->player.x) * tan(ray_angle);
	x_step = TILE_SIZE;
	if (is_ray_facing_left(ray_angle))
		x_step = -x_step;
	y_step = TILE_SIZE * tan(ray_angle);
	if (is_ray_facing_up(ray_angle) && y_step > 0)
		y_step = -y_step;
	if (is_ray_facing_down(ray_angle) && y_step < 0)
		y_step = -y_step;
	next_vert_touch_x = x_intercept;
	next_vert_touch_y = y_intercept;
	while (is_inside_map(data, next_vert_touch_x, next_vert_touch_y))
	{
		x_to_check = next_vert_touch_x;
		if (is_ray_facing_left(ray_angle))
			x_to_check -= 1;
		y_to_check = next_vert_touch_y;
		if (has_wall_at(data, x_to_check, y_to_check))
		{
			vert_wall_hit_x = next_vert_touch_x;
			vert_wall_hit_y = next_vert_touch_y;
			if (is_ray_facing_right(ray_angle))
				vert_wall_texture = 2;
			if (is_ray_facing_left(ray_angle))
				vert_wall_texture = 3;
			found_vert_wall_hit = 1;
			break ;
		}
		else
		{
			next_vert_touch_x += x_step;
			next_vert_touch_y += y_step;
		}
	}
	horz_hit_distance = 3.40282347e+38F;
	if (found_horz_wall_hit)
		horz_hit_distance = distance_between_points(data->player.x, data->player.y, horz_wall_hit_x, horz_wall_hit_y);
	vert_hit_distance = 3.40282347e+38F;
	if (found_vert_wall_hit)
		vert_hit_distance = distance_between_points(data->player.x, data->player.y, vert_wall_hit_x, vert_wall_hit_y);
	if (vert_hit_distance < horz_hit_distance)
	{
		data->rays[strip_id].distance = vert_hit_distance;
		data->rays[strip_id].wall_hit_x = vert_wall_hit_x;
		data->rays[strip_id].wall_hit_y = vert_wall_hit_y;
		data->rays[strip_id].texture = vert_wall_texture;
		data->rays[strip_id].was_hit_vertical = 1;
	}
	else
	{
		data->rays[strip_id].distance = horz_hit_distance;
		data->rays[strip_id].wall_hit_x = horz_wall_hit_x;
		data->rays[strip_id].wall_hit_y = horz_wall_hit_y;
		data->rays[strip_id].texture = horz_wall_texture;
		data->rays[strip_id].was_hit_vertical = 0;
	}
	data->rays[strip_id].angle = ray_angle;
}

static int	is_ray_facing_down(float angle)
{
	return (angle > 0 && angle < PI);
}

static int	is_ray_facing_up(float angle)
{
	return (!is_ray_facing_down(angle));
}

static int	is_ray_facing_right(float angle)
{
	return (angle < PI * 0.5 || angle > PI * 1.5);
}

static int	is_ray_facing_left(float angle)
{
	return (!is_ray_facing_right(angle));
}

static int	is_inside_map(t_data *data, float x, float y)
{
	return (x >= 0 && x <= data->width * TILE_SIZE && y >= 0 && y <= data->height * TILE_SIZE);
}
