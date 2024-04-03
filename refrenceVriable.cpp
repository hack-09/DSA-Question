#include <bits/stdc++.h>

using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x=y;
    y=temp;
}
int main() {
    int i=5;
    int &j=i;

    cout<<i<<" "<<j<<endl;

    i++;
    cout<<" i-> "<<i<<endl;
    j++;
    cout<<" i-> "<<i<<endl;

    int a=2, b=3;
    cout<<a<<" "<<b<<endl;
    swap(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}