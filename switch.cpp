#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter two numbers";
    cin>>a>>b;

    char op;
    cout<<"Enter opertaion ";
    cin>>op;

    switch(op){
        case '+': cout<<a+b; break;
        case '-': cout<<a-b; break;
        case '*': cout<<a*b; break;
        case '/': cout<<a/b; break;
        default: cout<<"default";
    }

}