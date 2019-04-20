#!/bin/bash

printf "#Test: "$1"\n\n" > ./resources/scripts/results/output_bash
printf "#Test: "$1"\n\n" > ./resources/scripts/results/output_sh

bash < $1 >> ./resources/scripts/results/output_bash 2> /dev/null
$2 < $1 >> ./resources/scripts/results/output_sh 2> /dev/null

exit 0
