//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    int solve(int start, int sum, int N, int W, int val[], int wt[]){
        if(sum == W or start >= N){
            return 0;
        }
        if(dp[start][sum] != -1){
            return dp[start][sum];
        }
        int choice_one = 0;
        if(sum + wt[start] <= W){
            choice_one = val[start] + solve(start, sum + wt[start], N, W, val, wt);
        }
        int choice_two = solve(start + 1, sum, N, W, val, wt);
        return dp[start][sum] = max(choice_one, choice_two);
        
    }
    int knapSack(int N, int W, int val[], int wt[]){
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, N, W, val, wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends