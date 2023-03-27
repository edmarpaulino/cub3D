/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:25:28 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/27 07:56:59 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	update_player(t_data *data);

void	update(t_data *data)
{
	update_player(data);
	cast_all_rays(data);
}

static void	update_player(t_data *data)
{
	float		move_step;
	float		strafe_step;
	float		new_player_x;
	float		new_player_y;
	t_player	*player;

	player = &data->player;
	player->rotation_angle += player->turn_direction * player->turn_speed;
	normalize_angle(&player->rotation_angle);
	move_step = player->walk_direction * player->walk_speed;
	strafe_step = player->strafe_direction * player->strafe_speed;
	new_player_x = player->x + cos(player->rotation_angle) * move_step;
	new_player_y = player->y + sin(player->rotation_angle) * move_step;
	new_player_x = new_player_x + sin(-player->rotation_angle) * strafe_step;
	new_player_y = new_player_y + cos(-player->rotation_angle) * strafe_step;
	if (!has_wall_at(data, new_player_x, new_player_y)
		&& is_inside_map(data, new_player_x, new_player_y))
	{
		player->x = new_player_x;
		player->y = new_player_y;
	}
}
