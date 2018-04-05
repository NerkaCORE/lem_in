/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:07:41 by unli-yaw          #+#    #+#             */
/*   Updated: 2016/11/28 16:07:56 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putnchar(char c, unsigned int n)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}