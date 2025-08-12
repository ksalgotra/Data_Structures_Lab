# include<iostream>
using namespace std;

char str[50];


void inputstr(){
    cout<<"Enter string 1 :";
    cin>>str;
}

void reverse(){
    int len = 0, i = 0;
    while(str[i++] != '\0')len++;

    int l = 0, r = len - 1;
    while(l < r){
        char temp = str[l];
        str[l] = str[r];
        str[r] = temp;
        l++,r--;
    }
}

int main(){
    inputstr();
    reverse();

    cout<<str;
}
