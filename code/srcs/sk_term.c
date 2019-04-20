/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:39:25 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/20 16:58:39 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/shake42.h"

int		sk_set_term_attributes(struct termios *backup)
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

int		sk_reset_term_attributes(struct termios *backup)
{
	if (tcsetattr(STDIN_FILENO, 0, backup) == -1)
		return (FAILURE);
	return (SUCCESS);
}
