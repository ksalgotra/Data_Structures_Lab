#include <iostream>
#include<string>
using namespace std;

bool checkisSubstr(const string &s1, const string &s2) {
    int m = s1.length();
    int n = s2.length();
    if (m > n) return false;

    // sliding window over s2
    for (int i = 0; i + m <= n; i++) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            if (s2[i + j] != s1[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

int main() {
	// your code goes here
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;  
    cin >> t;   // number of test cases
    while (t--) {
        string str;
        cin >> str;
        
        /* we set a partition where we see if we the left and right parts
        and check whether there is one which is a substring of another then
        we can conclude that it is possible 
        and do this for all three
        */
        int n = str.length();
        bool isYes = false;

        for (int part1 = 1; part1 <= n - 2 && !isYes; part1++) {
            for (int part2 = part1 + 1; part2 <= n - 1; part2++) {
                string X = str.substr(0, part1);
                string Y = str.substr(part1, part2 - part1);
                string Z = str.substr(part2);

                if ((checkisSubstr(Y, X) && checkisSubstr(Y, Z)) ||
                    (checkisSubstr(X, Y) && checkisSubstr(X, Z)) ||
                    (checkisSubstr(Z, X) && checkisSubstr(Z, Y))) {
                    isYes = true;
                    break;  
                }
            }
        }
        
        if(isYes) cout << "YES";
        else cout << "NO";
        
        cout << endl;
    }
}
