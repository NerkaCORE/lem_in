/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:01:16 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/02/22 12:08:34 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		putcol(t_var *var, char *color)
{
	var->str = ft_strjoin_free(var->str, color, 1);
}

void			ft_end_color(t_var *var)
{
	if (var->flag & FLAG_COLOR)
		var->str = ft_strjoin_free(var->str, CL_0, 1);
	var->flag = 0;
}

int				ft_color(t_var *var)
{
	if (var->form[var->i + 1] == '{' && var->form[var->i + 2] == '(')
	{
		var->flag |= FLAG_COLOR;
		var->i += 3;
		if (var->form[var->i] == '0')
			putcol(var, CL_0);
		else if (var->form[var->i] == '1')
			putcol(var, CL_1);
		else if (var->form[var->i] == '2')
			putcol(var, CL_2);
		else if (var->form[var->i] == '3')
			putcol(var, CL_3);
		else if (var->form[var->i] == '4')
			putcol(var, CL_4);
		else if (var->form[var->i] == '5')
			putcol(var, CL_5);
		else if (var->form[var->i] == '6')
			putcol(var, CL_6);
		else if (var->form[var->i] == '7')
			putcol(var, CL_7);
		else if (var->form[var->i] == '8')
			putcol(var, CL_8);
		var->i += 2;
	}
	return (1);
}
