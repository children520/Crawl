#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(void)
{
   int p1,p2;
   p1=fork();
while(p1==-1);
if(p1==0){
	lockf(1,1,0);
     	for(int i=0;i<5;i++)
		printf("这是子进程b,id is %d\n",getpid());
	lockf(1,0,0);
        
}
else
{
	 while(p2==-1);
	 p2=fork();
	 if(p2==0){
	   lockf(1,1,0);
	   for(int i=0;i<5;i++){
		   printf("这是子进程c,is %d\n",getpid());
	 	}
	   lockf(1,0,0);
	 }
	 else{
	 	lockf(1,1,0);
		for(int i=0;i<5;i++)
			printf("这是父进程a,is %d\n",getpid());
		lockf(1,0,0);
	 }
     
	
}
}


