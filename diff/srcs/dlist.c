/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:06:45 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/13 17:23:59 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/diff.h"

void	dlst_push(t_dlist **dlist, char *content, int number)
{
	t_dlist *newlist;

	if (!(newlist = (t_dlist *)malloc(sizeof(t_dlist))))
		return ;
	if (!(newlist->content = ft_strdup(content)))
	{
		if (newlist)
			free(newlist);
		return ;
	}
	newlist->number = number;
	newlist->next = *dlist;
	newlist->prev = NULL;
	if (*dlist)
		(*dlist)->prev = newlist;
	*dlist = newlist;
}

struct s_dlist	*dlst_file_create(char *file)
{
	struct	s_dlist *dlist;
	char	*line;
	int		ret;
	int		num;
	int		fd;

	ret = 1;
	num = 1;
	dlist = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	while (ret)
	{
		line = NULL;
		if ((ret = get_next_line(fd, &line)) == -1)
			return (NULL);
		if (ret)
			dlst_push(&dlist, line, num++);
		ft_strdel(&line);
	}
	while (dlist->next)
		dlist = dlist->next;
	return (dlist);
}

void	dlst_free(t_dlist *dlist)
{
	t_dlist	*tmp;

	while (dlist->prev)
		dlist = dlist->prev;
	while (dlist)
	{
		tmp = dlist->next;
		if (dlist->content)
			free(dlist->content);
		if (dlist)
			free(dlist);
		dlist = tmp;
	}
}
