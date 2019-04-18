/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:25:30 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/18 17:55:34 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

int		sk_check_action(char *buff)
{
	if (!ft_strcmp(buff, AE_UP))
		return (A_UP);
	if (!ft_strcmp(buff, AE_DOWN))
		return (A_DOWN);
	if (!ft_strcmp(buff, AE_RIGHT))
		return (A_RIGHT);
	if (!ft_strcmp(buff, AE_LEFT))
		return (A_LEFT);
	if (!ft_strcmp(buff, ENTER))
		return (A_ENTER);
	return (A_NOTHING);
}

int		sk_exec(struct s_sk *sk)
{
	sk_menu_blink(sk);
	sk_reset();
	if (sk->select == SL_CHECK || sk->step == STP_CHECK)
		if (sk_check_tests(sk))
			return (FAILURE);
	if (sk->select == SL_CHGPATH)
	{
		sk_path_reset(sk);
		sk_reset();
		sk->step = STP_MAIN_MENU;
		sk->select = 1;
		sk_main_menu(sk->window.ws_col);
	}
	return (SUCCESS);
}

int		shake42(struct s_sk *sk)
{
	char			buff[8];

	sk->action = 0;
	sk->select = 1;
	sk->step = STP_MAIN_MENU;
	if (ioctl(0, TIOCGWINSZ, &sk->window) == -1)
		return (FAILURE);
	sk_main_menu(sk->window.ws_col);
	while (1)
	{
		ft_bzero(buff, 8);
		if (read(STDIN_FILENO, &buff, 8) == -1)
			return (FAILURE);
		sk->action = sk_check_action(buff);
		if (sk->action != A_ENTER && sk->step == STP_MAIN_MENU)
			sk_main_menu_select(sk);
		else
		{
			if (sk->select == SL_EXIT && sk->step == STP_MAIN_MENU)
				return (sk_menu_blink(sk));
			if (sk_exec(sk))
				return (FAILURE);
		}
	}
	return (SUCCESS);
}

int		 main(void)
{
	struct s_sk	sk;

	sk_header();
	if (sk_path(sk.path))
		return (FAILURE);
	sk_reset();
	if (sk_set_term_attributes(&sk.backup))
		return (FAILURE);
	if (shake42(&sk))
		return (FAILURE);
	ft_putendl(AE_CUR_ON"\n");
	if (sk_reset_term_attributes(&sk.backup))
		return (FAILURE);
	return (0);
}
