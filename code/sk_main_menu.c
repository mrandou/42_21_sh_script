/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_main_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:51:52 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/18 17:46:39 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

void	sk_main_menu(int col)
{
	sk_print_center("Welcome to shake42 ! a 42 Shell checker..", col, C_BLUE);
	ft_putstr(AE_CUR_OFF);
	ft_putendl(C_GREEN"\n\n\n\n"SP_TABS"What do you want ?\n\n");
	ft_putendl(SP_TABS"> Checks Tests\n");
	ft_putendl(SP_TABS"> Old Results\n");
	ft_putendl(SP_TABS"> Change Shell Path\n");
	ft_putendl(SP_TABS"> Exit\n");
	sk_print_ansi("A", 8);
	sk_print_ansi("C", NB_SP_TABS);
	sk_main_menu_line(1, AE_SELECT);
}

void	sk_main_menu_line(int select, char *color)
{
	if (color)
		ft_putstr(color);
	if (select == SL_CHECK)
		ft_putstr("> Checks Tests");
	if (select == SL_OLDRESULT)
		ft_putstr("> Old Results");
	if (select == SL_CHGPATH)
		ft_putstr("> Change Shell Path");
	if (select == SL_EXIT)
		ft_putstr("> Exit");
	if (color)
		ft_putstr(C_OFF);
}

void 	sk_main_menu_select(struct s_sk *sk)
{
	if (sk->action == A_DOWN && sk->select < 4)
	{
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk_main_menu_line(sk->select, AE_UNSELECT);
		sk_print_ansi("B", 2);
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk->select += 1;
		sk_main_menu_line(sk->select, AE_SELECT);
	}
	if (sk->action == A_UP && sk->select > 1)
	{
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk_main_menu_line(sk->select, AE_UNSELECT);
		sk_print_ansi("A", 2);
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		sk->select -= 1;
		sk_main_menu_line(sk->select, AE_SELECT);
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
		if (sk->step == STP_MAIN_MENU)
			sk_main_menu_line(sk->select, AE_UNSELECT);
		if (sk->step == STP_CHECK)
			sk_check_tests_menu_line(sk->select, AE_UNSELECT);
		usleep(120000);
		sk_print_ansi("D", sk->window.ws_col);
		sk_print_ansi("C", NB_SP_TABS);
		if (sk->step == STP_MAIN_MENU)
			sk_main_menu_line(sk->select, AE_SELECT);
		if (sk->step == STP_CHECK)
			sk_check_tests_menu_line(sk->select, AE_UNSELECT);
		usleep(120000);
		blink--;
	}
	return (SUCCESS);
}
