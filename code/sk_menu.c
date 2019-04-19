/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:18:48 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/19 17:35:36 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

void	sk_main_menu(struct s_sk *sk)
{
	sk_print_center("Welcome to shake42 ! a 42 Shell checker..",
	sk->window.ws_col, C_BLUE);
	ft_putstr(AE_CUR_OFF);
	ft_putendl(C_GREEN"\n\n\n\n"SP_TABS"What do you want ?\n\n");
	ft_putendl(SP_TABS"> Checks Tests\n");
	ft_putendl(SP_TABS"> Old Results\n");
	ft_putendl(SP_TABS"> Change Shell Path\n");
	ft_putendl(SP_TABS"> Exit\n");
	sk_print_ansi("A", 8);
	sk_print_ansi("C", NB_SP_TABS);
	sk_menu_line(sk, AE_SELECT);
}

void	sk_check_tests_menu(struct s_sk *sk)
{
	ft_putendl(C_GREEN"\n\n\n\n"SP_TABS"What Tests do you want ?\n\n");
	ft_putendl(SP_TABS"> Operators\n");
	ft_putendl(SP_TABS"> Return\n");
	sk_print_ansi("A", 4);
	sk_print_ansi("C", NB_SP_TABS);
	sk_menu_line(sk, AE_SELECT);
}

void	sk_menu_select(struct s_sk *sk)
{
	if (sk->action == A_DOWN && sk->select < sk->act_max)
	{
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk_menu_line(sk, AE_UNSELECT);
		sk_print_ansi("B", 2);
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk->select += 1;
		sk_menu_line(sk, AE_SELECT);
	}
	if (sk->action == A_UP && sk->select > 1)
	{
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk_menu_line(sk, AE_UNSELECT);
		sk_print_ansi("A", 2);
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk->select -= 1;
		sk_menu_line(sk, AE_SELECT);
	}
}

int		sk_menu_blink(struct s_sk *sk)
{
	int	blink;

	blink = 2;
	while (blink)
	{
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk_menu_line(sk, AE_UNSELECT);
		usleep(120000);
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk_menu_line(sk, AE_SELECT);
		usleep(120000);
		blink--;
	}
	return (SUCCESS);
}
