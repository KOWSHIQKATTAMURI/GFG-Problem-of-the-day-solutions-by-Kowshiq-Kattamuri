//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dissolve(int num){
        int digit_sum = 0;
        while(num > 0){
            digit_sum += num%10;
            num /= 10;
        }
        return digit_sum;
    }
    int isPossible(int N, int arr[]){
        int sum = 0;
        for(int i = 0; i < N; i++){
            sum += dissolve(arr[i]);
        }
        return sum%3 == 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends