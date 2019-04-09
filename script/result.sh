#!/bin/bash

printf "\n\033[32m\033[3mBash output : \n\033[0m"
cat ./files/output/output_bash
printf "\n\033[32m\033[3m21/42sh output : \n\033[0m"
cat ./files/output/output_2142sh
printf "\n\033[32m\033[3mDiff Results : \n\033[0m"
cat ./files/output/result.txt

nb=`cat ./files/output/result.txt | grep -c \"\"`
if [ $nb -eq 0 ]
then
	echo "No differents, everything is fine !"
fi
exit 0