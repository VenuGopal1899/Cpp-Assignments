//NAME : M VENU GOPAL
//ROLL :17CS8064
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int fact(int n)
{
	if(n==0)
	return 1;
	else if(n==1)
	return 1;
	else
	return n*fact(n-1);
}

int main()
{
	int n,m;
	int x,y,z;
	long long int k,sum=0;
	cin>>n>>m;//n=length,m=steps
	z=((n-m)/2);
	while(z>0){
		y=n-m-2*z;
		x=m-y-z;
		if((x>=0) && (y>=0)){
			k=fact(m)/(fact(x)*fact(y)*fact(z));
			sum=sum+k;
			}
		z--;
		}
	cout<<sum<<endl;
	return 0;
}
