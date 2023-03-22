/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:04:36 by edpaulin          #+#    #+#             */
/*   Updated: 2023/03/22 20:37:14 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/queue.h"

t_queue	*queue_create(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	queue->len = 0;
	return (queue);
}

void	queue_destroy(t_queue *queue)
{
	if (!queue)
		return ;
	while (queue->len > 0)
		queue_pop(queue);
	free(queue);
}

void	queue_push(t_queue *queue, char *value)
{
	t_queue_item	*new_item;

	if (!queue || !value)
		return ;
	new_item = (t_queue_item *)malloc(sizeof(t_queue_item));
	if (!new_item)
		return ;
	new_item->value = value;
	new_item->next = NULL;
	if (queue->len > 0)
	{
		new_item->prev = queue->last;
		queue->last->next = new_item;
		queue->last = new_item;
	}
	else
	{
		new_item->prev = NULL;
		queue->first = new_item;
		queue->last = new_item;
	}
	queue->len++;
}

void	queue_pop(t_queue *queue)
{
	t_queue_item	*tmp;

	if (!queue || queue->len == 0)
		return ;
	tmp = queue->last;
	if (queue->len == 1)
	{
		queue->last = NULL;
		queue->first = NULL;
	}
	else
	{
		queue->last = tmp->prev;
		queue->last->next = NULL;
	}
	queue->len--;
	if (tmp->value)
		free(tmp->value);
	free(tmp);
}

void	queue_shift(t_queue *queue)
{
	t_queue_item	*tmp;

	if (!queue || queue->len == 0)
		return ;
	tmp = queue->first;
	if (queue->len == 1)
	{
		queue->first = NULL;
		queue->last = NULL;
	}
	else
	{
		queue->first = tmp->next;
		queue->first->prev = NULL;
	}
	queue->len--;
	if (tmp->value)
		free(tmp->value);
	free(tmp);
}
