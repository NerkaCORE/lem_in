/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:54:07 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/06/07 17:06:11 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"

t_lst		*fd_manager(t_lst **save, int fd)
{
	while (*save && (*save)->fd != fd)
		save = &(*save)->next;
	if (!(*save))
	{
		if (!(*save = malloc(sizeof(**save))))
			return (NULL);
		(*save)->fd = fd;
		(*save)->next = NULL;
		(*save)->reste = NULL;
	}
	return (*save);
}

int			read_tmp(char **line, t_lst *list)
{
	char *tmp;
	char *sub;

	if (!list->reste)
		return (0);
	if ((tmp = ft_strchr(list->reste, '\n')))
	{
		sub = ft_strsub(list->reste, 0, tmp - list->reste);
		*line = ft_strjoin_free(*line, sub, 2);
		ft_strdel(&sub);
		list->reste = ft_strdup(list->reste + (tmp - list->reste) + 1);
		return (*line == NULL ? -1 : 1);
	}
	else
	{
		*line = ft_strjoin_free(*line, list->reste, 1);
		ft_strdel(&(list->reste));
	}
	return (*line == NULL ? -1 : 0);
}

int			read_fd(char **line, t_lst *list)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	char	*tofree;

	while ((ret = read(list->fd, buffer, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buffer[ret] = '\0';
		if ((tmp = ft_strchr(buffer, '\n')))
		{
			tofree = ft_strsub(buffer, 0, tmp - buffer);
			*line = ft_strjoin_free(*line, tofree, 2);
			list->reste = ft_strdup(buffer + (tmp - buffer) + 1);
			return (1);
		}
		else
			*line = ft_strjoin_free(*line, buffer, 1);
	}
	if (!*line)
		return (-1);
	return ((ret == 0 && **line == '\0') ? 0 : 1);
}

int			get_next_line(int fd, char **line)
{
	static t_lst	*save = NULL;
	t_lst			*cur_fd;

	if (fd < 0 || !line)
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	if (!(cur_fd = fd_manager(&save, fd)))
		return (-1);
	if (read_tmp(line, cur_fd))
		return (*line == NULL ? -1 : 1);
	return (read_fd(line, cur_fd));
}
