#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i = 1; i < n ; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }

        }
        for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }
}

void selectionSort(int arr[],int n){
    for(int i = 0; i < n - 1; i++){
        int min_index = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
}

int main(){
    int arr[]={64,25,32,22,11};
    int n=sizeof(arr)/sizeof(arr[0]);

    // selectionSort(arr, n);
    bubbleSort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}