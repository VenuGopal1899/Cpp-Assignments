#include<bits/stdc++.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;

int main()
{
    int i,n,x;
    
    cout<<"ENTER NO OF CHILD ID: ";
    cin>>n;
    FILE *name;
    name=fopen("childlog.txt","rw+");
    while(n)
    {
        x=fork();
        if(x==0)
        {
            break;
        }
        else
        {
            cout<<x<<"  is child PID"<<"   "<<getpid()<<"  is parent PID"<<endl;
            if(x%2==0)
            {
                cout<<"HELLO"<<endl;
            }
            else
            {
                cout<<"WORLD"<<endl;
            }
            
        }
        fprintf(name,"%d is child pid  %d is parent pid \n",x,getpid());
        fprintf(name,"\n");
        cout<<endl;
        n--;

    }

    for(int i=0;i<n;i++)
    {
        wait(NULL);
    }
   
    return 0;
}
