/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:11:36 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 20:16:54 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int argc, char *argv[])
{
	t_map_file	*map_file;
	t_data		*data;

	if (argc < 2)
		exit_error("Map file was not informed");
	if (argc > 2)
		exit_error("The program requires only one map file");
	map_file = get_map_file(argv[1]);
	ft_putendl_fd("Welcome to the cub3D", STDOUT);
	setup(&data, map_file);
	key_hook(data);
	mlx_loop(data->mlx);
	free_data(data);
	free_map_file(map_file);
	return (0);
}
