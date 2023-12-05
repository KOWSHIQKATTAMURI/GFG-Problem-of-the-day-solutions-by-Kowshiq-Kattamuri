//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int getMinDiff(int A[], int n, int K){
        sort(A, A + n);
        int ans = A[n - 1] - A[0];
        int minimum = A[0] + K;
        int maximum = A[n - 1] - K;
        int current_minimum, current_maximum;
        for(int i = 0; i < n - 1; i++){
            current_minimum = min(A[i + 1] - K, minimum);
            current_maximum = max(A[i] + K, maximum);
            if(current_minimum >= 0){
                ans = min(ans, current_maximum - current_minimum);
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
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends