# include<iostream>
using namespace std;

char str[50];


void inputstr(){
    cout<<"Enter string 1 :";
    cin>>str;
}

void deletevowels(){
    int i = 0;
    
    while(str[i] != '\0'){
        char ch = str[i];
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch =='e' || ch == 'i' || ch == 'o' || ch == 'u'){
            int idx = i;
            while(str[idx + 1] != '\0'){
                str[idx] = str[idx + 1];
                idx++;
            }
            str[idx] = '\0';
            i--;
        }
        
        i++;
    }

    
}

int main(){
    inputstr();
    deletevowels();

    cout<<str;
}
