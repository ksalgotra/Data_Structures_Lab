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


void deleteval(int pos){

    if(size == 0){
        cout<<"Array is already empty"<<endl;
        return;
    }

    for(int i = pos - 1; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }

    size--;
}

void duplicateremover(){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){

            if(arr[i] == arr[j]){
                    deleteval(j + 1);// since delete function is designed along position
                    j--;
            }
            
        }
    }
}
int main(){
    createArr();

    duplicateremover();
    display();
    return 0;
}
