/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_menu_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:19:34 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/23 12:08:23 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/shake42.h"

void	sk_menu_line(struct s_sk *sk, char *mode)
{
	ft_putstr(C_GREEN"> ");
	if (mode)
		ft_putstr(mode);
	if (sk->step == STP_MAIN_MENU)
		sk_menu_line_main(sk->select);
	if (sk->step == STP_CHECK)
		sk_menu_line_check(sk->select);
	if (sk->step == STP_OP)
		sk_menu_line_ct_operators(sk->select);
	if (mode)
		ft_putstr(C_OFF);
}

void	sk_menu_line_main(int select)
{
	if (select == SL_CHECK)
		ft_putstr("Check Tests");
	if (select == SL_OLDRESULT)
		ft_putstr("Old Results");
	if (select == SL_CHGPATH)
		ft_putstr("Change Shell Path");
	if (select == SL_EXIT)
		ft_putstr("Exit");
}

void	sk_menu_line_check(int select)
{
	if (select == SLC_OP)
		ft_putstr("Operators");
	if (select == SLC_RET)
		ft_putstr("Return");
}

void	sk_menu_line_ct_operators(int select)
{
	if (select == SLO_SPIPE)
		ft_putstr("Simple Pipe : |");
	if (select == SLO_OR)
		ft_putstr("Or : ||");
	if (select == SLO_AMP)
		ft_putstr("Ampersand : &");
	if (select == SLO_AND)
		ft_putstr("And : &&");
	if (select == SLO_REDIR_R)
		ft_putstr("Right Redirection : >");
	if (select == SLO_REDIR_L)
		ft_putstr("Left Redirection : <");
	if (select == SLO_BANG)
		ft_putstr("Bang : !");
	if (select == SLO_SEMICOLON)
		ft_putstr("Semicolon : ;");
	if (select == SLO_RET)
		ft_putstr("Return");
}
