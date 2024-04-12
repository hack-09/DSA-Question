#include <bits/stdc++.h>

using namespace std;

bool isSorted(int arr[],int size){
    if(size==0 || size==1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }else{
        bool remain = isSorted(arr+1,size-1);
        return remain;
    }
}

int Sum(int arr[],int size){
    if(size==0) return 0;
    if(size==1) return arr[0];
    int sum= arr[0]+Sum(arr+1,size-1);
    return sum;
}

bool BinarySearch(int arr[],int s, int e, int k){
    if(s>e) return false;

    int mid = s+(e-s)/2;
    if(arr[mid]==k) return true;
    if(arr[mid]<k){
        return BinarySearch(arr,mid+1,e,k);
    }else{
        return BinarySearch(arr,s,mid-1,k);
    }
}

bool LinearSearch(int arr[],int size, int key){
    if(size==0) return false;
    if(arr[0]==key) return true;
    LinearSearch(arr+1,size-1,key);
}
int main() {
    // int arr[5]={2,4,6,8,9};
    int arr[5]={2,4,6,8,9};
    int size=5;
    bool ans = isSorted(arr,size);
    if(ans){
        cout<<"Array is sorted"<<endl;
    }else{
        cout<<"Array is not sorted"<<endl;
    }
    cout<<"Sum of arrays is "<<Sum(arr,size)<<endl;
    cout<<"LinearSearch in array is "<<LinearSearch(arr,size,5)<<endl;
    cout<<"BinarySearch in array is "<<BinarySearch(arr,0,size-1,8)<<endl;
    return 0;
}