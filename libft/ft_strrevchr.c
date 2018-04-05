/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:04:01 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/02/22 12:21:29 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_strrevchr(char *s, int c)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	if (!s || !*s)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * ((ft_strlen(s) + 1)))))
		return (NULL);
	ft_bzero(str, ft_strlen(s));
	while (s[i] != '\0' && s[i] != (char)c)
	{
		str[i] = s[i];
		i++;
	}
	str[i + 1] = '\0';
	return (str);
}
