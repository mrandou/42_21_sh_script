/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:55:08 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/16 17:56:27 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

int		sk_path_is_valid(void)
{
	int			fd;
	char		path[1024];

	if ((fd = open(SH_PATH, O_RDONLY)) == -1)
		return (FAILURE);
	if (read(fd, &path, 1024) == -1)
		return (FAILURE);
	if (access(path, F_OK) == -1)
		return (FAILURE);
	close (fd);
	return (SUCCESS);
}

int		sk_write_file(char *file, char *str)
{
	int		fd;

	if ((fd = open(file, O_WRONLY | O_CREAT, S_IREAD | S_IWRITE)) == -1)
		return (FAILURE);
	if (write(fd, str, ft_strlen(str)) == -1)
		return (FAILURE);
	close(fd);
	return (SUCCESS);
}

int		sk_path(void)
{
	char	path[1024];
	char	pwd[1024];
	int		error;

	error = 1;
	if (sk_path_is_valid() == SUCCESS)
		return (SUCCESS);
	while (error)
	{
		ft_bzero(path, 1024);
		ft_putstr("\nEnter a valid sh path > ");
		if (read(STDIN_FILENO, &path, 1024) == -1)
			return (FAILURE);
		path[ft_strlen(path) - 1] = '\0';
		if (!(getcwd(pwd, 1024)))
			return (FAILURE);
		ft_strcat(pwd, "/");
		ft_strcat(pwd, path);
		if ((error = access(pwd, F_OK)) == -1)
			perror(path);
		if (sk_write_file(SH_PATH, pwd))
			return (FAILURE);
	}
	return (SUCCESS);
}
