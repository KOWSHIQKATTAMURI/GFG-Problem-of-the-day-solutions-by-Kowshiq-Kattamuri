#User function Template for python3

class Solution:
    def antiDiagonalPattern(self, matrix):
        result = []
        n = len(matrix)
        for k in range(n): #upper triangle traversal
            for i, j in zip(range(0, k + 1), range(k,-1,-1)):
                result.append(matrix[i][j])
        for k in range(1, n): #lower triangle traversal
            for i, j in zip(range(k, n), range(n - 1, -1, -1)):
                result.append(matrix[i][j])
        return result


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input()) 
        inp=list(map(int,input().split()))
        matrix=[]
        k = 0
        for i in range(n):
            row = []
            for j in range(n):
                row.append(inp[k])
                k += 1
            matrix.append(row)
        ob = Solution()
        ans = ob.antiDiagonalPattern(matrix)
        for i in ans:
            print(i,end=" ")
        print()


# } Driver Code Ends