class Solution:
    def shuffleArray(self, arr, n):
        m = n//2
        for i in range(m):
            arr[i + m] += arr[i]*1001
        for i in range(m):
            arr[2*i] = arr[i + m]//1001
            arr[2*i + 1] = arr[i + m]%1001


#{ 
 # Driver Code Starts
if __name__ == '__main__': 
    
    t=int(input())
    for _ in range(0,t):
        n=int(input())
        a = list(map(int,input().split()))
        ob = Solution()
        ob.shuffleArray(a,n)
        print(*a)
# } Driver Code Ends