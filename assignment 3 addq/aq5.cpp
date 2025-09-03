#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool canBeSorted(vector<int>& A) {
    stack<int> S;
    vector<int> B;
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    int nextIndex = 0;

    for (int x : A) {
        S.push(x);

        while (!S.empty() && S.top() == sortedA[nextIndex]) {
            B.push_back(S.top());
            S.pop();
            nextIndex++;
        }
    }

    return B == sortedA;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter elements: ";
    
    for (int i = 0; i < n; i++) cin >> A[i];

    if (canBeSorted(A)) {
        cout << "array can be sorted." << endl;
    } else {
        cout << "array cannot be sorted." << endl;
    }

    return 0;
}
