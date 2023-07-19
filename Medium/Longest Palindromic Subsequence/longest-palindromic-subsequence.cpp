//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int lcs(string org, string temp){
        int n = org.length();
        vector<vector<int>> kow(n + 1, vector<int>(n + 1));
        for(int i = 0; i <= n; i++){
            kow[i][0] = 0;
            kow[0][i] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(org[i - 1] == temp[j - 1]){
                    kow[i][j] = 1 + kow[i - 1][j - 1];
                }else{
                    kow[i][j] = max(kow[i - 1][j], kow[i][j - 1]);
                }
            }
        }
        return kow[n][n];
    }
    int longestPalinSubseq(string A){
        string org = A;
        reverse(A.begin(), A.end());
        string temp = A;
        return lcs(org, temp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends