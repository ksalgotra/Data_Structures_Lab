#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>
using namespace std;

class Node{
public:
    int v;
    Node* next;
    Node(int val):v(val), next(NULL) {}
};

void displayLL(Node* head){
    if(!head) {
        cout << "NULL" << endl;
        return;
    }
    while(head){
        cout << head->v << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

vector<int> BFS(Node*List_arr[],Node* start){
    vector<int> bfs;
    if(!start) return bfs;

    queue<int> q;
    unordered_set<int> s;

    q.push(start->v);
    s.insert(start->v);

    while(!q.empty()){
        int val = q.front();
        q.pop();

        bfs.push_back(val);

        Node* temp = List_arr[val];
        while(temp){
            if(s.find(temp->v) == s.end()){
                q.push(temp->v);
                s.insert(temp->v);
            }
            temp = temp->next;
        }
    }
    return bfs;
}

vector<int> DFS(Node* List_arr[], Node* start){
    vector<int> dfs;
    if(!start) return dfs;

    unordered_set<int> s;
    stack<int> st;
    
    st.push(start->v);
    s.insert(start->v);

    while(!st.empty()){
        int val = st.top();
        st.pop();

        dfs.push_back(val);

        Node* temp = List_arr[val];
        vector<int> tempVec;
        while(temp){
            if(s.find(temp->v) == s.end()){
                tempVec.push_back(temp->v);
                s.insert(temp->v);
            }
            temp = temp->next;
        }
        for(int i = tempVec.size() - 1; i >= 0; i--){
            st.push(tempVec[i]);
        }
    }
    return dfs;
}

int main(){ 
    int Vn;
    cout << "Enter the number of vertices : ";
    cin >> Vn;
    
    int Adj_matrix[Vn][Vn];
    for(int i = 0; i < Vn; i++){
        for(int j = 0; j < Vn; j++){
            Adj_matrix[i][j] = 0;
        }
    }
    cout << "Enter {source destination} values for the Undirected Graph : " << endl;
    int count = 0;
    while(count < Vn * Vn){
        int i, j;
        cin >> i >> j;
        Adj_matrix[i][j] = 1;
        Adj_matrix[j][i] = 1;
        char ch;
        cout << "Have you entered all the values(Y/n) : ";
        cin >> ch;
        if(ch == 'Y')break;
        count++;
    }

    Node** List_arr = new Node*[Vn];
    for(int k = 0; k < Vn; ++k) List_arr[k] = NULL;

    for(int i = 0; i < Vn; i++){
        Node* head = NULL;
        Node* tail = NULL;
        for(int j = 0; j < Vn; j++){
            if(Adj_matrix[i][j] == 1){
                Node* newNode = new Node(j);
                if(!head){
                    head = tail = newNode;
                }
                else{
                    tail->next = newNode;
                    tail = newNode;
                }
            }
        }
        List_arr[i] = head;
    }

    for(int i = 0; i < Vn; i++){
        cout << i << ": ";
        displayLL(List_arr[i]);
    }

    vector<int> v = BFS(List_arr, List_arr[0]);
    cout << "\nBFS Traversal: ";
    for(int val : v) cout << val << " ";
    cout << endl;

    vector<int> d = DFS(List_arr, List_arr[0]);
    cout << "\nDFS Traversal: ";
    for(int val : d) cout << val << " ";
    cout << endl;

    return 0;
}
