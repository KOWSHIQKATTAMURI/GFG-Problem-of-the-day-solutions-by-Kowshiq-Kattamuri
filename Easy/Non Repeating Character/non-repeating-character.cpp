//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S){
       vector<int> status(26, 0);
       for(auto h : S){
           status[h - 'a']++;
       }
       char temp = '$';
       for(int i = 0; i < S.length(); i++){
           if(status[S[i] - 'a'] == 1){
               temp = S[i];
               break;
           }
       }
       return temp;
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends