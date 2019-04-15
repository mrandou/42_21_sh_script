/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_column_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:19:20 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/15 12:00:01 by mrandou          ###   ########.fr       */
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

// void	put_right_left_column(char *s1, char *s2, int line)
// {
// 	struct	winsize window;
// 	int		mid;
// 	int		mcol;
// 	int		ret;
// 	int		ten_prc;

// 	ret = 1;
// 	if (ioctl(0, TIOCGWINSZ, &window) == -1)
// 		return ;
// 	mid = window.ws_col / 2;
// 	ft_putnbr(line);
// 	ft_putstr(" > ");
// 	ten_prc = mid * 10 / 100;
// 	print_spaces(ten_prc);
// 	mcol = mid - ten_prc - (ft_nblen(line) + 3);
// 	while (ret)
// 	{
// 		if (s1)
// 		{
// 			ret = print_nstr(s1, mcol - ten_prc);
// 			if (ret)
// 				s1 += mcol - ten_prc;
// 		}
// 		else
// 			print_spaces(mid * 80 / 100);
// 		print_spaces(ten_prc - 1);
// 		ft_putchar('|');
// 		print_spaces(ten_prc);
// 		mcol = mid - ten_prc;
// 		if (s2)
// 		{
// 			ret = ret + print_nstr(s2, mcol - ten_prc);
// 			if (s2[mcol - ten_prc])
// 				s2 += mcol - ten_prc;
// 		}
// 		else
// 			print_spaces(mid * 80 / 100);
// 		ft_putchar('\n');
// 	}
// }
