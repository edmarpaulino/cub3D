/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:51:36 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/26 09:53:15 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	get_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + ((y * img->size_line) + (x * img->bpp / 8));
	return (*(unsigned int *)dst);
}
