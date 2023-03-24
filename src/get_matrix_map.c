/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:58:10 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/23 20:27:58 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include <stddef.h>
#include <stdlib.h>

static int		make_lines_same_len(t_queue *file_content);
static size_t	get_longest_line_len(t_queue *file_content);
static char		*get_padded_line(char *line, size_t size);

char	**get_matrix_map(t_queue *file_content)
{
	char	**matrix;
	char	*value;

	if (!file_content || file_content->len == 0)
		return (NULL);
	if (make_lines_same_len(file_content) != 0)
		return (NULL);
	matrix = (char **)malloc((file_content->len + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	matrix[file_content->len] = NULL;
	while (file_content->len > 0)
	{
		value = file_content->last->value;
		file_content->last->value = NULL;
		matrix[file_content->len - 1] = value;
		queue_pop(file_content);
	}
	return (matrix);
}

static int	make_lines_same_len(t_queue *file_content)
{
	t_queue_item	*tmp;
	char			*value;
	size_t			longest_line_len;

	longest_line_len = get_longest_line_len(file_content);
	tmp = file_content->first;
	while (tmp)
	{
		value = get_padded_line(tmp->value, longest_line_len);
		if (!value)
			return (-1);
		free(tmp->value);
		tmp->value = value;
		tmp = tmp->next;
	}
	return (0);
}

static size_t	get_longest_line_len(t_queue *file_content)
{
	t_queue_item	*tmp;
	size_t			len;
	size_t			longest_len;

	tmp = file_content->first;
	longest_len = 0;
	while (tmp)
	{
		len = ft_strlen(tmp->value);
		if (len > longest_len)
			longest_len = len;
		tmp = tmp->next;
	}
	return (longest_len);
}

static char	*get_padded_line(char *line, size_t size)
{
	char	*padded_line;
	size_t	len;
	size_t	i;

	len = ft_strlen(line);
	if (len == size)
		return (ft_strdup(line));
	padded_line = (char *)malloc((size + 1) * sizeof(char));
	if (!padded_line)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (i < len)
			padded_line[i] = line[i];
		else
			padded_line[i] = ' ';
		i++;
	}
	padded_line[i] = '\0';
	return (padded_line);
}
