/*************************************************************************
    > File Name: sign.c
    > Author: Bin_Xu
    > Mail: X_Shares@outlook.com 
    > Created Time: 2016年06月25日 星期六 22时12分57秒
 ***************************Never BUG To Code****************************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_usr(int);
int main(void)
{
	if(signal(SIGUSR1,sig_usr) == SIG_ERR){
		printf("can`t catch SIGUSR1\n");
		exit(1);
	}
	if(signal(SIGUSR2,sig_usr) == SIG_ERR){
		printf("cat`t catch SIGUSR2\n");
		exit(1);
	}
	for(;;)
		pause();
}

static void sig_usr(int signo)
{
	if(signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if(signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
		printf("received signal %d\n",signo);
}
