/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:47:19 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/15 17:44:13 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/diff.h"



void	print_select(struct s_file *files, int blink, char *color)
{
	if (blink)
		blink = 4;
	else
		blink = 1;
	while (blink)
	{
		ft_putstr(color);
		put_column_str(files->file1, files->file2);
		print_ansi("D", files->window.ws_col);
		blink--;
		if (blink)
		{
			usleep(120000);
			ft_putstr(AE_CLINE);
			usleep(120000);
		}
	}
}

int		term_select(struct s_file *files)
{
	print_select(files, 1, AE_INVERSE);
	files->file1->select = 1;
	files->file2->select = 1;
	return (SUCCESS);
}

void	term_enter(struct s_file *files)
{
	int	i;

	i = 0;
	ft_putstr("\033[");
	ft_putnbr(files->max + files->file1->number + 1);
	ft_putchar('B');
	ft_putendl("\n\n-RESULTS-\n");
	// reverse_files(files);
	while (i < files->max)
	{
		if (files->file1 && files->file1->select == 1)
		{
			ft_putstr("In ");
			ft_putnbr(files->file1->number);
			ft_putendl(" line:");
			ft_putendl("file 1 Output:");
			ft_putendl(files->file1->content);
			ft_putendl("\nfile 2 Output:");
			ft_putendl(files->file2->content);
			ft_putchar('\n');
			if (!ft_strcmp(files->file1->content, files->file2->content))
				ft_putendl("\033[32mDiff == OK :)\033[0m");
			else
				ft_putendl("\033[31mDiff == KO :(\033[0m");
			files->file1 = files->file1->prev;
			files->file2 = files->file2->prev;
		}
		i++;
	}
	exit (0);
}

int		term_exec(struct s_file *files)
{
	char	buff[8];

	while (3)
	{
		ft_bzero(buff, 8);
		if (read(STDIN_FILENO, &buff, 8) == -1)
			return (FAILURE);
		if (term_check(buff, files) != NO_PRINT)
			ft_putstr(buff);
	}
	return (SUCCESS);
}
