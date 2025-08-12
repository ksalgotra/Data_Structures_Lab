# include<iostream>
using namespace std;

int A[50][50];
int transpose[50][50];
int maxRows = 50, maxCols = 50;
int rows = 0, cols = 0;
int transposerows = 0, transposecols = 0;

void createArr() {
    cout << "Enter number of rows and columns for matrix A : ";
    cin >> rows >> cols;

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

void displaytranspose(){
    cout<<"Resultant Matrix :"<<endl;
    for(int i = 0; i < transposerows; i++){
        for(int j = 0; j < transposecols; j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
}

void maketranspose(){
    transposerows = cols;
    transposecols = rows;

    for(int i = 0; i < transposerows; i++){
        for(int j = 0; j < transposecols; j++){
            transpose[i][j] = A[j][i];
        }
    }
}


int main(){
    createArr();

    maketranspose();
    displaytranspose();
    return 0;
}
