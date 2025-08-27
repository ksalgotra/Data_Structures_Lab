#include <iostream>
#include<string>
using namespace std;

int main() {
	
    
    int t;
    cin >> t;
    while(t > 0){
        vector<int> freq(26, 0);
        
        string str1;
        cin >> str1;
        string str2; 
        cin >> str2;
        
        bool isYes = true;
        
        if(str1.length() != str2.length()) isYes = false;
        else {
            
            for(char ch : str1){
                freq[ch - 'a']++;
            }
            
            for(char ch : str2){
                freq[ch - 'a']--;
            }
            
            for(int val : freq){
                if(val != 0){
                    isYes = false;
                }
            }
        }
        
        cout << (isYes ? "YES" : "NO") << endl;

        
        t--;
    }
}
