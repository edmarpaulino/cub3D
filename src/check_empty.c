/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:00 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/23 21:17:12 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	has_empty_rows(char **matrix);
static int	has_empty_columns(char **matrix);

void	check_empty(t_map_file *map_file)
{
	char	*err_msg;
	int		empty_rows;
	int		empty_columns;

	err_msg = NULL;
	empty_rows = has_empty_rows(map_file->matrix);
	empty_columns = has_empty_columns(map_file->matrix);
	if (empty_rows && empty_columns)
		err_msg = "Has empty rows and columns in map";
	else if (empty_rows)
		err_msg = "Has empty rows in map";
	else if (empty_columns)
		err_msg = "Has empty columns in map";
	if (err_msg)
	{
		free_map_file(map_file);
		exit_error(err_msg);
	}
}

static int	has_empty_rows(char **matrix)
{
	int	row;
	int	empty_rows;

	row = 0;
	empty_rows = 0;
	while (matrix[row])
	{
		if (!has_content(matrix[row]))
			empty_rows++;
		row++;
	}
	return (empty_rows > 0);
}

static int	has_empty_columns(char **matrix)
{
	int	row;
	int	col;
	int	empty;
	int	empty_columns;

	col = 0;
	row = 0;
	empty = 1;
	empty_columns = 0;
	while (matrix[row])
	{
		if (matrix[row][col] != ' ')
			empty = 0;
		row++;
		if (!matrix[row])
		{
			empty_columns += empty;
			col++;
			row = 0;
			empty = 1;
			if (!matrix[row][col])
				break ;
		}
	}
	return (empty_columns > 0);
}
