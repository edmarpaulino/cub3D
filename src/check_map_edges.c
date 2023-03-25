/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_edges.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 08:41:42 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 12:05:56 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	set_start_point(t_map_file *map_file, t_coor *start);
static int	is_closed(
				t_map_file *map_file,
				const t_coor start,
				t_coor last,
				t_coor current
				);
static void	set_cardinals(t_coor cardinals[4], t_coor pos);
static int	is_edge(t_map_file *map_file, t_coor last, t_coor pos);

void	check_map_edges(t_map_file *map_file)
{
	t_coor	start;

	set_start_point(map_file, &start);
	if (!is_closed(map_file, start, start, start))
	{
		free_map_file(map_file);
		exit_error("Map edges aren't closed");
	}
}

static void	set_start_point(t_map_file *map_file, t_coor *start)
{
	char	**matrix;

	matrix = map_file->matrix;
	start->y = 0;
	while (matrix[start->y])
	{
		start->x = 0;
		while (matrix[start->y][start->x])
		{
			if (matrix[start->y][start->x] == '1'
				&& start->y < map_file->height
				&& start->x < map_file->width
				&& matrix[start->y + 1][start->x] == '1'
				&& matrix[start->y][start->x + 1] == '1')
				return ;
			start->x++;
		}
		start->y++;
	}
	free_map_file(map_file);
	exit_error("Map doesn't has walls");
}

static int	is_closed(
	t_map_file *map_file,
	const t_coor start,
	t_coor last,
	t_coor current
)
{
	t_coor	cardinals[4];
	int		i;

	if (map_file->matrix[current.y][current.x] == '#')
		return (current.y == start.y && current.x == start.x);
	map_file->matrix[current.y][current.x] = '#';
	set_cardinals(cardinals, current);
	i = 0;
	while (i < 4)
	{
		if (is_edge(map_file, last, cardinals[i])
			&& is_closed(map_file, start, current, cardinals[i]))
			return (1);
		i++;
	}
	map_file->matrix[current.y][current.x] = '1';
	return (0);
}

static void	set_cardinals(t_coor cardinals[4], t_coor pos)
{
	cardinals[0].y = pos.y - 1;
	cardinals[0].x = pos.x;
	cardinals[1].y = pos.y;
	cardinals[1].x = pos.x - 1;
	cardinals[2].y = pos.y + 1;
	cardinals[2].x = pos.x;
	cardinals[3].y = pos.y;
	cardinals[3].x = pos.x + 1;
}

static int	is_edge(t_map_file *map_file, t_coor last, t_coor pos)
{
	if (pos.y < 0 || pos.y >= map_file->height
		|| pos.x < 0 || pos.x >= map_file->width
		|| (last.y == pos.y && last.x == pos.x))
		return (0);
	return (\
		(\
			pos.y - 1 == -1 \
			|| pos.x - 1 == -1 \
			|| map_file->matrix[pos.y + 1] == NULL \
			|| map_file->matrix[pos.y][pos.x + 1] == '\0' \
			|| map_file->matrix[pos.y - 1][pos.x] == ' ' \
			|| map_file->matrix[pos.y + 1][pos.x] == ' ' \
			|| map_file->matrix[pos.y][pos.x - 1] == ' ' \
			|| map_file->matrix[pos.y][pos.x + 1] == ' ' \
			|| map_file->matrix[pos.y - 1][pos.x - 1] == ' ' \
			|| map_file->matrix[pos.y - 1][pos.x + 1] == ' ' \
			|| map_file->matrix[pos.y + 1][pos.x - 1] == ' ' \
			|| map_file->matrix[pos.y + 1][pos.x + 1] == ' ' \
		) && (\
			map_file->matrix[pos.y][pos.x] == '1' \
			|| map_file->matrix[pos.y][pos.x] == '#' \
		)
	);
}
