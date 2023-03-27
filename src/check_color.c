/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 06:54:35 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/27 07:22:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	join_colors(char **tex);
static int	is_valid_rgb(char *rgb);

void	check_color(t_map_file *map_file, char **tex)
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
	if (count_char(rgb, ',') != 2)
		return (0);
	i = 0;
	while (rgb[i] && (ft_isdigit(rgb[i]) || rgb[i] == ','))
		i++;
	return (rgb[i] == '\0');
}
