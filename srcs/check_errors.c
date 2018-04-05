/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:46:00 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/06/07 17:08:03 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	check_data(t_anthill *room)
{
	t_anthill *tmp;

	tmp = room;
	if (tmp == NULL)
	{
		ft_putendl_fd(CL_2"Error : Invalid room", 2);
		exit(EXIT_FAILURE);
	}
	while (tmp != NULL && tmp->start == 0)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		ft_putendl_fd(CL_2"Error : No start room declared", 2);
		exit(EXIT_FAILURE);
	}
	tmp = room;
	while (tmp != NULL && tmp->end == 0)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		ft_putendl_fd(CL_2"Error : No end room declared", 2);
		exit(EXIT_FAILURE);
	}
}

void	error_room(void)
{
	ft_putendl_fd(CL_2"Error : Room's name already used", 2);
	exit(EXIT_FAILURE);
}

void	path_error(void)
{
	ft_putendl_fd(CL_2"Error : No path found", 2);
	exit(EXIT_FAILURE);
}

void	free_split(char **split)
{
	int i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

int		check_tube(char *str, int i, t_anthill *room)
{
	char		**split;
	t_anthill	*tmp;

	tmp = room;
	split = ft_strsplit(str, '-');
	if (split[2] != NULL || split[1] == NULL)
	{
		free_split(split);
		return (0);
	}
	while (tmp != NULL && i < 2)
	{
		if (ft_strcmp(tmp->name, split[i]) == 0)
		{
			free_split(split);
			return (check_tube(str, i + 1, room));
		}
		tmp = tmp->next;
	}
	free_split(split);
	if (i < 2)
		return (0);
	return (2);
}
