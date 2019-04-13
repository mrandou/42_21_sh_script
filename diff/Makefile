# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/13 13:28:07 by mrandou           #+#    #+#              #
#    Updated: 2019/04/13 14:46:29 by mrandou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	diff42
LIBFT	=	./libft/

INC_DIR	=	./incs/
SRC_DIR	=	./srcs/

FILES	=	diff.c tools.c put_column_str.c

CPPFLAGS	=	-Iincludes
LDFLAGS		=	-Llibft
LDLIBS		=	-lft
CC			=	gcc
CFLAGS		=	-Werror -Wextra -Wall
TFLAGS		=	-ltermcap
MAKEFILE	=	./Makefile

all: compile

$(NAME):	

compile:
		make -C $(LIBFT)
		make $(NAME)
