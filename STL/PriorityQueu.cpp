#include <bits/stdc++.h>
using namespace std;

int main(){
    //max-heap
    priority_queue<int> maxi;

    // min-heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(1);
    maxi.push(31);
    maxi.push(21);
    maxi.push(0);
    
    int n= maxi.size();
    for(int i=0; i < n; i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }cout<<endl;

    mini.push(1);
    mini.push(31);
    mini.push(21);
    mini.push(0);
    
    int m= mini.size();
    for(int i=0; i < m; i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }cout<<endl;

    cout<<"Khali hai kya bhai ? "<<mini.empty();
    return 0;
}