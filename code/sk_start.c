/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:40:36 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/19 19:43:42 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

void	sk_start_main_menu(struct s_sk *sk)
{
	sk_reset();
	sk->step = STP_MAIN_MENU;
	sk->select = SL_CHECK;
	sk->act_max = 4;
	sk_main_menu(sk);
}

void	sk_start_check_test(struct s_sk *sk)
{
	sk_reset();
	sk->select = SLC_OP;
	sk->step = STP_CHECK;
	sk->act_max = 2;
	sk_check_tests_menu(sk);
}

void	sk_start_ct_operators(struct s_sk *sk)
{
	sk_reset();
	sk->step = STP_OP;
	sk->select = SLO_SPIPE;
	sk->act_max = 9;
	sk_ct_operators_menu(sk);
}
