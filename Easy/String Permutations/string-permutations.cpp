//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string> ans;
    void solve(string &S, string& temp, vector<bool> &status, int n){
        if(temp.size() == n){
            ans.push_back(temp);
        }
        for(int i = 0; i < n; i++){
            if(!status[i]){
                temp.push_back(S[i]);
                status[i] = true;
                solve(S, temp, status, n);
                temp.pop_back();
                status[i] = false;
            }
        }
    }
    vector<string> permutation(string S){
        string temp;
        int n = S.length();
        vector<bool> status(S.length());
        solve(S, temp, status, n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends