/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shake42.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:25:30 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/20 16:58:10 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/shake42.h"

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

int		shake42(struct s_sk *sk)
{
	char			buff[8];
	int				ret;

	ret = 0;
	sk->action = 0;
	sk->select = 1;
	sk->act_max = 4;
	sk->step = STP_MAIN_MENU;
	if (ioctl(0, TIOCGWINSZ, &sk->window) == -1)
		return (FAILURE);
	sk_main_menu(sk);
	while (1)
	{
		if (ioctl(0, TIOCGWINSZ, &sk->window) == -1)
			return (FAILURE);
		ft_bzero(buff, 8);
		if (read(STDIN_FILENO, &buff, 8) == -1)
			return (FAILURE);
		sk->action = sk_check_action(buff);
		ret = sk_step(sk);
		if (ret != CONTINUE)
			return (ret);
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
	if (shake42(&sk) == FAILURE)
		return (FAILURE);
	ft_putendl(AE_CUR_ON"\n");
	if (sk_reset_term_attributes(&sk.backup))
		return (FAILURE);
	return (0);
}
