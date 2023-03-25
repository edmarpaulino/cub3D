/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_matrix_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:00:06 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 12:04:34 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	replace_matrix_char(char **matrix, char old_c, char new_c)
{
	int	row;
	int	col;

	row = 0;
	while (matrix[row])
	{
		col = 0;
		while (matrix[row][col])
		{
			if (matrix[row][col] == old_c)
				matrix[row][col] = new_c;
			col++;
		}
		row++;
	}
}
