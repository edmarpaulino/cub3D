/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:59:24 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 18:53:19 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

// prototype
// player_angle = N: 1.5PI - S: .5PI - E: 0 - W: PI
// player_x = ((x_in_grid - 1) * TILE_SIZE) + (TILE_SIZE / 2)
//player_y = ((y_in_grid - 1) * TILE_SIZE) + (TILE_SIZE / 2)

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define MAP_EXT ".cub"
# define TEX_EXT ".xpm"

# define MAP_SET "01NSEW "
# define PLAYER_SET "NSEW"

# include "./queue.h"

typedef struct s_coor
{
	int	y;
	int	x;
}	t_coor;

typedef struct s_map_file
{
	char	**matrix;
	int		width;
	int		height;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	int		ceil_color;
	int		floor_color;
	char	player_direction;
	int		player_x;
	int		player_y;
	t_queue	*file_content;
}	t_map_file;

#endif
