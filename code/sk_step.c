/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_step.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:21:42 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/19 17:45:00 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

int		sk_step(struct s_sk *sk)
{
	if (sk->step == STP_MAIN_MENU && sk->action != A_ENTER)
		sk_menu_select(sk);
	else if (sk->step == STP_MAIN_MENU && sk->action == A_ENTER)
	{
		sk_menu_blink(sk);
		if (sk->select == SL_EXIT)
			return (SUCCESS);
		if (sk->select == SL_CHECK)
		{
			sk_reset();
			sk->select = SLC_OP;
			sk->step = STP_CHECK;
			sk->act_max = 2;
			sk_check_tests_menu(sk);
		}
		if (sk->select == SL_CHGPATH)
			if (sk_path_reset(sk))
				return (FAILURE);
	}
	else if (sk->step == STP_CHECK)
		return (sk_step_check(sk));
	return (CONTINUE);
}

int		sk_step_check(struct s_sk *sk)
{
	if (sk->action != A_ENTER)
		sk_menu_select(sk);
	if (sk->action == A_ENTER)
	{
		sk_menu_blink(sk);
		if (sk->select == SLC_RET)
		{
			sk_reset();
			sk->step = STP_MAIN_MENU;
			sk->select = SL_CHECK;
			sk->act_max = 4;
			sk_main_menu(sk);
		}
	}
	return (CONTINUE);
}
