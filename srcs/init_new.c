/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 18:56:56 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/06/07 19:05:42 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_anthill		*init_n(t_anthill *new, char **split, int start, int end)
{
	if (!(new->name = ft_strdup(split[0])))
		exit(EXIT_FAILURE);
	new->x = ft_atoi(split[1]);
	new->y = ft_atoi(split[2]);
	new->tubes = NULL;
	new->start = start;
	new->end = end;
	new->number = -1;
	new->used = 0;
	return (new);
}

void			elem_next(t_room *tmp, t_room *new, char *name, int number)
{
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (!(new = (t_room*)malloc(sizeof(t_room))))
		exit(EXIT_FAILURE);
	if (!(new->name = ft_strdup(name)))
		exit(EXIT_FAILURE);
	new->ant = 0;
	new->number = number;
	new->next = NULL;
	tmp->next = new;
}
