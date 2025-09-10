# include<iostream>
# include<vector>
# include<string>
using namespace std;

vector<string> GenerateBinary(int& n){
    vector<string> ans;
    queue<string> q;
    if(n < 1)return {""};
    q.push("1");
    ans.push_back(q.front());
    string s1 = "", s2 = "";
    while(ans.size() < n && q.size() > 0){
        if(ans.size() < n && !s1.empty())ans.push_back(s1);
        if(ans.size() < n && !s2.empty())ans.push_back(s2);
        string temp = q.front();
        q.pop();
        s1 = temp + "0";
        s2 = temp + "1";
        q.push(s1);
        q.push(s2);
    }
    return ans;
}


int main(){
    int n;
    cout << "Enter the number : ";
    cin >> n;
    vector<string> sol = GenerateBinary(n);
    int num = 1;
    for(string s : sol){
        cout << num++ << " binary : " << s << endl;
    }

    return 0;
}
