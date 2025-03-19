#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc,  char **argv)
{
	
	
	if(argc!=2)
	{
		printf("usage:%s<file>\n", argv[0]);
		return -1;
	} 
	int fd=open(argv[1], O_RDWR);
	int fd2=dup2(fd, 1);
	printf("fd2=%d\n", fd2);
	printf("hello world\n");
	return 0;
}
