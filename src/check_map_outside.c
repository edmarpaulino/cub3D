/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_outside.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:05:48 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 11:48:22 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	check_top(char **matrix);
static int	check_bottom(char **matrix, int height);
static int	check_left(char **matrix);
static int	check_right(char **matrix, int width);

void	check_map_outside(t_map_file *map_file)
{
	if (!check_top(map_file->matrix)
		|| !check_bottom(map_file->matrix, map_file->height)
		|| !check_left(map_file->matrix)
		|| !check_right(map_file->matrix, map_file->width))
	{
		free_map_file(map_file);
		exit_error("Has content outside the map");
	}
}

static int	check_top(char **matrix)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (matrix[row])
	{
		if (matrix[row][col] != ' ' && matrix[row][col] != '#')
			return (0);
		if (matrix[row][col] == ' ')
			row++;
		if (!matrix[row] || matrix[row][col] == '#')
		{
			col++;
			row = 0;
			if (!matrix[row][col])
				break ;
		}
	}
	return (1);
}

static int	check_bottom(char **matrix, int height)
{
	int	row;
	int	col;

	row = height - 1;
	col = 0;
	while (row >= 0)
	{
		if (matrix[row][col] != ' ' && matrix[row][col] != '#')
			return (0);
		if (matrix[row][col] == ' ')
			row--;
		if (row == 0 || matrix[row][col] == '#')
		{
			col++;
			row = height - 1;
			if (!matrix[row][col])
				break ;
		}
	}
	return (1);
}

static int	check_left(char **matrix)
{
	int	row;
	int	col;

	row = 0;
	while (matrix[row])
	{
		col = 0;
		while (matrix[row][col])
		{
			if (matrix[row][col] != ' ' && matrix[row][col] != '#')
				return (0);
			if (matrix[row][col] == '#')
				break ;
			col++;
		}
		row++;
	}
	return (1);
}

static int	check_right(char **matrix, int width)
{
	int	row;
	int	col;

	row = 0;
	while (matrix[row])
	{
		col = width - 1;
		while (col >= 0)
		{
			if (matrix[row][col] != ' ' && matrix[row][col] != '#')
				return (0);
			if (matrix[row][col] == '#')
				break ;
			col--;
		}
		row++;
	}
	return (1);
}
