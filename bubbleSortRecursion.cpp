#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int *arr, int n){
    if(n==0 || n==1) return;
    for(int i=0 ;i<n-1 ;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr,n-1);
}

void selectionSort(int *arr,int n){
    if(n==0 || n==1) return;
    int mini=INT_MAX;
    int index=-1;
    for(int i=0;i<n;i++){
        if(arr[i]<mini){
            mini=arr[i];
            index = i;
        }
    }
    swap(arr[0],arr[index]);
    selectionSort(arr+1,n-1);
}

// Merge Sort by Recursive method
void merge(int *arr, int s, int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }

    k=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }

    int index1=0;
    int index2=0;
    k=s; // main array index
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[k++]=first[index1++];
        }
        else{
            arr[k++]=second[index2++];
        }
    }

    while(index1<len1){
        arr[k++]=first[index1++];
    }

    while(index2<len2){
        arr[k++]=second[index2++];
    }

    delete []first; 
    delete []second;  

    cout<<"Merge is working23"<<endl;
}
void mergeSort(int *arr,int s, int e){
    if(s>=e) return;

    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    cout<<"mergeSort working"<<endl;
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}

int main() {

    int arr[5]={2,5,1,9,6};
    cout << "Original array: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, 4);

    cout << "Sorted array: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}