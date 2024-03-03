#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<string> s;

    s.push("Pranjal");
    s.push("Kumar");
    s.push("Singh");

    cout<<"ELement at top "<<s.top()<<endl;

    s.pop();
    cout<<"ELement at top "<<s.top()<<endl;
    cout<<"Size of "<<s.size()<<endl;
    cout<<"Empty or not ->"<<s.empty()<<endl;
    return 0;
}