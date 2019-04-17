/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:12:05 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/17 16:31:01 by mrandou          ###   ########.fr       */
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
#define AE_CLEAR	"\033[2J"
#define AE_CLINE	"\033[K"
#define AE_INVERSE	"\033[7m"
#define ENTER		"\n"
#define SPACE		" "

#define SUCCESS		0
#define FAILURE		1
#define NO_PRINT	2
#define ERROR		-1

typedef	struct		s_dlist
{
	void			*content;
	int				number;
	int				select;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef	struct		s_file
{
	t_dlist			*file1;
	t_dlist			*file2;
	int				max;
	struct winsize	window;
}					t_file;

void				print_compare_color(struct s_file *files);

void				put_column_str(struct s_dlist *f1, struct s_dlist *f2);

void				print_spaces(int nb);
void				print_ansi(char *ansi, int nb);
int					print_nstr(char *str, int nb);
struct s_dlist		*reverse_dlst(struct s_dlist *dlist);
void				reverse_files(struct s_file *files);

void				print_dlst(struct s_dlist *dlist);


void				print_select(struct s_file *files, int blink, char *color);
void				term_enter(struct s_file *files);
int					term_select(struct s_file *files);
int					term_exec(struct s_file *files);

int					set_shell_attributes(struct termios *backup);
int					term_check(char *buff, struct s_file *files);


void				dlst_push(t_dlist **dlist, char *content, int number);
struct s_dlist		*dlst_file_create(char *file);
void				dlst_free(t_dlist *dlist);

#endif
