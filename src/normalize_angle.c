/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:37:20 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/25 20:54:52 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	normalize_angle(float *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}
