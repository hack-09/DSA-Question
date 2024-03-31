#include <bits/stdc++.h>

using namespace std;

int main() {
    int num=5; 
    cout<<num<<endl;
 
    int *p = &num;
    // cout<<"Address is "<<p<<endl;  // to access the address
    // cout<<"Value is "<<*p<<endl; // to access the value 

    // cout<<"Size of integer is "<<sizeof(num)<<endl; 
    // cout<<"Size of pointer is "<<sizeof(p)<<endl; 

    // int *p=0; // Null pointer

    cout<<*p<<endl;

    int a = *p;
    a++;
    cout<<"a value :"<<a<<endl;   // no diffrence in int num althoug we copy it in a and increment it
    cout<<"num value :"<<num<<endl;  
    
    (*p)=(*p)*5;
    cout<<"num value :"<<num<<endl;  // but with p increment to change num value changes

    int *q=p;
    cout<<p<<" - "<<q<<endl;
    cout<<*p<<" - "<<*q<<endl;

    // important concept 
    int *t=&num;
    cout<< (*t)++<<endl;
    cout<<t+1<<endl;
    cout<<*(t+1)<<endl;

    int *r=p;
    cout<< (r)<<endl;

    void * ptr;
    int i = 10;
    // assign int address to void
    ptr = & i;
    cout << "Address of variable i " << & i << endl;
    cout << "Address where the void pointer is pointing " << ptr <<  endl;


    char b[] = "xyz";
    char *c = &b[1];
    cout << c << endl;
    return 0;
}