#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include<stdlib.h>
#define MAX_SIZE 4096

int main (int argc, char const * argv []) {

	int segment_id = shmget(IPC_PRIVATE, MAX_SIZE, S_IRUSR | S_IWUSR);

	int i;
	int *shared_memory = (int *) shmat(segment_id, NULL, SHM_RND);
	for(i=0;i<20;i++)
		shared_memory[i]=0;



	pid_t pid = fork();
	if (pid == 0)
	{

		
		for(i=1;i<20;i+=2)
		{
			while(shared_memory[i-1]==0);
				shared_memory[i]=shared_memory[i-1]+10;
		}
				
		for(i=1;i<20;i+=2)
			printf("Child number %d has value %d\n",i+1,shared_memory[i]);
		

	}
	else
	{
		for(i=0;i<20;i+=2)
		{
				
				shared_memory[i]=rand()%10;
		}
				
		for(i=0;i<20;i+=2)
			printf("Parent number %d has value %d\n",i+1,shared_memory[i]);
		
	
	}
	float p=0,c=0;
	for(i=0;i<20;i++)
	{
		if(pid>0)
		{
			if(i%2==1)
				p+=shared_memory[i];
		}
		else
		{
			if(i%2==0)
				c+=shared_memory[i];
		}
	}
	if(pid>0)
	printf("Parent calculated %f\n",p/10);
	if(pid==0)
	printf("Child calculated %f\n",c/10);


	shmctl(segment_id, IPC_RMID, NULL);

	return 0;
}