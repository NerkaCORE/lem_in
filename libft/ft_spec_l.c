/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:03:21 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/02/22 12:15:00 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_spe_l(t_var *var)
{
	var->flag |= FLAG_L;
	ft_verif_flag(var);
	if (var->form[var->i] == 'O')
		ft_spe_oct(var);
	else if (var->form[var->i] == 'U')
		ft_spe_unb(var);
	else if (var->form[var->i] == 'D')
		ft_spe_nb(var);
	return (1);
}
