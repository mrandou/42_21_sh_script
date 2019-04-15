/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:05:14 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/15 18:01:14 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/diff.h"

void	print_compare_color(struct s_file *files)
{
	if (!ft_strcmp(files->file1->content, files->file2->content))
		ft_putstr(C_GREEN);
	else
		ft_putstr(C_RED);
	put_column_str(files->file1, files->file2);
	ft_putchar('\n');
	ft_putstr(C_OFF);
}

void	print_compare(struct s_file *files)
{
	int	max;

	max = 0;
	while (max < files->max)
	{
		usleep(20000);
		print_compare_color(files);
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
	if (!(files->file1 = dlst_file_create(path1)))
		return (FAILURE);
	if (!(files->file2 = dlst_file_create(path2)))
		return (FAILURE);
	if (ioctl(0, TIOCGWINSZ, &files->window) == -1)
		return (FAILURE);
	get_max(files);
	reverse_files(files);
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
	print_compare(&files);
	term_exec(&files);
	dlst_free(files.file1);
	dlst_free(files.file2);
	tcsetattr(STDIN_FILENO, 0, &backup);
	return (0);
}
