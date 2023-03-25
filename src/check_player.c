/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:49:05 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 18:42:53 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	get_number_of_players(char **matrix);
static void	set_player_position(t_map_file *map_file);
static int	is_player_inside_map(char **matrix, int player_y, int player_x);

void	check_player(t_map_file *map_file)
{
	int		num_of_players;

	num_of_players = get_number_of_players(map_file->matrix);
	if (num_of_players != 1)
	{
		free_map_file(map_file);
		if (num_of_players > 0)
			exit_error("The map has more than one player");
		else
			exit_error("The map doesn't has player");
	}
	set_player_position(map_file);
	if (!is_player_inside_map(
			map_file->matrix,
			map_file->player_y,
			map_file->player_x))
	{
		free_map_file(map_file);
		exit_error("Player is not inside the map");
	}
}

static int	get_number_of_players(char **matrix)
{
	int	num_of_players;
	int	row;
	int	col;

	num_of_players = 0;
	row = 0;
	while (matrix[row])
	{
		col = 0;
		while (matrix[row][col])
		{
			if (is_in_set(matrix[row][col], PLAYER_SET))
				num_of_players++;
			col++;
		}
		row++;
	}
	return (num_of_players);
}

static void	set_player_position(t_map_file *map_file)
{
	int		y;
	int		x;
	char	**matrix;

	matrix = map_file->matrix;
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x]
			&& !is_in_set(matrix[y][x], PLAYER_SET))
			x++;
		if (is_in_set(matrix[y][x], PLAYER_SET))
			break ;
		y++;
	}
	if (matrix[y] == NULL
		|| matrix[y][x] == '\0')
	{
		free_map_file(map_file);
		exit_error("Map doesn't has a player");
	}
	map_file->player_direction = matrix[y][x];
	map_file->player_x = x;
	map_file->player_y = y;
}

static int	is_player_inside_map(char **matrix, int player_y, int player_x)
{
	int	row;
	int	col;

	row = player_y - 1;
	while (row >= 0 && matrix[row][player_x] != '1')
		row--;
	if (row < 0 || matrix[row][player_x] != '1')
		return (0);
	row = player_y + 1;
	while (matrix[row] && matrix[row][player_x] != '1')
		row++;
	if (matrix[row] == NULL || matrix[row][player_x] != '1')
		return (0);
	col = player_x - 1;
	while (col >= 0 && matrix[player_y][col] != '1')
		col--;
	if (col < 0 || matrix[player_y][col] != '1')
		return (0);
	col = player_x + 1;
	while (matrix[player_y][col] && matrix[player_y][col] != '1')
		col++;
	if (matrix[player_y][col] == '\0' || matrix[player_y][col] != '1')
		return (0);
	return (1);
}
