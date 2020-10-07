//NAME : M VENU GOPAL
//ROLL : 17CS8064
#include<iostream>
using namespace std;
struct point
{
	int x,y;
};
void sol1(int n,point A[])
{
	cout<<endl<<"Superiority count with O(n^2): ";
	for(int i=0;i<n;i++)
	{
		int sup_count=0;
		for(int j=0;j<n;j++)
		{
			if(j!=i && (A+i)->x>(A+j)->x && (A+i)->y>(A+j)->y)
			sup_count++;
		}
		cout<<endl<<"Point (x,y)=("<<(A+i)->x<<","<<(A+i)->y<<")"<<endl<<"Superiority count = "<<sup_count<<endl;
	}
}
void sort(int n,point A[])
{
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if((A+i)->x>(A+j)->x){
			point *p=A+i;
			*(A+i)=*(A+j);
			*(A+j)=*p;}
		}
	}
}
void sol2(int n, point A[])
{
	sort(n,A);
	int B[n],C[n];
	for(int i=0;i<n;i++)
	{
		B[i]=(A+i)->y;
		C[i]=0;
	}
	C[0]=B[0];
	for(int i=1;i<n;i++)
	{
		while(B[i]>=C[i])
		;
	}
}
int main()
{
	int n;
	cout<<"Enter no. of points: ";
	cin>>n;
	point A[n];
	cout<<"Enter "<<n<<" points in format:\nx  y"<<endl;
	for(int i=0;i<n;i++)
	cin>>(A+i)->x>>(A+i)->y;
	sol1(n,A);
	sol2(n,A);
	return 0;
}
