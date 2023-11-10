//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        int n = s.length(), current = 1, i = 0;
        string ans;
        ans.push_back('1');
        while(i < n){
            if(s[i] == 'D'){
                int j = i;
                while(j < n and s[j] == 'D'){
                    j++;
                }
                int no_of_D = j - i;
                current += no_of_D;
                ans[i] = (current + '0');
                int count = current;
                while(i != j){
                    count--;
                    ans.push_back(count + '0');
                    i++;
                }
            }else{
                current++;
                ans.push_back(current + '0');
                i++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends