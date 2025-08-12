# include<iostream>
using namespace std;

int arr[50];
int max_size = 50;
int n = 0;// total range 
int arr_size = 0;

void createArr(){
    cout<<"Enter n i.e. range (1 to n) :";
    cin>>n;
    arr_size = n -1;
    if(arr_size > max_size){
        cout<<"Invalid Input"<<endl;
        return;
    }
    cout<<"Enter array :";
    for(int i = 0; i < arr_size; i++){
        cin>>arr[i];
    }
}

void display(){
    for(int i = 0; i < arr_size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int LinearIteration(){
    int starter = arr[0];
    for(int i = 1; i < arr_size; i++){
        if(arr[i] != starter + i){
            return starter + i;
        }
    }

    return starter + arr_size;
}

int main(){
    createArr();

    int res = LinearIteration();
    cout<<"Missing number :"<<res;

    return 0;
}
