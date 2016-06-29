#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 	30
int main(void)
{
	char wr_buf[] = "This is the first line";
	char rd_buf[SIZE];
	int fd;
	int wr_cnt;
	fd = open("file.bat",O_CREAT | O_RDWR);		//if the file has existed,open faild
	if(fd <0){
		printf("open error\n");
		exit(1);
	}
	wr_cnt = write(fd,wr_buf,strlen(wr_buf));
//	lseek(fd,-(wr_cnt),SEEK_CUR);			//set file point to the start
	lseek(fd,0,SEEK_SET);			//other way to set file point to the stat
	read(fd,rd_buf,wr_cnt);
	printf("%s\n",rd_buf);
	exit(0);
}
