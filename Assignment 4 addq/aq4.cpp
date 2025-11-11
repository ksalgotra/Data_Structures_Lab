#include<iostream>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> st;
        queue<int> q;

        for (int student : students)
            q.push(student);

        for (int i = sandwiches.size() - 1; i >= 0; --i)
            st.push(sandwiches[i]);
        
        int rotations = 0;
        while (!q.empty() && rotations < q.size()) {
            if (q.front() == st.top()) {
                q.pop();
                st.pop();
                rotations = 0;  
            } else {
                int ele = q.front();
                q.pop();
                q.push(ele);     
                rotations++;    
            }
        }

        return q.size();
    }
};

int main() {
    Solution sol;

    vector<int> students2 = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches2 = {1, 0, 0, 0, 1, 1};
    cout << "Students unable to eat: " << sol.countStudents(students2, sandwiches2) << endl;
    return 0;
}
