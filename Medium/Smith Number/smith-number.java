//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.smithNum(n));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int digitsum(int n){
        int ans = 0;
        while(n > 0){
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    static int smithNum(int n){
        int sum = 0, k = n, temp = digitsum(n);
        for(int i = 2; i <= Math.sqrt(n); i++){
            while(n % i == 0){
                sum += digitsum(i);
                n /= i;
            }
        }
        if(n > 1 && n != k){
            sum += digitsum(n);
        }
        return sum == temp ? 1 : 0;
    }
};

