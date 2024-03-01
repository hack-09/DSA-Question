#include<bits/stdc++.h>
using namespace std;

// int pivot(int arr[],int n){
//     int s=0,e=n-1;
//     int m=s+(e-s)/2;
//     while(s<e){
//         if(arr[m]>arr[0]){
//             s=s+1;
//         }else{
//             e=m;
//         }
//         m=s+(e-s)/2;
//     }
//     return s;
// }

int pivot(vector<int>& arr,int n){
    int s=0,e=n-1;
    int m=s+(e-s)/2;
    while(s<e){
        if(arr[m]>=arr[0]){
            s=s+1;
        }else{
            e=m;
        }
        m=s+(e-s)/2;
    }
    return s;
}


int binarySearch(vector<int>& arr,int s, int e,int k){
    // int s=0;
    // int e=n-1;
    int m=s+(e-s)/2;
    while(s<=e){
        if(arr[m]==k){
            return m;
        }
        if(k>arr[m]){
            s=m+1;
        }else{
            e=m-1;
        }
        m=s+(e-s)/2;
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    int piv =pivot(arr, n);
    if(k>=arr[piv] && k<=arr[n-1]){
        return binarySearch(arr,piv, n-1, k);
    }
    else{
        return binarySearch(arr, 0, piv-1, k);
    }
}


int main(){
    int arr[]={7,8,9,1,3,5};
    int n=5;
    cout<<pivot(arr,n)<<endl;
    
}