/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:56:53 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 15:45:44 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	cast_all_rays(t_data *data)
{
	int		col;
	float	ray_angle;
	float	angle_adjust;

	col = 0;
	while (col < NUM_RAYS)
	{
		angle_adjust = atan((col - (NUM_RAYS / 2)) / data->dist_proj_plane);
		ray_angle = data->player.rotation_angle + angle_adjust;
		normalize_angle(&ray_angle);
		cast_ray(data, ray_angle, col);
		col++;
	}
}
