# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    operators.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrandou <mrandou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 17:42:14 by mrandou           #+#    #+#              #
#    Updated: 2019/04/11 18:21:32 by mrandou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

printf "\nSelect: \n"

tab[0]="|"
tab[1]="||"
tab[2]="&"
tab[3]="&&"
tab[4]="!"

printf "\nWhat operator would you want to test ? [|, ||, &, &&, !] > "
read value

for i in `seq 0 5`
do
	op=${tab[$i]}
	if [ "$op" = $value ]
		then
			exit $i
	fi
done

printf "\nError, please select a good operator !\n"
sh ./script/checks/operators.sh
