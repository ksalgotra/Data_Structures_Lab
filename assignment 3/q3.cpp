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



bool isMatching(char open, char close){
    return  (open == '(' && close == ')') ||
            (open == '{' && close == '}') || 
            (open == '[' && close == ']');
}

bool isBalancedParenthesis(string str, Stack& s){
    int idx = 0;
    while(str[idx] != '\0'){
        char ch = str[idx];
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(s.isEmpty() || !isMatching(s.peek(), ch)){
                return false;
            }
            else{
                s.pop();
            }
        }
        idx++;
    }
    if(s.isEmpty()){
        return true;
    }

    return false;
}

int main(){
    string str = "";
    cout << "Enter expression :";
    cin >> str;
    Stack s;
    if(isBalancedParenthesis(str, s)){
        cout << "The expression contains BALANCED PARANTHESES" << endl;
    }
    else{
        cout << "The expression does NOT CONTAIN BALANCED PARANTHESES" << endl;
    }

    return 0;
}
