/*
M VENU GOPAL
17CS8064
OS LAB ASSIGNMENT 6
*/

#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>
#include<pthread.h>
#define MAX 100
#define MAX_THREAD 2
using namespace std;

int a[MAX];
int sum[MAX_THREAD]={0};
int part=0;

void* sum_array(void *arg)
{
    int thread_part=part++;

    for(int j=(thread_part*(MAX/MAX_THREAD));j<((thread_part+1)*(MAX/MAX_THREAD));j++)
    {
        sum[thread_part]+=a[j];
    }

    cout<<"SUM OF THREAD "<<thread_part<<"  : "<<sum[thread_part]<<endl;
}

int main()
{
    int count=0;
    for(int p=0;p<MAX;p++)  
    {
        a[p]=rand()%100;
    }

    cout<<"Generated random elements in the array: "<<endl;
    for(int q=0;q<MAX;q++)
    {
        cout<<a[q]<<"  ";
    }

    cout<<endl;
    cout<<endl;
   
    int i;
    pthread_t threads[MAX_THREAD]; 

    for (i = 0; i < MAX_THREAD; i++) 
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL); 
  
    for (i = 0; i < MAX_THREAD; i++) 
        pthread_join(threads[i], NULL); 

    int total_sum = 0; 
    for (i = 0; i < MAX_THREAD; i++) 
        total_sum += sum[i]; 

    cout<<endl;
    cout<<endl;    
  
    cout << "Sum is " << total_sum << endl; 
  
    return 0;     
}

