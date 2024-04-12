#include <bits/stdc++.h>
using namespace std;

void fabinaci(int n){
    if(n==0 || n==1) return n;
    int sum = fabinaci(n-1)+fabinaci(n-2);
    cout<<sum<<endl;
}
void printNum(int n){
    if(n==0)
        return;
    
    printNum(n-1);
    cout<<n<<" ";
}


int power(int x, int y){
    if(y==0)
        return 1;
    
    int ans =x*power(x,y-1);

    return ans;
}
int factorial(int n){
    if(n==0){
        return 1;
    }

    int ans = n*factorial(n-1);

    return ans;

}
int main() {
    int n,p;
    cin>>n;
    cin>>p;

    cout<<factorial(n)<<endl;
    cout<<power(n,p)<<endl;
    printNum(n);

    fabinaci(n);
    
    return 0;
}