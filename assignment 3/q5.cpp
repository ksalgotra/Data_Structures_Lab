# include<iostream>
# include<string>
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
        top = top + 1;
        arr[top] = x;
    }

    int pop(){
        if(top != -1){
            int ele = arr[top];
            top = top - 1;
            return ele;
        }
        cout << "UNDERFLOW" << endl;
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

    int size(){
        return top + 1;
    }
};

bool isadigit(char ch){
    if(ch >= '0' && ch <= '9'){
        return true;
    }
    return false;
}


int postfixevaluation(string& postfix){
    Stack st;
    int n = postfix.length();

    for(int i = 0; i < n; i++){
        char ch = postfix[i];

        if(ch == ' '){
            continue;
        }
        else if(isadigit(ch)){
            int num = 0;
            while(i < n && isadigit(postfix[i])){
                int dig = postfix[i++] - '0';
                num = num * 10 + dig;
            }
            i--;
            st.push(num);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            if(st.size() < 2){
                cout << "ERROR: insufficent operands." << endl;
                return -1;
            }
            else{
                int operand2 = st.pop();
                int operand1 = st.pop();

                int ans = 0;
                switch (ch) {
                    case '+' :
                        ans = operand1 + operand2;
                        break;
                    case '-' :
                        ans = operand1 - operand2;
                        break;
                    case '*' :
                        ans = operand1 * operand2;
                        break;
                    case '/' :
                        if(operand2 == 0){
                            cout << "ERROR: division by zero\n";
                            return -1;
                        }
                        ans = operand1 / operand2;
                        break;
                    default :
                        break;
                }
                st.push(ans);
            }
        }
    }

    if(st.size() != 1){
        cout << "ERROR: invalid expression" << endl;
        return -1;
    }

    return st.peek();
}


int main(){
    string postfix = "";
    cout << "Enter postfix : ";
    getline(cin, postfix);
    int val = postfixevaluation(postfix);
    cout << "Value of expression :" << val << endl;
    return 0;
}
