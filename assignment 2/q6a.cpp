#include <iostream>
using namespace std;

int rows, cols, nze;
int A[100][3];
int max_size = 100;

void createSparseMatrix(){
    cout << "Enter number of rows, columns and non-zero elements: ";
    cin >> rows >> cols >> nze;
    if(rows <= 0 || cols <= 0){
        cout << "Invalid input of either rows or cols or both" << endl;
        return;
    }
    if (nze > max_size - 1 || nze > rows*cols || nze < 0) {
        cout << "Invalid input of non-zero elements." << endl;
        return;
    }
    A[0][0] = rows;
    A[0][1] = cols;
    A[0][2] = nze;
    cout << "Enter row, column and value for each non-zero element:\n";
    for (int i = 1; i <= nze; ++i) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }
}

void swapper(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void transpose(){
    for(int i = 0; i <= nze; i++){
        int temp = A[i][0];
        A[i][0] = A[i][1];
        A[i][1] = temp;
    }
    // now sorting the sparse matrix row majorly by bubble sort

    for(int i = 1; i < nze; i++){
        for(int j = 1; j <= nze - i; j++){
            if(A[j][0] > A[j + 1][0] || (A[j][0] == A[j + 1][0]) && A[j][1] > A[j + 1][1]){
                // swapping the whole row 
                swapper(A[j][0], A[j + 1][0]);
                swapper(A[j][1], A[j + 1][1]);
                swapper(A[j][2], A[j + 1][2]);
            }
        }
    }
}

void display(){
    for(int i = 1; i <= nze; i++){
        cout << A[i][0] << " " << A[i][1] << " " << A[i][2];
        cout << endl;
    }
}

int main() {
    createSparseMatrix();
    transpose();
    cout << "transpose = "<<endl;
    display();
    return 0;
}
