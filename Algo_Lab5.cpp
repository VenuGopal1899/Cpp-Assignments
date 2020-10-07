/***************************
   #  Name : M Venu Gopal
   #  Roll: 17CS8064
   
 * **********************/
#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include<time.h>
#include<map>
#define ll long long int
using namespace std;

int main(){
    cout<<"Enter bound: ";
    ll B;
    cin>>B;
    cout<<"Enter value of n: ";
    int n;
    cin>>n;
    map<double,double> mp;

    for(ll a=0;a<B;a++){
        for(ll b=-B;b<=B;b++){
            ll k=pow(a,3)+pow(b,3);
            if(k>0){
                 //mp[k]++;
                if(b>=0){
                    mp[k]+=0.5;
                }
                else{
                    mp[k]++;
                }
            }
        }
    }

    //if()
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second==n){
            cout<<"Lowest sum: "<<it->first<<endl;
            break;
        }
    }
    return 0;
}