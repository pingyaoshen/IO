#### dup（重定向函数）

```c
//头文件
#include <unistd.h>
//函数原型
int dup(int oldfd);//oldfd 表示为想要重定向的文件句柄
//返回值
成功则返回指向该文件的新句柄，失败返回-1
*********************************************
//假如读取一个1.txt的文件，读取第一个字节，在用新句柄去读取，就不是从开头开始读，而是从第二个字节开始读取
```

#### dup2(重定向函数）

```c
//头文件
#include <unistd.h>
//函数原型
 int dup2(int oldfd, int newfd);//oldfd 表示为想要重定向的文件句柄
//返回值
newfd的值
*********************************************
//每个打开的文件或设备都有一个文件描述符，包括标准输入（stdin，fd 0）、标准输出（stdout，fd 1）和标准错误（stderr，fd 2）。这些是进程启动时自动打开的三个文件描述符，通常用于输入输出操作。例如dup2(fd, 1)；表示的是将标准输入重定于该fd所对应的文件。
**************************************************************************
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
	int fd2=dup2(fd, 1);//fd2=1 把标准输出重定向于fd 则接下来所有的标准输出都将输出到fd所对应的文件里面
	printf("fd2=%d\n", fd2);
	printf("hello world\n");
	return 0;
}
```

