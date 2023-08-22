//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int findMinOpeartion(vector<vector<int>> matrix, int n){
        int max_sum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            int row_sum = 0;
            for(int j = 0; j < n; j++){
                row_sum += matrix[i][j];
            }
            max_sum = max(max_sum, row_sum);
        }
        for(int j = 0; j < n; j++){
            int col_sum = 0;
            for(int i = 0; i < n; i++){
                col_sum += matrix[i][j];
            }
            max_sum = max(max_sum, col_sum);
        }
        for(int i = 0; i < n; i++){
            int row_sum = 0;
            for(int j = 0; j < n; j++){
                row_sum += matrix[i][j];
            }
            ans += (max_sum - row_sum);
        }
        return ans;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends