#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int m, vector<int>& b, int n) {
        vector<int> v(m+n);
        int i=0,j=0;
        while(i<m && j<n){
            if(a[i]<b[j]){
                v.push_back(a[i]);
                i++;
            }else{
                v.push_back(b[j]);
                j++;
            }
        }
        while(i<m){
            v.push_back(a[i]);
        }
        while(j<n){
            v.push_back(b[j]);
        }
        for(int i=0;i<(m+n);i++){
            a[i]=v[i];
        }
    }

int main(){
    vector<int> a={1,2,3,0,0,0};
    vector<int> b={2,5,6};
    int m=3, n=3;
    merge(a,m,b,n);
    for(int i=0;i<m+n;i++){
        cout<<a[i]<<endl;
    }
}