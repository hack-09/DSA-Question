#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[]={0,2,1,2,2,2,0,1,0,1,0,0};
    int n=sizeof(a)/4;
    int i=0;
    int j=0;
    int k=n-1;
    while(j<k){
            if(a[i]>a[j]){
                swap(a[j],a[k]);
            }
            if(a[j]>a[k]){
                swap(a[j],a[k]);
            }
            if(a[i]==0) i++;
            if(a[j]<=1) j++;
            if(a[k]==2) k--;
            
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    }
    i=0,j=k;
    cout<<i<<" "<<j<<endl;
    while(i<j){
            if(a[i]==1 && a[j]==0){
                swap(a[i],a[j]);
            }
            
            if(a[i]==0) i++;
            if(a[j]==1) j--;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    }
}