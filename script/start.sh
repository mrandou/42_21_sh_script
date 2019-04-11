# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 17:37:34 by mrandou           #+#    #+#              #
#    Updated: 2019/04/11 17:37:35 by mrandou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

clear
COLUMNS=$(tput cols) 
title="Welcome to 21/42sh checker !" 
printf "\033[34m%*s\033[0m\n\n" $(((${#title}+$COLUMNS)/2)) "$title"
printf "\033[32m\033[3mMain menu\033[0m\n"
select i in "Tests" "Target Mod" "Results" "Exit"; do
	if [ "$i" = "Tests" ]; then
		exit 1
	elif [ "$i" = "Target Mod" ]; then
		exit 2
	elif [ "$i" = "Results" ]; then
		exit 3
	elif [ "$i" = "Exit" ]; then
		exit 0
	else
		printf "Wrong answer, please select 1, 2, 3 or 4\n\n"
	fi
done
exit 0
