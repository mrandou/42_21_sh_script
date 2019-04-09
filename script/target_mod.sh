#!/bin/bash

path=$1
clear
COLUMNS=$(tput cols) 
title="21/42sh checker - Target Tests" 
printf "\033[34m%*s\033[0m\n\n" $(((${#title}+$COLUMNS)/2)) "$title"
printf "\033[32mWhat command ? > \033[0m"
read cmd
printf "\n\033[31mTest >: \033[0m"
echo $cmd
printf "\n"
echo $cmd > tmp_file

printf "\033[3m\033[32m--Bash Output--\033[0m\n"
bash < tmp_file > ./files/output/output_bash
cat ./files/output/output_bash

printf "\033[3m\033[32m\n--21/42SH Output--\033[0m\n"
$path < tmp_file > ./files/output/output_2142sh
cat ./files/output/output_2142sh

rm tmp_file
printf "\n"
diff ./files/output/output_bash ./files/output/output_2142sh > ./files/output/result.txt

var1=$(cat ./files/output/result.txt | grep -c "<")
var2=$(cat ./files/output/result.txt | grep -c ">")

if [ $var1 -eq 0 ]  && [ $var2 -eq 0 ]
	then
		printf "\033[32m"
		echo "\ndiff == OK :)"
		printf "\033[0m"
	else
		printf "\033[31m"
		echo "\ndiff == KO :("
		cat ./files/output/result.txt
		printf "\033[32m"
fi

printf "\n"
read -p "Please, press enter for continue or enter exit to quit target mod.......... " output
if [ "$output" = "" ]
	then
		sh ./script/target_mod.sh $path
		exit 0
	else
		exit 0
fi
