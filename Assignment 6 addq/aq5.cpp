#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
    Node(int val) : data(val), next(NULL), prev(NULL), up(NULL), down(NULL) {}
};

Node* constructFromMatrix(const vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return NULL;
    int R = mat.size(), C = mat[0].size();
    vector<vector<Node*>> grid(R, vector<Node*>(C));

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            grid[i][j] = new Node(mat[i][j]);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (j + 1 < C) {
                grid[i][j]->next = grid[i][j + 1];
                grid[i][j + 1]->prev = grid[i][j];
            }
            if (i + 1 < R) {
                grid[i][j]->down = grid[i + 1][j];
                grid[i + 1][j]->up = grid[i][j];
            }
        }
    }
    return grid[0][0];
}

void printRowWise(Node* head) {
    Node* row = head;
    while (row) {
        Node* col = row;
        while (col) {
            cout << col->data << " ";
            col = col->next;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = constructFromMatrix(mat);
    printRowWise(head);
    return 0;
}
