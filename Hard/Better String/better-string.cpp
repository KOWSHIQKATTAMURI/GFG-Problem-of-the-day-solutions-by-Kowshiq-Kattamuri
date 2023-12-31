//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int distinct(string s){
        unordered_map<char, int> mp;
        int total = 0;
        for(int i = 0; i < s.length(); i++){
            int present = total + 1;
            if(mp[s[i]]){
                total += (present - mp[s[i]]);
            }else{
                total += present;
            }
            mp[s[i]] = present;
        } 
        return total;
    }
    string betterString(string str1, string str2){
        int distinct_one = distinct(str1);
        int distinct_two = distinct(str2);
        return distinct_one >= distinct_two ? str1 : str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends