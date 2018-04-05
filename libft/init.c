/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:42:15 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/02/22 12:30:42 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_zero(t_var *var, int x)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (2))))
		return (NULL);
	if (x == 0)
		tmp[0] = '0';
	else
		tmp[0] = '*';
	tmp[1] = '\0';
	if (x == 1)
	{
		var->index[var->ind] = ft_strlen(var->str) + var->width - 1;
		var->ind++;
	}
	return (tmp);
}

void		ft_init_tab(int (**tab_ft)(t_var *))
{
	tab_ft['%'] = &ft_spe_mod;
	tab_ft['c'] = &ft_spe_char;
	tab_ft['s'] = &ft_spe_str;
	tab_ft['d'] = &ft_spe_nb;
	tab_ft['i'] = &ft_spe_nb;
	tab_ft['u'] = &ft_spe_unb;
	tab_ft['o'] = &ft_spe_oct;
	tab_ft['x'] = &ft_spe_hex;
	tab_ft['X'] = &ft_spe_hexup;
	tab_ft['p'] = &ft_spe_mem;
	tab_ft['D'] = &ft_spe_l;
	tab_ft['O'] = &ft_spe_l;
	tab_ft['U'] = &ft_spe_l;
	tab_ft['C'] = &ft_spe_wchar;
	tab_ft['S'] = &ft_spe_wcstr;
	tab_ft['n'] = &ft_spe_intn;
	tab_ft['b'] = &ft_spe_ubin;
	tab_ft['B'] = &ft_spe_bin;
	tab_ft['f'] = &ft_spe_ld;
	tab_ft['F'] = &ft_spe_ld;
	tab_ft['e'] = &ft_spe_eld;
	tab_ft['E'] = &ft_spe_eld;
	tab_ft['g'] = &ft_spe_gld;
	tab_ft['G'] = &ft_spe_gld;
}

int			ft_check_flag(t_var *var)
{
	if (var->form[var->i] == '#' && (var->flag |= FLAG_DI))
		return (1);
	else if (var->form[var->i] == '0' && (var->flag |= FLAG_ZE))
		return (1);
	else if (var->form[var->i] == '-' && (var->flag |= FLAG_NEG))
		return (1);
	else if (var->form[var->i] == '+' && (var->flag |= FLAG_POS))
		return (1);
	else if (var->form[var->i] == ' ' && (var->flag |= FLAG_SP))
		return (1);
	else
		return (0);
}

int			ft_check_modif(t_var *var)
{
	if (var->form[var->i] == 'h' && var->form[var->i + 1] == 'h' &&
			(var->i += 1))
	{
		var->flag |= FLAG_HH;
		return (1);
	}
	else if (var->form[var->i] == 'l' && var->form[var->i + 1] == 'l' &&
			(var->i += 1))
	{
		var->flag |= FLAG_LL;
		return (1);
	}
	else if (var->form[var->i] == 'j' && (var->flag |= FLAG_J))
		return (1);
	else if (var->form[var->i] == 'L' && (var->flag |= FLAG_GL))
		return (1);
	else if (var->form[var->i] == 'h' && (var->flag |= FLAG_H))
		return (1);
	else if (var->form[var->i] == 'l' && (var->flag |= FLAG_L))
		return (1);
	else if (var->form[var->i] == 'z' && (var->flag |= FLAG_Z))
		return (1);
	else
		return (0);
}
