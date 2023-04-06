/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:14:12 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/01 16:38:10 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void		init_map_file(t_map_file *map_file);

t_map_file	*get_map_file(char *filename)
{
	t_map_file	*map_file;

	check_file(filename);
	map_file = (t_map_file *)malloc(sizeof(t_map_file));
	if (map_file == NULL)
		exit_error("Cannot allocate memory in get_map_file");
	init_map_file(map_file);
	map_file->file_content = get_file_content(filename);
	if (!map_file->file_content)
	{
		free_map_file(map_file);
		exit_error("Cannot get file content");
	}
	load_textures(map_file);
	load_map(map_file);
	return (map_file);
}

static void	init_map_file(t_map_file *map_file)
{
	map_file->matrix = NULL;
	map_file->width = -1;
	map_file->height = -1;
	map_file->texture_no = NULL;
	map_file->texture_so = NULL;
	map_file->texture_ea = NULL;
	map_file->texture_we = NULL;
	map_file->ceil_color = -1;
	map_file->floor_color = -1;
	map_file->player_direction = '?';
	map_file->player_x = -1;
	map_file->player_y = -1;
}
