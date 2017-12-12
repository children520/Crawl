#include "stdio.h"
#include "string.h"
#define size 128
#define N 12
typedef struct
{
	int pagenum;
	int flag;
	int block;
	int location;
}tacle;

typedef struct
{
	char ope[10];
	int pagenum;
	int address;

}list;
table p1[7]
{
	{0,1,5,11},{1,1,8,12},{2,1,9,13}
	{3,1,1,21}{4,0,NULL,22},{5,0,NULL,23},{6,0,NULL,121}
};

void main()
{
	list p2[N];
	int i,page,flag,memaddress;
	printf("the operating command has(+,-,*,int,out,displace)\n");
	for(i=0;i<N;i++)
	{
		printf("enter the command:\nope=");
		scanf("%s",&p2[i].ope);
		printf("pagename=");
		scanf("%d",&p2[i].pagenum);
		printf("Unitnum=");
		scanf("%d",&p2[i].address);
		page=p2[i].pagenum;
		flag=p1[page].flag;
		if(flag==0&&p2[i].pagenum<7)
		{
			printf("*pagenum=%d Page fault generated\n\n",p2[i].pagenum);
		}
		else if(p2[i].pagenum<7)
		{
			memaddress=p1[page].block*size+p2[i].address;
			printf("memaddress=block(%d)*size(%d)+address(%d);\n memaddress=%ld\n\n",p1[page].block,size,p2[i].address,memaddress);
		}
		eles
			printf("page over!again\n");
	}
}

