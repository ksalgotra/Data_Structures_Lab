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

int CountDistincts(){
    int count = 0;

    for(int i = 0; i < n; i++){

        bool isDuplicate = false;

        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                isDuplicate = true;
                break;
            }
        }

        if(!isDuplicate){
            count++;
        }
    }

    return count;
}

int main(){
    createArr();
    cout << "The number of distinct elements for the given array are :" << CountDistincts();

    return 0;
}
