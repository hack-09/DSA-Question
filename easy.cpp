#include<bits/stdc++.h>
using namespace std;

void CheckSort(int arr[],int len){
    int isSort=true;
    for(int i=0;i<len-1;i++){
        if(arr[i+1]<arr[i]){
            cout<<"Not Sorted Array"<<endl;
            return;
        }
    }
    
    cout<<"Sorted Array"<<endl;
}

void findMinMax(int arr[], int len){
    int maxV=INT_MIN, minV=INT_MAX;
    for(int i=0;i<len;i++){
        if(arr[i]>maxV){
            maxV=arr[i];
        }
        if(arr[i]<minV){
            minV=arr[i];
        }
    }
    cout<<"Min value is "<<minV<<"\nMax value is "<<maxV<<endl;
}


void reverseArr(int arr[], int len){
    for(int i=0;i<len/2;i++){
        swap(arr[i],arr[len-1-i]);
    }
    for(int i=0;i<len;i++){
        cout<<arr[i]<<", ";
    }cout<<endl;
}

void findThirdLargest(){
    int arr[]={49, 12, 5, 787, 1, 23, 648, 45};
    int len=sizeof(arr)/4;
    int a=INT_MIN,b=INT_MIN,c=INT_MIN;
    
    for(int i=0;i<len;i++){
        if(arr[i]>a){
            c=b;
            b=a;
            a=arr[i];
        }
        else if(arr[i] > b && arr[i] < a){
            c=b;
            b=arr[i];
        }
        else if(arr[i]>c && arr[i] < b){
            c=arr[i];
        }
    }
    
    if(c==INT_MIN){
        cout<<"Not Possible"<<endl;
        return;
    }
    
    cout<<"a->"<<a<<", b->"<<b<<", c->"<<c<<endl;
}
 
// to find kth largest number in array, 1st method is to sort the array and return kth index element
// 2nd method is max-heap where we remove the top k-1 element by removing heap root which is alway updated as max value 
// but it is not best  Time complexity= O(nlogn+k) and space = O(n) : all the element will go to heap
void findKth_LargestNum_UsingMaxHEap(){
    int arr[] = {49, 12, 5, 787, 1, 23, 648, 45,10};
    int k = 3; 
    int size = sizeof(arr)/4;
    
    priority_queue<int> m;
    for(int i=0;i<size;i++){
        m.push(arr[i]);
    }
    
    while(--k){
        m.pop();
    }
    cout<<"kth largest number is "<< m.top()<<endl;
}

// 3nd method is min-heap where we maintain a heap of size k by popping smallest elements as needed 
// it is  better than max heap  Time complexity= O(nlogk) and space = O(k) : all the element will go to heap
void findKthLargest_usingMinHeap() {
    int arr[] = {49, 12, 5, 787, 1, 23, 648, 45,10};
    int k = 3; 
    int size = sizeof(arr)/4;
    
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-Heap
    for (int num : arr) {
        minHeap.push(num); // Add element to the heap
        if (minHeap.size() > k) {
            minHeap.pop(); // Remove the smallest element if size > k
        }
    }
    cout<<"kth largest number is "<<minHeap.top()<<endl; // The root is the k-th largest element
}

void pairNum(){
    int arr[]={1,2,3,4,5};
    int sum=5;
    int len=5;
    
    unordered_map<int,bool> m;
    vector<vector<int>> v;

    for(int i=0;i<len;i++){
        m[arr[i]]=true;
        if(m[sum-arr[i]]){
            v.push_back({arr[i], sum-arr[i]});
        }
    }
    
    for(int i=0;i<v.size();i++){
        cout<<"("<<v[i][0]<<", "<<v[i][1]<<"), ";
    }cout<<endl;
}

int main(){
    int arr[]={3, 5, 1, 2, 4};
    int len=sizeof(arr)/4;
    
    // findMinMax(arr,len);
    // reverseArr(arr,len);
    // CheckSort(arr,len);
    // findThirdLargest();
    // findKth_LargestNum_UsingMaxHEap();
    // findKthLargest_usingMinHeap();
    pairNum();
 }



