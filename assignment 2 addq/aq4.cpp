#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int r = n - 1;
        int curr = 0;// current element i.e.
        
        while(curr <= r){
            if(arr[curr] == 0){
                swap(arr[l], arr[curr]);
                l++;
                curr++;
            }
            else if(arr[curr] == 2){
                swap(arr[curr], arr[r]);
                r--;
            }
            else{
                curr++;
            }
        }
    }
};
