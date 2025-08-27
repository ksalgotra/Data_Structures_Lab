#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        int count = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (m.find(k + arr[i]) != m.end()) {
                count += m[k + arr[i]];
            }
            if (k != 0 && m.find(-k + arr[i]) != m.end()) {
                count += m[-k + arr[i]];
            }
            m[arr[i]]++;
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 5, 3, 4, 2};// sample testcase
    int k = 2;
    cout << s.countPairs(arr, k) << endl;
    return 0;
}
