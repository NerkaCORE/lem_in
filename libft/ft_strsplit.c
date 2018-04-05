/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:14:08 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/06/07 17:07:25 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int				ft_countword(const char *str, char c)
{
	size_t	i;
	int		w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (i < ft_strlen(str))
			w++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (w);
}

static	char	*ft_countstr(const char *s, char c, int g, int *n)
{
	char	*str;
	int		t;
	int		i;

	i = 0;
	while (s[*n] == c)
		++*n;
	t = *n;
	while (s[*n] != c && s[*n] != '\0')
	{
		++*n;
		g++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (g + 1))))
		return (NULL);
	str[g] = '\0';
	while (i < g)
	{
		str[i] = s[t + i];
		i++;
	}
	return (str);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		z;
	char	**tab;

	z = 0;
	i = 0;
	if (!(tab = ((char **)malloc(sizeof(char *) *
						(ft_countword(s, c) + 1)))))
		return (NULL);
	while (i < ft_countword(s, c))
	{
		tab[i] = ft_countstr(s, c, 0, &z);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
