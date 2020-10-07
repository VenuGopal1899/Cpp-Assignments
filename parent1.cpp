#include<bits/stdc++.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;

int main()
{
    int i,n,x;
    cout<<"ENTER THE LENGTH OF HEIRARCHY: ";
    cin>>n;
    while(n)
    {   
        x=fork();
        if(x!=0)
        {
            break;
        }
        else
        {
            cout<<"Child id is : "<<getpid()<<" parent id is : "<<getppid()<<endl;
        }
        n--;

    }

    sleep(100);
}