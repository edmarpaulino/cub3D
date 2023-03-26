/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:36:06 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 20:26:03 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	is_valid_texture_file(char *filename);
static int	is_xpm_file(char *filename);
static void	join_colors(char **tex);
static int	is_valid_rgb(char *rgb);

void	check_texture(t_map_file *map_file, char **tex)
{
	if (ft_strcmp(tex[0], "NO") == 0 || ft_strcmp(tex[0], "SO") == 0
		|| ft_strcmp(tex[0], "EA") == 0 || ft_strcmp(tex[0], "WE") == 0)
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
	else if (ft_strcmp(tex[0], "C") == 0 || ft_strcmp(tex[0], "F") == 0)
	{
		if (ft_split_len(tex) < 2)
		{
			ft_clear_split(tex);
			free_map_file(map_file);
			exit_error("Invalid texture assignment");
		}
		join_colors(tex);
		if (!is_valid_rgb(tex[1]))
		{
			ft_clear_split(tex);
			free_map_file(map_file);
			exit_error("Invalid rgb");
		}
	}
	else
	{
		ft_clear_split(tex);
		free_map_file(map_file);
		exit_error("Invalid texture definition");
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

static void	join_colors(char **tex)
{
	char	*tmp;
	char	*color;
	int		i;

	if (ft_split_len(tex) == 2)
		return ;
	i = 1;
	tmp = ft_strdup("");
	while (tex[i])
	{
		color = ft_strjoin(tmp, tex[i]);
		free(tex[i]);
		tex[i] = NULL;
		free(tmp);
		tmp = color;
		i++;
	}
	tex[1] = color;
}

static int	is_valid_rgb(char *rgb)
{
	int		i;
	size_t	len;

	len = ft_strlen(rgb);
	if (len < 5 || len > 11)
		return (0);
	i = 0;
	while (rgb[i] && (ft_isdigit(rgb[i]) || rgb[i] == ','))
		i++;
	return (rgb[i] == '\0');
}
