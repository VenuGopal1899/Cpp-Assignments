/*
M VENU GOPAL
17CS8064
OS LAB ASSIGNMENT 3
*/


#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
using namespace std;
int search(int start, int end,int pass[],int val){
	for(int i=start;i<end;i++){
		if(pass[i]==val)
		{
			return i; 
		}
	}
	return 200;
}
int  main()
{
	int values[200];
	for (int i = 0; i < 200; i++)
	{
		int num = rand() % 200+1;
		values[i]= num;
	}
	for (int i = 0; i<200; i++){
		cout<<i<<": "<<values[i]<<endl;
	}	
	int val;
	cout<<"Enter the value to be searched: "<<endl;
	cin>>val;
	int n;
	cout<<"Enter the number of process: "<<endl;
	cin>>n;

	pid_t x;
	int parent;
	parent = getpid();
	for (int i=0;i<200; i = i+200/n){
		x = fork();
		if(x == 0) {
			int found_index = search(i, min(i+200/n-1, 200), values, val);
				exit(found_index);
		}
	}

	int ret = (200*256);
	pid_t child_ret = 0;
	while(ret == (200*256)&&child_ret!=-1)
		child_ret = wait(&ret);
    if(child_ret==-1)
        cout<<"value not present"<<endl;
    else
	    cout<<ret/256<<" "<<values[ret/256]<<endl;
	return 0;
}
