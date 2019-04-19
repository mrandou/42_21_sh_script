/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_menu_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:19:34 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/19 17:24:53 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

void	sk_menu_line(struct s_sk *sk, char *mode)
{
	if (mode)
		ft_putstr(mode);
	if (sk->step == STP_MAIN_MENU)
		sk_menu_line_main(sk->select);
	if (sk->step == STP_CHECK)
		sk_menu_line_check(sk->select);
	if (mode)
		ft_putstr(C_OFF);
}

void	sk_menu_line_main(int select)
{
	if (select == SL_CHECK)
		ft_putstr("> Checks Tests");
	if (select == SL_OLDRESULT)
		ft_putstr("> Old Results");
	if (select == SL_CHGPATH)
		ft_putstr("> Change Shell Path");
	if (select == SL_EXIT)
		ft_putstr("> Exit");
}

void	sk_menu_line_check(int select)
{
	if (select == SLC_OP)
		ft_putstr("> Operators");
	if (select == SLC_RET)
		ft_putstr("> Return");
}
