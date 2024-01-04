//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N){
        vector<int> count(32, 0);
        for(int bit = 0; bit < 32; bit++){
            for(int i = 0; i < N; i++){
                if(arr[i]&(1<<bit)){
                    count[bit]++;
                }
            }
        }
        int ans = 0;
        for(int bit = 0; bit < 32; bit++){
            if(count[bit]%3 != 0){
                ans += (1 << bit);
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
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends