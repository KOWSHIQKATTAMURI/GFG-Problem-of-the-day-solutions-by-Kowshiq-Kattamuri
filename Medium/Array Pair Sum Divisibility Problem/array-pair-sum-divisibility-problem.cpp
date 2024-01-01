//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k){
        if(nums.size()%2 != 0){
            return false;
        }
        unordered_map<int, int> mp;
        for(int i : nums){
            int y = i%k;
            if(mp[(k - y)%k] != 0){
                mp[(k - y)%k]--;
            }
            else{
                mp[y]++;
            }
        }
        for(auto it : mp){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends