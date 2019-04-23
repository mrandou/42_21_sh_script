# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/13 13:28:07 by mrandou           #+#    #+#              #
#    Updated: 2019/04/23 12:12:45 by mrandou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME		=		diff42

CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror

#######
# INC #
#######

INC_DIR		=		incs/

INC_NAME	=\
	diff.h\

INC			=		$(addprefix $(INC_DIR), $(INC_NAME))

INC_DIR_ALL	=\
	$(INC_DIR)\

ICFLAGS		=		$(addprefix -I, $(INC_DIR_ALL))


#######
# SRC #
#######

SRC_DIR		=		srcs/

SRC_NAME	=\
					diff.c \
					dlist.c \
					put_column_str.c \
					term_exec.c \
					term.c \
					tools.c

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
	@printf "Diff42 -- \033[33mCompilation Done ✓\n\033[0m"

$(LIBFT): $(SRC_LIBFT)
	@make -C libft

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)%.o:		 $(SRC_DIR)%.c ./Makefile $(INC)
	@$(CC) $(CFLAGS) $(ICFLAGS) -c $< -o $@
	@printf "> Diff42 <"
	@printf "\r\033[0m\n\033[K\033[A\033[K"
	
start: all
	./shake42

clean:
	@make -C libft clean
	@$(RM) $(OBJ)

fclean:
	@rm -rf $(OBJ_DIR)
	@make -C . clean

re: fclean all

print-%:
	@echo $($*)
