#include <bits/stdc++.h>

using namespace std;

int main() {

    int arr[10]={5,1,8,3,9,5,11};

    // cout<<"Address of first memory block is "<< arr<<endl;
    // cout<<arr[0]<<endl; 
    // cout<<"Address of first memory block is "<< &arr[0]<<endl;

    // cout<<"4th "<<*arr<<endl;
    // cout<<"5th "<<*arr+1<<endl;
    // cout<<"6th "<<*(arr+1)<<endl;
    // cout<<4[arr]<<endl;  // this is also a valid way to access 4th element of array

    // int temp[10]={1,2};
    // cout<<sizeof(temp)<<endl;
    // cout<<" 1st "<<sizeof(*temp)<<endl;
    // cout<<" 2nd "<<sizeof(&temp)<<endl;

    // int *ptr=&temp[0];
    // cout<<sizeof(ptr)<<endl;
    // cout<<sizeof(*ptr)<<endl;
    // cout<<sizeof(&ptr)<<endl;

    char ch[6] = "abcde";
    // char ch[6] = {'a','b','c','d','e','f'};

    cout<<ch<<endl;

    char *c=&ch[0];
    cout<<c<<endl;

    char temp = 'z';
    char *q=&temp;
    cout<<q<<endl;




    return 0;
}