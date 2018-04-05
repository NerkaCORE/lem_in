/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:59:35 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/06/07 19:07:25 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_room		*create_elem(t_room *path, char *name, int number)
{
	t_room	*tmp;
	t_room	*new;

	new = NULL;
	tmp = path;
	if (path == NULL)
	{
		if (!(path = (t_room*)malloc(sizeof(t_room))))
			exit(EXIT_FAILURE);
		path->name = ft_strdup(name);
		path->ant = 0;
		path->number = number;
		path->next = NULL;
	}
	else
		elem_next(tmp, new, name, number);
	return (path);
}

t_anthill	*search_tmp2(t_anthill *start)
{
	t_tubes		*tmp;
	t_anthill	*tmp2;

	tmp = start->tubes;
	if (tmp == NULL)
		return (NULL);
	tmp2 = start;
	while (tmp != NULL)
	{
		if (tmp->room->number < tmp2->number && tmp->room->number != -1
				&& tmp->room->used == 0)
			tmp2 = tmp->room;
		tmp = tmp->next;
	}
	if (tmp2->used == 1 || tmp2->start == 1)
		return (NULL);
	return (tmp2);
}

void		delete_path(t_room **path)
{
	t_room	*tmp;

	tmp = *path;
	while (*path != NULL)
	{
		free((*path)->name);
		tmp = (*path)->next;
		free(*path);
		*path = tmp;
	}
}

t_paths		*init_new(void)
{
	t_paths	*new;

	if (!(new = (t_paths*)malloc(sizeof(t_paths))))
		exit(EXIT_FAILURE);
	new->room = NULL;
	new->next = NULL;
	return (new);
}
