# include<iostream>
using namespace std;

char str[50];


void inputstr(){
    cout<<"Enter string 1 :";
    cin>>str;
}

void sortCharactersInString() {
    int len = 0;
    int idx = 0;
    while(str[idx] != '\0'){
        len++;
        idx++;
    }
    
   
    for (int i = 1; i <= len - 1; i++) {// len - 1 passes
        for (int j = 0; j < len - i; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main(){
    inputstr();
    sortCharactersInString();


    cout<<str;
}
