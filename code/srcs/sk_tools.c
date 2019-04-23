/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:16:55 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/23 12:06:03 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/shake42.h"

int		sk_header(char **env)
{
	ft_putstr(C_BLUE);
	ft_putstr(AE_CLEAR);
	sk_exec_cmd("./resources/misc/center.sh",
	"./resources/misc/center.sh ./resources/misc/header.txt", env);
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

void	sk_reset(char **env)
{
	ft_putstr(AE_CLEAR);
	sk_header(env);
}
