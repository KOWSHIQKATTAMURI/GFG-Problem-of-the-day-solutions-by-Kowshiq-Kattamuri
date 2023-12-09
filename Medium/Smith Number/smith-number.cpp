//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int digitsum(int n){
        int temp = n, ans = 0;
        while(temp != 0){
            ans += temp % 10;
            temp /= 10;
        }
        return ans;
    }
    int smithNum(int n){
        int sum = 0, k = n, temp = digitsum(n);
        for(int i = 2; i <= sqrt(n); i++){
            while(n % i == 0){
                sum += digitsum(i);
                n /= i;
            }
        }
        if(n > 1 && n != k){
            sum += digitsum(n);
        }
        return sum == temp ? 1 : 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends