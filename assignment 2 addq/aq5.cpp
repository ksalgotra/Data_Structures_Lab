# include<iostream>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(n, 0);
        int idx = 0;
        int i = 0;
        while(idx < n){
            temp[idx] = arr[i];
            if(arr[i] == 0){
                if(idx + 1 < n){
                    temp[idx + 1] = arr[i];
                    idx++;
                }
            }
            idx++;
            i++;
        }

        for(int i = 0; i < n; i++){
            arr[i] = temp[i];
        }

    }
};
