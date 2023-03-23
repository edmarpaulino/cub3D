/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:59:30 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/23 07:15:16 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>

# include "../libft/includes/libft.h"
# include "./defs.h"
# include "./queue.h"

void		exit_error(char *err);
t_map_file	*get_map_file(char *filename);
void		free_map_file(t_map_file *map_file);
void		check_file(char *filename);
int			is_file(char *filename);
t_queue		*get_file_content(char *filename);
int			has_content(char *content);
void		check_texture(t_map_file *map_file, char **tex);
void		load_textures(t_map_file *map_file);
int			get_color(char *texture);

#endif
