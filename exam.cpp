#include<bits/stdc++.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;
int n=2;

int sumfun(int p,int q,int count)
{
    int sum;
    sum=p+q;
    cout<<"Child 1----Sum is  "<<sum<<endl;

}

int profun(int p,int q)
{
    int pro;
    pro=p*q;
    cout<<"Child 2----Product is  "<<pro<<endl;
}


int main()
{
    int i,x,p,q,count=0;
    cout<<"Enter numbers:"<<endl;
    cin>>p>>q;
    cout<<endl;

    while(n)
    {
        x=fork();
        if(x==0)
        {
            break;
        }
        else
        {
            wait(NULL);
            if(count==0)
            {
                sumfun(p,q,count++);
            }
            else
            {
                profun(p,q);
            }
            cout<<endl;
            
            cout<<x<<"  is child PID"<<"   "<<getpid()<<"  is parent PID"<<endl;
            cout<<endl;
        }
        n--;
    }

    return 0;
}

