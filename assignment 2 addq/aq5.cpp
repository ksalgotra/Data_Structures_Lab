#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateTwos(vector<int>& arr) {
        int n = arr.size();
        int ndt = 0; 

        
        for (int val : arr) {
            if (val == 2) ndt++;
        }

        int i = n - 1;
        int j = n + ndt - 1; 

        while (i != j) {
            if (j < n) {
                arr[j] = arr[i];
            }
            j--;
            if (arr[i] == 2) {
                if (j < n) {
                    arr[j] = arr[i]; 
                }
                j--;
            }
            i--;
        }
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 5, 0};// sample testcase

    Solution s;
    s.duplicateTwos(arr);

    
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
