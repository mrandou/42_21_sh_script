/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:12:05 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/13 18:16:46 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIFF_H
# define DIFF_H

# include "../libft/incs/libft.h"
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
#define C_OFF		"\033[0m"
#define AE_UP		"\033[A"
#define AE_DOWN		"\033[B"
#define ENTER		"\n"

#define SUCCESS	0
#define FAILURE	1
#define NO_TERM	2
#define ERROR	-1

typedef	struct		s_dlist
{
	void			*content;
	int				number;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef	struct		s_file
{
	t_dlist			*file1;
	t_dlist			*file2;
	int				max;
}					t_file;

void				put_column_str(struct s_dlist *f1, struct s_dlist *f2);

void				print_spaces(int nb);
void				print_nstr(char *str, int nb);
struct s_dlist		*reverse_dlst(struct s_dlist *dlist);
void				restore_files(struct s_file *files);

void				print_dlst(struct s_dlist *dlist);

int					set_shell_attributes(struct termios *backup);
int					term_exec(struct s_file *files);

void				dlst_push(t_dlist **dlist, char *content, int number);
struct s_dlist		*dlst_file_create(char *file);
void				dlst_free(t_dlist *dlist);

#endif
