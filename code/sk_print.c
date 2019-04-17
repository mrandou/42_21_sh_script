/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:07:46 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/17 16:24:29 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

void	sk_print_center(char *str, int col, char *color)
{
	int	size;

	size = ft_strlen(str);
	if (size > col)
	{
		ft_putstr(str);
		return ;
	}
	sk_print_nspace(((col - 1) / 2) - (size / 2));
	if (color)
		ft_putstr(color);
	ft_putstr(str);
	if (color)
		ft_putstr(C_OFF);
	sk_print_nspace((col / 2) - (size / 2));
}
