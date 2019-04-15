/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:17:59 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/15 17:42:14 by mrandou          ###   ########.fr       */
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

int		term_up(struct s_file *files)
{
	if (files->file1->next && files->file2->next)
	{
		files->file1 = files->file1->next;
		files->file2 = files->file2->next;
	}
	else
		return (NO_PRINT);
	return (SUCCESS);
}

int		term_down(struct s_file *files)
{
	if (files->file1->prev && files->file2->prev)
	{
		files->file1 = files->file1->prev;
		files->file2 = files->file2->prev;
	}
	else
		return (NO_PRINT);
	return (SUCCESS);
}

int		term_check(char *buff, struct s_file *files)
{
	if (!ft_strcmp(buff, AE_UP))
		return (term_up(files));
	if (!ft_strcmp(buff, AE_DOWN))
		return (term_down(files));
	if (!ft_strcmp(buff, SPACE))
		term_select(files);
	if (!ft_strcmp(buff, ENTER))
		term_enter(files);
	return (NO_PRINT);
}
