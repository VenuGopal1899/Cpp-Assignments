#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include<stdlib.h>
#define MAX_SIZE 4096

int main (int argc, char const * argv []) 
{
	int n=200;
	int segment_id = shmget(IPC_PRIVATE, MAX_SIZE, S_IRUSR | S_IWUSR);
	int i;
	int *shared_memory = (int *) shmat(segment_id, NULL, SHM_RND);
	*shared_memory=1;
	pid_t x;
	while(n)
	{
		x=fork();
		if(x==0)
		{
			*shared_memory=*shared_memory+1;
			break;
		}
		n--;
	}
	if(x>0)
	printf("%d\ns",*shared_memory);
	return 0;
}
