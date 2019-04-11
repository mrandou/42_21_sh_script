# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    select.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 17:37:09 by mrandou           #+#    #+#              #
#    Updated: 2019/04/11 18:40:41 by mrandou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

path=$1

printf "\n\033[32m"
printf "What test do you want ?\033[0m\n"
select i in "Operators"; do
	if [ "$i" = "Operators" ]; then
		sh ./script/checks/operators.sh
		ret=$?
		if [ "$ret" = 0 ]; then
			test="./files/test/operators/simple_pipe.sh"
		elif [ "$ret" = 1 ]; then
			test="./files/test/operators/op_or.sh"
		elif [ "$ret" = 2 ]; then
			test="./files/test/operators/op_esp.sh"
		elif [ "$ret" = 3 ]; then
			test="./files/test/operators/op_and.sh"
		elif [ "$ret" = 4 ]; then
			test="./files/test/operators/op_bang.sh"
		fi
		break	
	else
		echo "Wrong answer"
	fi
done

bash < $test > ./files/output/output_bash
$path < $test > ./files/output/output_2142sh 
