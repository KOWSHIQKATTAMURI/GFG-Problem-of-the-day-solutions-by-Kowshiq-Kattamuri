//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int getbitposition(int x){
        int pos = 0;
        while((x&1) != 1){
            pos++;
            x >>= 1;
        }
        return pos;
    }
    vector<int> singleNumber(vector<int> nums){
        int x = 0;
        for(int i = 0; i < nums.size(); i++){
            x ^= nums[i];
        }
        int k = getbitposition(x);
        int a = 0, b = 0;
        for(int i = 0; i < nums.size(); i++){
            if(((nums[i] >> k)&1) == 1){
                a ^= nums[i];
            }else{
                b ^= nums[i];
            }
        }
        if(a >= b){
            return {b, a};
        }
        return {a, b};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends