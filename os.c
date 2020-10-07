#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>
#include<unistd.h>

int main()
{
	pid_t x,y;
	int r;
	
	x=fork();
	if(x==0)
	{
		printf("Child_id=%d Parent_id=%d\n",getpid(),getppid());	
		exit(5);
	}
	else
	{
		y=wait(&r);
		printf("Parent %d value of r %d\n",getppid(),r/256);
	}
	return 0;
}
