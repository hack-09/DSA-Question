#include<bits/stdc++.h>
using namespace std;

int main(){
  int b;
  cin>>b;
  int s=0, i=0;
  while(b!=0){
    int digit =b%10;
    if(digit==1){
      s+=pow(2,i);
    }
    b=b/10;
    i++;
  }
  cout<<s;
  return 0;
}