#include <iostream>
using namespace std;

int arr[100];// max_size
int max_size = 100;
int n = 0;
void createDiagMatrix(){
    cout << "Enter number of rows/cols of matrix :";
    cin >> n;

    if(n > max_size){
        cout<<"Invalid Input"<<endl;
        return;
    }

    cout << "Enter elements of diagonal :";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void displayMatrix(){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                cout << arr[i] << " ";
            }
            else{
                cout << "0 ";
            }
        }
        cout<<endl;
    }
}
int main() {
    createDiagMatrix();
    displayMatrix();
    return 0;
}
