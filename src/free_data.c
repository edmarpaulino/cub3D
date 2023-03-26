/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:05:32 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 16:25:20 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	free_textures(t_data *data);

int	free_data(t_data *data)
{
	if (!data)
		return (0);
	if (data->grid)
		ft_clear_split(data->grid);
	if (data->mlx)
	{
		free_textures(data);
		if (data->canvas)
		{
			mlx_destroy_image(data->mlx, data->canvas->buffer);
			free(data->canvas);
		}
		if (data->window)
			mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
	exit(1);
}

static void	free_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_TEX)
	{
		if (data->textures[i])
		{
			mlx_destroy_image(data->mlx, data->textures[i]->buffer);
			free(data->textures[i]);
		}
		i++;
	}
}
