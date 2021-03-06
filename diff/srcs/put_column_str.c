/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_column_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:19:20 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/15 13:17:52 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/diff.h"

void	first_column(struct s_dlist *file1, int mid)
{
	int		size;

	size = ft_strlen(file1->content);
	ft_putnbr(file1->number);
	ft_putstr(" > ");
	print_spaces(mid * 10 / 100 - ft_nblen(file1->number));
	print_nstr(file1->content, mid * 80 / 100);
	if (size > mid * 80 / 100 - 6)
		size = mid * 80 / 100;
	print_spaces(mid * 90 / 100 - size);
}

void	put_column_str(struct s_dlist *file1, struct s_dlist *file2)
{
	struct	winsize window;
	int		mid;
	int		ret;
	int		nb_print;

	ret = 0;
	if (ioctl(0, TIOCGWINSZ, &window) == -1)
		return ;
	mid = window.ws_col / 2;
	nb_print = mid;
	if	(file1->content)
		first_column(file1, mid);
	else
		print_spaces(mid);
	ft_putchar('|');
	if (file2->content)
	{
		print_spaces(mid * 10 / 100);
		nb_print += mid * 10 / 100;
		ret = print_nstr(file2->content, mid * 80 / 100);
		if (ret)
			nb_print += mid * 80 / 100;
		else
			nb_print += ft_strlen(file2->content);
		print_spaces((window.ws_col - nb_print) - 3);
	}
}
