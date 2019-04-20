/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:16:57 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/20 18:43:17 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/shake42.h"

int		sk_fork(char *cmd, char **array, char **env)
{
	pid_t	pid;

	if ((pid = fork()) == -1)
		return (FAILURE);
	if (pid == 0)
		if (execve(cmd, array, env) == -1)
			return (FAILURE);
	if (pid > 0)
		if (waitpid(pid, 0, 0) == -1)
			return (FAILURE);
	return (SUCCESS);
}

int		sk_exec_cmd(char *path, char *cmd, char **env)
{
	char	**array;

	if (!(array = ft_strsplit(cmd, ' ')))
		return (FAILURE);
	if (sk_fork(path, array, env))
	{
		ft_tabdel(array);
		return (FAILURE);
	}
	ft_tabdel(array);
	return (SUCCESS);
}

int		sk_exec_script(char *path, char *test, char **env)
{
	char	*str;
	char	*tmp;

	if (!(tmp = ft_strmjoin(LAUNCHER, " ", test)))
		return (FAILURE);
	if (!(str = ft_strmjoin(tmp, " ", path)))
	{
		ft_strdel(&tmp);
		return (FAILURE);
	}
	ft_strdel(&tmp);
	if (sk_exec_cmd(LAUNCHER, str, env))
	{
		ft_strdel(&str);
		return (FAILURE);
	}
	ft_strdel(&str);
	return (SUCCESS);
}
