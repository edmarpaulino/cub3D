/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:36:12 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/23 20:33:02 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	free_map_file(t_map_file *map_file)
{
	if (map_file == NULL)
		return ;
	if (map_file->matrix)
		ft_clear_split(map_file->matrix);
	if (map_file->texture_no)
		free(map_file->texture_no);
	if (map_file->texture_so)
		free(map_file->texture_so);
	if (map_file->texture_ea)
		free(map_file->texture_ea);
	if (map_file->texture_we)
		free(map_file->texture_we);
	if (map_file->file_content)
		queue_destroy(map_file->file_content);
	free(map_file);
}
