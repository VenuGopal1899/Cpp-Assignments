//MALLADI VENU GOPAL
//17CS8064
//TO FIND THE REGION OF LINES


#include<bits/stdc++.h>
using namespace std ;
int main()
{
        int n;
        double x,y;
        cout<<"enter the number of segments";
        cin>>n;
        double s[n],e[n],s1[n],e1[n],a,b;
        for(int i=0;i<n;i++)
        {
                x=(rand()%1001)/1000.0;
                y=(rand()%1001)/1000.0;
                if(x>y)
                {
                        s[i]=y;
                        s1[i]=y;
                        e[i]=x;
                        e1[i]=x;

                }
                else if(x<y)
                {
                        s[i]=x;
                        s1[i]=x;
                        e[i]=y;
                        e1[i]=y;
                }
                else if(x==y)
                {
                        i--;

                }
        }
        sort(s1,s1+n);
        sort(e1,e1+n);
        for(int i=0;i<n;i++)
        
        {
          
          cout<<s[i]<<" "  ;    
        }
        cout<<endl;
	for(int i=0;i<n;i++)
        {
                cout<<s[i]<<" ";

        }
	cout<<endl;
        for(int i=0;i<n;i++)
        {
                cout<<e[i]<<" ";

        }
        int i=0,j=0;
        int count=0,max=INT_MIN;
        while(i<n&&j<n)
        {
            if(s1[i]<e1[j])
            {
                count++;
                if(count>max)
              { 	 max=count;
               		 a=s1[i];
              }
		i++;
            }
            else if(s1[i]>e1[j])
            {
                if(count==max)
		{
		b=e1[j];
		}
		count--;
                j++;
            }

        }
        for(int k=j;k<n;k++)
        {
	if(count==max)
		{
		b=e1[j];
		}           
	 count--;
            
        }
        cout<<"\n the required zone is :"<<a<<" "<<b;
        cout<<" \n the lines in this range are"<<endl;

        for(int i=0;i<n;i++)
        {
            if(a>=s[i]&&b<=e[i])
            {
                cout<<s[i]<<" "<<e[i]<<endl;
            }
        }

        return 0;       
}

