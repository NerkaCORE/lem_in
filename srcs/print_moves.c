/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:59:14 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/06/07 17:09:04 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void	print_moves(t_ants *ants, int ants_nbr)
{
	int	i;

	i = 0;
	while (i < ants_nbr)
	{
		while (ants[i].room->next == NULL)
		{
			ants[i].room->ant = 0;
			i++;
		}
		if (ants[i].room->next->ant == 0)
		{
			ft_printf(CL_7"L%d-%s ", ants[i].name, ants[i].room->next->name);
			ants[i].room->next->ant = ants[i].name;
			ants[i].room->ant = 0;
			ants[i].room = ants[i].room->next;
		}
		i++;
	}
	ft_putchar('\n');
	if (ants[ants_nbr - 1].room->next == NULL)
		return ;
	return (print_moves(ants, ants_nbr));
}

static void	didnt_move(int i, t_room *room)
{
	if (ft_strcmp("start", room->name) == 0)
		ft_printf(CL_3"Ant %d still waiting in the start room.\n", i + 1);
	if (room->next == NULL)
		ft_printf(CL_3"Ant %d already arrived in the end room.\n", i + 1);
}

static void	move(int i, t_ants ants)
{
	if (ants.room->next->next == NULL)
	{
		ft_printf(CL_3"Ant %d went from room %s to room ", i + 1,
				ants.room->name);
		ft_printf("%s and arrived in the end room.\n", ants.room->next->name);
	}
	else
	{
		ft_printf(CL_3"Ant %d went from room %s to room ", i + 1,
				ants.room->name);
		ft_printf(CL_3"%s.\n"CL_0, ants.room->next->name);
	}
}

static void	print_moves_details(t_ants *ants, int ants_nbr)
{
	int	i;

	i = 0;
	while (i < ants_nbr)
	{
		while (ants[i].room->next == NULL)
		{
			didnt_move(i, ants[i].room);
			ants[i++].room->ant = 0;
		}
		if (ants[i].room->next->ant == 0)
		{
			move(i, ants[i]);
			ants[i].room->next->ant = ants[i].name;
			ants[i].room->ant = 0;
			ants[i].room = ants[i].room->next;
		}
		else
			didnt_move(i, ants[i].room);
		i++;
	}
	ft_putchar('\n');
	if (ants[ants_nbr - 1].room->next == NULL)
		return ;
	return (print_moves_details(ants, ants_nbr));
}

void		check_details(t_ants *ants, int ants_nbr, char **av)
{
	int	i;
	int j;
	int	details_flag;

	i = 0;
	details_flag = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 'd' && details_flag++ == 0)
				print_moves_details(ants, ants_nbr);
			j++;
		}
		i++;
	}
	if (details_flag == 0)
		print_moves(ants, ants_nbr);
	free((void*)ants);
}
