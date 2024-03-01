#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& v, int n, int m, int mid){
    int sum=0;
    for(int i = 0; i <n; i++){
        if(v[i]>mid){
            sum+=(v[i]-mid);
        }
    }
    if(sum>=m){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }

    int ans=-1;
    sort(v.begin(),v.end());
    int s=0, e=v[n-1];
    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossible(v, n, m, mid)){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    cout<<ans<<endl;

}