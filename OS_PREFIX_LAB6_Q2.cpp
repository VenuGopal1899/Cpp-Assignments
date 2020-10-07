/*
M VENU GOPAL
17CS8064
OS LAB ASSIGNMENT 6
*/

#include <bits/stdc++.h> 
#include<bits/stdc++.h>
#include<pthread.h>
#define MAX_THREAD 2
using namespace std; 

string exprsn;  
bool isOperand(char c) 
{ 
    // If the character is a digit then it must 
    // be an operand 
    return isdigit(c); 
} 
  
void* evaluatePrefix(void *arg) 
{ 
    stack<double> Stack; 
  
    for (int j = exprsn.size() - 1; j >= 0; j--)
    { 
  
        // Push operand to Stack 
        // To convert exprsn[j] to digit subtract 
        // '0' from exprsn[j]. 
        if (isOperand(exprsn[j])) 
            Stack.push(exprsn[j] - '0'); 
  
        else
        { 
  
            // Operator encountered 
            // Pop two elements from Stack 
            double o1 = Stack.top(); 
            Stack.pop(); 
            double o2 = Stack.top(); 
            Stack.pop(); 

            switch (exprsn[j]) 
            { 
                case '+': 
                Stack.push(o1 + o2); 
                break; 
                case '-': 
                Stack.push(o1 - o2); 
                break; 
                case '*': 
                Stack.push(o1 * o2); 
                break; 
                case '/': 
                Stack.push(o1 / o2); 
                break; 
            } 
        } 
    } 
    cout<<"VALUE IS : "<<Stack.top()<<endl; 
} 
  
// Driver code 
int main() 
{ 
    cout<<"Enter the prefix expression : ";
    cin>>exprsn;

    int i;
    pthread_t threads[MAX_THREAD]; 

    for (i = 0; i < MAX_THREAD; i++) 
    if(i==0)
        pthread_create(&threads[i], NULL, evaluatePrefix, (void*)NULL); 
    else
        break;
    return 0; 
} 