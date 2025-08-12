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


void deleteval(int pos){

    if(n == 0){
        cout<<"Array is already empty"<<endl;
        return;
    }

    for(int i = pos - 1; i < n - 1; i++){
        arr[i] = arr[i + 1];
    }

    n--;
}

void duplicateremover(){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){

            if(arr[i] == arr[j]){
                    deleteval(j + 1);// since delete function is designed alond position
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
