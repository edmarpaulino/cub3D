/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:14:12 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 18:50:06 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void		init_map_file(t_map_file *map_file);

static void	print_file_content(t_queue *file_content)
{
	t_queue_item	*content;

	content = file_content->first;
	while (content)
	{
		ft_putendl_fd(content->value, STDOUT);
		content = content->next;
	}
}

static void	print_matrix(char **matrix)
{
	int	row;

	row = 0;
	while (matrix[row])
	{
		ft_putendl_fd(matrix[row], STDOUT);
		row++;
	}
}

static void	print_map_file(t_map_file *map_file)
{
	printf("\n\n");
	print_matrix(map_file->matrix);
	printf("texture_no = %s\n", map_file->texture_no);
	printf("texture_so = %s\n", map_file->texture_so);
	printf("texture_ea = %s\n", map_file->texture_ea);
	printf("texture_we = %s\n", map_file->texture_we);
	printf("ceil_color = %d\n", map_file->ceil_color);
	printf("floor_color = %d\n", map_file->floor_color);
	printf("player_direction = %c\n", map_file->player_direction);
	printf("player_y = %d\n", map_file->player_y);
	printf("player_x = %d\n", map_file->player_x);
	printf("\n\n");
}

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
		exit_error("Cannot get file content");
	load_textures(map_file);
	load_map(map_file);
	print_map_file(map_file);
	print_file_content(map_file->file_content);
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
