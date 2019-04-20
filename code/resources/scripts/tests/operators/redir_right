#BINARY TEST
ls > file1 #content ls into file1
> empty_file
> em_file1 > em_file2 > em_file3 #all files empty
>1 #Should create file1
ls>wo_sp1>wo_sp2

#BUILTIN TEST
echo "42sh" > file2 > file3 > file4

#ARGUMENT TEST
ls > arg_test1 -l > arg_test2 -a > arg_test3 -F
ls > arg_test4 -laF > arg_test5 ..
>arg_1 ls >arg2 -a>arg3

#FILE ALREADY CREATED
touch file_exist
ls > file_exist > newfile -l

rm file1 file2 file3 file4 empty_file em_file1 em_file2 em_file3 arg_test1 arg_test2 arg_test3 arg_test4 arg_test5 arg_1 arg2 arg3