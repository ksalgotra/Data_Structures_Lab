# include<iostream>
using namespace std;

int arr[50];
int n = 50;
int size = 0;
void createArr(){
    cout<<"Enter size of array :";
    cin>>size;
    if(size > n){
        cout<<"Invalid Input"<<endl;
        return;
    }
    cout<<"Enter elements :";
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
}

void display(){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    createArr();
    int i = 0, j = size - 1;
    while(i < j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++, j--;
    }
    display();
    return 0;
}
