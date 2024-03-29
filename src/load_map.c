/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:23:05 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 19:31:25 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	check_characters(t_map_file *map_file);

void	load_map(t_map_file *map_file)
{
	check_characters(map_file);
	map_file->matrix = get_matrix_map(map_file->file_content);
	if (!map_file->matrix)
	{
		free_map_file(map_file);
		exit_error("Failed to create map matrix");
	}
	check_empty(map_file);
	define_map_sizes(map_file);
	check_map_edges(map_file);
	check_player(map_file);
	format_map(map_file);
}

static void	check_characters(t_map_file *map_file)
{
	t_queue_item	*tmp;
	int				i;

	if (!map_file->file_content)
	{
		free_map_file(map_file);
		exit_error("File doesn't has content");
	}
	tmp = map_file->file_content->first;
	while (tmp)
	{
		i = 0;
		while (tmp->value[i])
		{
			if (!is_in_set(tmp->value[i], MAP_SET))
			{
				free_map_file(map_file);
				exit_error("Invalid characters in map");
			}
			i++;
		}
		tmp = tmp->next;
	}
}
