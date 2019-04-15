/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:19:45 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/15 17:35:55 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/diff.h"

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

void	print_ansi(char *ansi, int nb)
{
	ft_putstr("\033[");
	if (nb)
		ft_putnbr(nb);
	ft_putstr(ansi);
}

int		print_nstr(char *str, int nb)
{
	int	i;
	int	size;

	size = ft_strlen(str);
	i = 0;
	while (str[i] && i < nb - 6)
		ft_putchar(str[i++]);
	if (i >= nb - 6)
	{
		ft_putstr(" (...)");
		return (nb);
	}
	return (0);
}

void	reverse_files(struct s_file *files)
{
	files->file1 = reverse_dlst(files->file1);
	files->file2 = reverse_dlst(files->file2);
}

struct s_dlist	*reverse_dlst(struct s_dlist *dlist)
{
	while (dlist->next)
		dlist = dlist->next;
	return (dlist);
}

void	print_dlst(struct s_dlist *dlist)
{
	while (dlist)
	{
		ft_putnbr(dlist->number);
		ft_putstr(" > ");
		ft_putendl(dlist->content);
		dlist = dlist->prev;
	}
}
