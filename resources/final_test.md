r0th@r0th:~/git/forty/pipex$ bash tester_pipex.sh 
------------------------------------
------------------------------------
	PIPEX TESTER
Started at 20:42 - 15 February 2026
by htoe on linux os
made by bguillau (@bastienkody)
------------------------------------
------------------------------------
Mandatory tests
Test norminette: 							--> norm ok
Test Makefile: 								--> no make error -- no relink -- exec named pipex
Test arg nb (<4): 							--> pipex wrote on std err (fd 2) 
Basics:
Test 1 : ./pipex Makefile ls ls t1_output 				--> OK (return status == 0)
Test 2 : ./pipex Makefile cat cat t2_output 				--> OK (return status == 0)
Test 3 : ./pipex Makefile "cat -e" "head -n3" t3_output			--> OK (return status == 0)
Absolut path cmd:
Test 1 : ./pipex Makefile /usr/bin/ls /usr/bin/cat t1_output 			--> OK (return status == 0)
Test 2 : ./pipex Makefile "/usr/bin/tail -n15" "/usr/bin/head -n6" t1_output	--> OK (return status == 0)
Absolut path cmd not found:
Test 1 : ./pipex Makefile /usr/bin/lsoip /usr/bin/cati outf 		--> OK Stderr: output. Stdout: no output. (err msg) (return status != 127)
Test 2 : ./pipex Makefile "touch OUI" /usr/bin/cati outf 		--> OK. (err msg ok) (return status != 127)
Test 3 : ./pipex Makefile /usr/bin/cati "touch OUI" outf 		--> OK. (err msg ok) (return status == 0)
Cmd not found:
Test 1 : ./pipex Makefile lsoip cati outf 				--> OK Stderr: output. Stdout: no output. (err msg) (return status == 127)
Test 2 : ./pipex Makefile "touch OUI" cati outf 			--> OK. (err msg) (return status == 127)
Test 3 : ./pipex Makefile cati "touch OUI" outf 			--> OK. (err msg) (return status == 0)
Empty cmd:
Test 1 : ./pipex Makefile " " " " outf 					--> OK Stderr: output. Stdout: no output. (not 2 err msg with "Command not found") (return status != 127)
Test 2 : ./pipex Makefile "touch OUI" " " outf 				--> KO. (err msg without "Command not found") (return status != 127)
Test 3 : ./pipex Makefile " " "touch OUI" outf 				--> KO. (err msg without "Command not found") (return status != 0)
Infile no readable:
Test 1 : ./pipex infile_r "touch truc" "touch truc2" t1_output		--> OK. (return status == 0)
Test 2 : ./pipex infile_no_r "touch NON" "touch OUI" t2_output		--> OK. (err msg) (return status == 0)
Test 3 : ./pipex infile_no_r lsop "echo yo" t2_output			--> OK. (err msg) (return status == 0)
Outfile no writable:
Test 1 : ./pipex Makefile "touch truc" "touch truc2" outfile_w 		--> OK. (return status == 0)
Test 2 : ./pipex Makefile "touch OUI" "touch NON" outfile_no_w 		--> OK. (err msg) (return status == 1)
Test 3 : ./pipex Makefile "touch OUI" lsop outfile_no_w 		--> OK. (err msg) (return status == 1)
Outfile created before exec:
Test 1 : ./pipex Makefile cat ls outf 					--> OK
Test 2 : ./pipex Makefile ls cat outf 					--> OK
Concurrency of cmds:
Test 1 : ./pipex Makefile yes "echo yo" outf 				--> OK (return status == 0)
Test 2 : ./pipex Makefile "sleep 2" "sleep 1" outf 			--> OK (return status == 0)
Test 3 : ./pipex Makefile yes cati outf 				--> (err msg Cmd not found ok) (return status == 127)
Test 4 : ./pipex Makefile yes cati outfile_no_w 			--> (err msg Perm denied ok) (return status == 1)
Custom exec:
Test 1 : ./pipex Makefile ./a.out cat outf 				--> OK (return status == 0)
Test 2 : ./pipex Makefile ls ./ls outf 					--> OK (return status == 0)
Test 3 : ./pipex Makefile date dir1/dir2/ls outf			--> OK (return status == 0) 
Test 4 : ./pipex Makefile ls ./a.out (chmod u-x) outf 			--> KO (code != 126). (err msg permission denied)
Empty environnement:
Test 1 : env -i ./pipex Makefile cat ls outf 				--> (return status != 127)
Test 2 : env -i ./pipex Makefile /usr/bin/cat /usr/bin/cat outf		--> OK (return status == 0)
$PATH unset:
Test 1 : unset PATH && ./pipex Makefile cat ls outf 			--> KO (not two lines written to stderr)(return status != 127)
Test 2 : unset PATH && ./pipex Makefile /usr/bin/cat /usr/bin/cat outf 	--> OK (return status == 0)
Leaks via valgrind:
Test 1 : valgrind ./pipex Makefile cat cat outf 			--> no leak cat - no leak cat - no leak main - no extra fd (main+child) - no extra fd on main
Test 2 : valgrind ./pipex Makefile yes head outf 			--> 18,548 leaks yes (it's ok) - no leak head - no leak main - no extra fd (main+child) - no extra fd on main
Test 3 : valgrind ./pipex Makefile /usr/bin/cat /usr/bin/head outf 	--> no leak cat - no leak head - no leak main - no extra fd (main+child) - no extra fd on main
Test 4 : valgrind ./pipex infile_no_r cat "echo yo" outfile_no_w 	--> no leak cat - no leak echo - no leak main - no extra fd (main+child) - no extra fd on main
Test 5 : valgrind ./pipex Makefile catiop " " outf 			--> no leak catiop - no leak empty cmd - no leak main - no extra fd (main+child) - no extra fd on main
Test 6 : valgrind ./pipex Makefile ./a.out (chmod u-x) "echo yo" outf 	--> no leak a.out - no leak echo - no leak main - no extra fd (main+child) - no extra fd on main
Zombies (children process not waited by pipex):
cc1: fatal error: popo.c: No such file or directory
compilation terminated.
Test 1 : ./pipex Makefile "sleep 3" "sleep 1" outf 			--> OK (sleep 1 did not became a zombie)
Test 2 : ./pipex Makefile "sleep 1" "sleep 3" outf 			--> KO: 1 process became a zombie before pipex returned (most probably sleep 1, please check 'zombie_test2')
Test 3 : ./pipex bad_infile ls "sleep 2" outf 				--> KO: 1 process became a zombie before pipex returned (most probably ls, please check 'zombie_test3')
Test 4 : ./pipex Makefile bad_cmd "sleep 1" outf 			--> KO: 1 process became a zombie before pipex returned (most probably bad_cmd, please check 'zombie_test4')
Bonus tests
Bonus multi cmds:
Test 1 : ./pipex Makefile cat cat cat t2_output					--> OK (+ return status == 0)
Test 2 : ./pipex Makefile ls cat cat cat cat cat cat cat cat cat cat t2_output	--> OK (+ return status == 0)
Test 3 : ./pipex Makefile yes headi pwd "cat -e" t2_output			--> OK (+ err msg) (+ return status == 0)
Test 4 : ./pipex Makefile date "man env" cat "grep -i exit" t2_output		--> OK (+ return status == 0)
Test 5 : ./pipex Makefile cat ls "sleep 3" date env ls outf 			--> OK (no zombie)
Test 6 : valgrind ./pipex Makefile cat cat cat cat cat cat outf			--> no leak - no extra fd (main+child) - no extra fd on main
Bonus here_doc:
Test 1 : ./pipex here_doc lim cat cat outf (to create + tests limiteur)		--> OK (return status == 0)
Test 2 : ./pipex here_doc lim cat cat outf (to append)				--> OK (return status == 0)
Test 3 : ./pipex here_doc lim cat outf (arg<5)					--> OK (return status > 0)
Test 4 : ./pipex here_doc lim cat cat "head -n2" outf (multicmd)		--> OK (return status == 0)
Test 5 : ./pipex here_doc lim cat cat outf_no_w					--> OK (return status == 1)
Test 6 : ./pipex here_doc lim lsopi "echo yo" outf 				--> OK (return status == 0)
Test 7 : valgrind ./pipex here_doc lim cat cat outf 				--> no leak cat - no leak cat - no leak main - no extra fd (main+child) - no extra fd on main
Additional tests (not all required to pass to validate pipex)
Single quotes parsing:
Test 1 : ./pipex Makefile "echo yo" "echo 'a' 'b' 'c'" outf 		--> KO (return status == 0)
Test 2 : ./pipex Makefile cat "grep 'clean'" outf 			--> KO (return status != 0)
Test 3 : ./pipex Makefile cat "cut -d'=' -f1" outf 			--> KO (return status != 0)
Test 4 : ./pipex Makefile cat "echo ''yo'" outf 			--> OK (return status == 0)
Spaces parsing:
Test 1 : ./pipex Makefile "echo yo" "echo ' '" outf 			--> KO (return status == 0)
Test 2 : ./pipex Makefile "echo yo" "echo ' hello '" outf 		--> KO (return status == 0)
Test 3 : ./pipex Makefile cat "cut -d' ' -f1" outf 			--> KO (return status != 0)
Test 4 : touch "t file" && ./pipex Makefile cat "ls 't file'" outf 	--> KO (return status != 0)
Backlash parsing:
Test 1 : touch t\ file && ./pipex Makefile cat "ls t\ file" outf 	--> KO (return status != 0)
Test 2 : touch 't\ file' && ./pipex Makefile cat "ls 't\ file'" outf 	--> KO (return status != 0)
Reaching 1024 fd openned:
Test 1 : ./pipex Makefile cat (510 times) outf 				--> OK (return status == 0) (no segfault)
Test 2 : ./pipex Makefile cat (511 times) outf 				--> KO (return status == 0) (err msg with open files) (no segfault)
Test 3 : ./pipex Makefile cat (521 times) outf 				--> KO (return status == 0) (err msg with open files) (no segfault)
