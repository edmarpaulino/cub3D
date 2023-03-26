/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:35:38 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 10:07:11 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static float	get_initial_rotation_angle(char direction);

void	init_player(t_player *player, char dir, int grid_y, int grid_x)
{
	player->x = ((grid_x - 1) * TILE_SIZE) + (TILE_SIZE / 2);
	player->y = ((grid_y - 1) * TILE_SIZE) + (TILE_SIZE / 2);
	player->width = 3;
	player->height = 3;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = get_initial_rotation_angle(dir);
	player->turn_speed = ONE_RADIAN;
	player->walk_speed = 2;
}

static float	get_initial_rotation_angle(char direction)
{
	if (direction == 'N')
		return (PI * 1.5f);
	if (direction == 'S')
		return (PI * 0.5f);
	if (direction == 'E')
		return (0);
	if (direction == 'W')
		return (PI);
	return (PI);
}
