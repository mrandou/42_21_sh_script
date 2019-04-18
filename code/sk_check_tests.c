/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_check_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:21:18 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/18 17:56:23 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

int		sk_check_tests(struct s_sk *sk)
{
	sk->step = STP_CHECK;
	sk_check_tests_menu(sk);
	sk_print_ansi("A", 4);
	sk_print_ansi("C", NB_SP_TABS);
	sk_check_tests_menu_line(1, AE_SELECT);
	sk_check_tests_menu_select(sk);
	return (SUCCESS);
}

void	sk_check_tests_menu_select(struct s_sk *sk)
{
	if (sk->action == A_DOWN && sk->select < 2)
	{
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk_check_tests_menu_line(sk->select, AE_UNSELECT);
		sk_print_ansi("B", 2);
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk->select += 1;
		sk_check_tests_menu_line(sk->select, AE_SELECT);
	}
	if (sk->action == A_UP && sk->select > 1)
	{
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk_check_tests_menu_line(sk->select, AE_UNSELECT);
		sk_print_ansi("A", 2);
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk->select -= 1;
		sk_check_tests_menu_line(sk->select, AE_SELECT);
	}
}

void	sk_check_tests_menu_line(int select, char *color)
{
	if (color)
		ft_putstr(color);
	if (select == 1)
		ft_putstr("> Operators");
	if (select == 2)
		ft_putstr("> Return");
	if (color)
		ft_putstr(C_OFF);
}

void	sk_check_tests_menu(struct s_sk *sk)
{
	ft_putendl(C_GREEN"\n\n\n\n"SP_TABS"What Tests do you want ?\n\n");
	ft_putendl(SP_TABS"> Oprators\n");
	ft_putendl(SP_TABS"> Return\n");
}
