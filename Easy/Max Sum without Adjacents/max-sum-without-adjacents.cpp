//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:	
	int findMaxSum(int *arr, int n){
	    int prev_first_idx_best = 0, prev_second_idx_best = 0;
	    for(int i = 0; i < n; i++){
	        int temp = prev_first_idx_best;
	        prev_first_idx_best = max(prev_first_idx_best, arr[i] + prev_second_idx_best);
	        prev_second_idx_best = temp;
	    }
	    return prev_first_idx_best;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends