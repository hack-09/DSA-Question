#include <bits/stdc++.h>

using namespace std;

char toLowerCase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }else{
        char temp = ch-'A'+'a';
        return temp;
    }
}

bool checkPalindrome(char ch[],int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        if(toLowerCase(ch[s]) != toLowerCase(ch[e])){
            return 0;
        }else{
            s++;
            e--;
        }
    }
    return 1;
}

int getLength(char name[]){
    int count = 0;
    for(int i=0; name[i]!='\0'; i++){
        count++;
    }
    return count;
}

void reverse(char name[], int n){
    int s=0;
    int e=n-1;   
    while(s<e){
        swap(name[s++], name[e--]);
    }
}
int main() {
    char name[20];
    cout<<"Enter name : ";
    cin>>name;

    cout<<"Your name is "<<name<<endl;

    int n=getLength(name);
    cout<<"Length of String is :"<<getLength(name)<<endl;

    reverse(name, n);
    cout<<"Your name is "<<name<<endl;

    cout<<"Character is "<< toLowerCase('A') << endl;

    cout<<"Check Palindrome "<< checkPalindrome(name,n) << endl;

    return 0;
}