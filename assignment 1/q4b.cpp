# include<iostream>
using namespace std;

int A[50][50];
int B[50][50];
int res[50][50];
int maxRows = 50, maxCols = 50;
int rows1 = 0, cols1 = 0;
int rows2 = 0, cols2 = 0;
int resrows = 0, rescols = 0;

void createArr() {
    cout << "Enter number of rows and columns for matrix A : ";
    cin >> rows1 >> cols1;

    if (rows1 > maxRows || cols1 > maxCols) {
        cout << "Invalid assignment" << endl;
        return;
    }

    cout << "Enter elements: " << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter number of rows and columns for matrix B : ";
    cin >> rows2 >> cols2;

    if (rows2 > maxRows || cols2 > maxCols) {
        cout << "Invalid assignment" << endl;
        return;
    }

    cout << "Enter elements: " << endl;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cin >> B[i][j];
        }
    }
}

void displayres(){
    cout<<"Resultant Matrix :"<<endl;
    for(int i = 0; i < resrows; i++){
        for(int j = 0; j < rescols; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}

void matrixmul(){
    if(cols1 != rows2){
        cout<<"Matrix multiplication NOT POSSIBLE"<<endl;
        return;
    }
    resrows = rows1;
    rescols = cols2;
    for(int i = 0; i < resrows; i++){
        for(int j = 0; j < rescols; j++){
            res[i][j] = 0;
            for(int k = 0; k < cols1; k++){
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(){
    createArr();

    matrixmul();
    displayres();

    return 0;
}
