/*
M VENU GOPAL
17CS8064
OS LAB ASSIGNMENT 5
*/

#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/resource.h>

using namespace std;
int main()
{
    int i,n,x,nice,count=1;
    int pid,ret,priority;
    int which = PRIO_PROCESS;
    cout<<"ENTER NO OF CHILD ID: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        x=fork();
        if(x==0)
        {
            break;
        }
        else
        {
           cout<<x<<"   "<<getpid()<<endl;  
           pid=x;
           nice = getpriority(which, pid);    
           cout<<"NICE VALUE OF ABOVE PROCESS IS:"<<nice<<endl;

           priority = count;
           ret= setpriority(which, pid, priority);
           ret= getpriority(which, pid);    
           cout<<"NICE VALUE AFTER SETTING PRIORITY IS:"<<ret<<endl;

           cout<<endl;
        }
        count++;
    }
    for(i=0;i<1000;i++)
    {
        wait(NULL);
    }
    return 0;
}

