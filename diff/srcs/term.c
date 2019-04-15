/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:47:19 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/15 12:11:16 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/diff.h"

int		set_shell_attributes(struct termios *backup)
{ 
	struct termios  s_set;

	if (tcgetattr(STDIN_FILENO, &s_set))
		return (FAILURE);
	*backup = s_set;
	s_set.c_lflag &= ~(ICANON | ECHO);
	if (tcsetattr(STDIN_FILENO, 0, &s_set))
		return (FAILURE);
	return (SUCCESS);
}

int		term_select(struct s_file *files)
{
	struct winsize	window;

	if (ioctl(0, TIOCGWINSZ, &window) == -1)
		return (FAILURE);
	ft_putstr("\033[7m");
	put_column_str(files->file1, files->file2);
	ft_putstr(C_OFF);
	ft_putstr("\033[");
	ft_putnbr(window.ws_col);
	ft_putchar('D');
	return (SUCCESS);
}

int		term_check(char *buff, struct s_file *files)
{
	if (!ft_strcmp(buff, AE_UP))
	{
		if (files->file1->next)
			files->file1 = files->file1->next;
		else
			return (NO_TERM);
		return (SUCCESS);
	}
	if (!ft_strcmp(buff, AE_DOWN))
	{
		if (files->file1->prev)
			files->file1 = files->file1->prev;
		else
			return (NO_TERM);
		return (SUCCESS);
	}
	if (!ft_strcmp(buff, SPACE))
	{
		term_select(files);
		usleep(120000);
		ft_putstr("\033[K");
		usleep(120000);
		term_select(files);
		usleep(120000);
		ft_putstr("\033[K");
		usleep(120000);
		term_select(files);
		return (NO_TERM);
	}
	return (NO_TERM);
}

int		term_exec(struct s_file *files)
{
	char	buff[8];

	while (3)
	{
		ft_bzero(buff, 8);
		if (read(STDIN_FILENO, &buff, 8) == -1)
			return (FAILURE);
		if (term_check(buff, files) != NO_TERM)
			ft_putstr(buff);
	}
	return (SUCCESS);
}
