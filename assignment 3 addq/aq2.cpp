# include<iostream>
using namespace std;


class Solution {
    stack<int> st;
    stack<int> mst;
    int min_val;
  public:
    Solution() {
        min_val = INT_MAX;
    }

    
    void push(int x) {
        min_val = min(x, min_val);
        st.push(x);
        mst.push(min_val);
    }

   
        
    void pop() {
        if(st.size() > 0){
            st.pop();
            mst.pop();
            if(mst.size() > 0)min_val = mst.top();
            else min_val = INT_MAX;
        }
    }

        

    int peek() {
        if(st.size() > 0){
            return st.top();
        }
        return -1;
    }
        

    // Finds minimum element of Stack
    int getMin() {
        if(!mst.empty())return min_val;
        
        return -1;
    }
};
