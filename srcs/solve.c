/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:46:00 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/06/07 11:43:24 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static t_anthill	*set_room_number(t_anthill *room, int i, int *change)
{
	t_tubes	*tmp;

	tmp = room->tubes;
	while (tmp != NULL)
	{
		if (tmp->room->number == -1)
		{
			tmp->room->number = i;
			*change = 1;
		}
		tmp = tmp->next;
	}
	return (room);
}

static t_anthill	*found_path(t_anthill *begin_list, int i, int *change)
{
	t_anthill	*tmp;

	tmp = begin_list;
	while (tmp != NULL)
	{
		if (tmp->number == i && tmp->start == 0)
			tmp = set_room_number(tmp, i + 1, change);
		tmp = tmp->next;
	}
	return (begin_list);
}

static void			found_shorter_path(t_anthill *room, t_room **path)
{
	t_tubes		*tmp;
	t_anthill	*tmp2;

	tmp = room->tubes;
	tmp2 = room;
	*path = create_elem(*path, tmp2->name, tmp2->number);
	tmp2->used = 1;
	if (tmp2->end == 1 || tmp2->number > room->number)
		return ;
	while (tmp != NULL)
	{
		if ((tmp->room->number <= tmp2->number && tmp->room->number != -1
				&& tmp->room->used == 0) || tmp->room->end == 1)
			tmp2 = tmp->room;
		tmp = tmp->next;
	}
	if (tmp2->used == 1)
	{
		if (tmp2->end == 1)
			*path = create_elem(*path, tmp2->name, tmp2->number);
		else
			delete_path(path);
		return ;
	}
	found_shorter_path(tmp2, path);
}

static void			create_paths(t_anthill *room, t_paths **paths)
{
	t_anthill	*tmp2;
	t_paths		*tmp;
	t_paths		*new;

	if ((tmp2 = search_tmp2(room)) == NULL)
		return ;
	tmp = *paths;
	if (*paths == NULL)
	{
		if (!((*paths) = (t_paths*)malloc(sizeof(t_paths))))
			exit(EXIT_FAILURE);
		(*paths)->room = NULL;
		(*paths)->next = NULL;
		found_shorter_path(tmp2, &((*paths)->room));
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		new = init_new();
		found_shorter_path(tmp2, &(new->room));
		if (new->room)
			tmp->next = new;
	}
	create_paths(room, paths);
}

void				solve(t_anthill *room, t_paths **paths)
{
	t_anthill	*tmp;
	int			i;
	int			change;

	i = 0;
	change = 1;
	tmp = room;
	while (tmp->end != 1)
		tmp = tmp->next;
	tmp->number = 0;
	while (change == 1)
	{
		change = 0;
		found_path(room, i, &change);
		i++;
	}
	tmp = room;
	while (tmp->start != 1)
		tmp = tmp->next;
	tmp->number = 2147483647;
	create_paths(tmp, paths);
	if (*paths == NULL)
		path_error();
}
