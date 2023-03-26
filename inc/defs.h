/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:59:24 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 09:37:53 by edpaulin         ###   ########.fr       */
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

# define EXIT 65307
# define LOOK_LEFT  65361
# define LOOK_RIGHT 65363
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define TITLE "cub3D"

# define NUM_RAYS (WINDOW_WIDTH)

# define TILE_SIZE 64

# define PI 3.14159265
# define TWO_PI 6.28318530

# define ONE_RADIAN 0.0174533

# define FOV_ANGLE_DEGREE 60

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

typedef struct s_ray
{
	float	angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vertical;
	int		texture;
}	t_ray;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction;
	int		walk_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}	t_player;

typedef struct s_img
{
	void	*buffer;
	char	*addr;
	int		bpp;
	int		size_line;	
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	char		**grid;
	int			width;
	int			height;
	t_img		*canvas;
	t_img		*north;
	t_img		*south;
	t_img		*east;
	t_img		*west;
	t_player	player;
	t_ray		rays[NUM_RAYS];
	int			ceil_color;
	int			floor_color;
	float		fov_angle;
	float		dist_proj_plane;
}	t_data;

#endif
