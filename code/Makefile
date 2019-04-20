# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 14:17:11 by mrandou           #+#    #+#              #
#    Updated: 2019/04/20 16:57:45 by mrandou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME		=		shake42

CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror

#######
# INC #
#######

INC_DIR		=		incs/

INC_NAME	=\
	shake42.h\

INC			=		$(addprefix $(INC_DIR), $(INC_NAME))

INC_DIR_ALL	=\
	$(INC_DIR)\

ICFLAGS		=		$(addprefix -I, $(INC_DIR_ALL))


#######
# SRC #
#######

SRC_DIR		=		srcs/

SRC_NAME	=\
					shake42.c \
					sk_fork.c \
					sk_menu.c \
					sk_menu_line.c \
					sk_path.c \
					sk_print.c \
					sk_start.c \
					sk_step.c \
					sk_term.c \
					sk_tools.c

SRC			=		$(addprefix $(SRC_DIR), $(SRC_NAME))

#######
# OBJ #
#######

OBJ_DIR		=		objs/

OBJ_NAME	=		$(SRC_NAME:.c=.o)

OBJ			=		$(addprefix $(OBJ_DIR), $(OBJ_NAME))

#######
# LIB #
#######

LDFLAGS		=		-Llibft

LIBFT_DIR = 		libft/

LDLIBS		=		-lft
LDIBS_DIR = $(LIBFT_DIR)incs
LIBFT = $(LIBFT_DIR)libft.a

SRC_LIBFT_NAME = $(shell make -C $(LIBFT_DIR) print-SRC)

SRC_LIBFT = $(addprefix $(LIBFT_DIR), $(SRC_LIBFT_NAME))
ICFLAGS		+=		$(addprefix -I, $(LDIBS_DIR))


########
# RULE #
########

all: 				$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@ $(LIBFT)
	@printf "Shake42 -- \033[34mCompilation Done ✓\n\033[0m"

$(LIBFT): $(SRC_LIBFT)
	@make -C libft

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)%.o:		 $(SRC_DIR)%.c ./Makefile $(INC)
	@$(CC) $(CFLAGS) $(ICFLAGS) -c $< -o $@
	@printf "> Shake42 <"
	@printf "\r\033[0m\n\033[K\033[A\033[K"
	


clean:
	@make -C libft clean
	@$(RM) $(OBJ)

fclean:
	@rm -rf $(OBJ_DIR)
	@make -C . clean

re: fclean all

print-%:
	@echo $($*)
