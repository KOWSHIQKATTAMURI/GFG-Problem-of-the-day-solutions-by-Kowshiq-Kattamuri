//{ Driver Code Starts
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.*;


public class Driver {
    
    public static void main(String[] args)throws IOException {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while(tc-->0)
        {
            String s1 = br.readLine();
            String s2 = br.readLine();
            
            Solution obj = new Solution();
            
            boolean a = obj.areIsomorphic(s1,s2);
            if(a)
            System.out.println(1);
            else
            System.out.println(0);
        }
    }
    
}

// } Driver Code Ends

class Solution{
    public static boolean areIsomorphic(String s1,String s2){
        if(s1.length() != s2.length()){
            return false;
        }
        int[] map = new int[26];
        Arrays.fill(map, -1);
        int n = s1.length(), used = 0;
        for(int i = 0; i < n; i++){
            if(map[s1.charAt(i) - 'a'] != -1) {
                if(map[s1.charAt(i) - 'a'] != s2.charAt(i) - 'a'){
                    return false;
                }
            }else{
                if((used >> (s2.charAt(i) - 'a') & 1) == 1){
                    return false;
                }else{
                    map[s1.charAt(i) - 'a'] = s2.charAt(i) - 'a';
                    used |= (1 << (s2.charAt(i) - 'a'));
                }
            }
        }
        return true;
    }
}

