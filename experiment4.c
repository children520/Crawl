#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void waiting(),stop();
int wait_mark;
int main()
{
	int p1,p2,stdout=1;
	p1=fork();
	p2=fork();
	while(p1==-1);
	if(p1>0)
	{
	while(p2==-1)
		if(p2>0){
		wait_mark=1;
		signal(SIGINT,stop);
		waiting();
		kill(p1,16);
		kill(p2,17);
		wait(0);
		wait(0);
		printf("Parent process is killed\n");
		exit(0);
			}
		else{
			wait_mark=1;
	signal(17,stop);
	waiting();
	lockf(stdout,1,0);
	printf("child process 2 is killed by parent!\n");
	lockf(stdout,0,0);
	exit(0);
	}
	}
	else
	{
		wait_mark=1;
		signal(16,stop);
		waiting();
		lockf(stdout,1,0);
		printf("child progress 1 is killed by parent!\n");
		lockf(stdout,0,0);
		exit(0);
	}
	return 0;
}
void waiting(){
	while(wait_mark!=0);

}
void stop()
{
	wait_mark=0;
}

