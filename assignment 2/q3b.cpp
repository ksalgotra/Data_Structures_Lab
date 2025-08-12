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

int BinarySearch(){
    int st = 0, end = arr_size - 1;
    while(st <= end){
        int mid = (st + end)/ 2;

        if(arr[mid] != mid + 1){
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }

    return st + 1;
}

int main(){
    createArr();

    int res = BinarySearch();
    cout<<"Missing number :"<<res;

    return 0;
}
