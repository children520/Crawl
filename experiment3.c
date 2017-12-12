#include<unistd.h>
#include<signal.h>
#include<stdio.h>
void handler(){
	printf("hello\n");
}
void main()
{
	int i;
	signal(SIGALRM,handler);//传入警告钟信号，执行handler函数，返回原来的断点
	alarm(5);//设置信号经过5秒传送给当前的进程
	for(i=1;i<7;i++)
	{
		printf("sleep %d...\n",i);
		sleep(1);
	}
}
