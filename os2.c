#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	register int i;
	pid_t x;
	
	x=getpid();

	for(i=0;i<6;i++)
	{
		
		if(fork()==0)
		{
			if(i&1)
				setpgrp();
	
			while(1)
			{
				printf("\n\t (%dth) Child_Pid=%d GrpTd=%d parent_pid=%d",i,getpid(),getpgrp(),getppid());
				sleep(1);
			}
		}
	}
	
	
	if(x==getppid())
	{
		sleep(3);
		kill(0,SIGINT);
		
	}

	return 0;
}
