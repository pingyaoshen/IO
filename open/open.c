#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	if(argc!=2)
	{ 
		printf("usage : %s <file>\n", argv[0]);
		return -1;
	}
	int fd=open(argv[1], O_RDWR|O_CREAT);
	if(fd<0)
	{
		printf("errro:%s, errorno:%d\n",strerror(errno),errno);
		
		return -1;
	}
	while(1)
	{
		sleep(10);
		
	}
	return 0;
}

