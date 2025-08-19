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

void display(int M[][3], int nze) {
    cout << "Sparse Matrix (Row Col Value):" << endl;
    cout << M[0][0] << " " << M[0][1] << " " << M[0][2] << endl;
    for (int i = 1; i <= nze; i++) {
        cout << M[i][0] << " " << M[i][1] << " " << M[i][2] << endl;
    }
}


void swapper(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void transpose(int M[][3], int nze) {

    for (int i = 0; i <= nze; i++) {
        int temp = M[i][0];
        M[i][0] = M[i][1];
        M[i][1] = temp;
    }

    // now sorting the sparse matrix row majorly by bubble sort
    for (int i = 1; i < nze; i++) {
        for (int j = 1; j <= nze - i; j++) {
            if (M[j][0] > M[j + 1][0] || 
               (M[j][0] == M[j + 1][0] && M[j][1] > M[j + 1][1])) {
                // swapping the whole row 
                swapper(M[j][0], M[j + 1][0]);
                swapper(M[j][1], M[j + 1][1]);
                swapper(M[j][2], M[j + 1][2]);
            }
        }
    }
}

void MatrixMultiplication(){
    if(colsA != rowsB){
        cout << "Multiplication can't be performed." << endl;
        return;
    }
    rowsR = rowsA;
    colsR = colsB;
    // taking transpose of B
    transpose(B, nzeB);
    int idx = 1;
    
    res[0][0] = rowsR;   // rows of A
    res[0][1] = colsR;  // rows of Transpose of B = cols of B
    res[0][2] = 0;
    
    for(int i = 1; i <= nzeA; i++){
        for(int j = 1; j <= nzeB; j++){
            if(A[i][1] == B[j][1]){
                int row = A[i][0];
                int col = B[j][0];
                int val = A[i][2] * B[j][2];


                bool isthere = false;
                for(int k = 1; k < idx; k++){
                    if(res[k][0] == row && res[k][1] == col){
                        res[k][2] += val;
                        isthere = true;
                        break;
                    }
                }
                if(!isthere){
                    res[idx][0] = row;
                    res[idx][1] = col;
                    res[idx][2] = val;
                    idx++;
                }
            }
        }
    }
    nzeR = idx - 1;
    res[0][2] = idx - 1;

}

int main(){

    createSparseMatrices();
    MatrixMultiplication();
    display(res, nzeR);

    return 0;
}
