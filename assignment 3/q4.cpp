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

bool isadigit(char ch){
    if(ch >= '0' && ch <= '9'){
        return true;
    }
    return false;
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(string& infix, string& postfix){
    Stack st;
    int n = infix.length();

    for(int i = 0; i < n; i++){
        char ch = infix[i];

        if(ch == ' ')continue;
        else if(isadigit(ch)){
            
            while(i < n && isadigit(infix[i])){
                postfix += infix[i++];
            }
            postfix += ' ';
            i--;

        }
        else if(ch == '('){
            st.push(ch);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(!st.isEmpty() && precedence(st.peek()) >= precedence(ch)){
                postfix += st.pop();
                postfix += ' ';
            }
          
            st.push(ch);
        }
        else if(ch == ')'){
            while(!st.isEmpty() && st.peek() != '('){
                postfix += st.pop();
                postfix += ' ';
            }
            st.pop();
        }
        
    }
    while(!st.isEmpty()){
        postfix += st.pop();
        postfix += ' ';
    }
}



int main(){
    string infix = "";
    getline(cin, infix);

    string postfix = "";
    infixToPostfix(infix, postfix);
    cout << "Postfix :" << postfix << endl;
    return 0;
}
