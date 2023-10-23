//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    int Arr[] = new int[n];
                    for(int i = 0;i<n;i++)
                        Arr[i] = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.maxSumIS(Arr,n));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution{
	public int maxSumIS(int arr[], int n){  
	    int dp[] = new int[n];
	    System.arraycopy(arr, 0, dp, 0, n);
	    int ans = dp[0];
	    for(int i = 1; i < n; i++){
	        for(int j = i - 1; j >= 0; j--){
	            if(arr[j] < arr[i]){
	                dp[i] = Math.max(dp[i], dp[j] + arr[i]);
                }
            }
            ans = Math.max(ans, dp[i]);
	    }
	    return ans;
	}  
}
