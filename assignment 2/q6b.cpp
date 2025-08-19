#include <iostream>
using namespace std;

int rowsA, colsA, nzeA;
int rowsB, colsB, nzeB;
int rowsR, colsR, nzeR;
int A[100][3], B[100][3];
int res[100][3];
int max_size = 100;

void createSparseMatrices() {
    // Matrix A
    cout << "Enter number of rows, columns and non-zero elements for Matrix A: ";
    cin >> rowsA >> colsA >> nzeA;
    if(rowsA <= 0 || colsA <= 0){
        cout << "Invalid input of either rows or cols or both for Matrix A" << endl;
        return;
    }
    if (nzeA > max_size - 1 || nzeA > rowsA*colsA || nzeA < 0) {
        cout << "Invalid input of non-zero elements for Matrix A." << endl;
        return;
    }
    A[0][0] = rowsA;
    A[0][1] = colsA;
    A[0][2] = nzeA;
    cout << "Enter row, column and value for each non-zero element of Matrix A:\n";
    for (int i = 1; i <= nzeA; i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    // Matrix B
    cout << "Enter number of rows, columns and non-zero elements for Matrix B: ";
    cin >> rowsB >> colsB >> nzeB;
    if(rowsB <= 0 || colsB <= 0){
        cout << "Invalid input of either rows or cols or both for Matrix B" << endl;
        return;
    }
    if (nzeB > max_size - 1 || nzeB > rowsB*colsB || nzeB < 0) {
        cout << "Invalid input of non-zero elements for Matrix B." << endl;
        return;
    }
    B[0][0] = rowsB;
    B[0][1] = colsB;
    B[0][2] = nzeB;
    cout << "Enter row, column and value for each non-zero element of Matrix B:\n";
    for (int i = 1; i <= nzeB; i++) {
        cin >> B[i][0] >> B[i][1] >> B[i][2];
    }
}

void display(){
    cout << "Result Sparse Matrix (Row Col Value):" << endl;
    cout << res[0][0] << " " << res[0][1] << " " << res[0][2] << endl;
    for(int i = 1; i <= nzeR; i++){
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2];
        cout << endl;
    }
}

void AddMatrices(){
    if((A[0][0] != B[0][0]) || (A[0][1] != B[0][1])){
        cout << "Invalid Input (Can not perform addition)"<<endl;
        return;
    }
    int i = 1;
    int j = 1;
    int idx = 1;
    while(i <= nzeA && j <= nzeB){
        if(A[i][0] == B[j][0] && A[i][1] == B[j][1]){
            if(A[i][2] + B[j][2] != 0){
                res[idx][0] = A[i][0];
                res[idx][1] = A[i][1];
                res[idx][2] = A[i][2] + B[j][2];
                idx++;
            }
            i++, j++;
        }
        else if((A[i][0] < B[j][0]) || (A[i][0] == B[j][0] && A[i][1] < B[j][1])){
            res[idx][0] = A[i][0];
            res[idx][1] = A[i][1];
            res[idx][2] = A[i][2];
            i++, idx++;
        }
        else{
            res[idx][0] = B[j][0];
            res[idx][1] = B[j][1];
            res[idx][2] = B[j][2];
            j++, idx++;
        }
    }
    while(i <= nzeA){
        res[idx][0] = A[i][0];
        res[idx][1] = A[i][1];
        res[idx][2] = A[i][2];
        i++, idx++;
    }
    while(j <= nzeB){
        res[idx][0] = B[j][0];
        res[idx][1] = B[j][1];
        res[idx][2] = B[j][2];
        j++, idx++;
    }
    rowsR = rowsA;
    colsR = colsA;
    nzeR = idx - 1;
    res[0][0] = rowsR;
    res[0][1] = colsR;
    res[0][2] = nzeR;
}

int main(){
    createSparseMatrices();
    AddMatrices();
    display();

    return 0;
}
