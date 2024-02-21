#include<bits/stdc++.h>
using namespace std;

int main(){
  int n=46;
  vector<int> v;
  if(n<0) {
    n=-n;
    int l=log2(n);
    int comp=INT_MAX;
    n =comp^n;
    n=n+1;
  }
  while(n!=0){
    int a=(n&1);
    v.push_back(a);
    n=n>>1;
  }
  
  reverse(v.begin(),v.end());
  for(int i:v){
    cout<<i;
  }
  return 0;
}