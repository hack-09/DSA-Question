#include<iostream>
using namespace std;


int main(){

    int n=4;
    // cin>>n;
    if(n==1 || n==2){
        cout<<"*";
        return 0;
    }
    for(int i=0;i<n/2;i++){
        cout<<string(n-2-i,' ');
        cout<<string(2*i+1,'*')<<endl;
    }
    for(int i=(n/2);i>=0;i--){
        cout<<string(n-2-i,' ');
        cout<<string(2*i+1,'*')<<endl;
    }
}


