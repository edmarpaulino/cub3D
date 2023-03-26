/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_facing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:17:36 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 10:18:04 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	is_ray_facing_down(float angle)
{
	return (angle > 0 && angle < PI);
}

int	is_ray_facing_up(float angle)
{
	return (!is_ray_facing_down(angle));
}

int	is_ray_facing_right(float angle)
{
	return (angle < PI * 0.5 || angle > PI * 1.5);
}

int	is_ray_facing_left(float angle)
{
	return (!is_ray_facing_right(angle));
}
