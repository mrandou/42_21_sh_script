#!/bin/bash

path=$1
clear
printf "\033[31mTest >: \033[0m"
cmd="ls"
printf $cmd
printf "\n\n"

echo $cmd > tmp_file
bash < tmp_file > ./files/output/output_bash
$path < tmp_file > ./files/output/output_2142sh
rm tmp_file

printf "\033[32m--Bash Output--\033[0m\n"
cat ./files/output/output_bash
printf "\033[32m\n--21/42SH Output--\033[0m\n"
cat ./files/output/output_2142sh
printf "\n"
diff ./files/output/output_bash ./files/output/output_2142sh > result.txt

var1=$(cat result.txt | grep -c "<")
var2=$(cat result.txt | grep -c ">")

if [ $var1 -eq 0 ]  && [ $var2 -eq 0 ]
	then
		printf "\033[32m"
		echo "\ndiff == OK :)"
		printf "\033[0m"
	else
		printf "\033[31m"
		echo "\ndiff == KO :("
		cat result.txt
		printf "\033[32m"
fi
