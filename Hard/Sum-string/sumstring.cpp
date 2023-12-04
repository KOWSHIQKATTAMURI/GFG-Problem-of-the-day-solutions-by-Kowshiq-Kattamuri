//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string string_sum(string num1, string num2){
        int i = num1.size()-1;
        int j = num2.size()-1;
        string output = "";
        int carry = 0;
        while(i >= 0 or j >= 0 or carry){
            int sum = carry;
            if(i >= 0){
                sum += num1[i--] - '0';
            }
            if(j >= 0){
                sum += num2[j--] - '0';
            }
            int rem = sum % 10;
            carry = sum / 10;
            output.push_back(rem + '0');
        }
        reverse(output.begin(), output.end());
        return output;
    }
    bool checkSumStrUtil(string str, int beg, int len1, int len2){
        string s1 = str.substr(beg, len1);
        string s2 = str.substr(beg + len1, len2);
        string s3 = string_sum(s1, s2);
        int s3_len = s3.size();
        if(s3_len > str.size() - len1 - len2 - beg){
            return false;
        }
        if(s3 == str.substr(beg + len1 + len2, s3_len)){
            if(beg + len1 + len2 + s3_len == str.size()){
                return true;
            }
            return checkSumStrUtil(str, beg + len1, len2, s3_len);
        }
        return false;
    }
    int isSumString(string str){
        int n = str.size();
        for(int i = 1; i < n; i++){
            for(int j = 1; i + j < n; j++){
                if(checkSumStrUtil(str, 0, i, j)){
                    return 1;
                }
            }
        }
        return 0;
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
        cout << ob.isSumString(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends