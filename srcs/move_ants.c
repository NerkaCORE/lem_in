/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:59:04 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/06/07 18:12:59 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void	make_start(t_room **room)
{
	t_room *new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		exit(EXIT_FAILURE);
	if (!(new->name = ft_strdup("start")))
		exit(EXIT_FAILURE);
	new->ant = 0;
	new->next = *room;
	*room = new;
}

static void	move_ants4(t_paths *paths, int ants_nbr, char **av)
{
	int		i;
	t_ants	*ants;
	t_paths *tmp;

	if (!(ants = (t_ants*)malloc(sizeof(t_ants) * ants_nbr)))
		exit(EXIT_FAILURE);
	tmp = paths;
	i = -1;
	while (++i < ants_nbr)
	{
		ants[i].name = i + 1;
		while (tmp->room->ant <= 0)
			if (tmp->next == NULL)
				tmp = paths;
			else
				tmp = tmp->next;
		ants[i].room = tmp->room;
		tmp->room->ant -= 1;
		if (tmp->next == NULL)
			tmp = paths;
		else
			tmp = tmp->next;
	}
	check_details(ants, ants_nbr, av);
}

static void	move_ants3(t_paths *paths, int i, int ants, char **av)
{
	t_paths *tmp;

	tmp = paths;
	while (i > 0)
	{
		if (tmp->room->ant - 1 >= 0)
		{
			tmp->room->ant -= 1;
			i--;
		}
		if (tmp->next == NULL)
			tmp = paths;
		else
			tmp = tmp->next;
	}
	tmp = paths;
	move_ants4(paths, ants, av);
}

static void	move_ants2(t_paths *paths, int paths_nbr, int ants, char **av)
{
	static int	i = 0;
	t_paths		*tmp;

	tmp = paths;
	if (paths_nbr > 1)
	{
		while (tmp->next != NULL)
		{
			while ((tmp->room->ant - tmp->next->room->ant)
				< (tmp->next->room->next->number - tmp->room->next->number))
			{
				tmp->room->ant += 1;
				i++;
			}
			tmp = tmp->next;
		}
		tmp = paths;
		if ((tmp->room->ant - tmp->next->room->ant)
			< (tmp->next->room->next->number - tmp->room->next->number))
			return (move_ants2(paths, paths_nbr, ants, av));
	}
	move_ants3(paths, i, ants, av);
}

void		move_ants(t_paths *paths, int ants, char **av)
{
	t_paths	*tmp;
	int		paths_nbr;
	int		i;

	paths_nbr = 0;
	tmp = paths;
	while (tmp != NULL)
	{
		paths_nbr++;
		tmp = tmp->next;
	}
	tmp = paths;
	i = ants % paths_nbr;
	while (tmp != NULL)
	{
		make_start(&(tmp->room));
		tmp->room->ant = ants / paths_nbr;
		if (i > 0)
		{
			tmp->room->ant += 1;
			i--;
		}
		tmp = tmp->next;
	}
	move_ants2(paths, paths_nbr, ants, av);
}
