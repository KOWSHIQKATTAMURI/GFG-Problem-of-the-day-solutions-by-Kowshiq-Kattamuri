//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    long long countWays(int n, int k){
        long long total = k, diff = k, same = 0, mod = 1e9 + 7;
        for(int sections = 2; sections <= n; sections++){
            same = diff;
            diff = ((k - 1)%mod*total%mod)%mod;
            total = (same + diff)%mod;
        }
        return total;
    }
};


//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends