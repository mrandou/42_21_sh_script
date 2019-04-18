/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:16:55 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/18 14:31:20 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

int		sk_header(void)
{
	ft_putstr(C_BLUE);
	ft_putstr(AE_CLEAR);
	sk_exec_cmd("/bin/cat", "cat ./misc/header.txt", NULL);
	ft_putendl(C_OFF"\n\n");
	return (SUCCESS);
}

void	sk_print_nspace(int nb)
{
	if (nb < 0)
		return ;
	while (nb)
	{
		ft_putchar(' ');
		nb--;
	}
}

void	sk_print_ansi(char *ansi, int nb)
{
	ft_putstr("\033[");
	if (nb)
		ft_putnbr(nb);
	ft_putstr(ansi);
}

void	sk_reset(void)
{
	ft_putstr(AE_CLEAR);
	sk_header();
}
