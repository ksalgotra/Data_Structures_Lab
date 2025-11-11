#include <iostream>
using namespace std;

bool checkSorted(int n, queue<int>& q)
{
    stack<int> st;
    int expected = 1;
    int front_ele;

    
    while (!q.empty()) {
        front_ele = q.front();
        q.pop();

        if (front_ele == expected)
            expected++;

        else {

            if (st.empty()) {
                st.push(front_ele);
            }


            else if (!st.empty() && st.top() < front_ele) {
                return false;
            }

            else
                st.push(front_ele);
        }

        while (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
    }

    
    if (expected - 1 == n && st.empty())
        return true;

    return false;
}

int main()
{
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    int n = q.size();

    (checkSorted(n, q) ? (cout << "Yes, It can be sorted") : (cout << "No, it can not be sorted"));

    return 0;
}
