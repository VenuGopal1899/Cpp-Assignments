//NAME : M VENU GOPAL
//ROLL NO:17CS8064
#include<iostream>
using namespace std;

int recurse(int n){
	if(n==1)
	return 1;
	else if(n==2)
	return 2;
	else if(n==3)
	return 4;
	else
	return recurse(n-1)+recurse(n-2)+recurse(n-3);
}

int main()
{
	int n,c;
	cin>>n;
	c=recurse(n);
	cout<<c<<endl;
	return 0;
	}
