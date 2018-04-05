/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:43:27 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/02/22 12:13:43 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_spe_mod(t_var *var)
{
	char	*tmp;

	if (var->width)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * 2)))
			return (0);
		tmp[0] = '%';
		tmp[1] = '\0';
		tmp = ft_space(tmp, var);
		var->str = ft_strjoin_free(var->str, tmp, 2);
		return (1);
	}
	else if ((var->str = ft_strjoin_free(var->str, "%", 1)))
		return (1);
	return (0);
}

int		ft_spe_char(t_var *var)
{
	char		c;

	if (var->flag & FLAG_L)
	{
		ft_spe_wchar(var);
		return (1);
	}
	if (var->ind == 0)
		var->index = (int*)malloc(sizeof(int) * 100);
	var->free = 1;
	c = (char)va_arg(var->ap, int);
	if (c == '\0')
	{
		c = '*';
		if (!(var->flag & FLAG_NEG))
			var->index[var->ind] = ft_strlen(var->str) + var->width - 1;
		else
			var->index[var->ind] = ft_strlen(var->str);
		var->ind++;
	}
	var->str = ft_add_char(var->str, c, var);
	return (1);
}

int		ft_spe_str(t_var *var)
{
	char	*tmp;

	if (var->flag & FLAG_L)
	{
		ft_spe_wcstr(var);
		return (1);
	}
	tmp = NULL;
	if (!(tmp = (char *)va_arg(var->ap, void *)))
	{
		var->free1 = 1;
		tmp = ft_strdup("(null)");
	}
	else
		var->free = -1;
	if (var->flag & FLAG_PR)
		tmp = ft_preci_str(tmp, var);
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_strjoin_free(var->str, tmp, 1);
	if (var->free1 == 1)
		ft_memdel((void **)&tmp);
	var->free1 = 0;
	return (1);
}
