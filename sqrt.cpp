#include<bits/stdc++.h>
using namespace std;

int floorSqrt(int n)
{
    int s=0,e=n;
    long long int sq=-1;
    long long int m;
    while(s<=e){
        m=s+(e-s)/2;
        if(m*m == n){
            return m;
        }
        
        if(m*m<n){
            sq=m;
            s=m+1;
        }else{
            e=m-1;
        }
    }
    return sq;
}

double morePrecise(int n, int p, int temp){
    double fact =1.0;
    double ans =temp;

    for(int i=0;i<p;i++){
        fact=fact/10.0;
        for (double j = ans; j*j < n; j=j+fact) 
        {
            ans=j;
        }
        
    }
    return ans;
}

int main(){
    int n=8;
    int temp=floorSqrt(n);
    cout<<morePrecise(n, 3, temp)<<endl;
}