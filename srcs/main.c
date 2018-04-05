/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:00:13 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/06/08 13:02:58 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	valid_ant_count(char **input)
{
	char	*str;
	int		i;

	i = 0;
	if (get_next_line(0, &str) == -1)
	{
		ft_putendl_fd(CL_2"Error : Reading has failed.", 2);
		exit(EXIT_FAILURE);
	}
	if (str[0] == '\0')
	{
		ft_putendl_fd(CL_2"Error : Not enough data.", 2);
		exit(EXIT_FAILURE);
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			ft_putendl_fd(CL_2"Error : Invalid ants number.", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	*input = ft_strjoin_free(*input, str, 2);
	return (ft_atoi(str));
}

static int	special_case(t_anthill *room)
{
	t_anthill	*tmp;

	tmp = room;
	while (tmp != NULL)
	{
		if (tmp->start == 1 && tmp->end == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		check_ants(int ants)
{
	if (ants < 0)
	{
		ft_putendl_fd(CL_2"Error : Invalid ants number.", 2);
		exit(1);
	}
}

int			main(int ac, char **av)
{
	t_anthill	*room;
	int			ants;
	char		*input;
	t_paths		*paths;

	room = NULL;
	paths = NULL;
	check_help(ac, av);
	input = ft_strdup("");
	ants = valid_ant_count(&input);
	check_ants(ants);
	room = get_room(&input, room, 0, 0);
	check_data(room);
	if (special_case(room) == 1 || ants == 0)
	{
		ft_putendl(input);
		exit(EXIT_SUCCESS);
	}
	solve(room, &paths);
	ft_putendl(input);
	ft_putchar('\n');
	check_bonus(room, paths, av);
	move_ants(paths, ants, av);
	exit(EXIT_SUCCESS);
}
