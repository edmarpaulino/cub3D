/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:23:05 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 12:06:57 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	is_valid_characters(t_queue *file_content);
static int	is_in_set(char c, char *set);
static int	has_only_one_player(t_queue *file_content);

// valid characters
// one player
// has no empty lines
// has no empty columns
// edges are closed
// only spaces outside the map
 
// TODO: player is inside the map

static void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	ft_putendl_fd("=============================================", STDOUT);
	while (matrix[i])
	{
		ft_putendl_fd(matrix[i], STDOUT);
		i++;
	}
	ft_putendl_fd("=============================================", STDOUT);
}

void	load_map(t_map_file *map_file)
{
	if (!is_valid_characters(map_file->file_content))
	{
		free_map_file(map_file);
		exit_error("Invalid characters in map");
	}
	if (!has_only_one_player(map_file->file_content))
	{
		free_map_file(map_file);
		exit_error("Invalid number of player");
	}
	map_file->matrix = get_matrix_map(map_file->file_content);
	if (!map_file->matrix)
	{
		free_map_file(map_file);
		exit_error("Failed to create map matrix");
	}
	check_empty(map_file);
	define_map_sizes(map_file);
	check_map_edges(map_file);
	check_map_outside(map_file);
	replace_matrix_char(map_file->matrix, '1', '#');
	print_matrix(map_file->matrix);
}

static int	is_valid_characters(t_queue *file_content)
{
	t_queue_item	*tmp;
	int				i;

	if (!file_content)
		return (0);
	tmp = file_content->first;
	while (tmp)
	{
		i = 0;
		while (tmp->value[i])
		{
			if (!is_in_set(tmp->value[i], MAP_SET))
				return (0);
			i++;
		}
		tmp = tmp->next;
	}
	return (1);
}

static int	is_in_set(char c, char *set)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	has_only_one_player(t_queue *file_content)
{
	t_queue_item	*tmp;
	int				i;
	int				num_of_players;

	tmp = file_content->first;
	num_of_players = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->value[i])
		{
			if (is_in_set(tmp->value[i], PLAYER_SET))
				num_of_players++;
			if (num_of_players > 1)
				return (0);
			i++;
		}
		tmp = tmp->next;
	}
	return (num_of_players == 1);
}
