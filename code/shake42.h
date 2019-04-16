/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shake42.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:26:10 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/16 17:56:23 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAKE42_H
# define SHAKE42_H

# include "../diff/libft/incs/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <limits.h>
# include <term.h>
# include <termios.h>

#define C_RED		"\033[31m"
#define C_GREEN		"\033[32m"
#define C_BLUE		"\033[34m"
#define C_OFF		"\033[0m"
#define AE_UP		"\033[A"
#define AE_DOWN		"\033[B"
#define AE_CLINE	"\033[K"
#define AE_INVERSE	"\033[7m"
#define AE_CLEAR	"\033[1;1H\033[2J"
#define ENTER		"\n"
#define SPACE		" "

#define SH_PATH		".shake_shpath"

#define SUCCESS		0
#define FAILURE		1
#define NO_PRINT	2
#define ERROR		-1

int		sk_fork(char *cmd, char **array, char **env);
int		sk_exec(char *path, char *cmd, char **env);

int		sk_path(void);

int		sk_header(void);

#endif
