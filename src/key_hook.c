/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:10:39 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 20:52:26 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	key_pressed(int key_code, t_data *data);
static int	key_released(int key_code, t_data *data);

void	key_hook(t_data *data)
{
	mlx_hook(data->window, 2, 1, &key_pressed, data);
	mlx_hook(data->window, 3, 10, &key_released, data);
	mlx_hook(data->window, 17, 0L, &free_data, data);
}

static int	key_pressed(int key_code, t_data *data)
{
	if (key_code == EXIT)
		free_data(data);
	if (key_code == RIGHT)
		data->player.turn_direction = +1;
	if (key_code == LEFT)
		data->player.turn_direction = -1;
	if (key_code == UP)
		data->player.walk_direction = +1;
	if (key_code == DOWN)
		data->player.walk_direction = -1;
	return (0);
}

static int	key_released(int key_code, t_data *data)
{
	if (key_code == RIGHT)
		data->player.turn_direction = 0;
	if (key_code == LEFT)
		data->player.turn_direction = 0;
	if (key_code == UP)
		data->player.walk_direction = 0;
	if (key_code == DOWN)
		data->player.walk_direction = 0;
	return (0);
}
