//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k){
        int ans = -1, unique = 0, n = s.length();
        vector<int> hash(26, 0);
        for(int left = 0, right = 0; right < n; right++){
            unique += (++hash[s[right] - 'a'] == 1);
            while(unique > k){
                unique -= (--hash[s[left] - 'a'] == 0);
                left++;
            }
            if(unique == k and left <= right){
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends