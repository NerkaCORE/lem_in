/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:33:45 by unli-yaw          #+#    #+#             */
/*   Updated: 2016/11/30 18:42:51 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *atm;

	atm = (char *)s + ft_strlen(s);
	while (*atm != (unsigned char)c)
	{
		if (atm == s)
			return (NULL);
		atm--;
	}
	return (atm);
}
