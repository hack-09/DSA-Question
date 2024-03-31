#include <bits/stdc++.h>
using namespace std;

void reverse(char name[], int s, int e){  
    while(s<e){
        swap(name[s++], name[e--]);
    }
}
int main() {
    char ch[]="the sky is blue";
    int i=0;

    for(int j=0 ; j<16 ; j++){
        if(ch[j]==' ' || ch[j]=='\0'){
            reverse(ch,i,j-1);
            i=j+1;
        }
    }
    reverse(ch,0,14);
    cout<<ch<<endl;

    return 0;
}