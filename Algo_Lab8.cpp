#include<bits/stdc++.h>
#include<iostream>
using namespace std;


struct Pair 
{
    int start,end;
};

struct Node 
{
    Pair interval;
    int count=0,max=0;
    Node *right=NULL,*left=NULL; 
};

int intervalcmp(Pair i,Pair j)
{
    if(i.start==j.start)
    {
        if(i.end==j.end)
        {
            return 0;
        }
        else if(i.end<j.end)
        {
            return -1;
        }
    }
    else if(i.start<j.start)
    {
        return -1;
    }
    else
    {
        return 1;
    }

}

Node* insert(Node *root, Pair interval )
{ 
    struct Node *leaf_node=(struct Node*)malloc(sizeof(Node));
    leaf_node->interval=interval;
    leaf_node->right=NULL;
    leaf_node->left=NULL;
    cout<<"hyy2"<<endl;
    if(root==NULL)
    {
        cout<<"hyy3"<<endl; root=leaf_node;
    }
 //   cout<<root->interval.start<<" "<<root->interval.end<<endl;
    cout<<"hyy4"<<endl;
    switch(intervalcmp(root->interval,interval))
    {
        case 0 :  cout<<"hyy5"<<endl; root->count+=1;
                  break;
        case -1 : cout<<"hyy6"<<endl; root->right=insert(root->right,interval );
                  break;
        case 1:   if(root->left==NULL)
                  { 
                      cout<<"hyy1"<<endl; 
                  }
                  root->left=insert(root->left,interval );
                  break;
    }

   return root;
}

int overlapcnt(Pair interval, Node *root) 
{   
    int sum=0;
    if(root!=NULL)
    {
        if(interval.start > root->interval.end) 
        {
            sum+=overlapcnt(interval,root->right);
        } 
        else if(interval.end < root->interval.start)
        {
            sum+=overlapcnt(interval,root->left);
        }
        else
        {
            sum=sum+root->count;
            sum+=overlapcnt(interval,root->right);
            sum+=overlapcnt(interval,root->left);
        }
    }

    return sum;
}


int minclassroomcnt(Node *root)
{
    //traverse tree and make an array of nodes
    //apply overlapcnt for a node in the array and all other nodes to the left
    //return max out of them
}



int main()
{
    int k,s;
    Pair obj1,obj2;
    //struct Node *bst=(struct Node*)malloc(sizeof(int));
    Node *bst = NULL;
    
    while(1)
    {
        cout<<"Enter choice 0 to enter and 1 to use overlap function  and 2 to exit :  ";
        cin>>k;
        switch(k)
        {
            case 0:   cout<<"ENTER PAIR Start and end time:"<<endl;
                      cin>>obj1.start>>obj1.end;
                      bst=insert(bst,obj1);
                      break;
            case 1:   cout<<"ENTER PAIR Start and end time for over lapping :"<<endl;
                      cin>>obj2.start>>obj2.end;
                      s=overlapcnt(obj2,bst);
                      cout<<s<<"  is the number of intervals overlapped"<<endl;
                
            case 2:   exit(0);
        }
    }

}