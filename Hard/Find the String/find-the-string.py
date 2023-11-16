#User function Template for python3

class Solution:
    def dfs(self, k, prev, seen, edges):
        for i in range(k):
            cur = prev
            cur += str(i)
            if cur not in seen:
                seen.add(cur)
                Solution().dfs(k, cur[1:], seen, edges)
                edges.append(i)

    def findString(self, n, k):
        seen = set()
        startingNode = '0' * (n-1)
        edges = []
        Solution().dfs(k, startingNode, seen, edges)
        ret = ''
        l = k ** n
        for i in range(l):
            ret += str(edges[i])
        ret += startingNode
        return ret






#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N,K=map(int,input().split())

        ob = Solution()
        ans = ob.findString(N,K)
        ok = 1
        for i in ans:
            if ord(i)<48 or ord(i)>K-1+48:
                ok = 0
        if not ok:
            print(-1)
            continue
        d = dict()
        i = 0
        while i+N-1<len(ans):
            d[ans[i:i+N]] = 1
            i += 1
        tot = pow(K,N)
        if len(d)==tot:
            print(len(ans))
        else:
            print(-1)
# } Driver Code Ends