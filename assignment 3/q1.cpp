# include<iostream>
using namespace std;

int max_size = 100;

class Stack {
    int top;
    int arr[100];

    public:
    Stack(){
        top = -1;
    }

    void push(int x){
        if(isFull()){
        cout << "Stack overflow! Cannot push " << x << endl;
        return;
        }
        top = top + 1;
        arr[top] = x;
    }

    int pop(){
        if(top != -1){
            int ele = arr[top];
            top = top - 1;
            return ele;
        }
        else{
            cout << "Stack underflow! Cannot pop " << endl;
        }
        return -1;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }

        return false;
    }

    bool isFull(){
        if(top == max_size - 1){
            return true;
        }

        return false;
    }

    void Display(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Displaying Stack :";
        for(int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int peek(){
        if(!isEmpty()) return arr[top];

        return -1;
    }
};

int main(){
    Stack s;

    while(true){
        int num;
        cout << "Please enter the operation you want to preform with stack :" << endl;
        cout << "1 for push :" << endl;
        cout << "2 for pop :" << endl;
        cout << "3 for isEmpty :" << endl;
        cout << "4 for isFull :" << endl;
        cout << "5 for display :" << endl;
        cout << "6 for peek :" << endl;
        cin >> num;
        int x;
        int val;
        switch (num){
            case 1:
                cout << "Enter element to push :" << endl;
                cin >> x;
                s.push(x);
                break;
            case 2:
                val = s.pop();
                if (val != -1)cout << val << " has been popped from the top" << endl;
                break;
            case 3:
                if(s.isEmpty()){
                    cout << "Stack is empty" << endl;
                }
                else{
                    cout << "Stack is not empty" << endl;
                }
                break;
            case 4:
                if(s.isFull()){
                    cout << "Stack is full" << endl;
                }
                else{
                    cout << "Stack is not full" << endl;
                }
                break;
            case 5:
                s.Display();
                break;
            case 6:
                cout << "Element at top is " << s.peek() << endl;
                break;
            default:
                cout << "Invalid Operation." << endl;
                break;
        }

        char ch = 'y';
        cout << "Press 'y' if you want to continue, any other key to discontinue :";
        cin >> ch;
        if(ch != 'y'){
            break;
        }
    }

    return 0;
}
