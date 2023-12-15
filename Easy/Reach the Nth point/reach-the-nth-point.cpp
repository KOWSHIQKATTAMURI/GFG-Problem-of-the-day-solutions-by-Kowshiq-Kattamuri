//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
		int nthPoint(int n){
		    int zeroth = 1, first = 1, mod = 1e9 + 7, ways = 0;
		    for(int ith_step = 2; ith_step <= n; ith_step++){
		        ways = (zeroth%mod + first%mod)%mod;
		        zeroth = first;
		        first = ways;
		    }
		    return first;
		}
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends