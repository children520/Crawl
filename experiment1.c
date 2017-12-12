#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(void)
{
    printf("创建新进程之前.\n");
    printf("这是父进程，输出为a,进程id is %d\n",getpid());
    pid_t pid1,pid2;      //文件标识符
    pid1=fork();
    

    if(pid1<0)
    {
      perror("创建子进程失败!\n");  
    }
    else if(pid1==0)
    	printf("这是子进程，输出为b,进程id is %d\n",getpid());
    else{
      pid2=fork();
      if(pid2<0)
     {
        perror("创建子进程失败!\n");  
     }
      else if(pid2==0)
    	printf("这是子进程，输出为c,进程id is %d\n",getpid());
	return 0;
    }
	
    
}
