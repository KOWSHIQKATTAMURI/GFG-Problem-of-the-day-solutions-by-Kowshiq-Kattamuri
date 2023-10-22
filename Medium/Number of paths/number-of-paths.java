//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GfG { 
    
	public static void main (String[] args) throws IOException  {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim());
		while(t-->0){
		    String inputLine[] = br.readLine().trim().split(" ");
		    int M = Integer.parseInt(inputLine[0]);
		    int N = Integer.parseInt(inputLine[1]);
		    Solution ob = new Solution();
		    System.out.println(ob.numberOfPaths(M, N));
		}
	}
}




// } Driver Code Ends


class Solution{
    long mod = 1000000007L;
    long binary_exponent(long base, long exponent){
        long ans = 1;
        while(exponent > 0){
            if((exponent & 1) == 1){
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            exponent >>= 1;
        }
        return ans;
    }
    long numberOfPaths(int rows, int cols){
        long n = rows + cols - 2;
        long r = Math.min(rows - 1, cols - 1);
        long numerator = 1, denominator = 1;
        for(long i = 0; i < r; i++){
            numerator = (numerator * (n - i)) % mod;
            denominator = (denominator * (i + 1)) % mod;
        }
        long MMI_B = binary_exponent(denominator % mod, mod - 2);
        return (numerator * MMI_B) % mod;
    }
}

