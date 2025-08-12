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
    cout<<"Enter array :";
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

void BubbleSort(){

    for(int i = 0; i < n; i++){// n - 1 passes
        bool isSwapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = true;
            }
        }

        if(!isSwapped){
            break;
        }

    }
}

int main(){
    createArr();

    BubbleSort();
    display();

    return 0;
}
