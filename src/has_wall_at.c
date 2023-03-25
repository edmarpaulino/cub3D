/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:38:47 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 20:42:53 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	has_wall_at(t_data *data, int x, int y)
{
	int	grid_index_x;
	int	grid_index_y;

	if (x < 0 || x >= data->width * TILE_SIZE
		|| y < 0 || y >= data->height * TILE_SIZE)
		return (1);
	grid_index_x = floor(x / TILE_SIZE);
	grid_index_y = floor(y / TILE_SIZE);
	return (data->grid[grid_index_y][grid_index_x] != '0');
}
