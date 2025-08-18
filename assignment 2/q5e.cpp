#include <iostream>
using namespace std;

int arr[100];// max_size
int max_size = 100;
int n = 0;
int m = 0; // for rows/cols
void createSymmMatrix(){
    cout << "Enter number of rows/cols of matrix :";
    cin >> m;
    n = (m * (m + 1)) / 2;

    if(n  > max_size){
        cout<<"Invalid Input"<<endl;
        return;
    }
    cout << "Enter elements in row major order for Only the Upper Triangular Matrix:";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

}

int get_ele(int& i, int& j){
    int idx = 0;
    if(i <= j){
        for(int r = 0; r < m; r++){
            for(int c = r; c < m; c++){
                if(r == i && c == j){
                    return arr[idx];
                }
            idx++;
            }
        }
    }
    else{
        return get_ele(j, i);
    }

    return -1;
}

void displayMatrix(){

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cout << get_ele(i, j) << " ";
        }
        cout << endl;
    }
}
int main() {
    createSymmMatrix();
    displayMatrix();
    return 0;
}
