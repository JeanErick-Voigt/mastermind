all: mastermind
mastermind: mastermind.c
	gcc -Wall -Wextra -Wpedantic -Wwrite-strings -wstack-usage=1024 -Wf;pat-equal -Waggregate-return -Winline -o mastermind mastermind.c
	
clean: mastermind


