/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:04:01 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 19:43:23 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	is_texture(char *content);
static void	add_all_textures(t_map_file *map_file, char *content);
static void	add_texture(t_map_file *map_file, char **tex);
static int	has_all_textures(t_map_file *map_file);

void	load_textures(t_map_file *map_file)
{
	t_queue	*file_content;

	file_content = map_file->file_content;
	while (file_content->len > 0)
	{
		if (has_content(file_content->first->value))
		{
			if (!is_texture(file_content->first->value))
				break ;
			add_all_textures(map_file, file_content->first->value);
		}
		queue_shift(file_content);
	}
	if (!has_all_textures(map_file))
	{
		free_map_file(map_file);
		exit_error("Invalid or missing textures");
	}
}

static int	is_texture(char *content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] == ' ')
		i++;
	return (
		content[i] == 'N'
		|| content[i] == 'S'
		|| content[i] == 'E'
		|| content[i] == 'W'
		|| content[i] == 'C'
		|| content[i] == 'F'
	);
}

static void	add_all_textures(t_map_file *map_file, char *content)
{
	char	**tex;

	tex = ft_split(content, ' ');
	if (!tex)
	{
		free_map_file(map_file);
		exit_error("Failed to split content");
	}
	if (ft_split_len(tex) != 2)
	{
		free_map_file(map_file);
		ft_clear_split(tex);
		exit_error("Invalid texture assign");
	}
	check_texture(map_file, tex);
	add_texture(map_file, tex);
	ft_clear_split(tex);
}

static void	add_texture(t_map_file *map_file, char **tex)
{
	if (!map_file->texture_no && ft_strcmp(tex[0], "NO") == 0)
		map_file->texture_no = ft_strdup(tex[1]);
	else if (!map_file->texture_so && ft_strcmp(tex[0], "SO") == 0)
		map_file->texture_so = ft_strdup(tex[1]);
	else if (!map_file->texture_ea && ft_strcmp(tex[0], "EA") == 0)
		map_file->texture_ea = ft_strdup(tex[1]);
	else if (!map_file->texture_we && ft_strcmp(tex[0], "WE") == 0)
		map_file->texture_we = ft_strdup(tex[1]);
	else if (map_file->ceil_color == -1 && ft_strcmp(tex[0], "C") == 0)
		map_file->ceil_color = get_color(tex[1]);
	else if (map_file->floor_color == -1 && ft_strcmp(tex[0], "F") == 0)
		map_file->floor_color = get_color(tex[1]);
	else
	{
		ft_clear_split(tex);
		free_map_file(map_file);
		exit_error("Invalid texture");
	}
}

static int	has_all_textures(t_map_file *map_file)
{
	return (
		map_file->texture_no
		&& map_file->texture_so
		&& map_file->texture_ea
		&& map_file->texture_we
		&& map_file->ceil_color != -1
		&& map_file->floor_color != -1
	);
}
