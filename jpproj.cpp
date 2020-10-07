#include<bits/stdc++.h>
#include<vector>
using namespace std;

int mincost(vector <int> proj,vector <int> cost,int len)
{
    int start=0,sum=0,p,q=999999;
    int max = *max_element(proj.begin(),proj.end());
    cout<<"Max element in the proj vector is : "<<max<<endl;
    while(start<=max)
    {
        for(p=0;p<len;p++)
        {
            if(proj[p]==start)
            {
                if(cost[p]<q)
                {
                    q=cost[p];
                }
            }
        }

        sum=sum+q;
        ++start;
        q=9999999;
    }

    return sum;
}

int  main()
{
    vector<int> proj;
    vector<int> cost;

    int len,i,ele;
    cout<<"Enter length of proj and cost vector : ";
    cin>>len;
    cout<<"Enter proj elements : "<<endl;
    for(i=0;i<len;i++)
    {
        cin>>ele;
        proj.push_back(ele);
    }

    cout<<"Enter cost elements : "<<endl;
    for(i=0;i<len;i++)
    {
        cin>>ele;
        cost.push_back(ele);
    }

    cout<<"Enter projects and corresponding bids are : "<<endl;

    for(i=0;i<len;i++)
    {
        cout<<proj[i]<<" - "<<cost[i]<<endl;;
    }

    int minimum_cost = mincost(proj,cost,len);
    cout<<"Total cost (Minimum) for projects is : "<<minimum_cost<<endl;
}

