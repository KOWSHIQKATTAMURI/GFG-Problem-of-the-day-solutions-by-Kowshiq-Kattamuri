//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    bool subArrayExists(int arr[], int n){
        unordered_map<int, int> mp;
        mp[arr[0]]++;
        for(int i = 1; i < n; i++){
            arr[i] += arr[i - 1];
            mp[arr[i]]++;
        }
        for(auto it : mp){
            if(it.first == 0 or it.second > 1){
                return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends