//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str){
        int n = str.size();
        vector<vector<bool>> dp(n, vector<bool> (n, true));
        for(int k = 1; k < n; k++){
            for(int i = 0; i < n - k; i++){
                int j = i + k;
                dp[i][j] = (str[i] == str[j] and dp[i + 1][j - 1]);
            }
        }
        vector<int> cuts(n + 1);
        cuts[0] = -1;
        for(int i = 1; i <= n; i++){
            cuts[i] = n;
            for(int j = 1; j <= i; j++){
                if(dp[j - 1][i - 1]){
                    cuts[i] = min(cuts[i], cuts[j - 1] + 1);
                }
            }
        }
        return cuts[n];
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends