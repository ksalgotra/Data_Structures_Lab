# include<iostream>
using namespace std;

class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairs(vector<int>& arr, int k) {
        unordered_map <int, int> m;
        //  map to store frequency of ele seen
        // abs(arr[j] - arr[i]) = k;
        // case 1 : arr[j] = k + arr[i];
        // case 2 : arr[j] = -k + arr[i];
        int count = 0;
        for(int i = arr.size() - 1; i >= 0; i--){
            if(m.find(k + arr[i]) != m.end()){
                 count+= m[k + arr[i]];
            }
            if(m.find(-k + arr[i]) != m.end()){
                count += m[-k + arr[i]];
            }
            m[arr[i]]++;
        }
        
        return count;
    }
};
