// next permutation
#include <bits/stdc++.h>
using namespace std;


void AllPermutation(int index,int arr[], int n) {
    if(index==n){
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
        return;
    }
    
    for(int i=index; i<n; i++){
        swap(arr[i],arr[index]);
        AllPermutation(index+1,arr,n);
        swap(arr[i],arr[index]);
    }
    
}

int main() {
    int arr[]={1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    AllPermutation(0,arr, n);
    cout << endl;
    return 0;
}