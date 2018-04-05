/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:43:48 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/02/22 12:23:28 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_add_char(char *str, char c, t_var *var)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	tmp[0] = c;
	tmp[1] = '\0';
	if (var->width)
		tmp = ft_space(tmp, var);
	if (str)
		str = ft_strjoin_free(str, tmp, 1);
	else
		return (tmp);
	ft_memdel((void **)&tmp);
	return (str);
}

int			cc(t_var *var, char c)
{
	if (var->form[var->i] == c)
		return (1);
	return (0);
}

char		*to_ubase(uintmax_t n, int b)
{
	char		*s;
	char		hex[128];
	uintmax_t	t;
	int			i;

	i = 0;
	if (!(s = malloc(sizeof(char) * 128)))
		return (NULL);
	ft_memset(s, 0, 128);
	ft_memset(hex, 0, 128);
	while (n)
	{
		t = n % b;
		if (t < 10)
			hex[i] = t + '0';
		else
			hex[i] = t + 'a' - 10;
		i++;
		n = n / b;
	}
	t = 0;
	while (i)
		s[t++] = hex[--i];
	return (s);
}

char		*to_ubaseup(uintmax_t n, int b)
{
	char		*s;
	char		hex[128];
	uintmax_t	t;
	int			i;

	i = 0;
	if (!(s = malloc(sizeof(char) * 128)))
		return (NULL);
	ft_memset(s, 0, 128);
	ft_memset(hex, 0, 128);
	while (n)
	{
		t = n % b;
		if (t < 10)
			hex[i] = t + '0';
		else
			hex[i] = t + 'A' - 10;
		i++;
		n = n / b;
	}
	t = 0;
	while (i)
		s[t++] = hex[--i];
	return (s);
}
