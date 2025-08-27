#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int r = n - 1;
        int curr = 0;
        while (curr <= r) {
            if (arr[curr] == 0) {
                swap(arr[l], arr[curr]);
                l++;
                curr++;
            } else if (arr[curr] == 2) {
                swap(arr[curr], arr[r]);
                r--;
            } else {
                curr++;
            }
        }
    }
};

int main() {
    vector<int> arr = {0, 2, 1, 2, 0, 1, 0, 2};// sample testcase
    Solution s;
    s.sort012(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
