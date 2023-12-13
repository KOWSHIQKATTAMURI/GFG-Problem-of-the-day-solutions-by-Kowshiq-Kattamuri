//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	ll countStrings(int n){
	    ll prev_zero = 1, prev_one = 1, curr_zero = 1, curr_one = 1, mod = 1e9 + 7;
	    for(int i = 2; i <= n; i++){
	        curr_zero = (prev_zero + prev_one)%mod;
	        curr_one = prev_zero%mod;
	        prev_zero = curr_zero;
	        prev_one = curr_one;
	    }
	    return (curr_one + curr_zero)%mod;
	}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends