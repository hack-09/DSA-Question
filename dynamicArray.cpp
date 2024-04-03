#include <bits/stdc++.h>
using namespace std;

int getSum(int *arr, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main() {
    // char ch='q';
    // cout<<sizeof(ch)<<endl;

    // char* c= &ch;
    // cout<<sizeof(c)<<endl;

    int n;
    cin>>n;
    //variable size array
    int* arr = new int[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int sum = getSum(arr,n);
    cout<<"Sum is : "<<sum<<endl;

    return 0;
}