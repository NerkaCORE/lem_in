/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:00:13 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/06/07 18:56:35 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int			check_room(char *str, int i)
{
	if (str[0] == 'L')
		return (0);
	while (str[i] != ' ')
	{
		if (str[i++] == '\0')
			return (0);
	}
	i++;
	if (str[i] == '-')
		i++;
	while (str[i] != ' ')
	{
		if (!(str[i] >= '0' && str[i] <= '9') || str[i] == '\0')
			return (0);
		i++;
	}
	i++;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i++] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

static int			check_line(char *str, t_anthill *room)
{
	static int	flag = 1;

	if (flag == 1)
	{
		if (check_room(str, 0) == 0)
		{
			flag = 2;
			return (check_line(str, room));
		}
		else
			return (1);
	}
	return (check_tube(str, 0, room));
}

static t_anthill	*create_room(t_anthill *room, char *str, int start, int end)
{
	t_anthill	*new;
	t_anthill	*tmp;
	char		**split;

	tmp = room;
	split = ft_strsplit(str, ' ');
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, split[0]) == 0)
			error_room();
		tmp = tmp->next;
	}
	if (!(new = (t_anthill*)malloc(sizeof(t_anthill))))
		exit(EXIT_FAILURE);
	new = init_n(new, split, start, end);
	new->next = room;
	room = new;
	free_split(split);
	return (room);
}

static t_anthill	*create_tube(t_anthill *room, char *str)
{
	char		**split;
	t_tubes		*new[2];
	t_anthill	*tmp;
	t_anthill	*tmp2;

	tmp = room;
	tmp2 = room;
	split = ft_strsplit(str, '-');
	while (ft_strcmp(tmp->name, split[0]) != 0)
		tmp = tmp->next;
	while (ft_strcmp(tmp2->name, split[1]) != 0)
		tmp2 = tmp2->next;
	if (!(new[0] = (t_tubes*)malloc(sizeof(t_tubes))))
		exit(EXIT_FAILURE);
	new[0]->room = tmp;
	new[0]->next = tmp2->tubes;
	tmp2->tubes = new[0];
	if (!(new[1] = (t_tubes*)malloc(sizeof(t_tubes))))
		exit(EXIT_FAILURE);
	new[1]->room = tmp2;
	new[1]->next = tmp->tubes;
	tmp->tubes = new[1];
	free_split(split);
	return (room);
}

t_anthill			*get_room(char **input, t_anthill *room, int start, int end)
{
	char	*str;

	if (get_next_line(0, &str) == 0 || str[0] == '\0')
	{
		free(str);
		return (room);
	}
	if (ft_strcmp(str, "##start") == 0)
		start = 1;
	else if (ft_strcmp(str, "##end") == 0)
		end = 1;
	else if (str[0] != '#')
	{
		if (check_line(str, room) == 0)
			return (room);
		else if (check_line(str, room) == 1)
			room = create_room(room, str, start, end);
		else
			room = create_tube(room, str);
		start = 0;
		end = 0;
	}
	*input = ft_strjoin_free(*input, "\n", 1);
	*input = ft_strjoin_free(*input, str, 2);
	return (get_room(input, room, start, end));
}
