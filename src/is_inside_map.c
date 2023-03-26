/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:18:58 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 10:19:37 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	is_inside_map(t_data *data, float x, float y)
{
	return (
		x >= 0
		&& x <= data->width * TILE_SIZE
		&& y >= 0
		&& y <= data->height * TILE_SIZE
	);
}
