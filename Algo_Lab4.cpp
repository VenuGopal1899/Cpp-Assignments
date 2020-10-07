/*
Coded By : M Venu Gopal
Roll No.: 17CS8064
National Institute of Technology Durgapur

*/
#include<bits/stdc++.h>
#define ll long long int
#define here cout<<"here\n"
#define pb push_back
#define mp make_pair
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf printf
#define pfi(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
using namespace std;

const ll mod = 1e9+7;

const int MAX = 100005;


void iterative(string s,int n)
{
int i,k;
    k=pow(3,n);
int count=0,cn=0;
    for(i=0;i<k;i++)
    {
    //cout<<s<<endl
    count=0;
    for(int l=0;l<n-2;l++)
    {
    if(s[l]=='a'&&s[l+1]=='b'&&s[l+2]=='c')
    count++;
    }
    if(count==1)
    {
    cn++;
    //cout<<s<<endl;
    }

    for(int j=n-1;j>=0;j--)
    {
    if(s[j]=='a'||s[j]=='b')
    {
    s[j]+=1;
    break;
    }
    else
    {
    if(s[j]=='b')
    s[j]-=1;
    else
    s[j]-=2;
    }

    }

    
    }
    cout<<cn<<endl;
}
int cn1=0;

int isValid(string s,int n)
{
        int count=0;
    for(int l=0;l<n-2;l++)
    {
    if(s[l]=='a'&&s[l+1]=='b'&&s[l+2]=='c')
    count++;
    }
    if(count==1)
    {
    return 1;
    //cout<<s<<endl;
    }
    else
    return 0;
}
void recursive(string s,int n)
{
if(s.size()==n)
{
       if(isValid(s,n))
       {
         cn1++;
       }
}
else
{
recursive(s+'a',n);
recursive(s+'b',n);
recursive(s+'c',n);
}
}
int cn2=0;
void efficient(int n)
{
ll s[n]={0};
s[0]=1;
s[1]=3;
s[2]=9;
for(int i=3;i<n-3;i++)
{
s[i]=pow(3,i)-(i-2)*(pow(3,i-3));
}

for(int i=0;i<n-3;i++)
{
cn2+=s[i]*s[n-i-3];
}
cout<<cn2<<endl;
for(int i=0;i<n;i++)
cout<<s[i]<<" ";
cout<<endl;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int i,k;
    k=pow(3,n);
    int j;
    string s="";
    recursive(s,n);
    cout<<"recursive = "<<cn1<<endl;
    for(i=0;i<n;i++)
    {
       s+='a';
    }
    //bool flag=true;

    cout<<"iterative = ";
    iterative(s,n);

    cout<<"\nRecursive = ";
    efficient(n);



return 0;
// print all combination of string of length n containing binary characters
}
