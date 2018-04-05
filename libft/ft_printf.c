/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:40:44 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/03/07 16:43:51 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_put_end(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	j = var->ind - 1;
	while (var->ind > 0)
	{
		if (var->str[var->index[i]] == '*')
			var->str[var->index[i]] = '\0';
		else if (var->str[var->index[i] + 1] == '*')
			var->str[var->index[i] + 1] = '\0';
		var->ind--;
		i++;
	}
}

void	init_var(t_var *var)
{
	var->neg = 0;
	var->width = 0;
	var->preci = 0;
	var->flag = 0;
	var->arg = 0;
	var->pwc = 0;
	var->ind = 0;
	var->index = 0;
	var->i = 0;
	var->spe = 0;
	var->naze = 0;
	var->free = 0;
	var->str = NULL;
	var->ptr = NULL;
	var->form = NULL;
	var->tmp = NULL;
}

void	free_var(t_var *var)
{
	ft_memdel((void **)&var->str);
	ft_memdel((void **)&var->form);
	ft_memdel((void **)&var->tmp);
}

int		ft_printf(const char *format, ...)
{
	t_var	var;
	int		i;

	init_var(&var);
	va_start(var.ap, format);
	if (!(var.form = ft_strdup(format)))
		return (-1);
	ft_pars_str(&var);
	va_end(var.ap);
	i = ft_strlen(var.str);
	if (var.ind != 0)
		ft_put_end(&var);
	if (var.free == 1)
		ft_memdel((void **)&var.index);
	write(1, var.str, i);
	free_var(&var);
	return (i);
}
