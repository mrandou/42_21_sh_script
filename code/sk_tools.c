/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:16:55 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/16 17:00:52 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

int		sk_header(void)
{
	ft_putstr(C_BLUE);
	ft_putstr(AE_CLEAR);
	sk_exec("/bin/cat", "cat ./misc/header.txt", NULL);
	ft_putendl(C_OFF"\n\n");
	return (SUCCESS);
}
