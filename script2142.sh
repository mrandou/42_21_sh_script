#!/bin/bash

if [ ${#1} -eq 0 ]
then
	echo "Please enter the 21/42sh path...\nusage: sh script.sh 21/42sh_PATH"
	exit 1
fi
path=$1
ls $path
if [ $? -eq 1 ]
then
		echo "Please enter a good path for 21/42sh...\nusage: sh script.sh 21/42sh_PATH"
		exit 1
fi
echo "What test do you want ?"
select i in "Basics tests" "Hards tests" "Spams tests" "Target tests"; do
	if [ "$i" = "Basics tests" ]; then
		test="./files/test/basic_test.sh"
		break
	elif [ "$i" = "Hards tests" ]; then
		test="./files/test/hard_test.sh"
		break
	elif [ "$i" = "Spams tests" ]; then
		test="./files/test/spam_test.sh"
		break
	elif [ "$i" = "Target tests" ]; then
		sh ./files/test/target_test.sh $path
		exit 0
	else
		echo "Wrong answer, please select 1, 2, 3 or 4"
fi
done
bash < $test > ./files/output/output_bash
$path < $test > ./files/output/output_2142sh 
diff ./files/output/output_bash ./files/output/output_2142sh > result.txt
var1=`cat result.txt | grep -c "<"`
var2=`cat result.txt | grep -c ">"`
$var1 = $var1 + $var2
clear
echo "\033[32mScript Test for 21/42sh\n\033[0m"
echo "Your 21/42sh path: $path"
echo "1 --> bash result ; 2 --> 21/42sh result\n"
cat result.txt
if [ $var1 = 0 ]
	then
		printf "\033[32m"
		echo "\ndiff == OK :)"
		printf "\033[0m"
	else
		printf "\033[31m"
		echo "\ndiff == KO :("
		printf "\033[32m"
fi

#target_test in progress
