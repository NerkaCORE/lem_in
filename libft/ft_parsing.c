/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 13:35:32 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/02/22 12:11:32 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_pars_str(t_var *var)
{
	int	i;

	i = 0;
	if (!(var->tmp = (char *)malloc(sizeof(char) * (ft_strlen(var->form) + 1))))
		return (-1);
	while (var->form[var->i])
	{
		while (var->form[var->i] && (var->form[var->i]) != '%')
		{
			var->tmp[i] = var->form[var->i];
			i++;
			var->i++;
		}
		var->tmp[i] = '\0';
		var->str = ft_strjoin_free(var->str, var->tmp, 1);
		if (var->form[var->i] == '%' && ft_color(var))
			ft_pars_mod(var);
		i = 0;
	}
	ft_memdel((void **)&var->tmp);
	return (1);
}

static int	init_wps(t_var *var)
{
	var->width = 0;
	var->preci = 0;
	var->spe = '0';
	return (1);
}

int			ft_pars_mod(t_var *var)
{
	static int		(*tab_ft[128])(t_var *) = {NULL};

	if ((init_wps(var)) && !tab_ft['%'])
		ft_init_tab(tab_ft);
	while (var->form[++var->i])
	{
		while (var->form[var->i] && ft_check_flag(var))
			var->i++;
		if (var->form[var->i] == '.' || ft_isdigit(var->form[var->i]) ||
				var->form[var->i] == '*')
			ft_pars_nb(var);
		if (!tab_ft[(int)var->form[var->i]] && !(ft_check_flag(var)) &&
				!(ft_check_modif(var)))
		{
			var->str = ft_strjoin_free(var->str, ft_add_char(NULL,
						var->form[var->i], var), 2);
			var->i++;
			break ;
		}
		if (tab_ft[(int)var->form[var->i]] && (ft_verif_flag(var)) &&
				((int)tab_ft[(int)var->form[var->i]](var)) && (var->i++))
			break ;
	}
	ft_end_color(var);
	return (0);
}

void		ft_pars_nb(t_var *var)
{
	char	str[10];
	int		i;

	if (var->form[var->i] == '0' && (var->i++))
		var->flag |= FLAG_ZE;
	while ((var->form[var->i] != '.' && (ft_isdigit(var->form[var->i]))) ||
			var->form[var->i] == '*')
	{
		i = 0;
		ft_bzero(str, 10);
		while (ft_isdigit(var->form[var->i]))
		{
			str[i] = var->form[var->i];
			var->i++;
			i++;
		}
		var->width = ft_atoi(str);
		if (var->form[var->i] == '*' && (var->i++))
			if ((var->width = (int)va_arg(var->ap, void *)) < 0)
			{
				var->flag |= FLAG_NEG;
				var->width = -var->width;
			}
	}
	ft_pars_nbp(var);
}

void		ft_pars_nbp(t_var *var)
{
	char	str[10];
	int		i;

	if (var->form[var->i] == '.')
	{
		i = 0;
		while (var->form[var->i] == '.' && (var->i++))
		{
			ft_bzero(str, 10);
			var->flag |= FLAG_PR;
			if (var->form[var->i] == '.')
				var->preci = 0;
			while (ft_isdigit(var->form[var->i]))
			{
				str[i] = var->form[var->i];
				var->i++;
				i++;
			}
			var->preci = ft_atoi(str);
			if (var->form[var->i] == '*' && (var->i++))
				if ((var->preci = (int)va_arg(var->ap, void *)) < 0)
					var->flag ^= FLAG_PR;
		}
	}
}
