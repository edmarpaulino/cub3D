/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:14:12 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/20 20:43:58 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	check_file(char *filename);
static int	is_cub_file(char *filename);
static int	is_file(char *filename);

t_map_file	*get_map_file(char *filename)
{
	t_map_file	*map_file;

	check_file(filename);
	map_file = (t_map_file *)malloc(sizeof(t_map_file));
	if (map_file == NULL)
		exit_error("Cannot allocate memory in get_map_file");
	return (map_file);
}

static void	check_file(char *filename)
{
	if (ft_strlen(ft_strrchr(filename, '/') + 1) < 5)
		exit_error("Invalid file");
	if (is_cub_file(filename) != 1)
		exit_error("Invalid file type");
	if (is_file(filename) != 1)
		exit_error("File does not exist");
}

static int	is_cub_file(char *filename)
{
	char	*filetype;

	filetype = &filename[ft_strlen(filename) - 4];
	return (ft_strcmp(filetype, MAP_EXT) == 0);
}

static int	is_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
