/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:16:57 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/17 18:00:40 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

int		sk_fork(char *cmd, char **array, char **env)
{
	pid_t	pid;

	if ((pid = fork()) == -1)
		return (FAILURE);
	if (pid == 0)
		execve(cmd, array, env);
	if (pid > 0)
		waitpid(pid, 0, 0);
	return (SUCCESS);
}

int		sk_exec_cmd(char *path, char *cmd, char **env)
{
	char	**array;

	if (!(array = ft_strsplit(cmd, ' ')))
		return (FAILURE);
	if (sk_fork(path, array, NULL))
	{
		ft_tabdel(array);
		return (FAILURE);
	}
	ft_tabdel(array);
	return (SUCCESS);
}
