# include<iostream>
using namespace std;

char str1[50];
char str2[15];
int resl;

void inputstr(){
    cout<<"Enter string 1 :";
    cin>>str1;
    cout<<"Enter string 2 :";
    cin>>str2;
}

void concatenate(){
    int l1 = 0, l2 = 0;
    int i = 0;
    while(str1[i++] != '\0'){
        l1++;

    }
    i = 0;
    while(str2[i++] != '\0'){
        l2++;
    }
    if(l1 + l2 >= 50){
        cout<<"Invalid Operation";
        return;
    }
    resl = l1 + l2;

    for(int i = 0; i < l2; i++){
        str1[i + l1] = str2[i];
    }
    str1[resl] = '\0';
}

int main(){
    inputstr();
    concatenate();

    cout<<str1;
}
