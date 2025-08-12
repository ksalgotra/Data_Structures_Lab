# include<iostream>
using namespace std;

int a[50];
int n = 50;
int size = 0;
void createArr(){
    cout<<"Enter size of array :";
    cin>>size;
    if(size > n){
        cout<<"Invalid Input"<<endl;
        return;
    }
    cout<<"Enter elements :";
    for(int i = 0; i < size; i++){
        cin>>a[i];
    }
}

void display(){
    for(int i = 0; i < size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void insert(){
    int val, pos;
    cout<<"Enter the element to be inserted and its position :";
    cin>>val>>pos;
    if(pos < 1 || pos > size + 1){
        cout<<"Invalid Operation"<<endl;
        return;
    }
    if(size + 1 > n){
        cout<<"Array is already full"<<endl;
        return;
    }

    for(int i = size - 1; i >= pos - 1; i--){
        a[i + 1] = a[i];
    }

    a[pos - 1] = val;
    size++;

}

void deleteval(){
    int pos;
    cout<<"Enter the position of the element to be deleted :";
    cin>>pos;
    if(pos < 1 || pos > size){
        cout<<"Invalid Operation"<<endl;
        return;
    }
    if(size == 0){
        cout<<"Array is already empty"<<endl;
        return;
    }

    for(int i = pos - 1; i < size - 1; i++){
        a[i] = a[i + 1];
    }

    size--;
}

int linearSearch(){
    int val;
    cout<<"Enter value to be searched :";
    cin>>val;

    for(int i = 0; i < size; i++){
        if(a[i] == val){
            return i;
        }
    }

    return -1;
}

int main(){
    int res;
    bool ison = true;
    createArr();

    char ch = 'y';
    while(ison == true){

        int num;
        cout<<"Press 1 for CREATE\nPress 2 for DISPLAY\nPress 3 for INSERT\nPress 4 for DELETE\nPress 5 for LINEAR SEARCH\nPress 6 for EXIT\n";
        cout<<"Please press the button :";
        cin>>num;
        switch (num) {
            case 1 :
                createArr();
                break;
            case 2 :
                display();
                break;
            case 3 :
                insert();
                break;
            case 4 :
                deleteval();
                break;
            case 5 :
                res = linearSearch();
                (res == -1)? cout<<"Value not found\n" : cout<<"Value found at index :"<<res<<endl;
                break;
            case 6 :
                ison = false;
                break;
            default :
                cout<<"\nPlease enter valid input\n";
        }

    }

    return 0;
}
