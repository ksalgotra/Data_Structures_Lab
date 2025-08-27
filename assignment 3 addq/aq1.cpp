# include<iostream>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    int n = A.size();
    stack<int> s;
    vector<int> res(n, 0);
    
    for(int i = 0; i < n; i++){
        
        while(!s.empty() && s.top() >= A[i]){
            s.pop();
        }
        
        if(s.empty())res[i] = -1;
        else res[i] = s.top();
        
        s.push(A[i]);
    }
    
    return res;
}
