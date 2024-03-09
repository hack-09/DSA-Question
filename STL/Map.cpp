#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,string> m;

    m[1]="Pranjal";
    m[2]="Kumar";
    m[3]="Singh";

    m.insert({13, "Priyanshu"});

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"Find 13 -> "<<m.count(13)<<endl;

    m.erase(13);
    cout<<"after erase"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }


    return 0;
}