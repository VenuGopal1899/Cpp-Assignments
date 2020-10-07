#include<bits/stdc++.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;

int main()
{
    int i,n,x;
    int temp=1;
    cout<<"Enter number of levels : ";
    cin>>n;

    while(temp<=n)
    {
    
        cout<<getpid()<<" is child PID "<<getppid()<<" is parent PID"<<endl;
        cout<<endl;
        if(getpid()%5==0)
        {
            cout<<endl;
            cout<<getpid()<<" is child PID "<<getppid()<<" is parent PID"<<endl;
            cout<<endl;

            temp++;
        }
        else if(getpid()%2==0 && getpid()%5!=0)
        {
            for(i=0;i<2;i++)
            {
                x=fork();
                if(x==0)
                {
                    break;
                }
                else
                {
                    cout<<x<<"  is child PID "<<"   "<<getpid()<<"  is parent PID"<<endl;
                }
            }

            temp++;
        }
        else if (getpid()%2!=0 && getpid()%5!=0)
        {
            x=fork();
            if(x==0)
            {
                break;
            }
            else
            {
                cout<<x<<"  is child PID "<<"   "<<getpid()<<"  is parent PID"<<endl;
            }

            temp++;
            
        }

    }

    sleep(100);
    
}

