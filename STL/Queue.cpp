#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<string> q;

    cout<<"Empty or not "<<q.empty()<<endl;

    q.push("Pranjal");
    q.push("Anushka");
    q.push("Ayansh");

    cout<<"Eement at front "<<q.front()<<endl;
    q.pop();
    cout<<"Eement at front "<<q.front()<<endl;

    cout<<"Size of queue "<<q.size()<<endl;

    return 0;
}