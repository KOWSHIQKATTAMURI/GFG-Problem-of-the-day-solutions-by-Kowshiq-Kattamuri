//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	void sieveOfEratosthenes(int n, vector<int> &prime){
        for(int i = 2; i*i <= n; i++){
            if(prime[i] == 0){
                for(int j = i*i; j <= n; j = j + i){
                   if(prime[j] == 0){
                       prime[j] = i;
                   }
                }
            }
        }
    }
	int sumOfPowers(int a, int b){
	    int points = 0;
	    vector<int> prime(b + 1, 0), dp(b + 1, 0);
	    sieveOfEratosthenes(b, prime);
	    for(int num = 2; num <= b; num++){
	        if(prime[num] == 0){
	            dp[num] = 1;
	        }else{
	            dp[num] = 1 + dp[num/prime[num]];
	        }
	        points += (num >= a) ? dp[num] : 0;
	    }
	    return points;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends