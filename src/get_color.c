/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 07:08:02 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/23 07:31:59 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	rgb2int(int r, int g, int b);

int	get_color(char *texture)
{
	size_t	len;
	int		color;
	char	**rgb;

	if (!texture)
		return (-1);
	rgb = ft_split(texture, ',');
	if (!rgb)
		return (-1);
	len = ft_split_len(rgb);
	if (len != 3)
	{
		ft_clear_split(rgb);
		return (-1);
	}
	color = rgb2int(
			ft_atoi(rgb[0]),
			ft_atoi(rgb[1]),
			ft_atoi(rgb[2])
			);
	ft_clear_split(rgb);
	return (color);
}

static int	rgb2int(int r, int g, int b)
{
	int	color;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	color = r;
	color = (color << 8) | g;
	color = (color << 8) | b;
	return (color);
}
