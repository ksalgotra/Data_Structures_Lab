#include <iostream>
using namespace std;

int arr[100];// max_size
int max_size = 100;
int n = 0;
int m = 0; // for rows/cols
void createUppertriMatrix(){
    cout << "Enter number of rows/cols of matrix :";
    cin >> m;
    n = (m * (m + 1)) / 2;

    if(n  > max_size){
        cout<<"Invalid Input"<<endl;
        return;
    }
    cout << "Enter elements in row major order :";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void displayMatrix(){
    int idx = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(i <= j){
                cout << arr[idx++] << " ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
int main() {
    createUppertriMatrix();
    displayMatrix();
    return 0;
}
