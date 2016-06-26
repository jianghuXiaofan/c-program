/*************************************************************************
    > File Name: pipe.c
    > Author: Bin_Xu
    > Mail: X_Shares@yeah.net 
    > Created Time: 2016年06月26日 星期日 21时55分30秒
 ***************************Never BUG To Code****************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int data_processed;
	int file_pipes[2];
	const char some_data[] = "123";
	char buffer[BUFSIZ + 1];
	pid_t fork_result;

	memset(buffer,'\0',sizeof(buffer));			//buff init;

	if(pipe(file_pipes) == 0){
		fork_result = fork();
		if(fork_result == -1){
			fprintf(stderr,"Fork failure");
			exit(EXIT_FAILURE);
		}
		if(fork_result == 0){		//child process
			data_processed = read(file_pipes[0],buffer,BUFSIZ);
			printf("Read %d bytes: %s\n",data_processed,buffer);
			exit(EXIT_SUCCESS);
		}
		else{
			data_processed = write(file_pipes[1],some_data,strlen(some_data));
			printf("Wrote %d by  bytes\n",data_processed);
		}
	}

	exit(EXIT_SUCCESS);
}
