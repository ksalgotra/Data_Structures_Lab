# include<iostream>
# include<string>
using namespace std;

int max_size = 100;

class Stack {
    int top;
    char arr[100];

public:
    Stack(){
        top = -1;
    }

    void push(char x){
        top = top + 1;
        arr[top] = x;
    }

    char pop(){
        if(top != -1){
            char ele = arr[top];
            top = top - 1;
            return ele;
        }
        
        return '\0';
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

    char peek(){
        if(!isEmpty()) return arr[top];

        return '\0';
    }
};

void reverse_string(string& s){
    Stack st;
    for(char ch : s){
        st.push(ch);
    }
    int idx = 0;

    while(!st.isEmpty()){
        s[idx++] = st.peek();
        st.pop();
    }
}

int main(){
    string s = "";

    cout << "Please enter a string : ";
    getline(cin, s);

    reverse_string(s);

    cout << s;

    return 0;
}

