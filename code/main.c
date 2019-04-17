/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:25:30 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/17 18:34:04 by mrandou          ###   ########.fr       */
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

int		sk_exec(char *path, int action, int select, int col)
{
	if (select == SL_CHGPATH)
	{
		sk_main_menu_blink(col, select);
		ft_putstr(AE_CLEAR);	
	}
	return (SUCCESS);
}

int		shake42(char *path)
{
	char			buff[8];
	struct	winsize	window;
	int				action;
	int				select;
	int				step;

	action = 0;
	select = 1;
	step = 0;
	if (ioctl(0, TIOCGWINSZ, &window) == -1)
		return (FAILURE);
	sk_main_menu(window.ws_col);
	while (1)
	{
		ft_bzero(buff, 8);
		if (read(STDIN_FILENO, &buff, 8) == -1)
			return (FAILURE);
		action = sk_check_action(buff);
		if (action != A_ENTER && !step)
			sk_main_menu_select(action, &select, window.ws_col);
		else
		{
			if (select == SL_EXIT && !step)
				return (sk_main_menu_blink(window.ws_col, select));
			step++;
			sk_exec(path, action, select, window.ws_col);
		}
	}
	return (SUCCESS);
}

int		 main(int argc, char **argv, char **env)
{
	struct termios	backup;
	char			path[1024];

	sk_header();
	if (sk_path(path))
		return (FAILURE);
	if (sk_set_term_attributes(&backup))
		return (FAILURE);
	if (shake42(path))
		return (FAILURE);
	ft_putendl(AE_CUR_ON"\n");
	if (sk_reset_term_attributes(&backup))
		return (FAILURE);
	return (0);
}
