#include <bits/stdc++.h>

using namespace std;

void func(vector<string> &str, string &res, int p, int n){
    if(p==n){
        cout<<res<<", ";
        return;
    }
    for(int i=0; i<str[p].length(); i++){
        res+=str[p][i];
        func(str, res, p+1, n);
        res.pop_back();
    }
}

int main(){
    vector<string> str = {"abc", "def", "ghi"};
    int n = str.size();

    string res="";
    func(str, res, 0, n);

    return 0;
}