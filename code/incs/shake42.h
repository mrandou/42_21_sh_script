/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shake42.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:26:10 by mrandou           #+#    #+#             */
/*   Updated: 2019/04/20 16:49:02 by mrandou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAKE42_H
# define SHAKE42_H

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
#define C_BLUE		"\033[34m"
#define C_OFF		"\033[0m"

#define AE_UP		"\033[A"
#define AE_DOWN		"\033[B"
#define AE_RIGHT	"\033[C"
#define AE_LEFT		"\033[D"

#define AE_CLINE	"\033[K"
#define AE_INVERSE	"\033[7m"
#define AE_CLEAR	"\033[1;1H\033[2J"
#define AE_CUR_OFF	"\033[?25l"
#define AE_CUR_ON	"\033[?25h"
#define AE_SELECT	AE_INVERSE C_GREEN
#define AE_UNSELECT	C_GREEN
#define ENTER		"\n"
#define SPACE		" "

#define SH_PATH		".shake_shpath"

#define	SP_TABS		"        "
#define NB_SP_TABS	8

#define SUCCESS		0
#define FAILURE		1
#define CONTINUE	2
#define RESET		4
#define ERROR		-1

typedef enum		e_actnum
{
	A_NOTHING,
	A_UP,
	A_DOWN,
	A_RIGHT,
	A_LEFT,
	A_ENTER
}					t_actnum;

typedef enum		e_selectnum
{
	SL_CHECK = 1,
	SL_OLDRESULT,
	SL_CHGPATH,
	SL_EXIT,
	SLC_OP = 1,
	SLC_RET,
	SLO_SPIPE = 1,
	SLO_OR,
	SLO_AMP,
	SLO_AND,
	SLO_REDIR_R,
	SLO_REDIR_L,
	SLO_BANG,
	SLO_SEMICOLON,
	SLO_RET
}					t_selectnum;

typedef enum		e_stepenum
{
	STP_MAIN_MENU,
	STP_CHECK,
	STP_CHGPATH,
	STP_OP
}					s_stepenum;

typedef struct		s_sk
{
	struct termios	backup;
	struct winsize	window;
	char			path[1024];
	int				action;
	int				select;
	int				step;
	int				act_max;
}					t_sk;

int		sk_fork(char *cmd, char **array, char **env);
int		sk_exec_cmd(char *path, char *cmd, char **env);

int		sk_path(char *path);
int		sk_path_reset(struct s_sk *sk);

int		sk_set_term_attributes(struct termios *backup);
int		sk_reset_term_attributes(struct termios *backup);

int		sk_header(void);
void	sk_print_nspace(int nb);
void	sk_print_ansi(char *ansi, int nb);
void	sk_reset(void);

void	sk_print_center(char *str, int col, char *color);

int		sk_step(struct s_sk *sk);
int		sk_step_check_tests(struct s_sk *sk);
int		sk_step_ct_operators(struct s_sk *sk);

void	sk_main_menu(struct s_sk *sk);
void	sk_check_tests_menu(struct s_sk *sk);
void	sk_ct_operators_menu(struct s_sk *sk);
void 	sk_menu_select(struct s_sk *sk);
int		sk_menu_blink(struct s_sk *sk);

void	sk_menu_line(struct s_sk *sk, char *mode);
void	sk_menu_line_main(int select);
void	sk_menu_line_check(int select);
void	sk_menu_line_ct_operators(int select);

void	sk_start_main_menu(struct s_sk *sk);
void	sk_start_check_test(struct s_sk *sk);
void	sk_start_ct_operators(struct s_sk *sk);

#endif
