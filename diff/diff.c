/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:05:14 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/12 18:01:11 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/incs/libft.h"
#include <fcntl.h>
#include <sys/ioctl.h>
#define C_RED		"\033[31m"
#define C_GREEN		"\033[32m"
#define C_OFF		"\033[0m"
#define SUCCESS	0
#define FAILURE	1
#define ERROR	-1

void	print_spaces(int nb)
{
	if (nb < 0)
		return ;
	while (nb)
	{
		ft_putchar(' ');
		nb--;
	}
}

void	print_nstr(char *str, int nb)
{
	int	i;

	i = 0;
	while (str[i] && i < nb - 6)
		ft_putchar(str[i++]);
	if (i >= nb - 6)
		ft_putstr(" (...)");
	
}

void	put_column_strings(char *s1, char *s2)
{
	struct	winsize window;
	int		size_1;
	int		size_2;
	int		mid;
	static int line = 0;

	line++;
	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	ioctl(0, TIOCGWINSZ, &window);
	mid = window.ws_col / 2;
	if	(s1)
	{
		ft_putnbr(line);
		ft_putstr(" > ");
		print_spaces(mid * 10 / 100 - (ft_nblen(line) + 3));
		print_nstr(s1, mid * 80 / 100);
		if (size_1 > mid * 80 / 100 - 6)
			size_1 = mid * 80 / 100;
		print_spaces(mid * 90 / 100 - size_1);
	}
	else
		print_spaces(mid);
	ft_putchar('|');
	if (s2)
	{
		print_spaces(mid * 10 / 100);
		print_nstr(s2, mid * 80 / 100);
	}
	ft_putchar('\n');
}

void	print_compare(char *line_f1, char *line_f2)
{
	if (!ft_strcmp(line_f1, line_f2))
	{
		ft_putstr(C_GREEN);
		put_column_strings(line_f1, line_f2);
		ft_putstr(C_OFF);
	}
	else
	{
		ft_putstr(C_RED);
		put_column_strings(line_f1, line_f2);
		ft_putstr(C_OFF);
	}
}

int		read_line_files(int fd_1, int fd_2, char **line1, char **line2)
{
	int	ret1;
	int	ret2;

	if ((ret1 = get_next_line(fd_1, line1)) == ERROR)
		return (ERROR);
	if ((ret2 = get_next_line(fd_2, line2)) == ERROR)
		return (ERROR);
	return (ret1 + ret2);
}

int		compare_file(char *file1, char *file2)
{
	char	*line_f1;
	char	*line_f2;
	int		ret;
	int		fd_f1;
	int		fd_f2;

	ret = 1;
	if ((fd_f1 = open(file1, O_RDONLY)) == -1)
		return (FAILURE);
	if ((fd_f2 = open(file2, O_RDONLY)) == -1)
		return (FAILURE);
	while (ret)
	{
		line_f1 = NULL;
		line_f2 = NULL;
		if ((ret = read_line_files(fd_f1, fd_f2, &line_f1, &line_f2)) == ERROR)
		{
			ft_strdbldel(&line_f1, &line_f2);
			return (FAILURE);
		}
		if (ret)
			print_compare(line_f1, line_f2);
		ft_strdbldel(&line_f1, &line_f2);
	}
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	int i = 0;
	compare_file(argv[1], argv[2]);
	return (0);
}
