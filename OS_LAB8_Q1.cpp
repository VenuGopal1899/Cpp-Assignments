#include<bits/stdc++.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;

int main()
{
    int i,n,x,num,ran;
    cout<<"ENTER NUMBER : ";
    cin>>num;
    cout<<"ENTER NO OF CHILD ID: ";
    cin>>n;

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
                //even child
                ran=rand()%10;
                num=num-ran;
                cout<<"THIS IS EVEN CHILD DECREMENTED BY  "<<ran<<"   FINAL RESULT IS  "<<num<<endl;
            }
            else
            {
                // odd child
                ran=rand()%10;
                num=num+2*ran;
                cout<<"THIS IS ODD CHILD INCREMENTED BY  "<<2*ran<<"   FINAL RESULT IS  "<<num<<endl;
            }
            
        }
        cout<<endl;
        n--;

    }
    
    for(int i=0;i<n;i++)
    {
        wait(NULL);
    } 
   
  
    cout<<endl;

   
    return 0;
}