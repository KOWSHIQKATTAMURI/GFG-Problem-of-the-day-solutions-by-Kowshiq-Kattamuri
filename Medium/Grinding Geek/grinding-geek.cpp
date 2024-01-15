//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int max_courses(int n, int total, vector<int> &cost){
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));
        for(int i = n; i >= 0; i--){
            for(int j = 0; j <= total; j++){
                if(i == n or j == 0){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i + 1][j];
                    if(j >= cost[i]){
                        dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j - cost[i] + (9*cost[i]/10)]);
                    }
                }
            }
        }
        return dp[0][total];
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends