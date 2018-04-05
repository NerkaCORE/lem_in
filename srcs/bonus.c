/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:58:42 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/06/01 16:58:46 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void	wrong_entry(char *str)
{
	ft_printf(CL_2"Error : Unknown option [%s]\n", str);
	ft_putendl_fd(CL_2"usage : ./lem-in [-hdrp] < [file_name]", 2);
	ft_putendl_fd(CL_2"-h : Help\n-r : Show rooms details", 2);
	ft_putendl_fd(CL_2"-p : Show the possible paths", 2);
	ft_putendl_fd(CL_2"-d : Show details", 2);
	exit(1);
}

void		check_help(int ac, char **av)
{
	int i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] != '-')
			wrong_entry(av[i]);
		j++;
		while (av[i][j])
		{
			if (ft_strchr("hrpd", av[i][j]) == NULL)
				wrong_entry(av[i]);
			if (av[i][j] == 'h')
			{
				ft_putendl("usage : ./lem-in [-hdrp] < [file_name]");
				ft_putendl("-h : Help\n-r : Show rooms details");
				ft_putendl("-p : Show the possible pathsi\n-d : Show details");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static void	print_rooms(t_anthill *rooms)
{
	t_anthill	*tmp;
	t_tubes		*tmp2;

	tmp = rooms;
	while (tmp != NULL)
	{
		tmp2 = tmp->tubes;
		ft_printf(CL_5"Room's name : %s\n", tmp->name);
		ft_printf("Coordinates : [%d;%d]\n", tmp->x, tmp->y);
		ft_putstr("Linked rooms : ");
		while (tmp2 != NULL)
		{
			ft_printf("[%s]", tmp2->room->name);
			tmp2 = tmp2->next;
		}
		ft_putchar('\n');
		if (tmp->start == 1)
			ft_putendl("This is the start room.");
		if (tmp->end == 1)
			ft_putendl("This is the end room."CL_0);
		tmp = tmp->next;
		ft_putstr("\n");
	}
}

static void	print_paths(t_paths *paths)
{
	t_paths	*tmp;
	t_room	*tmp2;
	int		i;

	tmp = paths;
	i = 1;
	while (tmp != NULL)
	{
		tmp2 = tmp->room;
		ft_printf(CL_6"Chemin %d : ", i);
		while (tmp2 != NULL)
		{
			if (tmp2->next == NULL)
				ft_printf(CL_6"[%s]", tmp2->name);
			else
				ft_printf(CL_6"[%s] - ", tmp2->name);
			tmp2 = tmp2->next;
		}
		ft_putchar('\n');
		tmp = tmp->next;
		i++;
	}
	ft_putchar('\n');
}

void		check_bonus(t_anthill *rooms, t_paths *paths, char **av)
{
	int	i;
	int	j;
	int	room_flag;
	int	paths_flag;

	i = 1;
	room_flag = 0;
	paths_flag = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 'r' && room_flag++ == 0)
				print_rooms(rooms);
			else if (av[i][j] == 'p' && paths_flag++ == 0)
				print_paths(paths);
			j++;
		}
		i++;
	}
}
