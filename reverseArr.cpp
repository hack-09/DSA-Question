#include<bits/stdc++.h>
using namespace std;

void resverse(int arr[],int n){
    for(int i=0;i<n/2;i++){
        swap(arr[i],arr[n-i-1]);
    }
}
int main(){
    int a[]={1,2,3,4,5,6,7,8,9,10,11};
    int n=11;
    resverse(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}