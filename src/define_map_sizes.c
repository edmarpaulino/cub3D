/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map_sizes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 08:48:53 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 08:55:38 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	get_map_width(char **map);
static int	get_map_height(char **map);

void	define_map_sizes(t_map_file *map_file)
{
	char	*err_msg;

	err_msg = NULL;
	map_file->width = get_map_width(map_file->matrix);
	map_file->height = get_map_height(map_file->matrix);
	if (map_file->width == 0 && map_file->height == 0)
		err_msg = "Map doesn't has width and height";
	else if (map_file->width == 0)
		err_msg = "Map doens't has width";
	else if (map_file->height == 0)
		err_msg = "Map doesn't has height";
	if (err_msg)
	{
		free_map_file(map_file);
		exit_error(err_msg);
	}
}

static int	get_map_width(char **map)
{
	int	width;

	width = 0;
	while (map[0][width])
		width++;
	return (width);
}

static int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}
