/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:39:10 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/23 07:47:53 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	is_cub_file(char *filename);

void	check_file(char *filename)
{
	char	*file_filename;

	file_filename = ft_strrchr(filename, '/');
	if (!file_filename)
		file_filename = filename;
	else
		file_filename++;
	if (ft_strlen(file_filename) < 5)
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

int	is_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
