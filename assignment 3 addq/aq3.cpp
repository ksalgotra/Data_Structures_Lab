# include<iostream>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n, 0);
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && arr[i] >= s.top()){
                s.pop();
            }
                
            if(!s.empty())ans[i] = s.top();
            else ans[i] = -1;
            
            s.push(arr[i]);
        }
        
        return ans;
    }
};
