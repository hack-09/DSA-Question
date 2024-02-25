#include<bits/stdc++.h>
using namespace std;

void power(int n,int m){
    while(--m){
        n=n*n;
    }
    cout<<n;
}

int main(){
    int a=4;
    int b=2;
    power(a,b);
}