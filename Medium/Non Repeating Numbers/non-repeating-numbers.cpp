//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the set bit.
    int getbitposition(int x){
        int pos = 0;
        while((x&1) != 1){
            pos++;
            x >>= 1;
        }
        return pos;
    }
//Explanation: 
	    // 1. The concept used here is that XOR of all those elements will be zero if their frequency is even.
	    // 2. If the frequence is odd, then the XOR will result in that particular element
	    // 3. Ex: In the array {1,1,2,3,3,4,4,5,5}, the XOR of all the elements will result in 2.
	    // 4. Ex: In the array {1,1,2,3,3,4,4,5,5,6,6,6}, the XOR of all the elements will result in 2(XOR)6.
	    // 5. So, take the XOR of all elements in the array and store the result in the variable named x.
	    // 6. Find the position of any set bit in x. Let it be k.
	    // 7. Take two elements int a = 0, b = 0. 
	    // 8. If any particular element in the array has the sit bit at k, then take it XOR with a, else take it XOR with b.
	    // 9. The final values of a, b will be the required result. 
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
