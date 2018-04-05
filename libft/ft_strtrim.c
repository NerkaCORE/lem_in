/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:10:13 by unli-yaw          #+#    #+#             */
/*   Updated: 2016/11/30 20:30:35 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

static int		is_none(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

char			*ft_strtrim(const char *s)
{
	char			*str;
	size_t			len;
	unsigned int	j;

	j = 0;
	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(s));
	while (is_none(s[j]))
		j++;
	len = ft_strlen(s) - 1;
	while (len > j && is_none(s[len]))
		len--;
	if (len < j)
		return (ft_strdup(""));
	return ((str = ft_strsub(s, j, len - (size_t)j + 1)));
}
