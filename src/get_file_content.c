/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:42:17 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/22 20:43:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	remove_newline(char *line);

t_queue	*get_file_content(char *filename)
{
	int		fd;
	t_queue	*file_content;
	char	*line;

	file_content = queue_create();
	if (!file_content)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		queue_destroy(file_content);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line)
	{
		remove_newline(line);
		queue_push(file_content, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (file_content);
}

static void	remove_newline(char *line)
{
	char	*nl;

	nl = ft_strrchr(line, '\n');
	if (nl)
		*nl = '\0';
}
