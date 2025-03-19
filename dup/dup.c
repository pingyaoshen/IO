#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc,  char **argv)
{
	char *buff=(char *)malloc(128*sizeof(char));
	char *buff1=(char *)malloc(128*sizeof(char));
	char *buff2=(char *)malloc(128*sizeof(char));
	
	
	if(argc!=2)
	{
		printf("usage:%s<file>\n", argv[0]);
		return -1;
	} 
	int fd=open(argv[1], O_RDONLY);
	int fd2=open(argv[1], O_RDONLY);
	int fd3=dup(fd);
	if(fd<0)
	{
		printf("can not open:%s\n", argv[1]);
		return -1;
		
	}
	read(fd, buff, 1);
	read(fd2, buff1, 1);
	read(fd3, buff2, 1);
	printf("data get from fd :%c\n", buff[0]);
	printf("data get from fd2 :%c\n", buff1[0]);
	printf("data get from fd3 :%c\n", buff2[0]);
}
