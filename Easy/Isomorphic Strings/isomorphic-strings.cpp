//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution{
    public:
    bool areIsomorphic(string s1, string s2){
        if(s1.length() != s2.length()){
            return false;
        }
        vector<int> map(26, -1);
        int n = s1.length(), used = 0;
        for(int i = 0; i < n; i++){
            if(map[s1[i] - 'a'] != -1){
                if(map[s1[i] - 'a'] != s2[i] - 'a'){
                    return false;
                }
            }else{
                if((used >> (s2[i] - 'a'))&1){
                    return false;
                }else{
                    map[s1[i] - 'a'] = s2[i] - 'a';
                    used |= (1 << (s2[i] - 'a'));
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends