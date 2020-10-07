/*
M VENU GOPAL
17CS8064
OS LAB ASSIGNMENT 5
*/

#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
using namespace std;
int main(){
	int maxx=INT_MIN;
	pid_t x,z;
	int i,y;
    int n;
    cout<<"Enter number of children:";
    cin>>n;
	for(i=0;i<n;i++){
		x=fork();
		maxx=max(maxx,x);
		if(x==0){
			cout<<"Child Id : "<<getpid()<<" Return code : "<<i<<endl;
			exit(i);
		}
	}	
	z=waitpid(maxx,&y,0);
	cout<<"Child Process Id : "<<z<<" Return code : "<<(y/256)<<endl;
	return 0;
}
