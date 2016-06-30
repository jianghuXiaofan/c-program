#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	if(pid < 0){
		printf("fork error\n");
		exit(1);
	}
	if(pid == 0){
		for(;;){
			sleep(10);
			system("clear");
		}
	}
	else{
		for(;;){
			printf("clear\n");
			sleep(1);
		}
	}
	exit(0);
}
