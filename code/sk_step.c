/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_step.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:21:42 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/19 19:44:00 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

int		sk_step(struct s_sk *sk)
{
	sk_menu_select(sk);
	if (sk->step == STP_MAIN_MENU && sk->action == A_ENTER)
	{
		sk_menu_blink(sk);
		if (sk->select == SL_EXIT)
			return (SUCCESS);
		if (sk->select == SL_CHECK)
			sk_start_check_test(sk);
		if (sk->select == SL_CHGPATH)
		{
			sk_reset();
			if (sk_path_reset(sk))
				return (FAILURE);
		}
	}
	else if (sk->step == STP_CHECK || sk->step == STP_OP)
		return (sk_step_check_tests(sk));
	return (CONTINUE);
}

int		sk_step_check_tests(struct s_sk *sk)
{
	if (sk->action == A_ENTER)
	{
		sk_menu_blink(sk);
		if (sk->step == STP_CHECK && sk->select == SLC_OP)
			sk_start_ct_operators(sk);
		if (sk->step == STP_CHECK && sk->select == SLC_RET)
			sk_start_main_menu(sk);
		if (sk->step == STP_OP)
			return (sk_step_ct_operators(sk));
	}
	return (CONTINUE);
}

int		sk_step_ct_operators(struct s_sk *sk)
{
	if (sk->action == A_ENTER)
	{
		if (sk->select == SLO_RET)
			sk_start_check_test(sk);
	}
	return (CONTINUE);
}