#include<bits/stdc++.h>
using namespace std;

int lowerBound(int arr[],int n,int k){
    int s=0;
    int e=n-1;
    int m=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[m]==k){
            ans=m;
            e=m-1;
        }
        if(k>arr[m]){
            s=m+1;
        }else{
            e=m-1;
        }
        m=s+(e-s)/2;
    }
    return ans;
}
int upperBound(int arr[],int n,int k){
    int s=0;
    int e=n-1;
    int m=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[m]==k){
            ans=m;
            s=m+1;
        }
        if(k>arr[m]){
            s=m+1;
        }else{
            e=m-1;
        }
        m=s+(e-s)/2;
    }
    return ans;
}
int main(){
    int arr[6]={4,8,8,11,54,66};
    int n=6;
    int k=8;

    cout<<lowerBound(arr,n,k)<<endl;
    cout<<upperBound(arr,n,k)<<endl;
}