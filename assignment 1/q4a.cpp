# include<iostream>
using namespace std;

int arr[50];
int max_size = 50;
int n = 0;
void createArr(){
    cout<<"Enter size of array :";
    cin>>n;
    if(n > max_size){
        cout<<"Invalid Input"<<endl;
        return;
    }
    cout<<"Enter elements :";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
}

void display(){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    createArr();
    int i = 0, j = n - 1;
    while(i < j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++, j--;
    }
    display();
    return 0;
}
