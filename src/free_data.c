/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:05:32 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 10:02:22 by edpaulin         ###   ########.fr       */
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
	if (data->north)
	{
		mlx_destroy_image(data->mlx, data->north->buffer);
		free(data->north);
	}
	if (data->north)
	{
		mlx_destroy_image(data->mlx, data->south->buffer);
		free(data->south);
	}
	if (data->east)
	{
		mlx_destroy_image(data->mlx, data->east->buffer);
		free(data->east);
	}
	if (data->west)
	{
		mlx_destroy_image(data->mlx, data->west->buffer);
		free(data->west);
	}
}
