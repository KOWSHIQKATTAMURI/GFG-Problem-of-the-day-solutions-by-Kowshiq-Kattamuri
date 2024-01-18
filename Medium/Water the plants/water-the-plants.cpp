//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n){
        vector<pair<int, int>> V;
        for(int i = 0; i < n; i++){
            if(gallery[i] > -1){
                V.push_back(pair<int, int>(i - gallery[i], i + gallery[i]));
            }
        }
        sort(V.begin(), V.end());
        int max_right = 0, ans = 0, idx = 0;
        while(max_right < n){
            if(idx == n or V[idx].first > max_right){
                return -1;
            }
            int curr_max = V[idx].second;
            while(idx + 1 < n and V[idx + 1].first <= max_right){
                idx++;
                curr_max = max(curr_max, V[idx].second);
            }
            if(curr_max < max_right){
                return -1;
            }
            ans++;
            max_right = curr_max + 1;
            idx++;
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
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends