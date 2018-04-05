/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 13:50:20 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/02/22 12:13:00 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_space(char *str, t_var *var)
{
	char	*tmp;

	tmp = NULL;
	var->width -= ft_strlen(str);
	norm_sp(var);
	if (var->width <= 0 && var->spe != 'c')
		return (str);
	if (!(tmp = (char *)malloc(sizeof(char) * (var->width + 1))))
		return (0);
	ft_memset(tmp, '\0', var->width + 1);
	if (var->flag & FLAG_ZE)
		ft_memset(tmp, '0', var->width);
	else
		ft_memset(tmp, ' ', var->width);
	if (var->flag & FLAG_NEG && var->free != -1)
		str = ft_strjoin_free(str, tmp, 1);
	else if (var->flag & FLAG_NEG && var->free == -1)
		str = ft_strjoin(str, tmp);
	else if (var->free >= 0)
		str = ft_strjoin_free(tmp, str, 3);
	else
		str = ft_strjoin(tmp, str);
	ft_memdel((void **)&tmp);
	return (str);
}
