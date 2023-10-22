//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    long long mod = 1e9 + 7;
    long long inv(long long base, long long exponent){
        long long ans = 1;
        while(exponent > 0){
            if(exponent%2 == 1){
                ans = (ans*base)%mod;
            }
            base = (base*base)%mod;
            exponent /= 2;
        }
        return ans;
    }
    long long  numberOfPaths(int rows, int cols){
        long long total_steps = rows + cols - 2;
        long long min_steps = min(rows - 1, cols - 1);
        long long numerator = 1, denominator = 1;
        for(long long i = 0; i < min_steps; i++){
            numerator = (numerator*(total_steps - i))%mod;
            denominator = (denominator*(i + 1))%mod;
        }
        long long inverse_denominator = inv(denominator%mod, mod - 2);
        return (numerator*inverse_denominator)%mod;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends