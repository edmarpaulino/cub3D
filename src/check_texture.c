/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:36:06 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/27 07:17:41 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	is_valid_texture_file(char *filename);
static int	is_xpm_file(char *filename);

void	check_texture(t_map_file *map_file, char **tex)
{
	if (ft_split_len(tex) != 2)
	{
		ft_clear_split(tex);
		free_map_file(map_file);
		exit_error("Invalid texture assignment");
	}
	if (!is_valid_texture_file(tex[1]))
	{
		ft_clear_split(tex);
		free_map_file(map_file);
		exit_error("Invalid texture file");
	}
}

static int	is_valid_texture_file(char *filename)
{
	char	*file_filename;

	file_filename = ft_strrchr(filename, '/');
	if (!file_filename)
		file_filename = filename;
	else
		file_filename++;
	return (
		ft_strlen(file_filename) >= 5
		&& is_xpm_file(filename)
		&& is_file(filename)
	);
}

static int	is_xpm_file(char *filename)
{
	char	*filetype;

	filetype = &filename[ft_strlen(filename) - 4];
	return (ft_strcmp(filetype, TEX_EXT) == 0);
}
