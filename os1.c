#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	pid_t x,z;
	int i,y;
	signal(SIGCLD,SIG_IGN);

	for(i=0;i<4;i++)
	{
		x=fork();
		
		if(x==0)
		{
			printf("\n\t chid pid=%d ret_code=%d\n",getpid(),i+1);
			exit(i+1);
		}
	}
	
	z=wait(&y);
	printf("parent_pid=%d sync with chid_id=%d ret_code=%d\n",getpid(),z,y/256);


	return 0;
}
