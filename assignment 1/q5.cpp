# include<iostream>
using namespace std;

int A[50][50];
int maxRows = 50, maxCols = 50;
int rows = 0, cols = 0;
int rowsum[50];
int colsum[50];
int row_size = 0;
int col_size = 0;

void createArr() {
    cout << "Enter number of rows and columns for matrix A : ";
    cin >> rows >> cols;
    row_size = rows;
    col_size = cols;

    if (rows > maxRows || cols > maxCols) {
        cout << "Invalid assignment" << endl;
        return;
    }

    cout << "Enter elements: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A[i][j];
        }
    }
}

void displayresult(){
    cout << "Sum of rows :";
    for(int i = 0; i < row_size; i++){
        cout<<rowsum[i]<<" ";
    }
    cout<<endl;

    cout<<"Sum of colums :";
    for(int i = 0; i < col_size; i++){
        cout<<colsum[i]<<" ";
    }
    cout<<endl;

}

void findSum(){
    int idx = 0;
    for(int i = 0; i < row_size; i++){
        rowsum[i] = 0;
    }
    for(int j = 0; j < col_size; j++){
        colsum[j] = 0;
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            rowsum[i] += A[i][j];
            colsum[j] += A[i][j];
        }
    }
}


int main(){
    createArr();
    findSum();
    displayresult();
   
    return 0;
}
