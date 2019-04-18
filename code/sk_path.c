/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:55:08 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/18 16:05:54 by mrandou          ###   ########.fr       */
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
	if (write(fd, "\0", 1) == -1)
		return (FAILURE);
	close(fd);
	return (SUCCESS);
}

int		sk_path_request(char *path)
{
	int		error;
	char	tmp[1024];
	char	pwd[1024];

	error = 1;
	while (error)
	{
		ft_bzero(pwd, 1024);
		ft_bzero(tmp, 1024);
		ft_putstr(C_GREEN "\n"SP_TABS"Please enter a SH path\n"SP_TABS"    > ");
		if (read(STDIN_FILENO, &tmp, 1024) == -1)
			return (FAILURE);
		tmp[ft_strlen(tmp) - 1] = '\0';
		if ((error = access(tmp, F_OK)) == -1)
		{
			if (!(getcwd(pwd, 1024)))
				return (FAILURE);
			ft_strcat(pwd, "/");
			if ((error = access(ft_strcat(pwd, tmp), F_OK)) == -1)
				ft_putendl(C_RED"\n"SP_TABS"Error. Try again with a valid path");
			else
				ft_strcpy(path, pwd);
		}
		else
			ft_strcpy(path, tmp);
		ft_putstr(C_OFF);
		if (sk_write_file(SH_PATH, path))
			return (FAILURE);
	}
	return (SUCCESS);
}

int		sk_path(char *path)
{
	ft_bzero(path, 1024);
	if (sk_path_is_valid(path) == SUCCESS)
		return (SUCCESS);
	if (sk_path_request(path))
		return (FAILURE);
	return (SUCCESS);
}

int		sk_path_reset(struct s_sk *sk)
{
	ft_bzero(sk->path, 1024);
	sk_reset_term_attributes(&sk->backup);
	ft_putstr(AE_CUR_ON);
	if (sk_path_request(sk->path))
		return (FAILURE);
	sk_set_term_attributes(&sk->backup);
	ft_putstr(AE_CUR_OFF);
	return (SUCCESS);
}
