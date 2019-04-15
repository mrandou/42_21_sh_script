/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:05:14 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/15 12:55:30 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/diff.h"

void	print_compare(struct s_file *files)
{
	int	max;

	max = 0;
	while (max < files->max)
	{
		if (!ft_strcmp(files->file1->content, files->file2->content))
		{
			usleep(20000);
			ft_putstr(C_GREEN);
			put_column_str(files->file1, files->file2);	
			ft_putchar('\n');
			ft_putstr(C_OFF);
		}
		else
		{
			usleep(20000);
			ft_putstr(C_RED);
			put_column_str(files->file1, files->file2);
			ft_putchar('\n');
			ft_putstr(C_OFF);
		}
		if (files->file1->prev)
			files->file1 = files->file1->prev;
		if (files->file2->prev)
			files->file2 = files->file2->prev;
		max++;
	}
	ft_putstr(AE_UP);
}

void	get_max(struct s_file *files)
{
	while (files->file1->prev)
		files->file1 = files->file1->prev;
	files->max = files->file1->number;
	while (files->file2->prev)
		files->file2 = files->file2->prev;
	if (files->file2->number > files->max)
		files->max = files->file2->number;
}

int		load_files(struct s_file *files, char *path1, char *path2)
{
	files->file1 = dlst_file_create(path1);
	files->file2 = dlst_file_create(path2);
	get_max(files);
	restore_files(files);
	return (0);
}

int		diff(struct s_file *files)
{
	print_compare(files);
	term_exec(files);
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	struct termios	backup;
	struct s_file	files;

	if (argc != 3)
		return (1);
	load_files(&files, argv[1], argv[2]);
	set_shell_attributes(&backup);
	diff(&files);
	tcsetattr(STDIN_FILENO, 0, &backup);
	return (0);
}
