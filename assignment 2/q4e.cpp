# include<iostream>
using namespace std;

char str[50];


void inputstr(){
    cout<<"Enter string 1 :";
    cin>>str;
}

void uppercasetolowercase(){
    int i = 0;
    
    while(str[i] != '\0'){
        char ch = str[i];
        if(ch >= 'A' && ch <= 'Z'){
            str[i] += 32;
        }
        i++;
    }

    
}

int main(){
    inputstr();
    uppercasetolowercase();

    cout<<str;
}
