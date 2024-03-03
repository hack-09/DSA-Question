#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> d;

    d.push_back(1);
    d.push_front(2);

    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    // d.pop_back();
    // d.pop_front();
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"ELement at 1st index "<<d.at(1)<<endl;

    cout<<"front "<<d.front()<<endl;
    cout<<"back "<<d.back()<<endl;

    cout<<"EMpty or not "<<d.empty()<<endl;

    
    cout<<"Before ersae"<<endl;
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    d.erase(d.begin(),d.begin()+2);

    cout<<"After ersae"<<endl;
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}