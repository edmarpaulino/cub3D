/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:59:30 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/20 20:38:00 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>

# include "../libft/includes/libft.h"
# include "./defs.h"

void		exit_error(char *err);
t_map_file	*get_map_file(char *filename);
void		free_map_file(t_map_file *map_file);

#endif
