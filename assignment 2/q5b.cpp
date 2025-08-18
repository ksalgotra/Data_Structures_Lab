#include <iostream>
using namespace std;

int arr[100];// max_size
int max_size = 100;
int n = 0;
void createtriDiagMatrix(){
    cout << "Enter number of rows/cols of matrix :";
    cin >> n;

    if(3*n - 2 > max_size){
        cout<<"Invalid Input"<<endl;
        return;
    }

    for(int i = 0; i < 3*n - 2; i++){
        if(i < n - 1){
            if(i == 0){
                cout << "Please enter elements of lower diagonal : ";
            }
            cin >> arr[i];
        }
        else if(i < 2*n - 1){
            if(i == n - 1){
                cout << "Please enter elements of main diagonal : ";
            }
            cin >> arr[i];
        }
        else{
            if(i == 2*n - 1){
                cout << "Please enter elements of upper diagonal : ";
            }
            cin >> arr[i];
        }
    }
}

void displayMatrix(){
    int lowerdiagst = 0;
    int maindiagst = n - 1;
    int upperdiagst = 2*n - 1;
  
    for(int i = 0; i < n; i++){
      
        for(int j = 0; j < n; j++){
          
            if(i == j){
                cout << arr[maindiagst + i] << " ";
            }
            else if(i == j + 1){
                cout << arr[lowerdiagst + j] << " ";
            }
            else if(i == j - 1){
                cout << arr[upperdiagst + i] << " ";
            }
            else{
                cout << "0 ";
            }
          
        }
        cout<<endl;
    }
  
}

int main() {
    createtriDiagMatrix();
    displayMatrix();
    return 0;
}
