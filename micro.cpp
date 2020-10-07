#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{   
    int n,k,i,ch;
    cout<<"Enter number of prisoners:";
    cin>>n;
    int pricount=n;
    int a[n];
    cout<<"Enter number of chocolates:";
    cin>>k;
    int choccount=k;
    cout<<"Enter the chair number :";
    cin>>ch;

    for(i=0;i<n;i++)
    {
        a[i]=0;
    }

    if(k==0)
    {
        cout<<"Chair number warned is:  1"<<endl;

    }
    else
    {
        for(i=ch-1;;i++)
        {        
            a[(ch-1)%pricount]=a[(ch-1)%pricount]+1;
            choccount=choccount-1;
            if(choccount>0)
            {
                continue;        
            }
            else
            {
                break;
            }

        }

        cout<<"Chair number warned is:  "<<(i+1)%pricount<<endl;   
    }    
}