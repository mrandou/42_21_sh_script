/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:55:08 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/17 18:31:46 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shake42.h"

int		sk_path_is_valid(char *path)
{
	int			fd;
	char		tmp[1024];

	ft_bzero(tmp, 1024);
	if ((fd = open(SH_PATH, O_RDONLY)) == -1)
		return (FAILURE);
	if (read(fd, &tmp, 1024) == -1)
		return (FAILURE);
	ft_strcpy(path, tmp);
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

int		sk_path(char *path)
{
	char	pwd[1024];
	char	tmp[1024];
	int		error;

	error = 1;
	ft_bzero(path, 1024);
	if (sk_path_is_valid(path) == SUCCESS)
		return (SUCCESS);
	while (error)
	{
		ft_bzero(pwd, 1024);
		ft_bzero(tmp, 1024);
		ft_putstr("\nEnter a valid sh path > ");
		if (read(STDIN_FILENO, &tmp, 1024) == -1)
			return (FAILURE);
		tmp[ft_strlen(tmp) - 1] = '\0';
		if (!(getcwd(pwd, 1024)))
			return (FAILURE);
		ft_strcat(pwd, "/");
		if ((error = access(ft_strcat(pwd, tmp), F_OK)) == -1)
			perror(tmp);
		else
			ft_strcpy(path, pwd);
		if (sk_write_file(SH_PATH, path))
			return (FAILURE);
	}
	return (SUCCESS);
}
