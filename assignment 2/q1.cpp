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
    cout<<"Enter sorted array :";
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
}

int BinarySearch(){
    int val;
    cout<<"Enter target value :";
    cin>>val;

    int st = 0, end = size - 1;
    
    while(st <= end){
        int mid = (st + end) / 2;

        if(arr[mid] == val){
            return mid;
        }
        else if(arr[mid] > val){
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }

    return -1;
}

int main(){
    createArr();
    
    int res = BinarySearch();
    (res == -1)? cout<<"Value not found" : cout<<"Value found at index :"<<res;

    return 0;
}
