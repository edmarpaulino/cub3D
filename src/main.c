/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:11:36 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/20 19:58:28 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
		exit_error("Map file was not informed");
	if (argc > 2)
		exit_error("The program requires only one map file");
	if (argv)
		ft_putendl_fd("Welcome to the cub3D", STDOUT);
	return (0);
}
