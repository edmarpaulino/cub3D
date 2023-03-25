/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:13:30 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 19:23:27 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	format_map(t_map_file *map_file)
{
	int	row;
	int	col;

	map_file->matrix[map_file->player_y][map_file->player_x] = '0';
	row = 0;
	while (map_file->matrix[row])
	{
		col = 0;
		while (map_file->matrix[row][col])
		{
			if (map_file->matrix[row][col] != '0')
				map_file->matrix[row][col] = '1';
			col++;
		}
		row++;
	}
}
